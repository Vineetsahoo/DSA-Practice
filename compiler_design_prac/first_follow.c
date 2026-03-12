#include<stdio.h>
#include<string.h>
#include<ctype.h>

char prod[20][20];
int n;

void first(char c){
    int i;

    if(!isupper(c)){
        printf("%c ",c);
        return;
    }

    for(i=0;i<n;i++){
        if(prod[i][0]==c){

            if(prod[i][2]=='#')
                printf("# ");

            else if(!isupper(prod[i][2]))
                printf("%c ",prod[i][2]);

            else
                first(prod[i][2]);
        }
    }
}

void follow(char c){
    int i,j;

    if(prod[0][0]==c)
        printf("$ ");

    for(i=0;i<n;i++){
        for(j=2;j<strlen(prod[i]);j++){

            if(prod[i][j]==c){

                if(prod[i][j+1]!='\0'){

                    if(!isupper(prod[i][j+1]))
                        printf("%c ",prod[i][j+1]);

                    else
                        first(prod[i][j+1]);
                }

                if(prod[i][j+1]=='\0' && c!=prod[i][0])
                    follow(prod[i][0]);
            }
        }
    }
}

int alreadyPrinted(char c){
    static char done[20];
    static int k=0;
    int i;

    for(i=0;i<k;i++)
        if(done[i]==c)
            return 1;

    done[k++]=c;
    return 0;
}

int main(){

    int i;

    printf("Enter Number of Productions: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Production %d: ",i+1);
        scanf("%s",prod[i]);
    }

    printf("\nFIRST sets:\n");

    for(i=0;i<n;i++){
        if(!alreadyPrinted(prod[i][0])){
            printf("FIRST(%c) = { ",prod[i][0]);
            first(prod[i][0]);
            printf("}\n");
        }
    }

    printf("\nFOLLOW sets:\n");

    for(i=0;i<n;i++){
        printf("FOLLOW(%c) = { ",prod[i][0]);
        follow(prod[i][0]);
        printf("}\n");
    }

    return 0;
}