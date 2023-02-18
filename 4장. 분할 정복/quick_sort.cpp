#include <iostream>
#include <vector>

using namespace std;

// (b) | z a e f t q u y |
// -->
// (b) | a | z e f t q u y |
// pivot을 기준으로 작은 원소를 왼쪽, 큰 원소를 오른쪽에 몰아 배치한다.
template <typename T>
auto partition(typename vector<T>::iterator begin, typename vector<T>::iterator end)
{
    auto pivot_val = *begin;
    auto it_left = begin + 1;
    auto it_right = end;

    while (true)
    {
		// begin부터 pivot보다 큰 원소를 찾는다.
        while (*it_left <= pivot_val && 0 < distance(it_left, it_right))
            ++it_left;

		// end부터 pivot보다 작거나 같은 원소를 찾는다.
		// 같은 원소를 포함하는 이유는 왼쪽으로 보내기 위해서이다.
        while (*it_right > pivot_val && 0 < distance(it_left, it_right))
            --it_right;

		// it_left == it_right의 의미는 왼쪽에서 더 이상 pivot보다 큰 수가 없고
		// 오른쪽에서 더 이상 pivot보다 작거나 같은 수가 없다는 의미이다.
		// 즉, 교환할 원소가 없다는 뜻이다.
        if (it_left == it_right)
            break;
		// pivot보다 큰 왼쪽 원소와 작은 오른쪽 원소를 교환한다.
        else
            iter_swap(it_left, it_right);
    }

	// 7 | 1 3 1 2 3 5 5 1 2 |
	// -->
	// | 1 3 1 2 3 5 5 1 2 | 7
	// pivot이 모든 원소보다 클 경우 위치를 고정하기 위해 교환한다.
	if (pivot_val > *it_right)
		iter_swap(begin, it_right);

	// pivot보다 큰 원소가 모인 시작점을 반환한다.
    return it_right;
}

template <typename T>
void quick_sort(typename vector<T>::iterator begin, typename vector<T>::iterator last)
{
	// 원소가 1개만 남을 때까지 분할한다.
    if (begin != last)
    {
        auto it_par = partition<T>(begin, last);

		// 내부 pivot보다 작거나 같은 원소들
        quick_sort<T>(begin, it_par - 1);
		// 내부 pivot보다 큰 원소들
        quick_sort<T>(it_par, last);
    }
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
	vector<int>    S1{45, 1, 3, 1, 2, 3, 45, 5, 1, 2, 44, 5, 7};
	vector<float>  S2{45.6f, 1.0f, 3.8f, 1.01f, 2.2f, 3.9f, 45.3f, 5.5f, 1.0f, 2.0f, 44.0f, 5.0f, 7.0f};
	vector<double> S3{45.6, 1.0, 3.8 , 1.01, 2.2, 3.9, 45.3, 5.5, 1.0, 2.0, 44.0, 5.0, 7.0};
	vector<char>   C{'b', 'z', 'a', 'e', 'f', 't', 'q', 'u', 'y'};

	cout << "정렬되지 않은 입력 벡터:" << endl;
	print_vector<int>(S1);
	print_vector<float>(S2);
	print_vector<double>(S3);
	print_vector<char>(C);
	cout << endl;

	quick_sort<int>(S1.begin(), S1.end() - 1);
	quick_sort<float>(S2.begin(), S2.end() - 1);
	quick_sort<double>(S3.begin(), S3.end() - 1);
	quick_sort<char>(C.begin(), C.end() - 1);

	cout << "퀵 정렬 수행 후의 벡터:" << endl;
	print_vector<int>(S1);
	print_vector<float>(S2);
	print_vector<double>(S3);
	print_vector<char>(C);
}
