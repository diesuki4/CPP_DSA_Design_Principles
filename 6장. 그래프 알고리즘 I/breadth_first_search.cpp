#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

template <typename T>
struct Edge
{
    unsigned src;
    unsigned dst;
    T weight;
};

template <typename T>
class Graph
{
private:
    unsigned V;
    vector<Edge<T>> edge_list;

public:
    // N개의 정점으로 구성된 그래프
    Graph(unsigned N) : V(N) {}

    // 정점 개수 반환
    unsigned vertices() const { return V; }

    // 간선 리스트 반환
    vector<Edge<T>>& edges() const { return edge_list; }

    // v가 출발지인 모든 간선을 반환
    vector<Edge<T>> edges(unsigned v) const
    {
        vector<Edge<T>> edges_from_v;

        copy_if(edge_list.begin(), edge_list.end(), back_inserter(edges_from_v), [v](const Edge<T>& e) { return e.src == v; });

        return edges_from_v;
    }

    void add_Edge(Edge<T>&& e)
    {
        if (1 <= e.src && e.src <= V && 1 <= e.dst && e.dst <= V)
            edge_list.emplace_back(e);
        else
            cerr << "에러: 유효 범위를 벗어난 정점!" << endl;
    }

    template <typename U>
    friend ostream& operator << (ostream& os, const Graph<U>& G);
};

template <typename U>
ostream& operator << (ostream& os, const Graph<U>& G)
{
    for (unsigned i = 1; i < G.vertices(); ++i)
    {
        os << i << ":\t";

        for (Edge<U>& e : G.edges(i))
            os << "{" << e.dst << ": " << e.weight << "}, ";

        os << endl;
    }

    return os;
}

template <typename T>
Graph<T> create_reference_graph()
{
    Graph<T> G(9);

    map<unsigned, vector<pair<unsigned, T>>> edge_map;
    edge_map[1] = {{2, 0}, {5, 0}};
    edge_map[2] = {{1, 0}, {5, 0}, {4, 0}};
    edge_map[3] = {{4, 0}, {7, 0}};
    edge_map[4] = {{2, 0}, {3, 0}, {5, 0}, {6, 0}, {8, 0}};
    edge_map[5] = {{1, 0}, {2, 0}, {4, 0}, {8, 0}};
    edge_map[6] = {{4, 0}, {7, 0}, {8, 0}};
    edge_map[7] = {{3, 0}, {6, 0}};
    edge_map[8] = {{4, 0}, {5, 0}, {6, 0}};

    for (auto& i : edge_map)
        for (pair<unsigned, T>& j : i.second)
            G.add_Edge(Edge<T>{i.first, j.first, j.second});

    return G;
}

template <typename T>
vector<unsigned> breadth_first_search(const Graph<T>& G, unsigned start)
{
    set<unsigned> visited;          // 방문한 정점
    vector<unsigned> visit_order;   // 방문 순서
    queue<unsigned> que;

    que.push(start);

    while (!que.empty())
    {
        unsigned current_vertex = que.front(); que.pop();

        if (visited.find(current_vertex) == visited.end())
        {
            visited.insert(current_vertex);
            visit_order.emplace_back(current_vertex);

            for (Edge<T>& e : G.edges(current_vertex))
                if (visited.find(e.dst) == visited.end())
                    que.push(e.dst);
        }
    }

    return visit_order;
}

void main()
{
    using T = unsigned;

    Graph<T> G = create_reference_graph<T>();
    cout << "[입력 그래프]" << endl;
    cout << G << endl;

    // 1번 정점부터 BFS 수행
    vector<T> bfs_visit_order = breadth_first_search<T>(G, 1);

    // 방문 순서 출력
    cout << "[BFS 방문 순서]" << endl;
    for (T v : bfs_visit_order)
        cout << v << endl;
}
