#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main()
{
    char input[100],inputdata;
    int i,sum;
    BinTree *tree = Create();
    while( scanf("%s",input)!=EOF)
    {
        tree->data = input[0];
        tree->parent=NULL;
        tree->rightChild=NULL;
        tree->leftChild=NULL;

        for(i=1; input[i]!='\0'; i++)
        {
            inputdata = input[i];
            tree = insert(tree,inputdata);
        }
        tree=findfirst(tree);
        sum = answer(tree);
        inorder(tree);
        printf("\n");
        printf("sum=%d\n",sum);
        printf("\n");
    }
    return 0;
}
