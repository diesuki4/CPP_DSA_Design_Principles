#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct median
{
    // maxHeap + 중앙값 + minHeap의 상태를 유지한다.
    // (가장 큰 수) - 중앙값 - (가장 작은 수) 구조를 통해 중앙값을 빠르게 찾는다.
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // data가 중앙값보다 작으면 maxHeap, 크면 minHeap에 저장한다.
    // maxHeap과 minHeap의 크기 차이는 매순간 1을 넘지 않는다.
    void insert(int data)
    {
        // 원소가 없거나 minHeap에 1개 있을 경우
        // (minHeap으로 구현해도 된다.)
        if (maxHeap.size() == 0)
        {
            // maxHeap에 넣는다.
            maxHeap.emplace(data);

            return;
        }
        // maxHeap, minHeap의 원소 개수가 같을 경우
        if (maxHeap.size() == minHeap.size())
        {
            // data가 중앙값보다 작으면
            if (data <= get())
                // maxHeap에 넣는다.
                maxHeap.emplace(data);
            // 중앙값보다 크면
            else
                // minHeap에 넣는다.
                minHeap.emplace(data);

            return;
        }
        // minHeap이 1개 더 많으면
        else if (maxHeap.size() < minHeap.size())
        {
            // data가 중앙값보다 크면
            if (data > get())
            {
                // minHeap의 가장 작은 원소를 maxHeap으로 옮기고
                // (옮겨진 원소는 maxHeap의 루트에 위치하게 된다.)
                maxHeap.emplace(minHeap.top());
                minHeap.pop();
                // minHeap에 넣는다.
                minHeap.emplace(data);
            }
            // 중앙값보다 작으면
            else
            {
                // maxHeap에 넣는다.
                maxHeap.emplace(data);
            }

            return;
        }
        // maxHeap이 1개 더 많으면
        else
        {
            // data가 중앙값보다 작으면
            if (data < get())
            {
                // maxHeap의 가장 큰 원소를 minHeap으로 옮기고
                // (옮겨진 원소는 minHeap의 루트에 위치하게 된다.)
                minHeap.emplace(maxHeap.top());
                maxHeap.pop();
                // maxHeap에 넣는다.
                maxHeap.emplace(data);
            }
            // 중앙값보다 크면
            else
            {
                // minHeap에 넣는다.
                minHeap.emplace(data);
            }
        }
    }

    double get()
    {
        // 원소가 짝수개 있으면
        if (maxHeap.size() == minHeap.size())
            // 가운데 두 수의 평균이 중앙값이다.
            return (maxHeap.top() + minHeap.top()) / 2.0;
        // minHeap이 1개 더 많으면
        if (maxHeap.size() < minHeap.size())
            // minHeap의 루트가 중앙값이다.
            return minHeap.top();
        // maxHeap이 1개 더 많으면
        else
            //maxHeap의 루트가 중앙값이다.
            return maxHeap.top();
    }
};

void main()
{
    median med;

    med.insert(1);
    cout << "1 삽입 후 중앙값: " << med.get() << endl;

    med.insert(5);
    cout << "5 삽입 후 중앙값: " << med.get() << endl;

    med.insert(2);
    cout << "2 삽입 후 중앙값: " << med.get() << endl;

    med.insert(10);
    cout << "10 삽입 후 중앙값: " << med.get() << endl;

    med.insert(40);
    cout << "40 삽입 후 중앙값: " << med.get() << endl;
}
