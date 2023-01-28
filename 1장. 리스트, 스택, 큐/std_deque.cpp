#include <iostream>
#include <deque>

using namespace std;

ostream& operator<<(ostream& os, const deque<int>& deq)
{
    for (int e : deq)
        os << e << ' ';

    return os;
}

void main()
{
    deque<int> deq = {1, 2, 3, 4, 5};

    // 맨 앞에 0 추가
    deq.emplace_front(0);
    cout << deq << endl;

    // 맨 뒤에 6 추가
    deq.emplace_back(6);
    cout << deq << endl;

    // 3번째 위치에 7, 8 추가
    deq.insert(deq.begin() + 2, {7, 8});
    cout << deq << endl;

    // 맨 뒤 원소 삭제
    deq.pop_back();
    cout << deq << endl;

    // 맨 앞 원소 삭제
    deq.pop_front();
    cout << deq << endl;

    // 4번째 원소부터 끝까지 삭제
    deq.erase(deq.begin() + 3, deq.end());
    cout << deq << endl;

    // 용량을 크기와 맞춘다.
    // 더 이상 원소 개수에 변화가 없는 경우 유용
    deq.shrink_to_fit();

    // 현재 크기
    cout << "크기: " << deq.size() << endl;

    // capacity()는 제공하지 않는다.
    // cout << "용량: " << deq.capacity() << endl;
}
