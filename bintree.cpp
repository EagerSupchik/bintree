// bintree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
template <class T>
struct Node
{
    Node* head = NULL;
    T data;
    bool b = 0;
    int level;
    Node* left = NULL;
    Node* right = NULL;
};

template <class T>
class Bin_Tree {
    Node<T>* node;
    int size = 0;
public:
    void create(Node<T>* head, Node<T>*& nodes, int in, int& j) {

        if (in <= 0) { return; }
        nodes = new Node<T>;
        nodes->head = head;
        nodes->data = ++j;
        in--;
        create(nodes, nodes->left, in, j);
        create(nodes, nodes->right, in, j);
    }
    Bin_Tree(int in) {
        create(NULL, node, in, size);
    }

    Node<T>* getNode() {
        return node;
    }

    int count()
    {
        return count(node);
    }

    int count(Node<T>* node)
    {
        if (node == nullptr) return 0;
        if (node->left != nullptr && node->right != nullptr) return 1 + count(node->left) + count(node->right);
        else return count(node->left) + count(node->right);
    }

    void print(ostream& ost, Node<T>* node) {
        ost << node->data << endl;
        if (node->right != NULL) {
            print(ost, node->right);
        }
        if (node->left != NULL) {
            print(ost, node->left);
        }

    }
    friend ostream& operator<< (ostream& ost, Bin_Tree& bt) {
        bt.print(ost, bt.node);
        return ost;
    }

    void add(int data) {

    }

};

int main()
{
    Bin_Tree<int> BT(3);
    cout << BT << endl;
    cout << BT.count() << endl;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
