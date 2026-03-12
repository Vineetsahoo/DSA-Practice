# include <stdio.h>
# include <string.h>

int main(){
    char lhs, prod[100],*token;
    char alpha[10][20], beta[10][20];
    int a=0 ,b=0,i;

    printf("Enter production (Example: S=S+S|S*S|a): ");
    scanf("%s",prod);

    lhs = prod[0];

    token  = strtok(prod+2,"|");

    while(token!=NULL){
        if(token[0]==lhs){
            strcpy(alpha[a],token+1);
            a++;
        }else{
            strcpy(beta[b],token);
            b++;
        }token =strtok(NULL,"|");
    }

    if(a==0){
        printf("No left Recursion\n");
        return 0;
    }

    printf("After removing left recursion: \n");

    printf("%c -> ",lhs);
    for (i=0;i<b;i++){
        printf("%s%c' ", beta[i], lhs);
    }
    printf("\n%c' -> ",lhs);
    for (i=0;i<a;i++){
        printf("%s%c' | ", alpha[i], lhs);
    }
    printf("e\n");

    return 0;
}