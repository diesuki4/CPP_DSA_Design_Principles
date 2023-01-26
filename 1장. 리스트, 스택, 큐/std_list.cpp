#include <iostream>
#include <list>

using namespace std;

ostream& operator<<(ostream& os, const list<int>& lst)
{
    for (int e : lst)
        cout << e << ' ';

    return os;
}

void main()
{
    list<int> lst = {1, 2, 3, 4, 5};

    // 맨 앞에 0 추가
    lst.emplace_front(0);
    cout << lst << endl;

    // 맨 뒤에 6 추가
    lst.emplace_back(6);
    cout << lst << endl;

    // 맨 뒤에 7 추가
    lst.emplace(lst.end(), 7);
    cout << lst << endl;

    // 2번째 위치에 8 추가
    lst.emplace(next(lst.begin()), 8);
    cout << lst << endl;

    // 맨 앞 원소 삭제
    lst.pop_front();
    cout << lst << endl;

    // 맨 뒤 원소 삭제
    lst.pop_back();
    cout << lst << endl;

    // 1번째 ~ 3번째 원소 삭제
    // lst.begin() + 3은 지원하지 않는다.
    lst.erase(lst.begin(), next(lst.begin(), 3));
    cout << lst << endl;

    // 첫 번째 원소
    cout << lst.front() << " " << *lst.begin() << endl;

    // 마지막 원소
    cout << lst.back() << " " << *lst.rbegin() << endl;

    cout << "크기: " << lst.size() << endl;
}
