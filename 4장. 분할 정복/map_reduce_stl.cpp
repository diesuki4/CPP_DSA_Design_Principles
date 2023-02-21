#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

void transform_test(vector<int> S)
{
    vector<int> Tr;
    auto Fx_transform = [](int x) { return pow(x, 2); };
    auto Fx_for_each = [](int& x) { x = pow(x, 2); };

    cout << "[맵 테스트]" << endl;
    cout << "입력 배열, S: ";
    for (int x : S) cout << x << " ";
    cout << endl;

    // std::transform()
    transform(S.begin(), S.end(), back_inserter(Tr), Fx_transform);

    cout << "std::transform(), Tr: ";
    for (int fx : Tr) cout << fx << " ";
    cout << endl;

    // std::for_each()
    for_each(S.begin(), S.end(), Fx_for_each);

    cout << "std::for_each(), S: ";
    for (int fx : S) cout << fx << " ";
    cout << endl;
}

void reduce_test(vector<int> S)
{
    cout << endl << "[리듀스 테스트]" << endl;
    cout << "입력 배열, S: ";
    for (int x : S) cout << x << " ";
    cout << endl;

    // std::accumulate()
    int ans = accumulate(S.begin(), S.end(), 0, [](int acc, int x) { return acc + x; });
    cout << "std::accumulate(), ans: " << ans << endl;

#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
    // std::reduce()
    ans = reduce(S.begin(), S.end());
    cout << "std::reduce(), ans: " << ans << endl;
#endif
}

void main()
{
    vector<int> S{1, 10, 4, 7, 3, 5, 6, 9, 8, 2};

    transform_test(S);
    reduce_test(S);
}
