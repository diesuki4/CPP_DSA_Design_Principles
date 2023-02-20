#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void main()
{
    vector<int> v1{10, 20, 20, 40, 50, 60, 70, 80, 90};

    if (search_n(v1.begin(), v1.end(), 2, 20) != v1.end())
        cout << "[20, 20]을 찾았습니다." << endl;
    else
        cout << "[20, 20]을 찾지 못했습니다." << endl;

    vector<int> v2{50, 90, 30, 50, 50, 50, 40, 80, 10};

    if (search_n(v2.begin(), v2.end(), 3, 50) != v2.end())
        cout << "[50, 50, 50]을 찾았습니다." << endl;
    else
        cout << "[50, 50, 50]을 찾지 못했습니다." << endl;
}
