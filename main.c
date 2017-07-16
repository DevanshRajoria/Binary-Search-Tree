#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct bstNode{
    int data;
    struct bstNode* left;
    struct bstNode* right;
};
typedef struct bstNode* node;

node createNode(int data){
    node newnode = (node)malloc(sizeof(struct bstNode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node addNode(node Node,int element){
    if(Node == NULL){
        Node = createNode(element);
        return Node;
    }
    else if(element <= Node->data){
        Node->left =  addNode(Node->left,element);
    }
    else{
        Node->right = addNode(Node->right,element);
    }
    return Node;
}


bool searchNode(node Node,int element){
    if(Node == NULL){
        return false;
    }
    if(Node->data == element){
        return true;
    }
    else if(element <= Node->data){
        return searchNode(Node->left,element);
    }
    else{
        return searchNode(Node->right,element);
    }
}

int maxElement(node Node){
    if(Node->right == NULL){
        return Node->data;
    }
    int max = maxElement(Node->right);
    return max;
}

int minElement(node Node){
    if(Node->left == NULL){
        return Node->data;
    }
    int min = minElement(Node->left);
    return min;
}

int height(node Node){
    if(Node == NULL){
        return -1;
    }
    int h1 = height(Node->left);
    int h2 = height(Node->right);
    if(h1<h2){
        return h2+1;
    }
    else{
        return h1+1;
    }
}

void preOrder(node Node){
    if(Node == NULL){
        return;
    }
    printf("%d ",Node->data);
    preOrder(Node->left);
    preOrder(Node->right);
    return;
}

void postOrder(node Node){
    if(Node == NULL){
        return;
    }
    postOrder(Node->left);
    postOrder(Node->right);
    printf("%d ",Node->data);
    return;
}

void inOrder(node Node){
    if(Node == NULL){
        return;
    }
    inOrder(Node->left);
    printf("%d ",Node->data);
    inOrder(Node->right);
    return;
}
bool isBST1(node Node,int minval,int maxval);

bool isBST(node Node){
    return isBST1(Node,INT_MIN,INT_MAX);
}
bool isBST1(node Node,int minval,int maxval){
    if(Node == NULL){
        return true;
    }
    if(maxval>Node->data && minval<Node->data && isBST1(Node->left,minval,Node->data) && isBST1(Node->right,Node->data,maxval)){
        return true;
    }
    return false;
}

node delNode(node Node,int data){
    if(Node == NULL){
        return;
    }
    if(Node->left->data==data){
        node temp = Node->left;
        if(temp->left==NULL && temp->right!=NULL){
            Node->left = temp->right;
        }
        else if(temp->right==NULL && temp->left!=NULL){
            Node->left = temp->left;
        }
        else if(temp->right==NULL && temp->left==NULL){
            Node->left = NULL;
        }
        else{
            int n = temp->right->data;
            temp->data = n;
            Node->left = delNode(temp,n);
        }
        //free(temp);
        return Node;
    }
    else if(Node->right->data==data){
        node temp = Node->right;
        if(temp->right==NULL && temp->left!=NULL){
            Node->right = temp->left;
        }
        else if(temp->left == NULL&&temp->right!=NULL){
            Node->right = temp->right;
        }
        else if(temp->right==NULL && temp->left==NULL){
            Node->right = NULL;
        }
        else{
            int n = temp->right->data;
            temp->data = n;
            Node->right = delNode(temp,n);
        }
        //free(temp);
        return Node;
    }

    if(data <= Node->data){
        delNode(Node->left,data);
    }
    else if(data > Node->data){
        delNode(Node->right,data);
    }
    return Node;
}

int NoOfNodes(node Node){
    if(Node==NULL){
        return 0;
    }
    int n1 = NoOfNodes(Node->left);
    int n2 = NoOfNodes(Node->right);
    return n1+n2+1;
}

void displayTree(node Node){
    if(Node == NULL){
        return;
    }
    if(Node->left == NULL && Node->right == NULL){
        printf("NULL<-%d->NULL\n",Node->data);
    }
    else if(Node->left == NULL && Node->right != NULL){
        printf("NULL<-%d->%d\n",Node->data,Node->right->data);
    }
    else if(Node->left != NULL && Node->right == NULL){
        printf("%d<-%d->NULL\n",Node->left->data,Node->data);
    }
    else{
        printf("%d<-%d->%d\n",Node->left->data,Node->data,Node->right->data);
    }
    displayTree(Node->left);
    displayTree(Node->right);
}

void maxbw2nodes(node Node,int x,int y,int* temp);

int main()
{
    node root = NULL;
    /*
    root = addNode(root,5);
    root = addNode(root,2);
    root = addNode(root,9);
    root = addNode(root,1);
    root = addNode(root,7);
    root = addNode(root,4);
    root = addNode(root,15);
    root = addNode(root,11);
    displayTree(root);

    printf("\nNo of Nodes : %d",NoOfNodes(root));

    printf("\n");
    bool x = searchNode(root,10);
    if(x==true){
        printf("Found");
    }
    else{
        printf("Not Found");
    }

    printf("\nMaximum Element : %d\n ",maxElement(root));
    printf("\nMinimum Element : %d\n ",minElement(root));

    printf("\nHeight of the tree is : %d",height(root));
    printf("\nPreOrder Traversal :");
    preOrder(root);
    printf("\nPostOrder Traversal :");
    postOrder(root);
    printf("\nInOrder Traversal :");
    inOrder(root);
    printf("\n");
    bool retval = isBST(root);
    if(retval == true){
        printf("YES");
    }
    else{
        printf("NO");
    }
    printf("\n");
    root = delNode(root,1);
    displayTree(root);printf("\n");
    */

    root = addNode(root,5);
    root = addNode(root,7);
    root = addNode(root,3);
    root = addNode(root,1);
    root = addNode(root,4);
    root = addNode(root,6);
    root = addNode(root,8);
    displayTree(root);
    int a = 1;
    int b = 3;
    if(a>b){
        int temp = a;
        a = b;
        b = temp;
    }
    int temp;
    temp = 0;
    maxbw2nodes(root,a,b,&temp);

    return 0;
}

void maxbw2nodes(node Node,int x,int y,int* temp){
    printf("%d ",*temp);
    if(Node == NULL){
        return;
    }
    if(x == Node->data){
        *temp = x;
    }
    else if(y != Node->data){
        if(*temp > Node->data){
            *temp = *temp;
        }
        else if(*temp <= Node->data){
            *temp = Node->data;
        }
    }

    if(Node->data == y){
        if(*temp > y){
            printf("max is:%d\n",*temp);
        }
        else{
            printf("max is:%d\n",y);
        }
        return;
    }
    maxbw2nodes(Node->left,x,y,temp);
    maxbw2nodes(Node->right,x,y,temp);
    return;
}
