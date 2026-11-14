#include <stdio.h>

#define LIMITE 1000000

/*@ requires 0 <= dividendo <= 1000000;
    requires 1 <= divisor <= 1000000;
    requires \valid(cociente) && \valid(residuo);
    requires \separated(cociente, residuo);
    assigns *cociente, *residuo;
    ensures dividendo == divisor * *cociente + *residuo;
    ensures *cociente >= 0;
    ensures 0 <= *residuo < divisor;
*/
void dividir(int dividendo, int divisor, int *cociente, int *residuo)
{
    int q = 0;
    int r = dividendo;

    /*@ loop invariant dividendo == divisor * q + r;
        loop invariant q >= 0;
        loop invariant r >= 0;
        loop assigns q, r;
        loop variant r;
    */
    while (r >= divisor) {
        r = r - divisor;
        q = q + 1;
    }

    *cociente = q;
    *residuo = r;
}

static void probar(int a, int b)
{
    int q;
    int r;

    if (a < 0 || a > LIMITE || b <= 0 || b > LIMITE) {
        printf("%d / %d -> entrada invalida (se requiere 0<=a<=%d y 1<=b<=%d)\n",
               a, b, LIMITE, LIMITE);
        return;
    }
    dividir(a, b, &q, &r);
    printf("%d / %d -> cociente = %d, residuo = %d\n", a, b, q, r);
}

int main(void)
{
    probar(20, 5);
    probar(17, 5);
    probar(0, 5);
    probar(3, 8);
    probar(1000000, 1);
    probar(1000000, 1000000);
    probar(999999, 1000000);
    probar(10, 0);
    probar(-10, 3);
    probar(10, -3);
    probar(1000001, 7);
    return 0;
}
