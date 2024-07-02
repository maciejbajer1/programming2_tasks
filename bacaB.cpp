#include <cstdarg>
#include <string>
#include <iostream>
using namespace std;

string deleteAdditionalZeros (string num)
{
    if (num == "")
    {
        return "0";
    }
    if (num[0] == '0')
    {
        num.erase(0, 1);
        return deleteAdditionalZeros(num);
    }
    return num;
}
void loop1 (string &a, string &b, int k, int step, int j)
{
    if (k < 0)
    {
        return;
    }
    else
    {
        a[j] += (b[k] - 48);
        loop1(a, b, k + step, step, j + step);
    }
}
void loop2 (string &a, string &b, int i, int step)
{
    if (i <= 0)
    {
        return;
    }
    else
    {
        if(a[i] > 57)
        {
            int z = a[i] - 48;
            a[i-1] = ((a [i - 1] - 48) + z / 10) + 48;
            a[i] = (z % 10) + 48;
        }
        loop2(a, b, i + step, step);
    }
}
void loop3 (string &a, string &b, int i, int step, int j)
{
    if (i < 0)
    {
        return;
    }
    else
    {
        a[j] = a[j] - (b[i] - 48);
        if (a[j] < 48)
        {
            a[j] = a[j] + 10;
            a[j - 1]--;
        }
        loop3(a, b, i + step, step, j + step);
    }
}
string arraySum1 (int i, const string *array, string *result)
{
    string a = *result;
    string b = (*(array + i - 1));
    if ((b[0] != '-' && a[0] != '-'))
    {
        if (a[0] == '+')
        {
            a.erase(0, 1);
        }
        if (b[0] == '+')
        {
            b.erase(0, 1);
        }
        b = deleteAdditionalZeros(b);
        if(a.length() < b.length())
        {
            string temp = a;
            a = b;
            b = temp;
        }

        int j = a.length() - 1;
        int k = b.length() - 1;
        int step = -1;
        loop1(a, b, k, step, j);

        int l = a.length() - 1;
        loop2(a, b, l, step);
        if(a[0] > 57)
        {
            string k;
            k = k + a[0];
            a[0] = ((a[0] - 48) % 10) + 48;
            k[0] = ((k[0] - 48) / 10) + 48;
            a = k + a;
        }
    }
    if ((b[0] == '-' && a[0] == '-') || (b[0] == '-' && a.empty()))
    {
        if (a[0] == '-')
        {
            a.erase(0, 1);
        }
        if (b[0] == '-')
        {
            b.erase(0, 1);
        }
        b = deleteAdditionalZeros(b);
        if(a.length() < b.length())
        {
            string temp = a;
            a = b;
            b = temp;
        }

        int j = a.length() - 1;
        int k = b.length() - 1;
        int step = -1;
        loop1(a, b, k, step, j);

        int l = a.length() - 1;
        loop2(a, b, l, step);
        if(a[0] > 57)
        {
            string k;
            k = k + a[0];
            a[0] = ((a[0] - 48) % 10) + 48;
            k[0] = ((k[0] - 48) / 10) + 48;
            a = k + a;
        }
        a.insert(0, "-");
    }
    else
    {
        if ((b[0] == '-' && a[0] != '-'))
        {
            if (b[0] == '-')
            {
                b.erase(0, 1);
            }
            if (a[0] == '+')
            {
                a.erase(0, 1);
            }
            b = deleteAdditionalZeros(b);

            bool neg = false;
            if (a.length() < b.length() || (a.length() == b.length() && a < b))
            {
                string temp = a;
                a = b;
                b = temp;
                neg = true;
            }

            int j = a.length() - 1;
            int i = b.length() - 1;
            int step = -1;
            loop3(a, b, i, step, j);
            a = deleteAdditionalZeros(a);
            if (neg)
            {
                a.insert(0, "-");
            }
        }
        else if ((b[0] != '-' && a[0] == '-') && !(b.empty()))
        {
            if (b[0] == '+')
            {
                b.erase(0, 1);
            }
            if (a[0] == '-')
            {
                a.erase(0, 1);
            }
            b = deleteAdditionalZeros(b);
            bool neg = true;
            if (a.length() < b.length() || (a.length() == b.length() && a < b))
            {
                string temp = a;
                a = b;
                b = temp;
                neg = false;
            }

            int j = a.length() - 1;
            int i = b.length() - 1;
            int step = -1;
            loop3(a, b, i, step, j);
            a = deleteAdditionalZeros(a);
            if (neg)
            {
                a.insert(0, "-");
            }
        }
    }

    string x = a;
    if (x == "-0")
    {
        x = "0";
    }
    if (i == 1) return x;
    return arraySum1(i - 1, array, &x);
}
void makingArray (string *array, int i, int count, int step, va_list arg)
{
    if (i >= count)
    {
        return;
    }
    else
    {
        array[i] = va_arg(arg, const char *);
        makingArray(array, i + step, count, step, arg);
    }
}


string Sum (int count, const string *stringArray)
{
    string result = "";
    string suma = arraySum1(count, stringArray, &result);;
    return suma;
}
string Sum (int count, ...)
{
    int step = 1;
    string array [count];
    int index = 0;
    va_list args;
    va_start(args, count);
    makingArray (array, index, count, step, args);
    va_end(args);
    string result = "";
    result = Sum(count, array);
    return result;
}
void Sum (string *result, int count, const string *array)
{
    *result = Sum(count, array);
}
void Sum (string *result, int count, ...)
{
    int step = 1;
    string array [count];
    int index = 0;
    va_list args;
    va_start(args, count);
    makingArray (array, index, count, step, args);
    va_end(args);
    *result = Sum(count, array);
}
void Sum (string &result, int count, const string *array)
{
    result = Sum(count, array);
}
void Sum (string &result, int count, ...)
{
    int step = 1;
    string array [count];
    int index = 0;
    va_list args;
    va_start(args, count);
    makingArray (array, index, count, step, args);
    va_end(args);
    result = Sum(count, array);
}



