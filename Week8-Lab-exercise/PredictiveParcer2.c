/*
Design of Non-Recursive Predictive Parsing
for the grammar

E -> TEdash
Edash -> +TEdash | epsilon
T -> FTdash
Tdash -> *FTdash | epsilon
F -> (E) | d

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
int i = 0, top = 0;
char stack[20], ip[20];

void push(char c)
{
    if (top >= 20)
        printf("Stack Overflow");
    else
        stack[top++] = c;
}

void pop(void)
{
    if (top < 0)
        printf("Stack underflow");
    else
        top--;
}

void error(void)
{
    printf("\n\nSyntax Error!!!! String is invalid\n");
    getch();
    exit(0);
}

int main(){
    printf("The given grammer is: ");
    printf("E -> TEdash");
    printf("\nEdash -> +TEdash | epsilon");  
    printf("\nT -> FTdash");  
    printf("\nTdash -> *FTdash | epsilon");
    printf("\nF -> (E) | d");

    printf("\nEnter the string to be parsed: ");
    scanf("%s",ip);
    int n = strlen(ip);
    ip[n] = '$';
    ip[n+1] = '\0';
    push('$');
    push('E');
    while(ip[i] !='\0'){
        if (ip[i] == '$' && stack[top - 1] == '$')
		{
			printf("\n\n Successful parsing of string \n");
			return (1);
		}
        else if (ip[i] == stack[top - 1])
		{
			printf("\nmatch of %c occured ", ip[i]);
			i++;
			pop();
		}
        else{
            if(stack[top-1] == 'E' && (ip[i] == '('||ip[i] == 'd') ){
                printf("\nE -> TEdash");
                pop();
                push('Y');
                push('T');

            }
            else if(stack[top-1] == 'Y' &&(ip[i] == '+') ){
            	printf("\nEdash -> +TEdash");
            	pop();
            	push('Y');
            	push('T');
            	push('+');
			}
			else if(stack[top-1] == 'Y' && (ip[i] == ')' || ip[i] == '$')){
				printf("\nEdash -> epsilon");
				pop();
			}
			else if(stack[top-1] == 'T' && (ip[i] =='d' || ip[i] == '(')){
				printf("\nT -> FTdash");
				pop();
				push('Z');
				push('F');
			}
			else if(stack[top-1] == 'Z' && (ip[i] == '*')){
				printf("\nTdash -> *FTdash");
				pop();
				push('Z');
				push('F');
				push('*');
			}
			else if(stack[top-1] == 'Z' && (ip[i] == '+'|| ip[i] ==')'|| ip[i]=='$')){
				printf("\nTdash -> epsilon");
				pop();
			}
			else if(stack[top-1] == 'F' && (ip[i] == 'd')){
				printf("\nF -> d");
				pop();
				push('d');
			}
			else if(stack[top-1] == 'F' && (ip[i] == '(')){
				printf("\nF -> (E)");
				pop();
				push(')');
				push('E');
				push('(');
			}
			else{
				error();
			}
        }
    }    
}
