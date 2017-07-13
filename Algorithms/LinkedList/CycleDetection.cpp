#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Node
{
    int value;
    Node* next;
    
    Node(int value_)
    {
        value = value_;
        next = nullptr;
    }
};

Node* insert(Node* head, int value)
{
    if(head == nullptr)
        return new Node(value);
    
    Node* newNode = new Node(value);
    newNode->next = head;
    
    return newNode;
}

void print(Node* head)
{
    if(head == nullptr) return;
    
    Node* ptr = head;
    
    while(ptr != nullptr)
    {
        cout << ptr->value << " - ";
        ptr = ptr->next;
    }
    cout << "null" << endl;
}

bool detectCycle(Node* head)
{
    if(head == nullptr) return false;
    
    unordered_set<Node*> S;
    Node* ptr = head;
    
    while(ptr != nullptr)
    {
        if(S.find(ptr) != S.end())
           return true;
        
        S.insert(ptr);
        ptr = ptr->next;
    }
    
    return false;
}

bool detectCycle_Floyd(Node* head)
{
    Node* fast = head;
    Node* slow = head;
    
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast)
            return true;
    }
    
    return false;
}

int main()
{
    vector<int> arr = { 1, 2, 3, 4, 5 };
    Node* head = nullptr;
    
    for(int x : arr)
        head = insert(head, x);
    head->next->next->next->next->next = head->next->next;
    
    if(detectCycle_Floyd(head))
        cout << "Cycle found!" << endl;
    else
        cout << "No cycle!" << endl;
    
    return 0;
}