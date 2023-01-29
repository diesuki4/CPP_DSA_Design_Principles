#include <iostream>
#include <queue>

using namespace std;

void main()
{
    queue<int> que;

    // 1, 2, 3 Push
    que.emplace(1);
    que.emplace(2);
    que.emplace(3);
    
    // Pop
    que.pop();

    cout << "Front: " << que.front() << endl;

    cout << "Rear: " << que.back() << endl;

    cout << "Empty: " << boolalpha << que.empty() << endl;

    cout << "크기: " << que.size() << endl;
}