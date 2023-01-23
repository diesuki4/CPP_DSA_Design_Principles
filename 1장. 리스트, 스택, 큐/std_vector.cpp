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
	// 크기가 10인 벡터
	vector<int> vec1(10);
	// 크기가 5이고 모든 값이 3으로 초기화된 벡터
	vector<int> vec2(5, 3);
	// 배열을 통한 초기화
	vector<int> vec3({1, 2, 3, 4, 5});
	// 벡터를 통한 초기화
	vector<int> vec4(vec3);
	// 반복자 범위를 통한 초기화
	vector<int> vec5(vec4.begin(), vec4.end());

	try
	{
		// [] 대신 at을 통해 범위 검사
		vec1[0] = vec5.at(6);
	}
	catch (const out_of_range& ex)
	{
		cerr << ex.what() << endl;
	}

	// 첫 번째 원소의 참조
	vec5.front() = 6;
	// 마지막 원소의 참조
	vec5.back() = 3;

	// 맨 뒤에 9 추가
	// vec5.push_back(9);
	vec5.emplace_back(9);

	// 맨 앞에 0 추가
	// vec5.insert(vec.begin(), 0);
	vec5.emplace(vec5.begin(), 0);

	// 2 앞에 8 추가
	vec5.emplace(find(vec5.begin(), vec5.end(), 2), 8);

	cout << vec5 << endl;

	// 맨 뒤의 원소 삭제
	vec5.pop_back();

	// 맨 앞의 원소 삭제
	vec5.erase(vec5.begin());

	// 1번째부터 2번째 원소까지 삭제
	vec5.erase(vec5.begin() + 1, vec5.begin() + 3);

	cout << vec5 << endl;

	// 벡터의 시작 주소, 크기, 용량
	cout << vec5.data() << ", " << vec5.size() << ", " << vec5.capacity() << endl;

	// 용량을 100으로 변경
	// 전달된 용량이 현재 용량보다 크면 메모리가 재할당된다.
	vec5.reserve(100);

	// 벡터의 시작 주소, 크기, 용량
	cout << vec5.data() << ", " << vec5.size() << ", " << vec5.capacity() << endl;

	// 용량을 크기와 같게 만들어 메모리 낭비를 줄인다.
	vec5.shrink_to_fit();

	// 벡터의 시작 주소, 크기, 용량
	cout << vec5.data() << ", " << vec5.size() << ", " << vec5.capacity() << endl;

	// 모든 원소가 큰지 확인
	cout << boolalpha << (vec3 < vec4) << endl;
	// 모든 원소가 같은지 확인
	cout << boolalpha << (vec3 == vec5) << endl;

	// 벡터 초기화
	vec5.clear();
}