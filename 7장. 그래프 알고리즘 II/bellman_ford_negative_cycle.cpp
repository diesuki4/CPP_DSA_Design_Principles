#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int UNKNOWN = INT_MAX;

struct Edge
{
    int src;
    int dst;
    int weight;
};

vector<int> BellmanFord(vector<Edge> edges, int V, int start)
{
    vector<int> distance(V, UNKNOWN);
    distance[start] = 0;

    // (V - 1)번 반복
    // 이 수만큼 반복해야 시작정점부터 마지막 정점까지 모든 거리가 갱신된다.
    for (int i = 0; i < V - 1; ++i)
    {
        // 모든 간선의 거리(시작점으로부터의)를 갱신
        for (Edge& e : edges)
        {
            // 간선의 시작 정점의 거리가 초기화되지 않았으면 스킵
            if (distance[e.src] == UNKNOWN)
                continue;

            // 새로운 경로에 의한 거리가 기존 거리보다 작으면
            if (distance[e.src] + e.weight < distance[e.dst])
                // 인접한 정점의 거리를 갱신
                distance[e.dst] = distance[e.src] + e.weight;
        }
    }

    // 음수 가중치 사이클이 있는지 검사
    for (Edge& e : edges)
    {
        // 간선의 시작 정점의 거리가 초기화되지 않았으면 스킵
        if (distance[e.src] == UNKNOWN)
            continue;

        // 다시 한 번 계산한 경로에 의한 거리가 기존 거리보다 작으면
        if (distance[e.src] + e.weight < distance[e.dst])
        {
            cout << "음수 가중치 사이클 발견!" << endl;
            return {};
        }
    }

    return distance;
}

void main()
{
    int V = 6;
    vector<Edge> edges;

    vector<vector<int>> edge_map{
        {0, 1, 3},
        {1, 3, -8},
        {2, 1, 3},
        {2, 5, 5},
        {3, 2, 3},
        {2, 4, 2},
        {4, 5, -1},
        {5, 1, 8}
    };

    for (vector<int>& e : edge_map)
        edges.emplace_back(Edge{e[0], e[1], e[2]});

    int start = 0;
    vector<int> distance = BellmanFord(edges, V, start);

    if (!distance.empty())
    {
        cout << "[" << start << "번 정점으로부터 최소 거리]" << endl;

        for (int i = 0; i < distance.size(); ++i)
            if (distance[i] == UNKNOWN)
                cout << i << "번 정점: 방문하지 않음!" << endl;
            else
                cout << i << "번 정점: " << distance[i] << endl;
    }
}
