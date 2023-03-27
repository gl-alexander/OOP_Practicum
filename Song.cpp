#include "Song.h"
#pragma warning( disable : 4996)

Song::Song(const char* title, const char* performer, unsigned hours, unsigned minutes, unsigned seconds, const char* lyrics, unsigned plays)
{
	setTitle(title);
	setPerformer(performer);
	setDuration(hours, minutes, seconds);
	setLyrics(lyrics);
	_plays = plays;
}

Song::Song() : Song("Unknown", "Unknown Artist", 0, 0, 0, "No lyrics available", 0)
{}

void Song::setTitle(const char* title)
{
	if (std::strlen(title) > 64)
	{
		std::strcpy(_title, "Unknown");
	}
	else
	{
		std::strcpy(_title, title);
	}
}
void Song::setPerformer(const char* performer)
{
	if (std::strlen(performer) > 64)
	{
		std::strcpy(_performer, "Unknown");
	}
	else
	{
		std::strcpy(_performer, performer);
	}
}
void Song::setDuration(unsigned hours, unsigned minutes, unsigned seconds)
{
	Time duration(hours, minutes, seconds);
	_duration = duration;
}

void Song::setLyrics(const char* lyrics)
{
	if (std::strlen(lyrics) > 512)
	{
		std::strcpy(_lyrics, "Unknown");
	}
	else
	{
		std::strcpy(_lyrics, lyrics);
	}

}


const char* Song::getTitle() const
{
	return _title;
}
const char* Song::getPerformer() const
{
	return _performer;
}
const char* Song::getLyrics() const
{
	return _lyrics;
}
const Time& Song::getDuration() const
{
	return _duration;
}
unsigned Song::getPlays() const
{
	return _plays;
}

void Song::printSong() const
{
	std::cout << "> " << this->getTitle() << " - " << this->getPerformer() << std::endl;
	std::cout <<  "\t[" << this->getLyrics() << "]" << std::endl;
}

void Song::printSongInfo() const
{
	std::cout << this->getTitle() << " - " << this->getPerformer() << std::endl;
}