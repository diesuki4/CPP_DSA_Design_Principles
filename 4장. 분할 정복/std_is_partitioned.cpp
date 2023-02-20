#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<int> v);

void main()
{
    vector<int> v{9, 2, 1, 6, 5, 4, 7, 8, 3};
    auto is_odd = [](int e) { return e & 1; };

    print(v);
    
    if (is_partitioned(v.begin(), v.end(), is_odd))
        cout << "[홀수][짝수]가 나뉘어져 있습니다." << endl << endl;
    else
        cout << "[홀수][짝수]가 나뉘어져 있지 않습니다." << endl << endl;

    partition(v.begin(), v.end(), is_odd);
    print(v);

    if (is_partitioned(v.begin(), v.end(), is_odd))
        cout << "[홀수][짝수]가 나뉘어져 있습니다.";
    else
        cout << "[홀수][짝수]가 나뉘어져 있지 않습니다.";
}
