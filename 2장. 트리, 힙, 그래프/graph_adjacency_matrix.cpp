#include <iostream>
#include <vector>

using namespace std;

enum class city : int
{
    MOSCOW,
    LONDON,
    SEOUL,
    SEATTLE,
    DUBAI,
    SYDNEY
};

ostream& operator<<(ostream& os, const city c)
{
    switch (c)
    {
    case city::MOSCOW:  os << "모스크바"; break;
    case city::LONDON:  os << "런던"; break;
    case city::SEOUL:   os << "서울"; break;
    case city::SEATTLE: os << "시애틀"; break;
    case city::DUBAI:   os << "두바이"; break;
    case city::SYDNEY:  os << "시드니"; break;
    }

    return os;
}

struct graph
{
    // 인접 행렬에 각 공항 사이의 거리를 저장한다.
    vector<vector<int>> data;

    graph(int n) : data(vector<vector<int>>(n, vector<int>(n, -1))) { }

    void addEdge(const city c1, const city c2, int dist)
    {
        int n1 = static_cast<int>(c1);
        int n2 = static_cast<int>(c2);

        data[n1][n2] = data[n2][n1] = dist;

        cout << "간선 추가: " << c1 << "-" << c2 << "=" << dist << endl;
    }

    void removeEdge(const city c1, const city c2)
    {
        int n1 = static_cast<int>(c1);
        int n2 = static_cast<int>(c2);

        data[n1][n2] = data[n2][n1] = -1;

        cout << "간선 삭제: " << c1 << "-" << c2 << endl;
    }
};

void main()
{
    graph g(6);

    g.addEdge(city::LONDON, city::MOSCOW, 2500);
    g.addEdge(city::LONDON, city::SEOUL, 9000);
    g.addEdge(city::LONDON, city::DUBAI, 5500);
    g.addEdge(city::SEOUL, city::MOSCOW, 6600);
    g.addEdge(city::SEOUL, city::SEATTLE, 8000);
    g.addEdge(city::SEOUL, city::DUBAI, 7000);
    g.addEdge(city::SEOUL, city::SYDNEY, 8000);
    g.addEdge(city::SEATTLE, city::MOSCOW, 8400);
    g.addEdge(city::SEATTLE, city::SYDNEY, 12000);
    g.addEdge(city::DUBAI, city::SYDNEY, 1200);
    g.addEdge(city::SEATTLE, city::LONDON, 8000);
    g.removeEdge(city::SEATTLE, city::LONDON);
}