void loopM2 (string &a, string &b, string &temp, int i, int j, int step)
{
    if (j < 0)
    {
        return;
    }
    else
    {
        int n = (a[i] - '0') * (b[j] - '0') + temp[i + j + 1];
        temp[i + j + 1] = n % 10;
        temp[i + j] += n / 10;
        loopM2 (a, b, temp, i, j + step, step);
    }
}
void loopM1 (string &a, string &b, string &temp, int i, int j, int step)
{
    if (i < 0)
    {
        return;
    }
    else
    {
        loopM2 (a, b, temp, i, j, step);
        loopM1 (a, b, temp, i + step, j, step);
    }
}
void loopM3 (string &temp, int i, int end, int step2)
{
    if (i >= end)
    {
        return;
    }
    else
    {
        temp[i] += '0';
        loopM3(temp, i + step2, end, step2);
    }
}
string arrayMult1 (int i, const string *array, string *result)
{

    string a = *result;
    string b = (*(array + i - 1));
    string temp;


    if (a == "")
    {
        temp = b;
    }
    else
    {

        if ( (a[0] != '-' && b[0] != '-') || (a[0] == '-' && b[0] == '-'))
        {
            if (a[0] == '-')
            {
                a.erase(0, 1);
            }
            if (b[0] == '-')
            {
                b.erase(0, 1);
            }
            if (a[0] == '+')
            {
                a.erase(0, 1);
            }
            if (b[0] == '+')
            {
                b.erase(0, 1);
            }

            a = deleteAdditionalZeros(a);
            b = deleteAdditionalZeros(b);

            int l = a.length() + b.length();
            temp.resize(l);

            int i = a.length() - 1;
            int step = -1;
            int j = b.length() - 1;
            loopM1(a, b, temp, i, j, step);


            int step2 = 1;
            int end = temp.length();

            loopM3 (temp, 0, end, step2);
            temp = deleteAdditionalZeros(temp);
            //temp.resize(a.length() + b.length());
        }
        else
        {
            if (a[0] == '-')
            {
                a.erase(0, 1);
            }
            if (b[0] == '-')
            {
                b.erase(0, 1);
            }
            if (a[0] == '+')
            {
                a.erase(0, 1);
            }
            if (b[0] == '+')
            {
                b.erase(0, 1);
            }

            a = deleteAdditionalZeros(a);
            b = deleteAdditionalZeros(b);


            int l = a.length() + b.length();
            temp.resize(l);

            int i = a.length() - 1;
            int step = -1;
            int j = b.length() - 1;
            loopM1(a, b, temp, i, j, step);


            int step2 = 1;
            int end = temp.length();

            loopM3 (temp, 0, end, step2);
            temp = deleteAdditionalZeros(temp);
            if (temp != "0")
            {
                temp.insert(0, "-");
            }
        }

    }

    string x = temp;
    if (i == 1) return x;
    return arrayMult1 (i - 1, array, &x);
}

string Mult (int count, const string *array)
{
    string result = "";
    string multiplied = arrayMult1(count, array, &result);
    return multiplied;

}
string Mult (int count, ...)
{
    int step = 1;
    string array [count];
    int index = 0;
    va_list args;
    va_start(args, count);
    makingArray (array, index, count, step, args);
    va_end(args);
    string result = "";
    result = Mult(count, array);
    return result;

}
void Mult (string *result, int count, const string *array)
{
    *result = Mult(count, array);
}
void Mult (string *result, int count, ...)
{
    int step = 1;
    string array [count];
    int index = 0;
    va_list args;
    va_start(args, count);
    makingArray (array, index, count, step, args);
    va_end(args);
    *result = Mult(count, array);
}
void Mult (string &result, int count, const string *array)
{
    result = Mult(count, array);
}
void Mult (string &result, int count, ...)
{
    int step = 1;
    string array [count];
    int index = 0;
    va_list args;
    va_start(args, count);
    makingArray (array, index, count, step, args);
    va_end(args);
    result = Mult(count, array);
}



string Operation (string(*function)(int, const string*), int count, const string *array)
{
    return function(count, array);
}
string Operation (string(*function)(int, const string*), int count, ...)
{
    string *array = new string [count];
    va_list args;
    int step = 1;
    int index = 0;
    va_start(args, count);
    makingArray (array, index, count, step, args);
    va_end(args);
    string result = function(count, array);
    delete [] array;
    return result;
}
void Operation (string* result, string(*function)(int, const string*), int count, ...)
{
    string *array = new string [count];
    va_list args;
    int step = 1;
    int index = 0;
    va_start(args, count);
    makingArray (array, index, count, step, args);
    va_end(args);
    string result2 = function(count, array);
    delete [] array;
    *result = result2;


}
void Operation (string* result, string(*function)(int, const string*), int count, const string *array)
{
    *result = function(count, array);
}
void Operation (string &result, void(*function)(string*, int, const string*), int count, const string *array)
{
    string *ptr = new string ();
    function(ptr, count, array);
    result = *ptr;
    delete ptr;
}
void Operation (string &result, void(*function)(string*, int, const string*), int count, ...)
{
    string *array = new string [count];
    string *ptr = new string ();
    va_list args;
    int step = 1;
    int index = 0;
    va_start(args, count);
    makingArray (array, index, count, step, args);
    va_end(args);
    function(ptr, count, array);
    result = *ptr;
    delete [] array;
    delete ptr;
}
