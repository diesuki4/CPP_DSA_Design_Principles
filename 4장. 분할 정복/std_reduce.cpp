#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>

using namespace std;

void main()
{
    vector<int> v{1, 2, 3};

#if (__cplusplus >= 201703L)
    cout << reduce(v.begin(), v.end(), 100) << endl;
    
    // current_sum은 현재까지의 합, e는 현재 원소를 뜻한다.
    cout << reduce(v.begin(), v.end(), 0, [](int current_sum, int e) { return current_sum + pow(e, 2); }) << endl;
#endif
}
