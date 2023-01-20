#include <iostream>
#include <array>

using namespace std;

template <typename T, size_t N>
void print(const array<T, N>& arr)
{
	for (T e : arr)
		cout << e << ' ';
	cout << endl;
}

void main()
{
	array<int, 10> arr1;
	array<int, 4> arr2 = {0, 1, 2, 3};

	try
	{
		// [] 대신 at을 통해 범위 검사
		arr1[0] = arr2.at(4);
	}
	catch (const out_of_range& ex)
	{
		cerr << ex.what() << endl;
	}

	print(arr2);

	// 첫 번째 원소의 참조
	arr2.front() = 6;
	// 마지막 원소의 참조
	arr2.back() = 3;

	// 배열의 시작 주소
	cout << arr2.data() << endl;

	array<float, 5> arr3;
	array<float, 5> arr4 = {0.1, 0.2, 0.3, 0.4, 0.5};
	array<float, 5> arr5 = {0.1, 0.2, 0.3, 0.4, 0.5};

	arr3 = arr4;

	// 모든 원소가 큰지 확인
	cout << boolalpha << (arr3 < arr5) << endl;
	// 모든 원소가 같은지 확인
	cout << boolalpha << (arr3 == arr5) << endl;
}
