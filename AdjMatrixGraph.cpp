#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class graph
{
    int n;             // Number of nodes in the graph
    bool matrix[5][5]; // take a 2D static array of fixed size for ease

public:
    graph(int size) : n(size)
    {
        // initialize all the values of the matrix to false
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = false;
            }
        }
    }

    void addedge(int source, int destination, bool bi)
    {
        // here bool bi means bidirectional or not
        // if true so node 1 should be connected to node 2 and also the vice versa
        matrix[source][destination] = true;
        if (bi)
        {
            matrix[destination][source] = true;
        }
    }

    void removeEdge(int source, int destination, bool bi)
    {
        matrix[source][destination] = false;
        if (bi)
        {
            matrix[destination][source] = false;
        }
    }

    void DFS(int start)
    {
        vector<bool> visited(n, false);
        stack<int> stack;

        stack.push(start);
        while (!stack.empty())
        {
            int vertex = stack.top();
            stack.pop();

            if (!visited[vertex])
            {
                visited[vertex] = true;
                cout << vertex << " ";

                for (int i = 0; i < n; i++)
                {
                    if (matrix[vertex][i] && !visited[i])
                    {
                        stack.push(i);
                    }
                }
            }
        }
    }

    void BFS(int start)
    {
        vector<bool> visited(n, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();
            cout << vertex << " ";

            for (int i = 0; i < n; i++)
            {
                if (matrix[vertex][i] && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    void print()
    {
        for (int i = 0; i < n; ++i)
        {
            cout << i << ": ";
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j])
                {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    graph g(5);
    g.addedge(0, 1, true);
    g.addedge(3, 1, true);
    g.addedge(0, 2, true);
    g.addedge(3, 2, true);
    g.addedge(0, 3, true);

    cout << "Graph before removing edges:" << endl;
    g.print();

    cout << "Graph after removing edges:" << endl;
    g.removeEdge(2, 3, true);
    g.print();

    cout << "DFS: ";
    g.DFS(0);
    cout << endl;

    cout << "BFS: ";
    g.BFS(0);
    cout << endl;

    return 0;
}