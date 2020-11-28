#include <stdio.h>

int main(void) {

    int length;
    int width;
    int area;

    printf("Enter the length of the rectangle:");
    scanf("%d", &length);
    printf("Enter the width of the rectangle:");
    scanf("%d", &width);
    area = length * width;
    printf("Area=%d\n",area);
    return 0;
}
