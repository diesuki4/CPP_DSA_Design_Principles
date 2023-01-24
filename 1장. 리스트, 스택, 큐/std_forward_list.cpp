#include <iostream>
#include <forward_list>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const forward_list<T> fwd_list)
{
	for (T e : fwd_list)
		os << e << ' ';

	return os;
}

void main()
{
	forward_list<int> fwd_list = {1, 2, 3};

	// 맨 앞에 0 추가
	fwd_list.emplace_front(0);

	// 맨 앞 원소 뒤에 5 추가
	fwd_list.emplace_after(fwd_list.begin(), 5);

	// 맨 앞 원소 뒤에 6 추가
	fwd_list.emplace_after(fwd_list.begin(), 6);

	cout << fwd_list << endl;

	// 맨 앞 원소를 삭제
	fwd_list.pop_front();

	// 맨 앞 원소의 다음 원소를 삭제
	fwd_list.erase_after(fwd_list.begin());

	// 맨 앞 원소의 다음 원소부터 마지막 원소까지 삭제
	fwd_list.erase_after(fwd_list.begin(), fwd_list.end());

	cout << fwd_list << endl << endl;

	forward_list<int> fwd_list2 = {-3, 9, 1, 2, 5, 4, 9, 3, 2, 1, 6, 2, 11, 8};

	// 모든 2를 삭제
	fwd_list2.remove(2);

	// 10보다 큰 모든 수 삭제
	fwd_list2.remove_if([](const int& e) { return 10 < e; });

	cout << fwd_list2 << endl;

	// 오름차순 정렬
	fwd_list2.sort();

	cout << fwd_list2 << endl;

	// 내림차순 정렬
	fwd_list2.sort(std::greater<int>());

	cout << fwd_list2 << endl;

	// 원소 순서를 역순으로 변경
	fwd_list2.reverse();

	cout << fwd_list2 << endl;

	// 중복 원소를 제거
	// 인접한 원소들을 비교하여 O(n)에 처리된다.
	// 정순 혹은 역순 정렬된 상태에서만 정상 작동한다.
	fwd_list2.unique();

	cout << fwd_list2 << endl;
}
