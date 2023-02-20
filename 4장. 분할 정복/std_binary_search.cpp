#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void main()
{
    vector<int> v{1, 2, 3, 4, 5, 4, 3, 2, 1};

    sort(v.begin(), v.end());

    if (binary_search(v.begin(), v.end(), 3))
        cout << "3을 찾았습니다." << endl;
    else
        cout << "3을 찾지 못했습니다." << endl;

    sort(v.begin(), v.end(), greater<int>());

    if (binary_search(v.begin(), v.end(), 6, greater<int>()))
        cout << "6을 찾았습니다." << endl;
    else
        cout << "6을 찾지 못했습니다." << endl;
}
