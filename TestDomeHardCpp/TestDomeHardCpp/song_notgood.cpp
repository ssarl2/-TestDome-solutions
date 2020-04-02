#include <stdexcept>
#include <iostream>

class Song
{
public:
    Song(std::string name) : name(name), nextSong(NULL) {}

    void next(Song* song)
    {
        this->nextSong = song;
    }

    bool isRepeatingPlaylist()
    {
        Song* curr(this->nextSong);

        while (curr != nullptr)
        {
            if (curr == this)
                return true;
            curr = curr->nextSong;
        }

        return false;
    }

private:
    const std::string name;
    Song* nextSong;
};

#ifndef RunTests
int main()
{
    Song* first = new Song("Hello");
    Song* second = new Song("Eye of the tiger");

    first->next(second);
    second->next(first);

    std::cout << std::boolalpha << first->isRepeatingPlaylist();
}
#endif