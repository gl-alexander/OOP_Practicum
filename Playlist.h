#pragma once
#include "Song.h"

const int MAX_SONGS_COUNT = 120;

class Playlist
{
	char _name[50];
	Song _songs[MAX_SONGS_COUNT];
	Time _playlist_duration;
	unsigned _songsCount;

	bool isInPlaylist(const Song& song) const;
	unsigned getUniqueSongsCount() const;
	Song* getUniqueSongs() const;

public:
	void playAllSongs();
	void printAllSongs() const;
	void printMostPopular() const;
	const Time& getDuration() const;
	void addSong(const Song& song);
	void removeSong(unsigned ind);

	Playlist(const char* name);
}; 
