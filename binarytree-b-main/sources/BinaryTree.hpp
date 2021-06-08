#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

const int PreOrder = 1;
const int InOrder = 2;
const int PostOrder = 3;

namespace ariel
{

    template <class T>
    class BinaryTree
    {
        struct Node
        {
            T info;
            Node *left, *right;

            Node(const T &v) : info(v), left(nullptr), right(nullptr) {}
            Node(const Node *copy) : info(0), right(nullptr), left(nullptr)
            {
                if (copy != nullptr)
                {
                    if (copy->left)
                    {
                        left = new Node(copy->left);
                    }
                    if (copy->right)
                    {
                        right = new Node(copy->right);
                    }
                    info = copy->info;
                }
            }
        };

        class Iterator
        {

        private:
            queue<Node *> Q;
            Node *cur;

        public:
            Iterator(Node *n) : cur(n) {}
            Iterator(Node *n, int type) : cur(n)
            {
                if (cur == nullptr)
                {
                    return;
                }
                Node *v = nullptr;
                stack<Node *> st1;
                stack<Node *> st2;

                if (type == 1) // PreOrder
                {
                    st1.push(cur);

                    while (!st1.empty())
                    {
                        v = st1.top();
                        Q.push(v);
                        st1.pop();

                        if (v->right)
                        {
                            st1.push(v->right);
                        }
                        if (v->left)
                        {
                            st1.push(v->left);
                        }
                    }

                    Q.push(nullptr);
                    cur = Q.front();
                    Q.pop();
                }

                else if (type == 2) // InOrder
                {
                    v = this->cur;
                    while (!st1.empty() || v)
                    {
                        while (v)
                        {
                            st1.push(v);
                            v = v->left;
                        }
                        v = st1.top();
                        Q.push(v);
                        st1.pop();

                        v = v->right;
                    }

                    Q.push(nullptr);
                    cur = Q.front();
                    Q.pop();
                }

                else if (type == 3) // PostOrder
                {
                    st1.push(cur);

                    while (!st1.empty())
                    {
                        v = st1.top();
                        st1.pop();
                        st2.push(v);

                        if (v->left)
                        {
                            st1.push(v->left);
                        }
                        if (v->right)
                        {
                            st1.push(v->right);
                        }
                    }

                    while (!st2.empty())
                    {
                        v = st2.top();
                        Q.push(v);
                        st2.pop();
                    }
                    Q.push(nullptr);
                    cur = Q.front();
                    Q.pop();
                }
            }
            const T *operator->() const { return &(cur->info); }
            T &operator*() const { return cur->info; }
            bool operator==(const Iterator &iter) const { return iter.cur == cur; }
            bool operator!=(const Iterator &iter) const { return !(*this == iter.cur); }

            // ++i increment
            Iterator &operator++()
            {
                if (Q.empty())
                {
                    return *this;
                }
                cur = Q.front();
                Q.pop();

                return *this;
            }

            // i++ increment
            Iterator operator++(int)
            {
                Iterator temp = *this;
                cur = Q.front();
                Q.pop();
                return temp;
            }
        };

        Node *root;

    public:
        BinaryTree() : root(nullptr) {}
        BinaryTree(const BinaryTree &copy) : root(new Node(copy.root)) {}

        BinaryTree &operator=(BinaryTree copy)
        {
            if (this == &copy)
            {
                return *this;
            }
            delete (this->root);
            root = new Node(copy.root);
            return *this;
        }

        BinaryTree &operator=(BinaryTree &&move) noexcept
        {
            root = move.root;
            move.root = nullptr;
            return *this;
        }

        BinaryTree(BinaryTree &&move) noexcept
        {
            root = move.root;
            move.root = nullptr;
        }

        void deleteNodes(Node *n)
        {
            if (!n)
            {
                return;
            }
            deleteNodes(n->left);
            deleteNodes(n->right);
        }

        ~BinaryTree()
        {
            deleteNodes(root);
        }

        friend ostream &operator<<(ostream &os, const BinaryTree &b)
        {
            os << "SHALOM OMER SHALOM";
            return os;
        }

        Iterator begin_preorder() const { return Iterator(root, PreOrder); }
        Iterator end_preorder() const { return nullptr; }
        Iterator begin_inorder() const { return Iterator(root, InOrder); }
        Iterator end_inorder() const { return nullptr; }
        Iterator begin_postorder() const { return Iterator(root, PostOrder); }
        Iterator end_postorder() const { return nullptr; }
        Iterator begin() const { return Iterator(root, InOrder); }
        Iterator end() const { return nullptr; }

        BinaryTree<T> &add_root(const T &info)
        {
            if (!root)
            {
                this->root = new Node(info);
            }
            else
            {
                this->root->info = info;
            }

            return *this;
        }

        BinaryTree<T> &add_left(const T &exist, const T &left)
        {
            if (root == nullptr)
            {
                throw std::invalid_argument{"The tree doesnt have a root"};
            }
            Node *s = search(root, exist);
            if (s == nullptr)
            {
                throw std::invalid_argument{"The desired node not found"};
            }
            if (s->left != nullptr)
            {
                s->left->info = left;
            }
            else
            {
                s->left = new Node(left);
            }

            return *this;
        }
        BinaryTree<T> &add_right(const T &exist, const T &right)
        {
            if (root == nullptr)
            {
                throw std::invalid_argument{"The tree doesnt have a root"};
            }
            Node *s = search(root, exist);
            if (s == nullptr)
            {
                throw std::invalid_argument{"The desired node not found"};
            }
            if (s->right != nullptr)
            {
                s->right->info = right;
            }
            else
            {
                s->right = new Node(right);
            }

            return *this;
        }
        Node *search(Node *root, T info)
        {
            if (root)
            {
                if (root->info == info)
                {
                    return root;
                }
                if (!(root->info == info))
                {
                    Node *n = search(root->left, info);
                    if (!n)
                    {
                        n = search(root->right, info);
                    }
                    return n;
                }
            }
            return nullptr;
        }
    };
}

// Assisted by: https://www.geeksforgeeks.org/implementing-forward-iterator-in-bst/
//              https://stackoverflow.com/questions/245628/c-binary-search-tree-recursive-search-function
//              https://codereview.stackexchange.com/questions/41844/iterator-for-binary-tree-pre-in-and-post-order-iterators