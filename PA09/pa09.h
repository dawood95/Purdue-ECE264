#ifndef PA09_H
#define PA09_H

typedef struct huffnode {
  int value; 
  struct huffnode *left;
  struct huffnode *right;
} Node;

typedef struct stack {
  struct stack * next;
  struct huffnode * node;
} Stack;

Node * createTree_ch(FILE* );
Node * createTree_bit(FILE* );
Node * copyTree(Node*  );
Node * newTreeNode(char );

Stack * pushStack(Stack* , char );
Stack * popStackAndProcess(Stack* );
Stack * newStackNode(char );
Stack *deleteStackTopNode(Stack* );
Stack * cleanBuffer(Stack* );

int getStackHeight(Stack* );
void deleteStack(Stack* );
void postOrderPrint(Node* ,FILE* );
void deleteTree(Node* );

#endif

