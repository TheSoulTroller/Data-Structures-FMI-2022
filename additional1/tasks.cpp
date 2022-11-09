#include <iostream>
#include <cmath>
#include <stack>
using std::cin;
using std::cout;
using std::endl;

template<typename T>
struct Node {
    T data;
    Node *next;
    Node(T data, Node *next = nullptr) : data(data), next(next) {}
};

template<typename T>
void sortList(Node<T>* first)
{
    Node<T> *p = first;
    while (p->next != NULL) {
        Node<T> *q = p->next;
        while (q != NULL) {
            if (abs(p->data) > abs(q->data)) {
                T temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}

template<typename T>
void printList(Node<T>* first)
{
    if(first == nullptr) {
        cout << "nulptr" << endl;
        return;
    }
    cout << first->data << " -> ";
    printList(first->next);
}

bool isPalindrome(int& num)
{
    int temp = num;
    int reverse = 0;
    while (temp != 0) {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }
    return reverse == num;
}

bool isSLLPalindromeV1(Node<int>* first)
{
    int num = 0;
    while (first != nullptr) {
        num = num * 10 + first->data;
        first = first->next;
    }
    return isPalindrome(num);
}

Node<int>* copy(Node<int>* first)
{
    Node<int>* newFirst = nullptr;
    Node<int>* newLast = nullptr;
    while (first != nullptr) {
        if (newFirst == nullptr) {
            newFirst = new Node<int>(first->data);
            newLast = newFirst;
        } else {
            newLast->next = new Node<int>(first->data);
            newLast = newLast->next;
        }
        first = first->next;
    }
    return newFirst;
}

void reverseSLL(Node<int>*& first)
{
    Node<int> *prev = nullptr;
    Node<int> *curr = first;
    Node<int> *next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    first = prev;
}

bool isSLLPalindromeV2(Node<int>* first)
{
    Node<int>* reversedSLL = copy(first);
    reverseSLL(reversedSLL);
    while (first != nullptr) {
        if (first->data != reversedSLL->data) {
            return false;
        }
        first = first->next;
        reversedSLL = reversedSLL->next;
    }
    return true;
}

bool isSLLPalindromewStack(Node<int>* first)
{
    std::stack<int> stack;
    Node<int>*curr = first;

    while (curr != nullptr) {
        stack.push(curr->data);
        curr = curr->next;
    }

    curr = first;

    while (curr != nullptr) {
        if (curr->data != stack.top()) {
            return false;
        }
        stack.pop();
        curr = curr->next;
    }
    return true;
}

bool hasCycleV1(Node<int>* first)
{
    if(first == nullptr) {
        return false;
    }

    Node<int>* slow = first;
    Node<int>* fast = first->next;

    while(fast != nullptr)
    {
        if(fast == slow)
        {
            return true;
        }
        if(fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        else
        {
            return false;
        }   
    }
    return false;
}

bool hasCycleV2(Node<int>* first)
{
    if(first == nullptr) {
        return false;
    }

    Node<int>* slow = first;
    Node<int>* fast = first->next;

    while(slow != fast)
    {
        if(fast == nullptr || fast->next == nullptr)
        {
            return false;
        }
        fast = fast->next->next;
        slow = slow->next;
    }

    return true;
}

Node<int>* getMiddleNode(Node<int>* first, Node<int>* last)
{
    if(first == nullptr) {
        return nullptr;
    }

    Node<int>* slow = first;
    Node<int>* fast = first->next;

    while(fast != nullptr)
    {
        if(fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        else
        {
            return slow;
        }   
    }
    return slow;
}

Node<int>* findNSLLUsingBinarySearch(Node<int>* first, int n, Node<int>* last = nullptr)
{   
    if(first == nullptr) {
        return nullptr;
    }

    Node<int>* middle = getMiddleNode(first, last);

    if(middle->data == n) {
        return middle;
    }

    if(middle->data > n) {
        return findNSLLUsingBinarySearch(first, n, middle);
    } else {
        return findNSLLUsingBinarySearch(middle->next, n, last);
    }
}

void emptySLL(Node<int>*& first)
{
    while (first != nullptr) {
        Node<int>* temp = first;
        first = first->next;
        delete temp;
    }
}

int main()
{
    Node<int> *first = new Node<int>{-3,
                       new Node<int>{1,
                       new Node<int>{2,
                       new Node<int>{-10,
                       new Node<int>{11,
                       new Node<int>{-7,nullptr}}}}}};

    Node<int> *palindrome = new Node<int>{1,
                            new Node<int>{2,
                            new Node<int>{3,
                            new Node<int>{2,
                            new Node<int>{1,nullptr}}}}};

    return 0;
}