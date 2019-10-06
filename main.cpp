#include "PlaylistNode.h"
#include <iostream>
using namespace std;

//function prototypes
void PrintMenu(string title);
void AddSong(PlaylistNode* &head, PlaylistNode* &tail, string id, string songname, string artistname, int length);
bool RemoveSong(PlaylistNode* &head, PlaylistNode* &tail, string id);
void PrintList(PlaylistNode* head);
bool ChangePosition(PlaylistNode* &head, PlaylistNode* &tail, int oldPos, int newPos);
void SongsByArtist(PlaylistNode *head, string artist);
int TotalTime(PlaylistNode *head);

int main()
{
    string plTitle;
    cout << "Enter playlist's title: " << endl;
    getline(cin, plTitle);
    PrintMenu(plTitle);
}

void PrintMenu(string title)
{
    string choice = "";
    string id, sname, aname;
    int length, oldPos, newPos;
    PlaylistNode *head = NULL, *tail = NULL;

    do
    {
        cout << title << " PLAYLIST MENU" << endl;
        cout << "a - Add song" << endl;
        cout << "d - Remove song" << endl;
        cout << "c - Change position of song" << endl;
        cout << "s - Output songs by specific artist" << endl;
        cout << "t - Output total time of playlist (in seconds)" << endl;
        cout << "o - Output full playlist" << endl;
        cout << "q - Quit" << endl << endl;
        cout << "Choose an option: " << endl;
        cin >> choice;
        cin.ignore(); //flush newline

        if(choice == "a")
        {
            cout << "Enter song's unique ID: " << endl;
            cin >> id;
            cin.ignore();//ignore newline

            cout << "Enter song's name: " << endl;
            getline(cin, sname);
            cin.ignore();

            cout << "Enter artist's name: " << endl;
            getline(cin, aname);
            cin.ignore();

            cout << "Enter song's length(in seconds): " << endl;
            cin >> length;

            AddSong(head, tail, id, sname, aname, length);
        }

        else if(choice == "d")
        {
            cout << "Enter song's unique ID: ";
            cin >> id;

            RemoveSong(head, tail, id);
        }

        else if(choice == "c")
        {
            cout << "Enter song's current position: ";
            cin >> oldPos;
            cout << "Enter new position for song: ";
            cin >> newPos;

            ChangePosition(head, tail, oldPos, newPos);
        }

        else if(choice == "s")
        {
            cout << "Enter artist's name: ";
            getline(cin, aname);
            SongsByArtist(head, aname);
        }

        else if(choice == "t")
        {
            cout << "Total time: " << TotalTime(head) << " seconds" << endl;
        }

        else if(choice == "o")
        {
            PrintList(head);
        }
/*        
        else if(choice == "q")
        {
            cout << "Invalid menu choice! Please try again." << endl;
        }*/
    }while(choice != "q");
}

void AddSong(PlaylistNode* &head, PlaylistNode* &tail, string id, string songname, string artistname, int length)
{
    PlaylistNode* n = new PlaylistNode(id, songname, artistname, length);
    if(head == 0)
    {
        head = tail = n;
    }
    else
    {
        n -> InsertAfter(tail);
        tail = n;
    }
}

bool RemoveSong(PlaylistNode* &head, PlaylistNode* &tail, string id)
{
    PlaylistNode* curr = head;
    PlaylistNode* prev = NULL;
   
    while(curr != NULL)
    {
        if(curr->GetID() == id)
        {
            break;
        
            prev = curr;
            curr = curr->GetNext();
        }

        else if(curr == NULL)
        { //not found
            return false;
        }

        else
        {
            if(prev != NULL)
            {
                prev->SetNext(curr->GetNext());
            }

            else if(tail == curr)
            {
                tail = prev;
                cout << "\"" << curr->GetSongName() << "\" removed"<< endl;
                delete curr;
                return true;
            }

            else
            {
                head = curr->GetNext();
            }
        }
    }
    return true;
}

void PrintList(PlaylistNode* head)
{
    int i;
    
    if(head == NULL)
    {
        cout << "Playlist is empty." << endl;
    }

    else
    {
        PlaylistNode* curr = head;
        i = 1;
    
        while(curr != NULL)
        {
        cout << i++ << "." << endl;
        curr->PrintPlaylistNode();
        cout << endl;
        curr = curr->GetNext();
        }
    }
    cout << endl;
}

bool ChangePosition(PlaylistNode* &head, PlaylistNode* &tail, int oldPos, int newPos)
{
    PlaylistNode* prev = NULL;
    PlaylistNode* curr = head;

    int pos ;

    if(head == NULL || head == tail)
    {
        return false;
    //first locate the node that is to be move
    for(pos = 1; curr != NULL && pos < oldPos; pos++)
    {
        prev = curr;
        curr = curr->GetNext();
    
        if(curr != NULL) //found a node at given position
        {
        //delete it from the current list and later on insert it into the list at specified new poistion
        //after removing it from the curretn list, we don;t deallocate it but simply insert it in new position
        }
        
        else if(prev == NULL)
        {
            head = curr->GetNext();
        }
        
        else
        {
            prev->SetNext(curr->GetNext());
        }
    
    if(curr == tail)
    { //if we removed the tail node
            tail = prev;
        
            PlaylistNode* curr1 = curr;
            prev = NULL;
            curr = head;
        
        //now locate the new position
            for(pos = 1; curr != NULL && pos < newPos; pos++ )
            {
                prev = curr;
                curr = curr->GetNext();          
//insert in located position
                if(prev == NULL)
                {
                    curr->SetNext(head);
                    head = curr;
                }

                else
                {
                    curr->InsertAfter(prev);
                }
        
            }
    if(curr == NULL)
    {
        tail = curr;
        return true;
    }      
    }
    }
        }
        else
        {
            return false;
        }
    }


void SongsByArtist(PlaylistNode *head, string artist)
{
    if(head == NULL)
    {
        cout << "Playlist is empty." << endl;
    }
    else
    {
        PlaylistNode* curr = head;
        int i = 1;
    
        while(curr != NULL)
        {
            if(curr->GetArtistName() == artist)
            {
                cout << i << "." << endl;
                curr->PrintPlaylistNode();
                cout << endl;
                curr = curr->GetNext();
                i++;
            }
        }
    }
    cout << endl;
}
   
int TotalTime(PlaylistNode *head)
{
        int total = 0;
        PlaylistNode* curr = head;
        while(curr != NULL)
        {
            total += curr->GetSongLength();
            curr = curr->GetNext();
        }
    return total;
}