#include <iostream>
#ifndef stack_hpp
#define stack_hpp

using namespace std;

template <typename T>
class Node{
    public:
        T data;
        Node *next;

        Node(T x){
            data = x;
            next = nullptr;
        }
};

template <typename T>
class Stack{
    Node<T> *top;

    public:
        Stack(){
            top = nullptr;
        }

        void push(T x){
            Node<T> *temp = new Node<T>(x);
            temp->next = top;
            top = temp;
        }

        T pop(){
            if (top == nullptr){
                cout << "Stack Underflow" << endl;
                return T();
            }

            Node<T> *temp = top;
            top = top->next;
            T value = temp->data;

            delete temp;
            return value;
        }

        T peek(){
            if (top == nullptr){
                cout << "Stack is empty!" << endl;
                return T();
            }
            return top->data;
        }

        bool isEmpty(){
            return top == nullptr;
        }
};

bool isBalance(string input){
    Stack<char> s;
    bool insideQoute = false;

    for(int i = 0; i < input.length(); i++){
        char c = input[i];

        if (c == '\''){
            insideQoute = !insideQoute;
            continue;
        }

        if(!insideQoute){
            if (c == '(' || c == '[' || c == '{'){
                s.push(c);
            } 
            else if (c == ')' || c == ']' || c == '}')
            {
                if (s.isEmpty())
                {
                    cout << "ERROR at pos "<< i + 1 <<" reason: Extra-closing"; 
                    return false;
                }

                char top = s.pop();
                if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{'))
                {
                    cout << "ERROR at pos "<< i + 1 <<" reason: Mismatched"; 
                    return false;
                }
            }
        }
    }

    if(!s.isEmpty()){
        cout << "ERROR at pos 1 reason: Unclosed";
    }

    return s.isEmpty();
}

#endif