#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void main()
{
    vector<int> v{10, 20, 30, 30, 20, 10, 10, 20};

    // 10, 10, 10, 20, 20, 20, 30, 30
    sort(v.begin(), v.end());

    auto low_bound = lower_bound(v.begin(), v.end(), 20);
    auto up_bound = upper_bound(v.begin(), v.end(), 20);

    cout << "위치 " << low_bound - v.begin() << "에서 20보다 크거나 같은 수를 찾았습니다." << endl;
    cout << "위치 " << up_bound - v.begin() << "에서 20보다 큰 수를 찾았습니다." << endl;
}
