#include <iostream>
#include <queue>

using namespace std;

void main()
{
    priority_queue<int> pr_que;

    // 100, 300, 200 Push
    pr_que.emplace(100);
    pr_que.emplace(300);
    pr_que.emplace(200);

    // Pop 300
    pr_que.pop();

    cout << "Top: " << pr_que.top() << endl;

    cout << "Empty: " << boolalpha << pr_que.empty() << endl;

    cout << "크기: " << pr_que.size() << endl;
}