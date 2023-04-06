#include "BelotTournament.h"
#include <iostream>
#include <random>
#include <time.h>

const unsigned POINTS_TO_WIN = 151;

namespace
{
	int getPowerOfTwo(unsigned n)
	{
		unsigned i = 0;
		while (true)
		{
			if ((1 << i) >= n) return i;
			i++;
		}
		return -1;
	}

	
}

void BelotTournament::resize(size_t newCapacity)
{
	Team* newTeams = new Team[newCapacity];
	for (int i = 0; i < _capacity; i++)
	{
		newTeams[i] = _teams[i];
	}
	delete[] _teams;
	_teams = newTeams;
	_capacity = newCapacity;
}
void BelotTournament::copyFrom(const BelotTournament& other)
{
	_teamsCount = other._teamsCount;
	_capacity = other._capacity;
	_teams = new Team[_teamsCount];
	for (int i = 0; i < _teamsCount; i++)
	{
		_teams[i] = other._teams[i];
	}
}
void BelotTournament::free()
{
	delete[] _teams;
	_teams = nullptr;
	_capacity = _teamsCount = 0;
}

BelotTournament::BelotTournament(unsigned startingCapcity = 2)
{
	_capacity = startingCapcity;
	_teams = new Team[_capacity];
	_teamsCount = 0;
}

BelotTournament::BelotTournament(const BelotTournament& other)
{
	copyFrom(other);
}
BelotTournament& BelotTournament::operator=(const BelotTournament& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
BelotTournament::~BelotTournament()
{
	free();
}

void BelotTournament::addTeam(const SoftwareEngineer& first, const SoftwareEngineer& second)
{
	if (_teamsCount + 1 > _capacity)
	{
		resize(_capacity * 2);
	}

	Team newTeam;
	newTeam._first = first;
	newTeam._second = second;
	_teams[_teamsCount++] = newTeam;
}

int* BelotTournament::generateShuffle(unsigned teamCount) const
{
	srand(time(0));
	int* shuffle = new int[teamCount];
	for (int i = 0; i < teamCount; i++)
	{
		shuffle[i] = i + 1;
	}
	for (int i = 0; i < teamCount; i++)
	{
		int randIndex = rand() % teamCount;
		if (randIndex == i) continue;
		std::swap(shuffle[i], shuffle[randIndex]);
	}
	return shuffle;
}

void BelotTournament::runBracket(size_t activeTeams, int indFirst, int indSecond, int* winnerIndexes) const
{
	for (int i = 0; i < activeTeams / 2; i++ )
	{
		std::cout << "Now playing: Team #" << indFirst << " against Team #" << indSecond << std::endl;
		winnerIndexes[i] = runRound(indFirst, indSecond, i + 1);
	}
}

int BelotTournament::runRound(unsigned indFirst, unsigned indSecond, size_t roundNumber) const
{
	int resultFirst = 0;
	int resultSecond = 0;

	std::cout << "Enter the scores of both teams in the format: <score first> <score second>\n";
	while (resultFirst < 2 && resultSecond < 2)
	{
		runDuel(resultFirst, resultSecond, indFirst, indSecond);
	}
	
	size_t winnerIndex = (resultFirst == 2) ? indFirst : indSecond;

	std::cout << "Team #" << winnerIndex << " wins round " << roundNumber << "!\n";
	return winnerIndex;
}

void BelotTournament::runDuel(int& scoreFirst, int& scoreSecond, unsigned indFirst, unsigned indSecond) const
{
	int duelPointsFirst = 0;
	int duelPointsSecond = 0;
	while (duelPointsFirst < POINTS_TO_WIN && duelPointsSecond < POINTS_TO_WIN)
	{
		int roundFirst, roundSecond;
		std::cin >> roundFirst >> roundSecond;
		duelPointsFirst += roundFirst;
		duelPointsSecond += roundSecond;
	}

	if (duelPointsFirst > duelPointsSecond)
		scoreFirst++;
	else
		scoreSecond++;

	std::cout << "Team #" << indFirst << ": " << scoreFirst << " \tTeam #" << indSecond << ": " << scoreSecond << std::endl;
}



unsigned BelotTournament::getTeamsCount() const
{
	return _teamsCount;
}
void BelotTournament::runTournament()
{
	if (_teamsCount % 2) _teamsCount--;

	int* winnerIndexes = new int[_teamsCount / 2];
	//8 -- 4 -- 2 -- 1 ---> 7
	//6 -- 3->2 -- 1
	unsigned totalRounds = getPowerOfTwo(_teamsCount);
	
	for (int i = 1; i <= totalRounds; i++)
	{
		int activeTeams = _teamsCount / i;
		int* shuffle = generateShuffle(activeTeams); // array with shuffled indexes
		
		runBracket(activeTeams, shuffle[i], shuffle[i + 1], winnerIndexes);

		delete[] shuffle;
	}
	
	delete[] winnerIndexes;
}

