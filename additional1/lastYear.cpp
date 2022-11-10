#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct Node{
    int data;
    Node* next;
    Node(int data, Node* next) : data(data), next(next) {}
};

void printList(Node* first)
{
    while(first != nullptr)
    {
        cout << first->data << " -> ";
        first = first->next;
    }
    cout << "nullptr" << endl;
}

void deleteList(Node*& first)
{
    Node* temp = first;
    while(first != nullptr)
    {
        first = first->next;
        delete temp;
        temp = first;
    }
}

Node* arrToList(const int* arr, size_t size)
{
    Node* first = nullptr;
    Node* last = nullptr;
    for(size_t i = 0; i < size; i++)
    {
        Node* newNode = new Node{arr[i], nullptr};
        if(first == nullptr)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
    }
    return first;
}

void removeConsecutiveDuplicates(Node*& first)
{
    Node* check = first;
    while(check->next != nullptr)
    {
        Node* temp = check->next;
        if(check->data == temp->data)
        {
            check->next = temp->next;
            delete temp;
        }
        else
        {
            check = check->next;
        }
    }
}

int main()
{
    int arr[] = {1,1,2,2,1,1,2,2,2,2,1,2,1,2};
    Node* first = arrToList(arr, 14);
    printList(first);
    removeConsecutiveDuplicates(first);
    printList(first);
    deleteList(first);
    return 0;
}