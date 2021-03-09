#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node(int _val = 0, Node *_next = nullptr):val(_val), next(_next) {}
};

class List
{
    Node *first;
public:
    List():first(nullptr) {}
    
    void add(int a)
    {
        Node *p = new Node(a, first);
        first = p;
    }
    
    void print()
    {
        Node *t = first;
        while (t != nullptr)
        {
            cout << t->val << " ";
            t = t->next;
        }
        cout << endl;
    }
    
    void addcycle(int size)
    {
        Node *foll = first;
        Node *prev = nullptr;
        while (foll != nullptr)
        {
            prev = foll;
            foll = foll->next;
        }
        Node *f = prev;
        for(int i = 0; i < size; i++)
        {
            prev->next = new Node(i, nullptr);
            prev = prev->next;
        }
        prev->next = f;
    }
    
    bool hasLoop1()
    {
        if(first == nullptr)
            return false;
        Node *slow = first;
        Node *fast = first->next;
        while(true)
        {
            slow = slow->next;
            if(fast->next != nullptr)
                fast = fast->next->next;
            else
                return false;
            if((slow == nullptr) || (fast == nullptr))
                return false;
            if(slow == fast)
                return true;
        }
    }
    
    bool hasLoop2()
    {
        if(first == nullptr)
            return false;
        int i = 1;
        Node *p = first;
        while(true)
        {
            Node *tmp = p;
            for(int j = 0; j < i; j++)
            {
                tmp = tmp->next;
                if(tmp == nullptr)
                    return false;
            }
            if(p == tmp)
                return true;
            p = tmp;
            i++;
        }
    }
};


int main()
{
    List l;
    for(int i = 0; i < 5; i++)
        l.add(i+1);
    l.print();
    cout << "First Loop check w/o cycle: " << l.hasLoop1() << endl;
    cout << "Second Loop check w/o cycle: " << l.hasLoop2() << endl;
    l.addcycle(5);
    cout << "First Loop check w/ cycle: " << l.hasLoop1() << endl;
    cout << "Second Loop check w/ cycle: " << l.hasLoop2() << endl;
    return 0;
}
