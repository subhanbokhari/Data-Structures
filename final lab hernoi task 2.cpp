#include <iostream>
using namespace std;

struct Move
{
    int disk;
    char source;
    char destination;
    char auxiliary;
};

void towerOfHanoi(int numDisks)
{
    Move moves[numDisks];
    int moveCounter = 0;

    int top = -1;
    moves[++top] = {numDisks, 'A', 'C', 'B'};

    while (top >= 0)
    {
        Move currentMove = moves[top--];

        int disk = currentMove.disk;
        char source = currentMove.source;
        char destination = currentMove.destination;
        char auxiliary = currentMove.auxiliary;

        if (disk == 1)
        {
            cout << "Move disk 1 from rod " << source << " to rod " << destination << endl;
            moveCounter++;
        }
        else
        {
            moves[++top] = {disk - 1, auxiliary, destination, source};
            moves[++top] = {disk, source, destination, auxiliary};
            moves[++top] = {disk - 1, source, auxiliary, destination};
        }
    }

    cout << "Number of moves: " << moveCounter << endl;
}

int main()
{
    int numDisks;

    cout << "Enter the number of disks: ";
    cin >> numDisks;

    towerOfHanoi(numDisks);

    return 0;
}