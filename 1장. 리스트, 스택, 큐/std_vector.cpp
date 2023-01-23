#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec)
{
	for (T e : vec)
		os << e << ' ';

	return os;
}

void main()
{
	// ũ�Ⱑ 10�� ����
	vector<int> vec1(10);
	// ũ�Ⱑ 5�̰� ��� ���� 3���� �ʱ�ȭ�� ����
	vector<int> vec2(5, 3);
	// �迭�� ���� �ʱ�ȭ
	vector<int> vec3({1, 2, 3, 4, 5});
	// ���͸� ���� �ʱ�ȭ
	vector<int> vec4(vec3);
	// �ݺ��� ������ ���� �ʱ�ȭ
	vector<int> vec5(vec4.begin(), vec4.end());

	try
	{
		// [] ��� at�� ���� ���� �˻�
		vec1[0] = vec5.at(6);
	}
	catch (const out_of_range& ex)
	{
		cerr << ex.what() << endl;
	}

	// ù ��° ������ ����
	vec5.front() = 6;
	// ������ ������ ����
	vec5.back() = 3;

	// �� �ڿ� 9 �߰�
	// vec5.push_back(9);
	vec5.emplace_back(9);

	// �� �տ� 0 �߰�
	// vec5.insert(vec.begin(), 0);
	vec5.emplace(vec5.begin(), 0);

	// 2 �տ� 8 �߰�
	vec5.emplace(find(vec5.begin(), vec5.end(), 2), 8);

	cout << vec5 << endl;

	// �� ���� ���� ����
	vec5.pop_back();

	// �� ���� ���� ����
	vec5.erase(vec5.begin());

	// 1��°���� 2��° ���ұ��� ����
	vec5.erase(vec5.begin() + 1, vec5.begin() + 3);

	cout << vec5 << endl;

	// ������ ���� �ּ�, ũ��, �뷮
	cout << vec5.data() << ", " << vec5.size() << ", " << vec5.capacity() << endl;

	// �뷮�� 100���� ����
	// ���޵� �뷮�� ���� �뷮���� ũ�� �޸𸮰� ���Ҵ�ȴ�.
	vec5.reserve(100);

	// ������ ���� �ּ�, ũ��, �뷮
	cout << vec5.data() << ", " << vec5.size() << ", " << vec5.capacity() << endl;

	// �뷮�� ũ��� ���� ����� �޸� ���� ���δ�.
	vec5.shrink_to_fit();

	// ������ ���� �ּ�, ũ��, �뷮
	cout << vec5.data() << ", " << vec5.size() << ", " << vec5.capacity() << endl;

	// ��� ���Ұ� ū�� Ȯ��
	cout << boolalpha << (vec3 < vec4) << endl;
	// ��� ���Ұ� ������ Ȯ��
	cout << boolalpha << (vec3 == vec5) << endl;

	// ���� �ʱ�ȭ
	vec5.clear();
}