#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<T> merge(vector<T>& v1, vector<T>& v2)
{
    vector<T> m;

    auto it1 = v1.begin();
    auto it2 = v2.begin();

    while (it1 != v1.end() && it2 != v2.end())
        if (*it1 < *it2)
            m.emplace_back(*(it1++));
        else
            m.emplace_back(*(it2++));

    if (it1 == v1.end())
        m.insert(m.end(), it2, v2.end());
    else
        m.insert(m.end(), it1, v1.end());

    return m;
}

template <typename T>
vector<T> merge_sort(vector<T> v)
{
    if (v.size() <= 1)
        return v;

    int mid = v.size() / 2;
    vector<T> v1 = merge_sort<T>(vector<T>(v.begin(), v.begin() + mid));
    vector<T> v2 = merge_sort<T>(vector<T>(v.begin() + mid, v.end()));

    return merge<T>(v1, v2);
}

template <typename T>
void print_vector(vector<T> v)
{
    for (auto e : v)
        cout << e << " ";

    cout << endl;
}

void main()
{
    vector<int>     S1{45, 1, 3, 1, 2, 3, 45, 5, 1, 2, 44, 5, 7};
    vector<float>   S2{45.6f, 1.0f, 3.8f, 1.01f, 2.2f, 3.9f, 45.3f, 5.5f,
					    1.0f, 2.0f, 44.0f, 5.0f, 7.0f};
    vector<double>  S3{45.6, 1.0, 3.8 , 1.01, 2.2, 3.9, 45.3, 5.5,
					    1.0, 2.0, 44.0, 5.0, 7.0};
    vector<char>    C{'b', 'z', 'a', 'e', 'f', 't', 'q', 'u', 'y'};

    cout << "정렬되지 않은 입력 벡터:" << endl;
    print_vector<int>(S1);
    print_vector<float>(S2);
    print_vector<double>(S3);
    print_vector<char>(C);
    cout << endl;

    auto sorted_S1  = merge_sort<int>(S1);
    auto sorted_S2  = merge_sort<float>(S2);
    auto sorted_S3  = merge_sort<double>(S3);
    auto sorted_C   = merge_sort<char>(C);

    cout << "병합 정렬에 의해 정렬된 벡터:" << endl;
    print_vector<int>(sorted_S1);
    print_vector<float>(sorted_S2);
    print_vector<double>(sorted_S3);
    print_vector<char>(sorted_C);
}
