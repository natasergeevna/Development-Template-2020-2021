#include "roman.h"
#include <gtest.h>

TEST(test_convertor, test_1)
{
    convertor c;
    arabic ar;
    ar.value = 1;
    c.ToRoman(ar);
    EXPECT_EQ("I", c.getRoman().value);
}

TEST(test_convertor, test_5)
{
    convertor c;
    arabic ar;
    ar.value = 5;
    c.ToRoman(ar);
    EXPECT_EQ("V", c.getRoman().value);
}

TEST(test_convertor, test_4)
{
    convertor c;
    roman r;
    r.value = "IV";
    c.ToArabic(r);
    EXPECT_EQ(4, c.getArabian().value);
}

TEST(test_convertor, test_7)
{
    convertor c;
    roman r;
    r.value = "VII";
    c.ToArabic(r);
    EXPECT_EQ(7, c.getArabian().value);
}

TEST(test_convertor, test_12)
{
    convertor c;
    arabic ar;
    ar.value = 12;
    c.ToRoman(ar);
    EXPECT_EQ("XII", c.getRoman().value);
}

TEST(test_convertor, test_23)
{
    convertor c;
    arabic ar;
    ar.value = 23;
    c.ToRoman(ar);
    EXPECT_EQ("XXIII", c.getRoman().value);
}

TEST(test_convertor, test_49)
{
    convertor c;
    roman r;
    r.value = "XXXXVIIII";
    c.ToArabic(r);
    EXPECT_EQ(49, c.getArabian().value);
}

TEST(test_convertor, test_36)
{
    convertor c;
    roman r;
    r.value = "XXXIIIIII";
    c.ToArabic(r);
    EXPECT_EQ(36, c.getArabian().value);
}

TEST(test_convertor, test_17minus6)
{
    convertor c;
    arabic ar;
    ar.value = 17-6;
    c.ToRoman(ar);
    EXPECT_EQ("XI", c.getRoman().value);
}
