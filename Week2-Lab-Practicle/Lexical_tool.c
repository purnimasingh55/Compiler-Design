//#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
//using namespace std;




char keyword[30][30]={"int","while","break","for","do","if","float","char","switch",
    "double","short","long","unsigned","sizeof","else","register","extern","static",
    "auto","case","break","volatile","enum","typedef"};

char id[20],num[20];
char symdl_tbl[20][20];




int Check_Keyword(char s[]){
    for(int i =0;i<24;i++){
        if(strcmp(s,keyword[i])==0){
            return 1;
        }
    }
    return 0;
}



//void store_symb_tbl(char id[],char symdl_tbl[][20]){


void store_symb_tbl(char id[]){
    
    //cout<<"\n\t\t\tSymbol Table\n\t\t\t";
    printf("\n\t\t\tSymbol Table\n\t\t\t");
    
    for(int i=0;i<strlen(id);i++){
        //for(int j =0;j<n;j++){
            //cout<<"\tSymbol Name\t\tToken\t\t Data Type\t\t";
            printf("\tSymbol Name\t\tToken\t\t Data Type\t\t");
            //cout<<"\t"<<id[i]<<"\t\t"<<"id"<<"Variable";
            printf("\t%c\t\t id\t\t Variable",id[i] );
        //}
    }
}




int main(){
    FILE *f1,*f2;
    f1 = fopen("x.txt","r");
    f1 = fopen("y.txt","w");
    char c;
    int state =0,i=0,j=0;
    while((c=fgetc(f1))!=EOF){
        switch (state)
        {
        case 0: /* constant-expression */
            /* code */
            if(isalpha(c)){
                state = 1;
                id[i++] = c;
            }
            else if(isdigit(c)){
                state = 3;
                num[j++] = c;
            }
            else if(c=='>'||c=='<'){
                state = 5;
            }
            else if(c=='='||c=='!'){
                state = 8;
            }
            else if(c==' '||c=='\t'||c=='\n'){
                state = 0;
            }
            else if(c=='/'){
                state = 10;
            }
            else{
                fprintf(f2,"\n%c",c);
            }

            break;
        case 1:
            if(isalnum(c)){
                state=1; id[i++]=c;
            }
            else{
                id[i]='\0';
                if(Check_Keyword(id))
                    fprintf(f2," \n %s : keyword ",id);
                else
                    fprintf(f2,"\n %s : identifier",id);
                store_symb_tbl(id);
                state=0;
                i=0;
                ungetc(c,f1);
            }
            break;
        case 3:
            if(isdigit(c)){
                num[j++]=c;
                state=3;
            }
            else{
                num[j]='\0';
                fprintf(f2, " \n%s: number",num);
                state=0;
                j=0;
                ungetc(c,f1);
            }
            break;
            case 5:
                if(c=='='){
                    fprintf(f2,"\n relational operator ");
                    //write code to print specific operator like <= or >=
                    fprintf(f2,"%c",c);
                    id[i++] = c;
                    fprintf(f2,"%c",c);
                    
                    
                    state=0;
                }
                else{
                    fprintf(f2,"\n relational operator ");
                    //write code to print specific operator like <, >, <= or >=
                    fprintf(f2,"%c",c);
                    id[i++] = c;
                    fprintf(f2,"%c",c);
                    state=0;
                    ungetc(c,f1);
                }
            break;
            case 8:
                if(c=='='){
                    fprintf(f2,"\n relational operator ");
                    //write code to print specific operator like == or !=
                    fprintf(f2,"%c",c);
                    id[i++] = c;
                    fprintf(f2,"%c",c);
                    state=0;
                }
                else{
                    ungetc(c,f1);
                    state=0;
                }
            break;
            case 10:
                if(c=='*')
                    state=11;
                else
                    fprintf(f2,"\n invalid lexeme");
            break;
            case 11: 
                if(c=='*')
                    state=12;
                else
                    state=11;
                break;
            case 12: 
                if(c=='*')
                    state=12;
                else if(c=='/')
                    state=0;
                else
                    state=11;
            break;
        }//End of switch
    }//end of while
    if(state==11)
        fprintf(f2,"\ncomment did not close");
    fclose(f1);
    fclose(f2);
    return 0;
}
