#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

template <typename T>
auto compute_waiting_times(vector<T>& service_times)
{
    size_t size = service_times.size();
    vector<T> W(size, 0);

    for (int i = 1; i < size; ++i)
        W[i] = W[i - 1] + service_times[i - 1];

    return W;
}

template <typename T>
auto print_vector(vector<T>& V)
{
    for (auto& i : V)
        cout << i << " ";

    cout << endl;
}

template <typename T>
void compute_and_print_waiting_times(vector<T>& service_times)
{
    auto waiting_times = compute_waiting_times<T>(service_times);

    cout << "- 처리 시간: ";
    print_vector<T>(service_times);

    cout << "- 대기 시간: ";
    print_vector<T>(waiting_times);

    auto avg_waiting_times = accumulate(waiting_times.begin(), waiting_times.end(), 0.0f) / waiting_times.size();

    cout << "- 평균 대기 시간: " << avg_waiting_times << endl;
}

void main()
{
    vector<int> service_times{8, 1, 2, 4, 9, 2, 3, 5};

    cout << "[처음 일 처리 시간 & 대기 시간]" << endl;
    compute_and_print_waiting_times<int>(service_times);

    // 일 처리 시간을 오름차순으로 정렬
    sort(service_times.begin(), service_times.end());

    cout << endl << "[정렬 후 일 처리 시간 & 대기 시간]" << endl;
    compute_and_print_waiting_times<int>(service_times);
}
