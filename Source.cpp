#include <iostream>

using namespace std;
struct Elem {
    char data;
    Elem* next;
    Elem* prev;
};

class Stack {
    Elem* Head;
    Elem* Tail;
    int Count;
    int top; 
    enum { EMPTY = 0, FULL = 10 };

public:
    Stack();
    ~Stack();
    int GetCount();
    void Clear();
    void Pop();
    bool IsEmpty();
    bool IsFull();
    void Add(char n);
    void Print();
    void DelAll();
};

Stack::Stack() {
    Tail = nullptr;
    Head = nullptr;
    Count = 0;
    top = EMPTY;
}

void Stack::Clear() {
    top = EMPTY;
    DelAll();
}

void Stack::Pop() {
    if (Count == 0)
        return;

    Elem* del = Tail;
    Tail = Tail->prev;

    if (Tail != nullptr)
        Tail->next = nullptr;
    else
        Head = nullptr;

    delete del;
    Count--;
    top--;
}

bool Stack::IsEmpty() {
    return top == EMPTY;
}

bool Stack::IsFull() {
    return top == FULL;
}

int Stack::GetCount() {
    return Count;
}

void Stack::Add(char n) {
    if (!IsFull()) {
        Elem* temp = new Elem;
        temp->data = n;
        temp->prev = Tail;
        temp->next = nullptr;

        if (Count == 0)
            Head = temp;
        else
            Tail->next = temp;

        Tail = temp;
        Count++;
        top++;
    }
}

Stack::~Stack() {
    DelAll();
}

void Stack::Print() {
    if (Count != 0) {
        Elem* temp = Head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void Stack::DelAll() {
    while (Head != NULL)
        Pop();
}

int main() {
    Stack a;
    a.Add('h');
    a.Add('e');
    a.Add('l');
    a.Add('l');
    a.Add('o');
    a.Add('!');
    cout << "Print: ";
    a.Print();
    a.Pop();
    a.Pop();
    cout << "Delete 2 elements: ";
    a.Print();
    a.Clear();
    cout << "Clear stack" << endl;
    a.Print();
    a.Add('b');
    a.Add('y');
    a.Add('e');
    cout << "Print: ";
    a.Print();

    return 0;
}
