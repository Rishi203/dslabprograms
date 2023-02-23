#include<stdio.h>


#define maxterms 100

struct sparse{
    int row;
    int col;
    int val;
};


struct sparse sparse1[maxterms];
struct sparse transposesparse[maxterms];

int matrix [100][100];
int transpose [100][100];
int size;
int rows,cols;

void printmatrix(int matrix[100][100],int rows,int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void printsparse(struct sparse sparsematrix[maxterms]){
    printf("ROW COLUMN VALUE");
    printf("\n");
    for(int i=0;i<size;i++){
        printf("%d\t%d\t%d\t\n",sparsematrix[i].row,sparsematrix[i].col,sparsematrix[i].val);
    }
    
}

void converttosparse(){
    sparse1[0].row=rows;
    sparse1[0].col=cols;
    int i,j,k =1;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            if(matrix[i][j]!=0){
                sparse1[k].row =i+1;
                sparse1[k].col =j+1;
                sparse1[k].val =matrix[i][j];
                k++;
            }   
        }
    }
    sparse1[0].val = k-1;
    size = k;

}

void converttomatrix(){
    for(int i=0;i<cols;i++){
        for(int j=0;j<rows;j++){
            transpose[i][j] = 0;
        }
    }

    for(int i=1;i<size;i++){
        transpose[transposesparse[i].row-1][transposesparse[i].col-1]=transposesparse[i].val;
    }
}

void findtranspose(){
    transposesparse[0].row = cols;
    transposesparse[0].col = rows;
    transposesparse[0].val = sparse1[0].val;
    int k=1;

    for(int i=1;i<=cols;i++){
        for(int j=1;j<=size;j++){
            if(sparse1[j].col==i){
                transposesparse[k].row=sparse1[j].col;
                transposesparse[k].col=sparse1[j].row;
                transposesparse[k].val=sparse1[j].val;
                k++;
            }
        }
    }
}


void main(){
    printf("Enter the total no of rows");
    scanf("%d",&rows);
    printf("Enter the total no of cols");
    scanf("%d",&cols);
    printf("Enter the elements in matrix");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("\ninput matrix\n");
    printmatrix(matrix,rows,cols);
    converttosparse(sparse1);

    printf("\nsparse matrix\n");
    printsparse(sparse1);

    printf("\ntranspose sparse matrix\n");
    findtranspose();
    printsparse(transposesparse);

    printf("\ntranspose matrix matrix\n");
    converttomatrix();
    printmatrix(transpose,cols,rows);

}