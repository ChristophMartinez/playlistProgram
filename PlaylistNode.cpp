#include "PlaylistNode.h"
using namespace std;

PlaylistNode::PlaylistNode()
{
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = 0;
}

PlaylistNode::PlaylistNode(string id, string songname, string artist, int length)
{
    uniqueID = id;
    songName = songname;
    artistName = artist;
    songLength = length;
    nextNodePtr = 0;
}

void PlaylistNode::InsertAfter(PlaylistNode* ptr)
{
    this -> SetNext(ptr->GetNext());
    ptr -> SetNext(this);
}

void PlaylistNode::SetNext(PlaylistNode* ptr)
{
    nextNodePtr = ptr;
}

string PlaylistNode::GetID()
{
    return uniqueID;
}

string PlaylistNode::GetSongName()
{
    return songName;
}

string PlaylistNode::GetArtistName()
{
    return artistName;
}

int PlaylistNode::GetSongLength()
{
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext()
{
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode()
{
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length: " << songLength << endl;
}

