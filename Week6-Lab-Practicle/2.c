#include<stdio.h>
#include<string.h>
/*
Production rules are: 
S->(L)|a;
L->SL'
L'->,SL'|e

*/

char *ip;
char string[50];
int S(),L(),Ldash();

//S->(L)|a
int S(){
    if(*ip=='('){
        printf("%s\t\tS->(L)\n",ip);
        ip++;
        if(L()){
            if (*ip == ')')
            {
                ip++;
                return 1;
            }
            else
                return 0;
        }
        else{
            return 0;
        }
    }
    else if (*ip == 'a')
    {
        ip++;
        printf("%s\t\tS->a \n", ip);
        return 1;
    }
    else
        return 0;

}


//L->SL'

int L(){
    printf("%s\t\tL->SL' \n", ip);
    if (S())
    {

        if (Ldash())
        {
            return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}

//L'->,SL'|e

int Ldash(){
    if (*ip == ',')
    {
        printf("%s\t\tL'->,SL' \n", ip);
        ip++;
        if (S())
        {
            if (Ldash())
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
        printf("%s\t\tL'->^ \n", ip);
        return 1;
    }
}
int main(){
    printf("Enter the string\n");
    scanf("%s", string);
    ip = string;
    printf("\n\nInput\t\t\tAction\n--------------------------------\n");

    if (S()&& *ip=='\0')
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