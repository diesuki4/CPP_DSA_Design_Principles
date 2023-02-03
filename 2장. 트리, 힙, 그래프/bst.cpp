#include <iostream>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

struct bst
{
    node* root = nullptr;

    node* find(int value)
    {
        return find_impl(root, value);
    }

private:
    node* find_impl(node* current, int value)
    {
        if (current == nullptr)
        {
            cout << value << "��(��) ã�� ���߽��ϴ�." << endl;
            return nullptr;
        }

        if (current->data == value)
        {
            cout << value << "��(��) ã�ҽ��ϴ�." << endl;
            return current;
        }

        if (value < current->data)
            return find_impl(current->left, value);
        else
            return find_impl(current->right, value);
    }

public:
    void insert(int value)
    {
        if (root == nullptr)
            root = new node{value, nullptr, nullptr};
        else
            insert_impl(root, value);
    }

private:
    void insert_impl(node* current, int value)
    {
        if (value < current->data)
        {
            // �� ��带 ã������
            if (current->left == nullptr)
                current->left = new node{value, nullptr, nullptr};
            // ���� �� ã������
            else
                insert_impl(current->left, value);
        }
        else
        {
            // �� ��带 ã������
            if (current->right == nullptr)
                current->right = new node{value, nullptr, nullptr};
            // ���� �� ã������
            else
                insert_impl(current->right, value);
        }
    }

public:
    // BST�� ���� ��ȸ�ϸ� ������������ ��Ÿ����.
    void inorder()
    {
        inorder_impl(root);
    }

private:
    void inorder_impl(node* start)
    {
        if (start == nullptr)
            return;

        inorder_impl(start->left);
        cout << start->data << " ";
        inorder_impl(start->right);
    }

public:
    node* successor(node* start)
    {
        node* current = start->right;

        if (current == nullptr)
            return nullptr;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }

public:
    void deleteValue(int value)
    {
        root = delete_impl(root, value);
    }

private:
    node* delete_impl(node* start, int value)
    {
        // value�� ã�� ���ߴ�.
        if (start == nullptr)
            return nullptr;

        // value�� ã�� ������ �̵��Ѵ�.
        if (value < start->data)
        {
            start->left = delete_impl(start->left, value);
        }
        else if (value > start->data)
        {
            start->right = delete_impl(start->right, value);
        }
        else
        {
            if (start->left == nullptr)
            {
                node* p = start->right;
                delete start;

                return p;
            }

            if (start->right == nullptr)
            {
                node* p = start->left;
                delete start;

                return p;
            }

            node* succNode = successor(start);
            start->data = succNode->data;

            start->right = delete_impl(start->right, succNode->data);
        }

        return start;
    }
};

void main()
{
    bst tree;
    tree.insert(12);
    tree.insert(10);
    tree.insert(20);
    tree.insert(8);
    tree.insert(11);
    tree.insert(15);
    tree.insert(28);
    tree.insert(4);
    tree.insert(2);

    cout << "���� ��ȸ: ";
    tree.inorder();
    cout << endl;

    tree.deleteValue(12);
    cout << "12�� ������ �� ���� ��ȸ: ";
    tree.inorder();
    cout << endl;

    tree.find(12);
}
