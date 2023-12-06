
#include<stdio.h>

struct Paratha {
   int unit, price;
};

struct Vegetable {
   int unit, price;
};

struct Minwater {
   int unit, price;
};

 int main()
{

    struct Paratha p1;
    struct Vegetable v1;
    struct Minwater m1;
    int n;

    scanf("%d", &p1.unit);
    scanf("%d", &p1.price);
    scanf("%d", &v1.unit);
    scanf("%d", &v1.price);
    scanf("%d", &m1.unit);
    scanf("%d", &m1.price);
    scanf("%d", &n);

    double total = 0.0;

    total += p1.unit * 1.0;
    total += p1.price * 1.0;
    total += v1.unit * 1.0;
    total += v1.price * 1.0;
    total += m1.unit * 1.0;
    total += m1.price * 1.0;

    printf("%f\n", total / n );

   return 0;
}
