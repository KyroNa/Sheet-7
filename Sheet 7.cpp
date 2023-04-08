// Sheet 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//problem 1
unsigned long factorial(int);

//problem 2
/*The Euclidean algorithm is a way to find the greatest common divisor of two positive integers, a and b. First let me show the computations for a=210 and b=45.

Divide 210 by 45, and get the result 4 with remainder 30, so 210=4·45+30.
Divide 45 by 30, and get the result 1 with remainder 15, so 45=1·30+15.
Divide 30 by 15, and get the result 2 with remainder 0, so 30=2·15+0.
The greatest common divisor of 210 and 45 is 15.*/
int gcd(int, int);

//problem 3
int fibb(int);

//problem 4
void recFun(int x) 
{ 
    if (x > 10) 
    { 
        recFun(x / 10); 
        cout << x % 10 << endl; 
    } 
    else cout << x << endl; 
}

//problem 5
int test(int x, int y) 
{ 
    if (x == y) 
        return x; 
    else if (x > y) 
        return (x + y); 
    else 
        return test(x + 1, y - 1); 
}

//problem 6 
int vowels(string);

//problem 7 
int power(int, int);

//problem 8
int seq_search(int[], int, int);

int main()
{
    int x, y;
    cout << "Insert two numbers: ";
    cin >> x >> y;

    cout << "Factorial " << x << " is " << factorial(x) << "\n";
    cout << "Greatest common divisor of " << x << " and " << y << " is " << gcd(x, y) << "\n";
    cout << "The " << x <<"th term of fibbonacci sequence is " << fibb(x) << "\n";
    recFun(451);
    cout << test(5, 10) << endl;
    cout << test(3, 9) << endl;
    string str = "Hello World!";
    cout << "\"" << str << "\" has " << vowels(str) << " vowels" << "\n";
    cout << x << " ^ " << y << " = " << power(x, y) << "\n";
    int arr[] = { 1, 2, 3, 4, 5 };
    int z = seq_search(arr, 5, x);
    if (z == -1)
        cout << "The value " << x << " is not in the array";
    else
        cout << "The value " << x << " is found in index " << z;

}


unsigned long factorial(int x)
{
    if (x == 0 || x == 1)
        return 1;
    else
        return x * factorial(x - 1);
}

int gcd(int a, int b)
{
    int temp;
    if (a == b)
        return a;

    if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }

    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

int fibb(int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
        return fibb(n - 1) + fibb(n - 2);
}

int vowels(string str)
{
    if (str == "")
    {
        return 0;
    }

    else
    {
        switch (str[0])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            str.erase(0, 1);
            return 1 + vowels(str);
        }
        str.erase(0, 1);
        return 0 + vowels(str);
    }
}

int power(int x, int y)
{
    if (x == 0)
        return 0;
    if (y == 0)
        return 1;
    else
        return x * power(x, y - 1);
}

int seq_search(int arr[], int size, int x)
{
    if (size == 0)
        return -1;

    if (arr[size - 1] == x)
        return size - 1;
    else
        return seq_search(arr, size - 1, x);
}