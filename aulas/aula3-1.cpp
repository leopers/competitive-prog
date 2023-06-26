#include "stdc++.h"
using namespace std;
#define LSOne(S) ((S) & (-S))

int main()
{
    // Bitmask
    int mask = 0;
    // 1 = 000000000000001
    // 4 = 00000000000100
    // 24 = 00000000011000
    // | -> or
    // ^ -> xor
    // & -> and
    // ~ -> not
    // << shift operator
    cout << "--------------------" << endl;
    cout << "Bitmask:" << endl;
    mask |= (1) | (1<<4) | (1<<15) | (1<<21);
    mask = ~mask;
    cout << mask << endl;
    while(mask != 0)
    {
        int rightestBit = LSOne(mask);
        cout << __builtin_ctz(rightestBit) << endl;
        mask ^= rightestBit;
    }

    cout << endl;

    // Big integer
    cout << "--------------------" << endl;
    cout << "Big Integer:" << endl;
    long long int fact = 1;
    for(int i = 2; i <= 40; i++)
        fact *= i;
    cout << fact << endl;
    
    cout << endl;


    cout << "--------------------" << endl;
    cout << "Money with integers:" << endl;
    int cents = 205;
    cout << cents/100 << "." << setw(2) << setfill('0') << cents%100 << endl;
    
    cout << endl;

    // Linked List
    cout << "--------------------" << endl;
    cout << "Linked list:" << endl;
    //forward_list<int> linkedList;
    list<int> doublyLinkedList {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto it = doublyLinkedList.begin();
    for(int i = 0; i < 2; i++)
        it++;
    cout << *it << endl;
    auto it2 = doublyLinkedList.insert(it, 0);
    it--;
    cout << *it << endl;

    cout << endl;

    // Stack
    cout << "--------------------" << endl;
    cout << "Stack:" << endl;
    stack<int> numberStack;
    numberStack.push(3);
    numberStack.push(1);
    numberStack.push(4);

    while(!numberStack.empty())
    {
        cout << numberStack.top() << endl;
        numberStack.pop();
    }

    cout << endl;

    // Queue
    cout << "--------------------" << endl;
    cout << "Queue:" << endl;
    queue<int> numbersQueue;
    numbersQueue.push(3);
    numbersQueue.push(1);
    numbersQueue.push(4);

    while(!numbersQueue.empty())
    {
        cout << numbersQueue.front() << endl;
        numbersQueue.pop();
    }

    // Deque
    cout << "--------------------" << endl;
    cout << "Deque:" << endl;
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(2);
    cout << dq.front() << endl;
    cout << dq.back() << endl;
    cout << dq[1] << endl;

    return 0;
}