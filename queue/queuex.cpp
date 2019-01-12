
#include <iostream>
using namespace std;

template <class T>
class xQueue {
    struct node {  //ОС
        T d;
        node* next;
    };
private:
    node * ptr;   
public:
    xQueue(void) : ptr(NULL) {}
    ~xQueue() {
        this->clear();
    }
public:
    void  push(T d) {
        node* e = new node();
        e->d = d;
        //e новый элемент очереди, поле последнего элемента next будет указывать на 1 элемент
        //устальные элементы указывают на стоящий взади элемент  
        if (!ptr) {        
            ptr = e;             
            ptr->next = ptr; 
        }
        else {
            e->next = ptr->next;
            ptr = ptr->next = e;
        }
    }

    T& front(void) {
        return ptr->next->d;
    }

    void  pop(void) {
        //если очердь из 1 элемента 
        if (ptr == ptr->next) {
            delete ptr;
            ptr = nullptr;
            return;
        }
        node* tmp = ptr->next;
        ptr->next = tmp->next;
        delete tmp;
        tmp = nullptr;
    }

    size_t  size(void) const {
        size_t cnt = 0u;
        const node* iter = ptr->next;
        // цикл с первого элемента
        // пока не дайдем до последнего элемента
        //последний элемент тот который указывает на вершину
        do {
            cnt++;
            iter = iter->next;
        } while (iter != ptr->next);
        return cnt;
    }

    bool empty(void) const {
        return (!ptr);
    }

    void clear(void) {
        while (!this->empty())
            this->pop();
    }
};


int main(void) {
    xQueue<char> q;

    char a = 'h';// заполняем очередь
    q.push(a);
    a = 'e';// заполняем очередь
    q.push(a);
    a = 'l';// заполняем очередь
    q.push(a);
    a = 'l';// заполняем очередь
    q.push(a);
    a = 'o';// заполняем очередь
    q.push(a);

    cout << "size queue: " << q.size() << endl;  // показать размер очереди

    while (!q.empty()) {  // читаем очередь от первого до последнего элемента
    cout<<q.front()<<endl;
    q.pop();
    }
    q.clear();

    if (q.empty())  // очередь у нас пустая
    cout << "queue NULL" << endl;
    
    cin.get();
    return 0;
}