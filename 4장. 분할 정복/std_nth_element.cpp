#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<int> v);

void main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};

    random_shuffle(v.begin(), v.end());
    // 2 ~ 9 구간에서 4(5-2+1)번째로 작은 수가 정해질 때까지 정렬
    nth_element(v.begin() + 2, v.begin() + 5, v.end());
    print(v);

    random_shuffle(v.begin(), v.end());
    // 2 ~ 9 구간에서 2(3-2+1)번째로 작은 수가 정해질 때까지 정렬
    nth_element(v.begin() + 2, v.begin() + 3, v.end());
    print(v);
}
