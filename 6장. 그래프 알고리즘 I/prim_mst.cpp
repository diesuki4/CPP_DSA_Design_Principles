#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <limits>

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
    Graph(unsigned V) : V(V) {}

    // 정점 개수 반환
    unsigned vertices() const { return V; }

    // 간선 리스트 반환
    vector<Edge<T>>& edges() const { return edge_list; }

    // v가 출발지인 모든 간선 반환
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

    friend ostream& operator << (ostream& os, const Graph<T>& G)
    {
        for (unsigned i = 1; i < G.vertices(); ++i)
        {
            os << i << ":\t";

            for (Edge<T>& e : G.edges(i))
                os << "{" << e.dst << ": " << e.weight << "}, ";

            os << endl;
        }

        return os;
    }
};

template <typename T>
Graph<T> create_reference_graph()
{
    // 정점이 8개인 그래프 생성
    // 0번 ID는 사용하지 않는다.
    Graph<T> G(9);

    map<unsigned, vector<pair<unsigned, T>>> edge_map;
    edge_map[1] = {{2, 2}, {5, 3}};
    edge_map[2] = {{1, 2}, {5, 5}, {4, 1}};
    edge_map[3] = {{4, 2}, {7, 3}};
    edge_map[4] = {{2, 1}, {3, 2}, {5, 2}, {6, 4}, {8, 5}};
    edge_map[5] = {{1, 3}, {2, 5}, {4, 2}, {8, 3}};
    edge_map[6] = {{4, 4}, {7, 4}, {8, 1}};
    edge_map[7] = {{3, 3}, {6, 4}};
    edge_map[8] = {{4, 5}, {5, 3}, {6, 1}};

    for (auto& i : edge_map)
        for (pair<unsigned, T>& j : i.second)
            G.add_Edge(Edge<T>{i.first, j.first, j.second});

    return G;
}

template <typename T>
struct Label
{
    unsigned ID;
    T distance;

    inline bool operator > (const Label<T>& l) const
    {
        return distance > l.distance;
    }
};

// 매 번 경계에서 가장 가까운 정점을 선택한다.
template <typename T>
vector<unsigned> prim_MST(const Graph<T>& G, unsigned src)
{
    priority_queue<Label<T>, vector<Label<T>>, greater<Label<T>>> heap;
    vector<T> distance(G.vertices(), numeric_limits<T>::max());

    set<unsigned> visited;
    vector<unsigned> MST;

    heap.emplace(Label<T>{src, 0});

    while (!heap.empty())
    {
        Label<T> current_vertex = heap.top(); heap.pop();

        if (visited.find(current_vertex.ID) == visited.end())
        {
            MST.emplace_back(current_vertex.ID);

            for (Edge<T>& e : G.edges(current_vertex.ID))
            {
                unsigned neighbor = e.dst;
                T new_distance = e.weight;

                // 경계로부터의 거리를 갱신
                if (new_distance < distance[neighbor])
                {
                    heap.emplace(Label<T>{neighbor, new_distance});
                    distance[neighbor] = new_distance;
                }

                visited.emplace(current_vertex.ID);
            }
        }
    }

    return MST;
}

void main()
{
    using T = unsigned;

    Graph<T> G = create_reference_graph<T>();
    cout << "[입력 그래프]" << endl;
    cout << G << endl;

    // aaaa
    vector<T> MST = prim_MST<T>(G, 1);

    // bbbb
    cout << "[최소 신장 트리]" << endl;
    for (unsigned v : MST)
        cout << v << endl;
}
