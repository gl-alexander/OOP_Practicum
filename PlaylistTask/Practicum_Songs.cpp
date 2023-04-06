#include <iostream>
#include "Playlist.h"

int main()
{
    Playlist playlist("My playlist");

    Song song1("Ataka mix", "Kondio", 0, 2, 34, "male dvata noja", 12300);
    Song song2("Sen trope", "Azis", 0, 3, 44, "vs sa na sen trope", 2300000);
    Song song3("momiche ot led", "Simona", 0, 4, 12, "5 min samo", 2000);
    Song song4("Kato za final", "Preslava", 0, 3, 53, "do sinio", 79932);

 

    playlist.addSong(song1);
    playlist.addSong(song2);
    playlist.addSong(song1);
    playlist.addSong(song3);
    playlist.addSong(song3);
    playlist.addSong(song4);
    playlist.addSong(song2);
    playlist.addSong(song1);

    std::cout << "Durationn: " << std::endl;
    playlist.getDuration().print(false);

    std::cout << "songs: " << std::endl;
    playlist.printAllSongs();

    std::cout << "playsongs: " << std::endl;
    playlist.playAllSongs();

    std::cout << "most popular: " << std::endl;
    playlist.printMostPopular();
}

