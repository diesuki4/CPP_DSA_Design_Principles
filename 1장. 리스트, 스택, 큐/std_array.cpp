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
		// [] ��� at�� ���� ���� �˻�
		arr1[0] = arr2.at(4);
	}
	catch (const out_of_range& ex)
	{
		cerr << ex.what() << endl;
	}

	print(arr2);

	// ù ��° ������ ����
	arr2.front() = 6;
	// ������ ������ ����
	arr2.back() = 3;

	// �迭�� ���� �ּ�
	cout << arr2.data() << endl;

	array<float, 5> arr3;
	array<float, 5> arr4 = {0.1, 0.2, 0.3, 0.4, 0.5};
	array<float, 5> arr5 = {0.1, 0.2, 0.3, 0.4, 0.5};

	arr3 = arr4;

	// ��� ���Ұ� ū�� Ȯ��
	cout << boolalpha << (arr3 < arr5) << endl;
	// ��� ���Ұ� ������ Ȯ��
	cout << boolalpha << (arr3 == arr5) << endl;
}
