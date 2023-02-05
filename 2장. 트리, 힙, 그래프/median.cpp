#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct median
{
    // maxHeap + �߾Ӱ� + minHeap�� ���¸� �����Ѵ�.
    // (���� ū ��) - �߾Ӱ� - (���� ���� ��) ������ ���� �߾Ӱ��� ������ ã�´�.
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // data�� �߾Ӱ����� ������ maxHeap, ũ�� minHeap�� �����Ѵ�.
    // maxHeap�� minHeap�� ũ�� ���̴� �ż��� 1�� ���� �ʴ´�.
    void insert(int data)
    {
        // ���Ұ� ���ų� minHeap�� 1�� ���� ���
        // (minHeap���� �����ص� �ȴ�.)
        if (maxHeap.size() == 0)
        {
            // maxHeap�� �ִ´�.
            maxHeap.emplace(data);

            return;
        }
        // maxHeap, minHeap�� ���� ������ ���� ���
        if (maxHeap.size() == minHeap.size())
        {
            // data�� �߾Ӱ����� ������
            if (data <= get())
                // maxHeap�� �ִ´�.
                maxHeap.emplace(data);
            // �߾Ӱ����� ũ��
            else
                // minHeap�� �ִ´�.
                minHeap.emplace(data);

            return;
        }
        // minHeap�� 1�� �� ������
        else if (maxHeap.size() < minHeap.size())
        {
            // data�� �߾Ӱ����� ũ��
            if (data > get())
            {
                // minHeap�� ���� ���� ���Ҹ� maxHeap���� �ű��
                // (�Ű��� ���Ҵ� maxHeap�� ��Ʈ�� ��ġ�ϰ� �ȴ�.)
                maxHeap.emplace(minHeap.top());
                minHeap.pop();
                // minHeap�� �ִ´�.
                minHeap.emplace(data);
            }
            // �߾Ӱ����� ������
            else
            {
                // maxHeap�� �ִ´�.
                maxHeap.emplace(data);
            }

            return;
        }
        // maxHeap�� 1�� �� ������
        else
        {
            // data�� �߾Ӱ����� ������
            if (data < get())
            {
                // maxHeap�� ���� ū ���Ҹ� minHeap���� �ű��
                // (�Ű��� ���Ҵ� minHeap�� ��Ʈ�� ��ġ�ϰ� �ȴ�.)
                minHeap.emplace(maxHeap.top());
                maxHeap.pop();
                // maxHeap�� �ִ´�.
                maxHeap.emplace(data);
            }
            // �߾Ӱ����� ũ��
            else
            {
                // minHeap�� �ִ´�.
                minHeap.emplace(data);
            }
        }
    }

    double get()
    {
        // ���Ұ� ¦���� ������
        if (maxHeap.size() == minHeap.size())
            // ��� �� ���� ����� �߾Ӱ��̴�.
            return (maxHeap.top() + minHeap.top()) / 2.0;
        // minHeap�� 1�� �� ������
        if (maxHeap.size() < minHeap.size())
            // minHeap�� ��Ʈ�� �߾Ӱ��̴�.
            return minHeap.top();
        // maxHeap�� 1�� �� ������
        else
            //maxHeap�� ��Ʈ�� �߾Ӱ��̴�.
            return maxHeap.top();
    }
};

void main()
{
    median med;

    med.insert(1);
    cout << "1 ���� �� �߾Ӱ�: " << med.get() << endl;

    med.insert(5);
    cout << "5 ���� �� �߾Ӱ�: " << med.get() << endl;

    med.insert(2);
    cout << "2 ���� �� �߾Ӱ�: " << med.get() << endl;

    med.insert(10);
    cout << "10 ���� �� �߾Ӱ�: " << med.get() << endl;

    med.insert(40);
    cout << "40 ���� �� �߾Ӱ�: " << med.get() << endl;
}
