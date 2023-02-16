#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

bool linear_search(int N, vector<int>& S)
{
    for (int e : S)
        if (e == N)
            return true;

    return false;
}

bool binary_search(int N, vector<int>& S)
{
    auto first = S.begin();
    auto last = S.end();

    while (true)
    {
        int range_length = distance(first, last);
        auto mid_element_pos = first + range_length / 2;
        int mid_element = *mid_element_pos;

        if (mid_element == N)
            return true;
        else if (mid_element > N)
            last = mid_element_pos - 1;
        else
            first = mid_element_pos + 1;

        if (range_length < 1)
            return false;
    }
}

bool binary_search_recursive(int N, vector<int>& S, vector<int>::iterator first, vector<int>::iterator last)
{
    int range_length = distance(first, last);
    auto mid_element_pos = first + range_length / 2;
    int mid_element = *mid_element_pos;

    if (mid_element == N)
        return true;

    if (range_length < 1)
        return false;

    if (mid_element > N)
        return binary_search_recursive(N, S, first, mid_element_pos - 1);
    else
        return binary_search_recursive(N, S, mid_element_pos + 1, last);
}

void run_small_search_test()
{
    int N = 2;
    vector<int> S{1, 3, 2, 4, 5, 7, 9, 8, 6};

    sort(S.begin(), S.end());

    if (linear_search(N, S))
        cout << "선형 검색으로 원소를 찾았습니다!" << endl;
    else
        cout << "선형 검색으로 원소를 찾지 못했습니다." << endl;

    if (binary_search(N, S))
        cout << "이진 검색으로 원소를 찾았습니다!" << endl;
    else
        cout << "이진 검색으로 원소를 찾지 못했습니다." << endl;
}

void run_large_search_test(int size, int N)
{
    vector<int> S;
    random_device rd;
    mt19937 rand(rd());

    // [1, size] 범위에서 정수 난수 발생
    uniform_int_distribution<mt19937::result_type> uniform_dist(1, size);

    // S에 난수 추가
    for (int i = 0; i < size; ++i)
        S.push_back(uniform_dist(rand));

    sort(S.begin(), S.end());

    // 검색 시간 측정 시작
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    bool search_result = binary_search_recursive(N, S, S.begin(), S.end());

    // 검색 시간 측정 종료
    chrono::steady_clock::time_point end = chrono::steady_clock::now();

    auto diff = chrono::duration_cast<chrono::microseconds>(end - begin);
    cout << "이진 검색 수행 시간: " << diff.count() << endl;

    if (search_result)
        cout << "원소를 찾았습니다." << endl;
    else
        cout << "원소를 찾지 못했습니다." << endl;
}

void main()
{
    run_small_search_test();

    run_large_search_test(100000, 36543);
    run_large_search_test(1000000, 36543);
    run_large_search_test(10000000, 36543);
}
