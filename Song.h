#pragma once
#include "Time.h"

class Song
{
	char _title[65];
	char _performer[65];
	Time _duration;
	char _lyrics[512 + 1];
	unsigned _plays;

public:
	Song(const char* title, const char* performer, unsigned hours, unsigned minutes, unsigned seconds, const char* lyrics, unsigned plays);
	Song();

	void setTitle(const char* title);
	void setPerformer(const char* performer);
	void setDuration(unsigned hours, unsigned minutes, unsigned seconds);
	void setLyrics(const char* lyrics);

	const char* getTitle() const;
	const char* getPerformer() const;
	const char* getLyrics() const;
	const Time& getDuration() const;
	unsigned getPlays() const;

	void printSong() const;
	void printSongInfo() const;
}; 
