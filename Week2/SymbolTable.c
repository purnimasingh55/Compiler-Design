#include <stdio.h>
#include <string.h>

int main()
{
    char s[999];
    int i, n, k;
    char temp[] = "+-/*=%";

    printf("Expression terminated by $:");
    gets(s);

    printf("Given Expression:");
    for (i = 0; s[i] != '$'; i++)
        printf("%c", s[i]);

    i = 0;

    printf("\n Symbol Table\nSymbol\t\taddr\t\ttype\n");
    do
    {
        char arr[999] = {'\0'}, j = 0;
        n = s[i];

        if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
        {
            arr[j] = s[i];
            i++;
            j++;
            while (1)
            {
                if ((s[i] <= 65 || s[i] >= 90) && (s[i] <= 97 || s[i] >= 122))
                {
                    arr[i] = '\0';
                    printf("%s\t\t%d\t\tidentifier\n", arr, &s[i]);
                    // flag=0;
                    break;
                }
                arr[j] = s[i];
                i++;
                j++;
            }
        }
        else if (n >= 48 && n <= 57)
        {
            arr[j] = s[i];
            i++;
            j++;
            n = s[i];
            while (1 && i < (strlen(s)) - 1)
            {
                n = s[i];
                if (n < 48 || n > 57)
                {
                    arr[i] = '\0';
                    printf("%s\t\t%d\t\tconstant\n", arr, &s[i]);
                    break;
                }
                arr[j] = s[i];
                i++;
                j++;
            }
        }
        else
        {
            for (k = 0; k < strlen(temp); k++)
                if (s[i] == temp[k])
                    printf("%c\t\t%d\t\toperator\n", s[i], &s[i]);
            i++;
        }
    } while (i < (strlen(s)) - 1);

    return 0;
}