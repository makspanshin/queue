#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BST
{

private:
//тип callback функции
    typedef void(*tree_traverse)(Node *x_root);
//создания нового узла
    Node* new_node( int x)
    {
        Node* e = new Node();
        e->data = x;
        e->left = nullptr;
        e->right = nullptr;
        //cout << e<<endl;
        return e;
    }
public:
//вывод дерева
    int traverse(Node* x_root,tree_traverse t_t)
    {
        t_t(x_root);
        return 0;
    }
//добавление узла
/*Если дерево пусто, заменить его на дерево с одним корневым узлом  и остановиться.
Иначе сравнить K с ключом корневого узла X.
Если K>X, рекурсивно добавить  в правое поддерево Т.
Если K<X, рекурсивно добавить  в левое поддерево Т.*/

    int add_node(int data, Node** x_root)
    {
        Node *tmp;
        if (!*x_root)
        {
            tmp = new_node(data);
            *x_root = tmp;
            return 0;
        }
        else
        {
            tmp = (*x_root);
            if (data <= (tmp->data))
                add_node(data, &tmp->left);
            else
                add_node(data, &tmp->right);
        }
        return 0;
        
    }

/*Если дерево пусто, сообщить, что узел не найден, и остановиться.
Иначе сравнить K со значением ключа корневого узла X.
Если K=X, выдать ссылку на этот узел и остановиться.
Если K>X, рекурсивно искать ключ K в правом поддереве Т.
Если K<X, рекурсивно искать ключ K в левом поддереве Т.*/

    int node_find(int data, Node* x_root)
    {
        if (!x_root)
        {
            cout << "Not found" << endl;
            return 0;
            
        }
        else
        {
            if (data == x_root->data)
            {
                cout << "Node found:" << x_root << endl;
                return 0;
            }
            if (data < x_root->data)
            {
                node_find(data, x_root->left);
            }
            else
            {
                node_find(data, x_root->right);
            }
        }
    }
    // закончить
    int delete_node(int data, Node** x_root)
    {
        if (!*x_root)
        {
            return 0;
        }
        Node* tmp;
        tmp = *x_root;
        if (data <= tmp->data)
        {
            delete_node(data, &tmp->left);
        }
        else
        {
            if (data <= tmp->data)
            {
                delete_node(data, &tmp->right);
            }
        }
        // закончить
        if (data == tmp->data)
        {
            if (tmp->left == nullptr && tmp->right == nullptr)
            {
                delete(tmp);
                tmp = nullptr;
            }
            if (tmp->left != nullptr && tmp->right == nullptr)    
            {
                Node* tmp1;
                tmp1 = tmp->left;
                delete(tmp);
                tmp = tmp1;
            }
            if (tmp->left == nullptr && tmp->right != nullptr)
            {
                Node* tmp1;
                tmp1 = tmp->right;
                delete(tmp);
                tmp = tmp1;
            }
            if (tmp->left != nullptr && tmp->right != nullptr)
            {
                delete(tmp);
                tmp = tmp->left;

                
            }

        }

    }

    void delete_tree(Node** x_root)
    {
        Node* tmp;
        tmp = *x_root;
        if (tmp != nullptr)                //Пока не встретится пустое звено
        {
            delete_tree(&tmp->left);                //Рекурсивная функция прохода по левому поддереву
            delete_tree(&tmp->right);                //Рекурсивная функци для прохода по правому поддереву
            delete tmp;                 //Убиваем конечный элемент дерева
            tmp = nullptr;   
            *x_root = tmp;//Может и не обязательно, но плохого не будет
        }
        
    }
    
};
void postfix_traverse(Node* x_root)
{
    if (x_root) {
        postfix_traverse(x_root->left); //Рекурсивная функция для левого поддерева
        postfix_traverse(x_root->right); //Рекурсивная функция для правого поддерева
        cout << x_root->data<<endl; //Отображаем корень дерева
    }

}

void infix_traverse(Node *x_root)
{
    if (x_root) {
        infix_traverse(x_root->left); //Рекурсивная функция для левого поддерева
        cout << x_root->data<<endl; //Отображаем корень дерева
        infix_traverse(x_root->right);//Рекурсивная функция для правого поддерева
    }
}
void prefix_traverse(Node* x_root)
{
    if (x_root) {
        cout << x_root->data << endl; //Отображаем корень дерева
        prefix_traverse(x_root->left); //Рекурсивная функция для левого поддерева
        prefix_traverse(x_root->right); //Рекурсивная функция для правого поддерева
    }
}

int main()
{
    BST a;
    Node *s = nullptr;
    a.add_node(2, &s);
    a.add_node(4, &s);
    a.add_node(3, &s);
    a.add_node(5, &s);
    a.add_node(6, &s);
    a.add_node(7, &s);
    a.add_node(8, &s);
    a.add_node(9, &s);
    a.traverse(s, postfix_traverse);
    cout << "#######################" << endl;
    a.traverse(s, infix_traverse);
    cout << "#######################" << endl;
    a.traverse(s, prefix_traverse);
    a.node_find(4,s);
    a.delete_tree(&s);
    a.traverse(s, postfix_traverse);
    
    cin.get();

    return 0;
}