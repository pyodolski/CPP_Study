#include <stdio.h>
#include <math.h>

double distance(int x1, int y1, int x2, int y2)
{ // 두 좌표간의 거리 계산
    double result = ((x1-x2)^2 + (y1-y2)^2);
    return sqrt(result);
}
// void swap1(int a, int b) 
// {
//     int tmp;
//     tmp = a;
//     a = b;
//     b = tmp;
// }

// void swap2(int *a, int *b) // call by reference
// {
//     int tmp;
//     tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

// int add(int a, int b)
// {
//     return a + b;
// }

// int div(int a, int b)
// {
//     return a / b;
// }

// int mod(int a, int b)
// {
//     return a % b;
// }

int main()
{
    
    // int x;
    // int y;

    // x = 10;
    // y = 20;
    // printf("x = %d, y = %d\n", x, y);
    // swap1(x, y);
    // printf("x = %d, y = %d\n", x, y);
    // swap2(&x,&y);
    // printf("x = %d, y = %d\n", x, y);
    
    // printf("%d\n", add(a,b));
    // printf("%d\n", div(a,b));
    // printf("%d\n", mod(a,b));
    // int a[] = {1,2,3,4,5,6,7,8,9};
    // int i = 0;
    // while(i < 9)
    // {
    //     printf("%d\n", a[i]);
    //     i++;
    // }

    // printf("\n");

    // int b[] = {1,2,3,4,5,6,7,8,9};
    // int j = 8;
    // while(j >= 0)
    // {
    //     printf("%d\n", b[j]);
    //     j--;
    // }
    // return 0;

}