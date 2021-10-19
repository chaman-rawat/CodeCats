// Q8. Write a C program to find all roots of a quadratic equation.

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int a, b, c;    // a, b and c are coefficients

    printf("Enter value of quadratic equations coefficient (a, b, c): ");
    scanf("%d %d %d", &a, &b, &c);

    float root1, root2, d;  // d is Discriminant

    d = b*b - 4*a*c;    

    root1 = (-b + sqrt(d))/(2*a);
    root2 = (-b - sqrt(d))/(2*a);
    
    printf("The root of %dx^2 + %dx + %d is:\nroot1 = %.2f and root2 = %.2f\n", a, b, c, root1, root2);
    
    return 0;
}