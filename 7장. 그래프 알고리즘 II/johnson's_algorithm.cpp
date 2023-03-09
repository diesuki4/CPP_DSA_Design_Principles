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

bool HasNegativeCycle(const vector<Edge>& edges, vector<int> distance)
{
    for (const Edge& e : edges)
    {
        if (distance[e.src] == UNKNOWN)
            continue;

        if (distance[e.src] + e.weight < distance[e.dst])
            return true;
    }

    return false;
}

vector<int> BellmanFord(vector<Edge> edges, int V)
{
    vector<int> distance(V + 1, UNKNOWN);
    int s = V;

    for (int i = 0; i < V; ++i)
        edges.emplace_back(Edge{s, i, 0});

    distance[s] = 0;

    // 정점 개수가 V + 1개이므로
    // V번 반복해야 모든 거리를 갱신할 수 있다.
    for (int i = 0; i < V; ++i)
    {
        for (Edge& e : edges)
        {
            // 간선의 시작 정점의 거리가 UNKNOWN이면 스킵
            if (distance[e.src] == UNKNOWN)
                continue;

            // 새로 계산한 거리가 기존 거리보다 작으면
            if (distance[e.src] + e.weight < distance[e.dst])
                // 거리를 갱신
                distance[e.dst] = distance[e.src] + e.weight;
        }
    }

    // 음수 가중치 사이클 처리
    if (HasNegativeCycle(edges, distance))
    {
        cout << "음수 가중치 사이클 발견!" << endl;
        return {};
    }

    return distance;
}

int GetMinDistance(vector<int>& distance, vector<bool>& visited)
{
    int minDistance = UNKNOWN;
    int minIndex = -1;

    for (int i = 0; i < distance.size(); ++i)
    {
        if (visited[i] == false && distance[i] <= minDistance)
        {
            minDistance = distance[i];
            minIndex = i;
        }
    }

    return minIndex;
}

vector<int> Dijkstra(vector<Edge> edges, int V, int start)
{
    vector<int> distance(V, UNKNOWN);
    vector<bool> visited(V, false);

    distance[start] = 0;

    for (int i = 0; i < V - 1; ++i)
    {
        // 방문하지 않은 정점 중에 최소 거리 정점
        int curr = GetMinDistance(distance, visited);

        visited[curr] = true;

        for (const Edge& e : edges)
        {
            // 인접한 정점만 검사
            if (e.src != curr)
                continue;

            // 방문하지 않은 정점만 검사
            if (visited[e.dst])
                continue;

            // 현재 정점의 거리가 아직 설정되지 않았으면 스킵
            if (distance[curr] == UNKNOWN)
                continue;

            if (distance[curr] + e.weight < distance[e.dst])
                distance[e.dst] = distance[curr] + e.weight;
        }
    }

    return distance;
}

void Johnson(vector<Edge> edges, int V)
{
    // Dummy 정점을 추가한 그래프에서 최단 거리를 계산
    vector<int> h = BellmanFord(edges, V);

    if (h.empty())
        return;
    
    // 간선 가중치 재설정
    for (Edge& e : edges)
        e.weight += (h[e.src] - h[e.dst]);

    // 모든 정점들 사이의 최단 거리를 저장
    vector<vector<int>> shortest(V);

    for (int i = 0; i < V; ++i)
        shortest[i] = Dijkstra(edges, V, i);

    // 가중치 변환 수식을 역으로 적용해 최단 거리를 출력
    for (int i = 0; i < V; ++i)
    {
        cout << i << ":\n";

        for (int j = 0; j < V; ++j)
        {
            if (shortest[i][j] != UNKNOWN)
            {
                shortest[i][j] += (h[j] - h[i]);

                cout << "\t" << j << ": " << shortest[i][j] << endl;
            }
        }
    }
}

void main()
{
    int V = 5;
    vector<Edge> edges;
    vector<vector<int>> edge_map{
        {0, 1, -7},
        {1, 2, -2},
        {2, 0, 10},
        {0, 3, -5},
        {0, 4, 2},
        {3, 4, 4}
    };

    for (vector<int>& e : edge_map)
        edges.emplace_back(Edge{e[0], e[1], e[2]});

    Johnson(edges, V);
}
