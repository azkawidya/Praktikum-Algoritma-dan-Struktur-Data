#include <iostream>
using namespace std;
// main program
int main()
{
    char op;
    float num1, num2;
    // it allows user to enter operator i.e. +, -, *, /
    cout << "masukkan operator: ";
    cin >> op;
    // it allows user to enter the operands
    cout << "\nMasukkan bilangan ke-1 dan ke-2: ";
    cin >> num1 >> num2;
    // switch statement begins
    switch (op)
    {
    // if user enter +
    case '+':
        cout << num1 + num2;
        break;
    // if user enter -
    case '-':
        cout << num1 - num2;
        break;
    // if user enter *
    case '*':
        cout << num1 * num2;
        break;
    //if user enter /
    case '/':
        cout << num1 / num2;
        break;
    // if the operator is other than +, -, *, or /,
    // error message will display
    default:
         cout << "Error! operator is not correct";
    } // switch statement ends
    return 0;
}

