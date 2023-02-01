#include <iostream>
#include <queue>

using namespace std;

struct node
{
    string position;    // 직책
    node* first;        // 첫 번째 부하 직원
    node* second;       // 두 번째 부하 직원
};

struct org_tree
{
    node* root;

    // 조직 생성 함수
    static org_tree create_org_structure(const string& pos)
    {
        org_tree tree;
        tree.root = new node{pos, nullptr, nullptr};

        return tree;
    }

    // 직책으로 검색 (전위순회)
    static node* find(node* root, const string& pos)
    {
        node* first;

        if (root == nullptr)
            return nullptr;

        if (root->position == pos)
            return root;

        if ((first = find(root->first, pos)) != nullptr)
            return first;
        else
            return find(root->second, pos);
    }

    // manager 직책을 갖는 상사의 부하 직원으로 subordinate 추가
    bool addSubordinate(const string& manager, const string& subordinate)
    {
        node* managerNode = find(root, manager);
        node* subordinateNode;

        // 해당 직책의 상사가 존재하지 않는다.
        if (managerNode == nullptr)
            return false;

        // 이미 2명의 부하 직원을 갖고 있다.
        if (managerNode->first && managerNode->second)
            return false;

        subordinateNode = new node{subordinate, nullptr, nullptr};

        if (managerNode->first == nullptr)  // 첫 번째 부하 직원으로 삼을 수 있다.
            managerNode->first = subordinateNode;
        else    // 첫 번째 부하 직원은 있으므로 두 번째로 삼을 수 있다.
            managerNode->second = subordinateNode;

        return true;
    }

    // 전위 순회
    static void preOrder(node* start)
    {
        if (start == nullptr)
            return;

        cout << start->position << ", ";
        preOrder(start->first);
        preOrder(start->second);
    }

    // 중위 순회
    static void inOrder(node* start)
    {
        if (start == nullptr)
            return;

        preOrder(start->first);
        cout << start->position << ", ";
        preOrder(start->second);
    }

    // 후위 순회
    static void postOrder(node* start)
    {
        if (start == nullptr)
            return;

        preOrder(start->first);
        preOrder(start->second);
        cout << start->position << ", ";
    }

    // 레벨 순회
    static void levelOrder(node* start)
    {
        if (start == nullptr)
            return;

        queue<node*> que;
        que.push(start);

        while (!que.empty())
        {
            size_t size = que.size();
            
            for (int i = 0; i < size; ++i)
            {
                node* current = que.front();
                que.pop();

                // 부모 노드를 방문하고
                cout << current->position << ", ";

                // 자식 노드를 큐에 삽입한다.
                if (current->first)
                    que.push(current->first);

                if (current->second)
                    que.push(current->second);

                // front에 가까울 수록 레벨이 낮은 노드가 위치한다.
            }

            cout << endl;
        }
    }
};

void main()
{
    org_tree tree = org_tree::create_org_structure("CEO");

    tree.addSubordinate("CEO", "부사장");
    tree.addSubordinate("부사장", "IT부장");
    tree.addSubordinate("부사장", "마케팅부장");
    tree.addSubordinate("IT부장", "보안팀장");
    tree.addSubordinate("IT부장", "앱개발팀장");
    tree.addSubordinate("마케팅부장", "물류팀장");
    tree.addSubordinate("마케팅부장", "홍보팀장");
    tree.addSubordinate("부사장", "재무부장");

    cout << "[전위 순회]" << endl;
    org_tree::preOrder(tree.root); cout << endl << endl;

    cout << "[중위 순회]" << endl;
    org_tree::inOrder(tree.root); cout << endl << endl;

    cout << "[후위 순회]" << endl;
    org_tree::postOrder(tree.root); cout << endl << endl;

    cout << "[레벨 순회]" << endl;
    org_tree::levelOrder(tree.root);
}
