#include <iostream>
#include <deque>

using namespace std;

ostream& operator<<(ostream& os, deque<int> deq)
{
    for (int e : deq)
        os << e << ' ';

    return os;
}

void main()
{
    deque<int> que;

    // 1, 2, 3 Push
    que.emplace_back(1);
    que.emplace_back(2);
    que.emplace_back(3);

    // Pop
    que.pop_front();

    cout << que << endl;

    cout << "Front: " << que.front() << endl;

    cout << "Rear: " << que.back() << endl;

    cout << "Empty: " << boolalpha << que.empty() << endl;

    cout << "크기: " << que.size() << endl;
}