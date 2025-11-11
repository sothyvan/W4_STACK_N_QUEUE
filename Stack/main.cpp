#include "stack.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){

    string test1 = "({[]})";
    string test2 = "()[]{}"; 
    string test3 = "([)]";
    string test4 = "(((";
    string test5 = "()))";
    string test6 = "if (a[0] == '{')";

    cout << "Test 1: " << test1 << " -> " << (isBalance(test1) ? "OK" : "") << endl;
    cout << "Test 2: " << test2 << " -> " << (isBalance(test2) ? "OK" : "") << endl;
    cout << "Test 3: " << test3 << " -> " << (isBalance(test3) ? "OK" : "") << endl;
    cout << "Test 4: " << test4 << " -> " << (isBalance(test4) ? "OK" : "") << endl;
    cout << "Test 5: " << test5 << " -> " << (isBalance(test5) ? "OK" : "") << endl;
    cout << "Test 6: " << test6 << " -> " << (isBalance(test6) ? "OK" : "") << endl;

    return 0;
}