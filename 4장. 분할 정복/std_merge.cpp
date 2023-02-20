#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<int> v);

void main()
{
    vector<int> v1{5, 10, 15, 20, 25};
    vector<int> v2{50, 40, 30, 20, 10};
    vector<int> m(10);

    // 런타임 오류 발생 ! !
    // merge(v1.begin(), v1.end(), v2.begin(), v2.end(), m.begin());

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), m.begin());
    print(m);
}
