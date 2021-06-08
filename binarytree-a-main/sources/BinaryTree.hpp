
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

namespace ariel
{

    template <class T>
    class BinaryTree
    {

        struct Node
        {
            T info;
            Node *right, *left;

            Node(T x) : info(x), right(nullptr), left(nullptr) {}
        };

        Node *root;
        class Iterator
        {
        private:
            Node *cur;

        public:
            Iterator() : cur(nullptr)
            {
                cur = nullptr;
            }
            T &operator*() const
            {
                return cur->info;
            }

            T *operator->() const
            {
                return &(cur->info);
            }

            bool operator==(const Iterator &it) const
            {
                return cur == it.cur;
            }

            bool operator!=(const Iterator &it) const
            {
                return cur != it.cur;
            }
            // ++i

            Iterator &operator++()
            {
                return *this;
            }

            // i++
            const Iterator operator++(int)
            {
                Iterator temp = *this;
                return temp;
            }
        };

    public:
        BinaryTree()
        {
            root = nullptr;
        }

        BinaryTree<T> add_root(const T &info) { 
            return *this; }
        BinaryTree<T> add_left(const T &info, const T &left) { return *this; }
        BinaryTree<T> add_right(const T &info, const T &right) { return *this; }

        Iterator begin_preorder() { return Iterator{}; }
        Iterator end_preorder() { return Iterator{}; }
        Iterator begin_inorder() { return Iterator{}; }
        Iterator end_inorder() { return Iterator{}; }
        Iterator begin_postorder() { return Iterator{}; }
        Iterator end_postorder() { return Iterator{}; }

        Iterator begin() { return Iterator{}; }
        Iterator end() { return Iterator{}; }

        friend ostream &operator<<(ostream &out, const BinaryTree<T> &b) { return out; }
    };

}
