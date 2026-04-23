# include <stdio.h>
# include <string.h>

# define MAX 20

typedef struct{
    char op;
    char arg1;
    char arg2;
    char result;
}Quadruple;

typedef struct{
    char op;
    char arg1;
    char arg2;
}Triple;

int main(){
    int n, i;

    char input[MAX][10];

    Quadruple quad[MAX];
    Triple tri[MAX];

    int indirect[MAX];

    printf("Enter the Number of Productions: ");
    scanf("%d", &n);

    printf("Enter the statements:");
    for(i =0;i<n;i++){
        scanf("%s", input[i]);
    }

    for(i=0; i<n; i++){
        char result, arg1, arg2, op;

        result = input[i][0];
        arg1 = input[i][2];
        op = input[i][3];
        arg2 = input[i][4];

        quad[i].op = op;
        quad[i].arg1 = arg1;
        quad[i].arg2 = arg2;
        quad[i].result = result;
        
        tri[i].op = op;
        tri[i].arg1 = arg1;
        tri[i].arg2 = arg2;

        indirect[i] = i;
    }
    printf("\n QUADRUPLE REPRESENTATION \n");
    printf("Result\tArg1\tArg2\tOp\n");
    for(int i=0;i<n;i++){
        printf("%c\t%c\t%c\t%c\n",
            quad[i].op,
            quad[i].arg1,
            quad[i].arg2,
            quad[i].result);
    }
    printf("\n TRIPLE REPRESENTATION \n");
    printf("Index\tArg1\tArg2\tOp\n");
    for(int i=0;i<n;i++){
        printf("%d\t%c\t%c\t%c\n",
            i,
            tri[i].op,
            tri[i].arg1,
            tri[i].arg2);
    }
    printf("\n INDIRECT TRIPLE REPRESENTATION \n");
    printf("Pointer\tIndex\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\n",
            i,
            indirect[i]);
    }
    return 0;
}