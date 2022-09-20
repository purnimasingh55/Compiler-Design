#include <stdio.h>
#include <string.h>
int E(), Edash(), T(), Tdash(), F();

/*
Production Rules are: 
E->TE'
E'->+TE'|e
T->FT'|e
T'->*FT'|e
F->(E)|i

TE' FT'E' (E)T'E' (TE')T'E' (FT'E')T'E'  (i*FT'E')T' (i*i)
*/
char *ip;
char string[50];
int main()
{
    printf("Enter the string\n");
    scanf("%s", string);
    ip = string;
    printf("\n\nInput\tAction\n--------------------------------\n");

    if (E() && *ip =='\0')
    {
        printf("\n--------------------------------\n");
        printf("\n String is successfully parsed\n");
    }
    else
    {
        printf("\n--------------------------------\n");
        printf("Error in parsing String\n");
    }
}
//E->TE'
int E()
{
    printf("%s\tE->TE' \n", ip);
    if (T())
    {
        if (Edash())
        {
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}
//E'->+TE'|e
int Edash()
{
    if (*ip == '+')
    {
        printf("%s\tE'->+TE' \n", ip);
        ip++;
        if (T())
        {
            if (Edash())
            {
                return 1;
            }
            else
                return 0;
        }
        else
            return 0;
    }
    else
    {
        printf("%s\tE'->^ \n", ip);
        return 1;
    }
}
//T->FT'
int T()
{
    printf("%s\tT->FT' \n", ip);
    if (F())
    {

        if (Tdash())
        {
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}
//T'->*FT'|e
int Tdash()
{
    if (*ip == '*')
    {
        printf("%s\tT'->*FT' \n", ip);
        ip++;
        if (F())
        {
            if (Tdash())
            {
                return 1;
            }
            else
                return 0;
        }
        else
            return 0;
    }
    else
    {
        printf("%s\tT'->^ \n", ip);
        return 1;
    }
}
//F->(E)|i
int F()
{
    if (*ip == '(')
    {
        printf("%s\tF->(E) \n", ip);
        ip++;
        if (E())
        {
            if (*ip == ')')
            {
                ip++;
                return 1;
            }
            else
                return 0;
        }
        else
            return 0;
    }

    else if (*ip == 'i')
    {
        ip++;
        printf("%s\tF->i \n", ip);
        return 1;
    }
    else
        return 0;
}
