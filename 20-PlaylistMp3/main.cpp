
/*
Section 20
Challenge 2
Using std::list

In this challenge you will create a menu driven application that
will simulate a user playing songs from a playlist of songs.

We will use a list to simulate the user selecting the the first song in the playlist and
then selecting next and previous to play forward of backwards through the
playlist.

Please refer to the video demo run.

We will also allow users to add new song to the playlist and they
will be added prior to the currently playing song.
The menu looks as follows:

F - Play First Song
N - Play Next song
P - Play Previous song
A - Add and play a new Song at current location
L - List the current playlist
========================
Enter a selection (Q to quit):

And the available playlist is modeled as a std::list<Song>
I will provide the Song class. Following are the songs in the playlist.
I grabbed these from the pop charts, you can use them or change
them to any songs you wish.

God's Plan                  Drake                                       5
Never Be The Same   Camila Cabello                         5
Pray For Me               The Weekend and K. Lamar      4
The Middle                Zedd, Maren Morris & Grey     5
Wait                           Maroone 5                                4
Whatever It Takes      Imagine Dragons                      3

I have provided the starting project.
Have fun!

Note:
If you have trouble reading input, you can clear std::cin and
ignore everything in the buffer with:

std::cin.clear();
std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

Make sure you #include <limits> to use it.

******************************************************************************/

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include <cstring>
#include <vector>


using namespace std;


class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }

    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }

    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
  os << std::setw(20) << std::left << s.name
    << std::setw(30) << std::left << s.artist
    << std::setw(2) << std::left << s.rating;
    return os;
}




void display_menu() {
  std::cout << "\nF - Play First Song" << std::endl;
  std::cout << "N - Play Next song" << std::endl;
  std::cout << "P - Play Previous song" << std::endl;
  std::cout << "A - Add and play a new Song at current location" << std::endl;
  std::cout << "L - List the current playlist" << std::endl;
  std::cout << "===============================================" << std::endl;
  std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
  cout << "Playing... " << song.get_name() << " by " << song.get_artist() << endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    // This function should display the current playlist
    // and then the current song playing.

  std::cout << "----------------Playlist-------------------"<< endl;
    for( auto it = playlist.begin(); it != playlist.end(); it++) {
		  std::cout << *it << std::endl;
	  }
  std::cout << "------------------------------------------"<< endl;

  play_current_song(current_song);

}

char getSelection()
{
  char selection {};
  cin >> selection;
  return toupper(selection);
}

std::list<Song>::iterator firstSong(std::list<Song> playlist) {
  cout << "First song will be played" << endl;

  std::list<Song>::iterator first_song = playlist.begin();

  play_current_song(*first_song) ;
  return first_song;
}

std::list<Song>::iterator addSong(std::list<Song> &playlist, std::list<Song>::iterator it) {

  string name, artist, ratingStr {};
  int rating {};

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  cout << "--- New Song ---" << endl;
  cout << "Write the name:" << endl;
  std::getline(std::cin, name);

  cout << "Write the artist:" << endl;
  std::getline(std::cin, artist);
  cout << "Ingress de rating [1-5]:" << endl;
  cin >> rating;

  Song s {name, artist, rating};
  playlist.insert(it, s);

  return it;
}

std::list<Song>::iterator nextSong(std::list<Song>::iterator it) {

  cout << "Next song will be played" << endl;
  it++;
  play_current_song(*it) ;
  return it;

}

std::list<Song>::iterator prevSong(std::list<Song>::iterator it) {
  cout << "Prev song will be played" << endl;
  it--;
  play_current_song(*it) ;
  return it;
}



int main()
{

    std::list<Song> playlist{
        {"God's Plan",        "Drake",                     5},
        {"Never Be The Same", "Camila Cabello",            5},
        {"Pray For Me",       "The Weekend and K. Lamar",  4},
        {"The Middle",        "Zedd, Maren Morris & Grey", 5},
        {"Wait",              "Maroone 5",                 4},
        {"Whatever It Takes", "Imagine Dragons",           3}
    };

    std::list<Song>::iterator current_song = playlist.begin();

    // Your program logic goes here

    char selection {};

    do {
      display_menu();

      selection = getSelection();

      //cout << "Current selection: "<< selection << endl;

      switch(selection){
        case 'F':
          current_song = firstSong(playlist);
          break;
        case 'N':
          current_song = nextSong(current_song);
          break;
    		case 'P':
          current_song = prevSong(current_song);
          break;
    		case 'A':
          current_song = addSong(playlist, current_song);
          break;
    		case 'L':
          display_playlist(playlist, *current_song);
          break;
    		case 'Q':
          cout << "Exit...";
          break;
        default:
          cout << "Unknown selection, please try again" << endl ;
        }

    } while ( selection != 'Q');

    std::cout << "Thanks for listening!" << std::endl;
    return 0;



}
