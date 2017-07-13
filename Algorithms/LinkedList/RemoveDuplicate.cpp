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

void printList(Node* head)
{
    if(head == nullptr)
        return;
    
    Node* ptr = head;
    while(ptr != nullptr)
    {
        cout << ptr->value << " - ";
        ptr = ptr->next;
    }
    cout << "null" << endl;
}

void removeDuplicate(Node* head)
{
    if(head == nullptr) return;
    
    unordered_set<int> S;
    Node* prev = nullptr;
    Node* current = head;
    
    while(current != nullptr)
    {
        if(S.find(current->value) != S.end())
        {
            prev->next = current->next;
            delete current;
        }
        else
        {
            prev = current;
            S.insert(current->value);
        }
        
        current = prev->next;
    }
}

int main()
{
    vector<int> arr = { 5, 3, 4, 2, 5, 4, 3, 1, 3};
    Node* head = nullptr;
    
    for(int x : arr)
        head = insert(head, x);
    printList(head);
    
    removeDuplicate(head);
    cout << "Remove duplicate: \n" << endl;
    printList(head);
    
    return 0;  
}