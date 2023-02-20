#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void main()
{
    vector<int> v1{10, 20, 30, 40, 50, 60, 70, 80, 90};
    vector<int> sub_sequence1{40, 50, 60};

    if (search(v1.begin(), v1.end(), sub_sequence1.begin(), sub_sequence1.end()) != v1.end())
        cout << "[40, 50, 60]을 찾았습니다." << endl;
    else
        cout << "[40, 50, 60]을 찾지 못했습니다." << endl;

    vector<int> v2{20, 90, 30, 70, 50, 60, 40, 80, 10};
    vector<int> sub_sequence2{30, 70, 50};

    if (search(v2.begin(), v2.end(), sub_sequence2.begin(), sub_sequence2.end()) != v2.end())
        cout << "[30, 70, 50]을 찾았습니다." << endl;
    else
        cout << "[30, 70, 50]을 찾지 못했습니다." << endl;
}
