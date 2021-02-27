#include "roman.h"
#include <iostream>
using namespace std;

arabic convertor::ToArabic(roman& rome)
{
    int arrarab[] = {1,2,3,4,5,6,7,8,9,10,20,30, 40};
    string arrrom[] = { "I","II","III","IV","V","VI","VII","VIII","IX","X","XX","XXX","XL"};
    int res = 0;
    int i = 0;
    for (i=0; i < rome.value.size() - 1; i++)
    {
        string fst, nxt;
        fst += rome.value[i];
        nxt += rome.value[i+1];
        if (arrarab[findi1(fst, arrrom)] >= arrarab[findi1(nxt, arrrom)])
        {
            res += arrarab[findi1(fst, arrrom)];
        }
        else
        {
            res -= arrarab[findi1(fst, arrrom)];
        }
    }
    string lst;
    lst += rome.value[i];
    res += arrarab[findi1(lst, arrrom)];
    a.value = res;
    r = rome;
    return a;
}

roman convertor::ToRoman(arabic& arab)
{
    int arrarab[] = {1,2,3,4,5,6,7,8,9,10,20,30,40};
    string arrrom[] = {"I","II","III","IV","V","VI","VII","VIII","IX","X","XX","XXX","XL"};
    string res;
    int n = arab.value % 100 / 10 * 10;
    if (n != 0)
    {
        res += arrrom[findi(n, arrarab)];
    }
    n = arab.value % 10;
    if (n != 0)
    {
        res += arrrom[findi(n, arrarab)];
    }
    r.value = res;
    a = arab;
    return r;
}

roman convertor::getRoman()
{
    return r;
}

arabic convertor::getArabian()
{
    return a;
}

int convertor::findi(int n, int arr[])
{
    for (int i = 0; i < 13; i++)
    {
        if (arr[i] == n)
        {
            return i;
        }
    }
    return -1;
}

int convertor::findi1(string n1, string arr[])
{
    for (int i = 0; i < 13; i++)
    {
        if (arr[i] == n1)
        {
            return i;
        }
    }
    return -1;
}

void convertor::printr()
{
    cout << "roman: " << r.value << " - arabian: " << a.value << endl;
}

void convertor::printa()
{
    cout << "arabian: " << a.value << " - roman: " << r.value<< endl;
}
