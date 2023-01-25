#include <iostream>
#include <vector>
#include <forward_list>

using namespace std;

void main()
{
    vector<string> vec = {"Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg",
                            "Sebastian Vettel", "Lewis Hamilton", "Sebastian Vettel",
                            "Sebastian Vettel", "Sebastian Vettel", "Fernando Alonso"};
    
    vector<string>::iterator it = vec.begin();
    cout << "가장 최근 우승자: " << *it << endl;

    // O(1) 소요
    it += 8;
    cout << "8년전 우승자: " << *it << endl;

    // O(1) 소요
    advance(it, -3);
    cout << "그후 3년 뒤 우승자: " << *it << endl;

    // O(1) 소요
    cout << "그 2년 전 우승자: " << *next(it, 2) << endl;

    forward_list<string> fwd(vec.begin(), vec.end());

    forward_list<string>::iterator jt = fwd.begin();
    cout << "가장 최근 우승자: " << *jt << endl;

    // 선형 시간 소요
    advance(jt, 5);
    cout << "5년전 우승자: " << *jt << endl;

    // forward_list는 순방향으로만 이동할 수 있으므로 에러 발생
    //advance(jt, -2);
}
