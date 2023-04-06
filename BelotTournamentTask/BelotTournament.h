#pragma once
#include "Team.h"

//TODO: big 4, resize teams

class BelotTournament
{
	Team* _teams = nullptr;
	Team* _losingTeams = nullptr;

	unsigned _teamsCount = 0;
	unsigned _capacity = 2;

	int runRound(unsigned indFirst, unsigned indSecond, size_t roundNumber) const;
	void runDuel(int& scoreFirst, int& scoreSecond, unsigned indFirst, unsigned indSecond) const;
	void runBracket(size_t activeTeams,int indexF, int indexS, int* winnerIndexes) const;

	int* generateShuffle(unsigned teamsCount) const;

	void resize(size_t newCapacity);
	void copyFrom(const BelotTournament& other);
	void free();
public:
	BelotTournament(unsigned startingCapacity);
	BelotTournament(const BelotTournament& other);
	BelotTournament& operator=(const BelotTournament& other);
	~BelotTournament();

	void addTeam(const SoftwareEngineer& first, const SoftwareEngineer& second);
	unsigned getTeamsCount() const;
	void runTournament();

};