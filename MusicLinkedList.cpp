#include <iostream>
using namespace std;

class node
{
public:
    string song;
    node *next;
    node()
    {
        song="Null";
        next=nullptr;
    }
};

class songlist
{
private:
    node *head;
    node *temp;
    node *temp2;
    node *tail;

public:
    songlist()
    {
        head=temp=tail=temp2=nullptr;
    }

    void add_song()
    {
        int choice2;
        string replace;
        if (head==nullptr)
        {
            head=new node;
            cout << "Please Enter First Song Name: " << endl;
            cin >> head->song;
            head->next=nullptr;
            tail=head;
        }
        else
        {
            string key;
            temp=head;
            cout << "After which song do you want to enter? " << endl;
            cin >> key;
            while (temp!=nullptr)
            {
                if (temp->song==key)
                {
                    cout << "Found!" << endl;
                    temp2=new node;
                    cout << "Enter the Song Name: " << endl;
                    cin >> temp2->song;
                    temp2->next=temp->next;
                    temp->next=temp2;
                    cout << "1) - Top Favourite" << endl
                         << "2) - Least Favourite" << endl
                         << "3) - Somewhere Between, let me specify" << endl;
                    cin >> choice2;
                    if (choice2==1)
                    {
                        replace=head->song;
                        head->song=temp2->song;
                        temp2->song=replace;
                    }
                    else if (choice2==2)
                    {
                        tail=head;
                        while (tail->next!=nullptr)
                        {
                            tail=tail->next;
                        }
                        replace=tail->song;
                        tail->song=temp2->song;
                        temp2->song=replace;
                    }
                    else if (choice2==3)
                    {
                        int position;
                        cout << "Please Enter the position where you want to add it to" << endl;
                        cin >> position;
                        if (position <= 0)
                        {
                            cout << "Invalid position. Position should be a positive integer." << endl;
                            return;
                        }

                        int count=1;
                        temp=head;
                        while (temp!=nullptr && count!=position)
                        {
                            temp=temp->next;
                            count++;
                        }

                        if (temp!=nullptr)
                        {
                            replace=temp->song;
                            temp->song=temp2->song;
                            temp2->song=replace;
                        }
                        else
                        {
                            cout << "Position not found in the linked list." << endl;
                        }
                    }
                    return;
                }
                temp=temp->next;
            }

            cout << "Key not found in the linked list." << endl;
        }
    }

    void del_song()
    {
        if (head==nullptr)
        {
            cout << "The song list is empty." << endl;
            return;
        }

        string songName;
        cout << "Enter the song name to delete: ";
        cin >> songName;

        if (head->song==songName)
        {
            node *temp=head;
            head=head->next;
            delete temp;
            cout << "Song deleted successfully." << endl;
            return;
        }

        node *prev=head;
        node *curr=head->next;

        while (curr!=nullptr)
        {
            if (curr->song==songName)
            {
                prev->next=curr->next;
                if (curr==tail)
                {
                    tail=prev;
                }
                delete curr;
                cout << "Song deleted successfully." << endl;
                return;
            }
            prev=curr;
            curr=curr->next;
        }

        cout << "Song not found in the list." << endl;
    }

    void search_song()
    {
        if (head==nullptr)
        {
            cout << "The song list is empty." << endl;
            return;
        }

        string songName;
        cout << "Enter the song name to search: ";
        cin >> songName;

        temp=head;
        int count=0;
        bool found=false;

        while (temp!=nullptr)
        {
            if (temp->song==songName)
            {
                cout << "Song found at position " << count + 1 << "." << endl;
                found=true;
                break;
            }
            temp=temp->next;
            count++;
        }

        if (!found)
        {
            cout << "Song not found in the list." << endl;
        }
    }

    void update_song()
    {
        if (head==nullptr)
        {
            cout << "The song list is empty." << endl;
            return;
        }

        string songName;
        cout << "Enter the song name to update: ";
        cin >> songName;

        temp=head;
        bool found=false;

        while (temp!=nullptr)
        {
            if (temp->song==songName)
            {
                cout << "Enter the new song name: ";
                cin >> temp->song;
                cout << "Song updated successfully." << endl;
                found=true;
                break;
            }
            temp=temp->next;
        }

        if (!found)
        {
            cout << "Song not found in the list." << endl;
        }
    }

    void print_list()
    {
        if (head==nullptr)
        {
            cout << "The song list is empty." << endl;
            return;
        }

        temp=head;
        int count=1;

        while (temp!=nullptr)
        {
            cout << count << ". " << temp->song << endl;
            temp=temp->next;
            count++;
        }
    }

    void play_songs()
    {
        if (head==nullptr)
        {
            cout << "The song list is empty." << endl;
            return;
        }

        cout << "Playing songs:" << endl;
        temp=head;

        while (temp!=nullptr)
        {
            cout << "Now playing: " << temp->song << endl;
            temp=temp->next;
        }
    }
};

int main()
{
    songlist playlist;
    int choice;

    do
    {
        cout << "=========================================" << endl;
        cout << "1) - Add a Song" << endl;
        cout << "2) - Delete a Song" << endl;
        cout << "3) - Search for a Song" << endl;
        cout << "4) - Update a Song" << endl;
        cout << "5) - Print Playlist" << endl;
        cout << "6) - Play Songs" << endl;
        cout << "0) - Exit" << endl;
        cout << "=========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                playlist.add_song();
                break;
            case 2:
                playlist.del_song();
                break;
            case 3:
                playlist.search_song();
                break;
            case 4:
                playlist.update_song();
                break;
            case 5:
                playlist.print_list();
                break;
            case 6:
                playlist.play_songs();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice!=0);

    return 0;
}