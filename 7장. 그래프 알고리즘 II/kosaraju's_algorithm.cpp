#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void FillStack(int node, vector<bool>& visited, vector<vector<int>>& adj, stack<int>& stack)
{
    visited[node] = true;

    for (int next : adj[node])
        if (visited[next] == false)
            FillStack(next, visited, adj, stack);

    stack.emplace(node);
}

vector<vector<int>> Transpose(int V, vector<vector<int>> adj)
{
    vector<vector<int>> transpose(V);

    for (int i = 0; i < V; ++i)
        for (int next : adj[i])
            transpose[next].emplace_back(i);

    return transpose;
}

void CollectConnectedComponents(int node, vector<bool>& visited, vector<vector<int>>& adj, vector<int>& component)
{
    visited[node] = true;
    component.emplace_back(node);

    for (int next : adj[node])
        if (visited[next] == false)
            CollectConnectedComponents(next, visited, adj, component);
}

vector<vector<int>> Kosaraju(int V, vector<vector<int>> adj)
{
    vector<bool> visited(V, false);
    stack<int> stack;

    for (int i = 0; i < V; ++i)
        if (visited[i] == false)
            FillStack(i, visited, adj, stack);

    vector<vector<int>> transpose = Transpose(V, adj);

    fill(visited.begin(), visited.end(), false);

    vector<vector<int>> connectedComponents;

    while (!stack.empty())
    {
        int node = stack.top(); stack.pop();

        if (visited[node] == false)
        {
            vector<int> component;

            CollectConnectedComponents(node, visited, transpose, component);
            connectedComponents.emplace_back(component);
        }
    }

    return connectedComponents;
}

void main()
{
    int V = 9;
    vector<vector<int>> adj = {
        {1, 3},
        {2, 4},
        {3, 5},
        {7},
        {2},
        {4, 6},
        {7, 2},
        {8},
        {3}
    };

    vector<vector<int>> connectecComponents = Kosaraju(V, adj);

    cout << "강한 연결 요소 개수: " << connectecComponents.size() << endl;

    for (int i = 0; i < connectecComponents.size(); ++i)
    {
        cout << "[" << i + 1 << "] ";

        for (int node : connectecComponents[i])
            cout << node << " ";

        cout << endl;
    }
}
