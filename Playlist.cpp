#include "Playlist.h"
#pragma warning( disable : 4996)

namespace 
{
	bool compareSongsPlays(const Song& song1, const Song& song2)
	{
		return song1.getPlays() > song2.getPlays();
	}

	void sortSongsByPlays(Song* songs, size_t size)
	{
		for (int i = 0; i < size - 1; i++)
		{
			int maxDur = i;
			for (int j = i + 1; j < size; j++)
			{
				if (!compareSongsPlays(songs[maxDur], songs[j]))
					maxDur = j;
			}
			if (maxDur != i)
			{
				std::swap(songs[maxDur], songs[i]);
			}
		}
	}

	bool isSongInArray(const Song& song, Song* arr, size_t size)
	{
		for (int i = 0; i < size; i++)
		{
			if (std::strcmp(song.getTitle(), arr[i].getTitle()) == 0) return true;
		}
		return false;
	}

	bool sameSong(const Song& song1, const Song& song2)
	{
		bool sameTitle = std::strcmp(song1.getTitle(), song2.getTitle()) == 0;
		bool samePerformer = std::strcmp(song1.getPerformer(), song2.getPerformer()) == 0;

		return sameTitle && samePerformer;
	}
}

bool Playlist::isInPlaylist(const Song& song) const
{
	for (int i = 0; i < _songsCount; i++)
	{
		if (sameSong(_songs[i], song)) return true;
	}
	return false;
}

unsigned Playlist::getUniqueSongsCount() const
{
	int count = 0;
	bool visited[MAX_SONGS_COUNT] = { 0 };

	for (int i = 0; i < _songsCount - 1; i++)
	{
		if (visited[i]) continue;
		for (int j = i + 1; j < _songsCount; j++)
		{
			if (sameSong(_songs[i], _songs[j]))
				visited[j] = true;
		}

		count++;
	}
	return count;
}

Song* Playlist::getUniqueSongs() const
{
	int uniqueSongsCount = getUniqueSongsCount();
	Song* unique = new Song[uniqueSongsCount];
	int currentInd = 0;
	bool visited[MAX_SONGS_COUNT] = { 0 };

	for (int i = 0; i < _songsCount; i++)
	{
		if (visited[i]) continue;
		for (int j = i + 1; j < _songsCount; j++)
		{
			if (sameSong(_songs[i], _songs[j]))
				visited[j] = true;
		}
		unique[currentInd++] = _songs[i];
	}
	return unique;
}



void Playlist::playAllSongs()
{
	for (int i = 0; i < _songsCount; i++)
		_songs[i].printSong();
}

void Playlist::printAllSongs() const
{
	for (int i = 0; i < _songsCount; i++)
		_songs[i].printSongInfo();
}

void Playlist::printMostPopular() const
{
	int uniqueSongsCount = getUniqueSongsCount();
	Song* sortedSongs = getUniqueSongs();

	sortSongsByPlays(sortedSongs, uniqueSongsCount);

	for (int i = 0; i < uniqueSongsCount; i++)
	{
		std::cout << sortedSongs[i].getPlays() << " ";
		sortedSongs[i].printSongInfo();
	}

	delete[] sortedSongs;
}

const Time& Playlist::getDuration() const
{
	return _playlist_duration;
}


void Playlist::addSong(const Song& song)
{
	_songs[_songsCount++] = song; //add song to songs array and increment the count
	_playlist_duration.addTime(song.getDuration()); // add to playlist duration
}
void Playlist::removeSong(unsigned ind)
{
	if (ind >= _songsCount) return;

	_playlist_duration.subtractTime(_songs[ind].getDuration()); // subtract from the playlist duration
	std::swap(_songs[ind], _songs[_songsCount]); //move it to the end
	_songsCount--; //reduce song count
}

Playlist::Playlist(const char* name)
{
	_songsCount = 0;
	if (std::strlen(name) > 0 && std::strlen(name) < 40)
	{
		std::strcpy(_name, name);
	}
	else
	{
		std::strcpy(_name, "Unnamed playlist");
	}
}