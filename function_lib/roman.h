#pragma once
#include <string>
using namespace std;

struct roman
{
  string value;
};

struct arabic
{
  int value;
};

class convertor
{
    roman r;
    arabic a;
public:
    arabic ToArabic(roman& rome);
    roman ToRoman(arabic& arab);
    roman getRoman();
    arabic getArabian();
    int findi(int n, int arr[]);
    int findi1(string n1, string arr[]);
    void printr();
    void printa();
 
};


