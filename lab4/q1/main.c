#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int red[n], blue[n], yellow[n];

    int r = 0, b = 0, y = 0;

    printf("Enter number and color:\n");
    printf("1 = Red, 2 = Blue, 3 = Yellow\n");

    for (int i = 0; i < n; i++)
    {
        int num, color;

        scanf("%d %d", &num, &color);

        if (color == 1)
        {
            red[r] = num;
            r++;
        }
        else if (color == 2)
        {
            blue[b] = num;
            b++;
        }
        else
        {
            yellow[y] = num;
            y++;
        }
    }

    printf("\nSorted by color:\n");

    // Red
    for (int i = 0; i < r; i++)
        printf("%d Red\n", red[i]);

    // Blue
    for (int i = 0; i < b; i++)
        printf("%d Blue\n", blue[i]);

    // Yellow
    for (int i = 0; i < y; i++)
        printf("%d Yellow\n", yellow[i]);

    return 0;
}