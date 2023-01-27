#include <iostream>
#include <vector>
#include <list>

using namespace std;

void main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    // 용량을 10으로 변경
    v.reserve(10);

    // it는 5의 위치를 가리킨다.
    vector<int>::iterator v_it = v.begin() + 4;

    cout << *v_it << endl;

    // 3번째 위치에 0 추가
    v.emplace(v.begin() + 2, 0);

    // 오류 발생!!
    // 주소가 유효하더라도 값으로 직접 접근하는 것으로 인식한다.
    // cout << *v_it << endl;

    // 오류가 발생하지 않는다.
    cout << *(v.begin() + 4) << endl;



    list<int> lst = {1, 2, 3, 4, 5};

    list<int>::iterator lst_it = next(lst.begin(), 4);

    cout << *lst_it << endl;

    // 3번째 위치에 0 추가
    lst.emplace(prev(lst_it, 1), 0);

    // 오류가 발생하지 않는다.
    cout << *lst_it << endl;
}
