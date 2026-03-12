# include <stdio.h>
# include <string.h>

int main(){
    char lhs,prod[100], prefix[20],*token;
    char arr[10][20];
    int n=0,i,j;

    printf("Enter production (Example: S=ab|ac|a): ");
    scanf("%s",prod);

    lhs = prod[0];
    token = strtok(prod+2,"|");

    while(token!=NULL){
        strcpy(arr[n++],token);
        token = strtok(NULL,"|");
    }

    if(n<2){
        printf("No Left Factoring Needed\n");
        return 0;
    }

    strcpy(prefix,arr[0]);

    for (i=0;i<n;i++){
        j=0;
        while(prefix[j] == arr[i][j] && prefix[j]!='\0')
            j++;
        prefix[j]='\0';
    }

    if(strlen(prefix)==0){
        printf(" No left facoring is needed.");
        return 0;
    }

    printf("After removing left recursion:\n");

    printf("%c -> %s%c'\n",lhs,prefix,lhs);

    printf("%c' -> ", lhs);
    for(i=0;i<n;i++){
        if (strlen(arr[i]) == strlen(prefix))
            printf("e");
        else
            printf("%s",arr[i]+strlen(prefix));
        if (i<n-1) printf(" | ");
    }
    printf("\n");

    return 0;
}