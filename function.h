#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
typedef struct BinTree *Tree;
typedef struct BinTree
{
    int *data;
    Tree leftChild;
    Tree rightChild;
    Tree parent;
} BinTree;

struct
{
    int *data;
    int *next;
} stack;
BinTree * Create()
{
    BinTree *newtree = (BinTree*)malloc(sizeof (BinTree));
    newtree->data=newtree->leftChild=newtree->rightChild=newtree->parent=NULL;
    return newtree;
}
BinTree * findparent(BinTree *tree)
{
    while(tree->parent->rightChild != NULL)
    {
        tree=tree->parent;
    }
    return tree->parent;
}
BinTree * insert(BinTree *tree ,int *inputdata)
{
    BinTree *newtree = Create();
    newtree->data = inputdata;

    if( tree->data == '/' || tree->data == '*' || tree->data == '+' || tree->data == '-')
    {
        if(tree->leftChild==NULL)
        {
            tree->leftChild = newtree;
            newtree->parent = tree;
            return newtree;
        }
        else
        {
            tree->rightChild=newtree;
            newtree->parent=tree;
            return newtree;
        }
    }
    else
    {

        if( tree->parent->rightChild == NULL)
        {
            tree->parent->rightChild = newtree;
            newtree->parent = tree->parent;
            return newtree;
        }

        else
        {
            tree = findparent(tree);
            return insert( tree , newtree->data);
        }
    }
}
BinTree *findfirst(BinTree *tree)
{
    while(tree->parent!=NULL)
    {
        tree=tree->parent;
    }
    return tree;
}
void inorder(BinTree * tree)
{
    if(tree)
    {
        inorder(tree->leftChild);
        printf("%c",tree->data);
        inorder(tree->rightChild);
    }
}
int condition(char oprator,int num1,int num2)
{
    switch(oprator)
    {
    case '*':
        return (num1 * num2);
    case '/':
        return (num1 / num2);
    case '+':
        return (num1 + num2);
    case '-':
        return (num1 - num2);
    }
    return -1;
}
int answer(BinTree *tree)
{
    int firstnumber =0 ;
    int secondnumber = 0;
    int temp;
    if(tree->leftChild==NULL && tree->rightChild==NULL)
    {
        temp = tree->data;
        return temp-48;
    }
    else
    {
        firstnumber = answer(tree->leftChild);
        secondnumber = answer(tree->rightChild);
        return condition((char)tree->data,firstnumber,secondnumber);
    }

}


#endif // FUNCTION_H_INCLUDED
