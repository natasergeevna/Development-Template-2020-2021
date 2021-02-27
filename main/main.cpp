#include <iostream>
#include "roman.h"

int main()
{
    roman rom1;
    arabic arab1;
    roman rom2;
    arabic arab2;
    convertor conv;
    
    rom1.value = "XXI";
    arab1.value = 49;
    rom2.value = "XXV";
    arab2.value = 17 - 3 ;
    conv.ToArabic(rom1);
    conv.printr();
    conv.ToArabic(rom2);
    conv.printr();
    conv.ToRoman(arab1);
    conv.printa();
    conv.ToRoman(arab2);
    conv.printa();

  return 0;
}
