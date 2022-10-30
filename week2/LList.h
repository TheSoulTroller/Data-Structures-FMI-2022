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

    class Iterator
    {
    private:
        Node *current;
    public:
        Iterator()
        {
            current = nullptr;
        }
        Iterator(Node *current)
        {
            this->current = current;
        }
        bool operator!=(const Iterator &it)
        {
            return current != it.current;
        }
        void operator++(){
            current = current->next;
        }
        void operator--(){
            Node *temp = first
            while(temp->next != current){
                temp = temp->next;
            }
            current = temp;
        }
        T &operator*(){
            return current->data;
        }
        
    }
    
    Iterator begin(){
        return Iterator(first);
    }
    Iterator end(){
        return Iterator(nullptr);
    }

    LList<T>::push_back(const T &elem)
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