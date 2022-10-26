#pragma once
#include <iostream>
template <typename T>
class LList {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* first;

    void erase(){
        while(first){
            Node* temp = first;
            first = first->next;
            delete temp;
        }
    }

public:
    LList<T>(){
        first = nullptr;
    }
    LList<T>(const LList<T>& other){
        first = nullptr;
        Node* temp = other.first;
        while(temp){
            push_back(temp->data);
            temp = temp->next;
        }
    }
    ~LLits<T>(){
        erase();
    }
    
    //12.1
    int LList<T>::count(int x) const
    {
        int count = 0;
        Node* temp = first;
        while(temp != nullptr)
        {
            temp->data == x ? count++ : temp = temp->next;
        }
    }

    //12.2
    LList(int x, int y){
        if(x <= y)
        {
            first = nullptr;
            for (int i = x; i <= y; i++)
            {
                Node *temp = new Node;
                temp->data = i;
                temp->next = first;
                first = temp;
            }
        }
        else
        {
            first = nullptr;
        }
    }

    //12.3
    void LList<T>::push_back(const T& elem)
    {
        Node* newNode = new Node;
        newNode->data = elem;
        newNode->next = nullptr;
        if(first == nullptr)
        {
            first = newNode;
        }
        else
        {
            Node* temp2 = first;
            while(temp2->next != nullptr)
            {
                temp2 = temp2->next;
            }
            temp2->next = newNode;
        }
    }

    //12.4
    void LList<T>::operator +=(const T& elem)
    {
        push_back(elem);
    }

    //12.7
    void LList<T>::append(const LList<T>& other)
    {
        Node* last = first;
        while(last->next != nullptr)
        {
            last = last->next;
        }
        last->next = other.first;
    }

    void print() const
    {
        if(first != nullptr)
        {
            Node *temp = first;
            while (temp != nullptr)
            {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            return;
        }
        cout << "List is empty!" << endl;
    }
};