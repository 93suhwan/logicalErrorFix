#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n;
    int i;
    int a, b, c;
    scanf_s("%d", &n);
    for (i = 0; i < n; i++) {
        scanf_s("%d %d %d", &a, &b, &c);
        if (abs(a - b) < ((a < b) ? a : b)){
            printf("-1");
        }
        else {
            if (c >= 1 + abs(a - b)) {
                printf("%d\n", c - abs(a - b));
            }
            else {
                printf("%d\n", c + abs(a - b));
            }
        }
    }
}

