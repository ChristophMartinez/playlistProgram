#pragma once
#include <iostream>
using namespace std;
class PlaylistNode
{
    public:
        PlaylistNode();
        PlaylistNode(string id, string songname, string artist, int length);
        void InsertAfter(PlaylistNode* ptr);
        void SetNext(PlaylistNode* ptr);
        string GetID();
        string GetSongName();
        string GetArtistName();
        int GetSongLength();
        PlaylistNode* GetNext();
        void PrintPlaylistNode();

    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;
};


