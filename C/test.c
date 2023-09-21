#include <stdio.h>

const int N = 20;
const int MAX = 100000;

typedef struct node
{
    int vex;
    int data;
    struct node* next;
}Node;

typedef struct
{
    Node* vexList[N];
    int n;
    int e;
}AdjGraph;

typedef struct
{
    int vex[N];
    int size;
}Stack;

void InitialStack(Stack* stack) {
    for (int i = 0; i < stack->size; i++) {
        stack->vex[i] = MAX;
    }
}

int Pop(Stack* stack) {
    int vex = stack->vex[stack->size - 1];
    stack->vex[stack->size - 1] = MAX;
    stack->size -= 1;
    return vex;
}

void Push(Stack* stack, int vex){
    stack->vex[stack->size] = vex;
    stack->size++;
}

int ipty(Stack* stack) {
    if (stack->size == 0) {
        return 1;
    }
    return 0;
}

void DFS(AdjGraph* adjGraph, int v) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    InitialStack(stack);
    int visited[adjGraph->n];
    for (int i = 0; i < adjGraph->n; i++) {
        visited[i] = 0;
    }
    Push(stack, v);
    visited[v] = 1;
    while(!ipty(stack)) {
        int currVex = Pop(stack);
        printf("%d,", currVex);

        Node* p = adjGraph->vexList[currVex];
        while(p) {
            int adjVex = p->vex;
            if (visited[adjVex] == 0) {
                Push(stack, adjVex);
                visited[adjVex] = 1;
            }
            p = p->next;
        }
    }
}

int isReachable(AdjGraph* adjGraph, int u, int v, int k, int* visited){
    if (k == 0 && u == v) {
        return 1;
    }
    visited[u] = 1;
    Node* p = adjGraph->vexList[u];
    while (p) {
        if (!visited[p->vex] && isReachable(adjGraph, p->vex, v, k - 1, visited)) {
            return 1;
        }
        p = p->next;
    }
    visited[u] = 0;
    return 0;
}

int HasPath(AdjGraph* adjGraph, int u, int v, int k) {
    if (k == 0 && u == k) {
        return 1;
    }
    int visited[N];
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }
    visited[u] = 1;
    Node* p = adjGraph->vexList[u];
    while(p) {
        if (isReachable(adjGraph, p->vex, v, k-1, visited)) {
            return 1;
        }
        p = p->next;
    }
    return 0;
}


int SearchVex(Node* node, int vex) {
    for (Node* p = node->next; p != NULL; p = p->next) {
        if (p->vex == vex) {
            return 1;
        }
    }
    return 0;
}

void CaculateDegrees(AdjGraph* adjGraph, int* Indegree) {
    for (int i = 0; i < adjGraph->n; i++) {
        for (int j = 0; j < adjGraph->n; j++) {
            Indegree[i] += SearchVex(adjGraph->vexList[j], i);
        }
    }
}

void AddToLast(Node* node, Node* sentinal) {
    Node* p;
    for (p = sentinal;  p->next != NULL; p = p->next);
    p->next = node;
}

void CreatAdjGraph(int** matrix, AdjGraph* adjGraph) {
    for (int i = 0; i < adjGraph->n; i++) {
        for (int j = 0; j < adjGraph->n; j++) {
            if (matrix[i][j] != MAX) {
                Node* node = (Node*)malloc(sizeof(Node));
                node->data = matrix[i][j];
                node->vex = j;
                node->next = NULL;
                AddToLast(node, adjGraph->vexList[i]);
            }
        }
    }
}

void PrintList(Node* node, int vex) {
    for (Node* p = node->next; p != NULL; p = p->next) {
        printf("%d->%d cost %d\n", vex, p->vex, p->data);
    }
}

void PrintAdjGraph(AdjGraph* adjGraph) {
    for (int i = 0; i < adjGraph->n; i++) {
        PrintList(adjGraph->vexList[i], i);
    }
}

void PrintMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != MAX) {
                printf("%d -> %d cost %d\n", i, j, matrix[i][j]);
            }
        }
    }
}

typedef struct BST
{
    int data;
    struct BST* lchild;
    struct BST* rchild;
}BSTNode;

void inOrderTravel(BSTNode* root) {
    if (root == NULL) {
        return;
    }
    printf(root->data);
    inOrderTravel(root->lchild);
    inOrderTravel(root->rchild);
}

void findNoLessThanX(BSTNode* root, int x) {
    if (root == NULL) {
        return;
    }
    if (root->data >= x) {
        printf("%d", root->data);
        inOrderTravel(root->rchild);
        findNoLessThanX(root->lchild, x);
    } else if (root->data < x) {
        findNoLessThanX(root->rchild, x);
    }
}

int* CountingSort(int* keys, int n) {
    int min = keys[0];
    int max = keys[0];
    //寻找最大和最小值，确定键值范围
    for (int i = 0; i < n; i++) {
        if (keys[i] > max) {
            max = keys[i];
        }
        if (keys[i] < min) {
            min = keys[i];
        }
    }
    int length = max - min;
    //创建计数数组，初始化，计算各键值出现次数
    int count[length];
    for (int i = 0; i < length; i++) {
        count[i] = 0;
    } 
    for (int i = 0; i < n; i++) {
        int index = keys[i] - min;
        count[index] += 1;
    }

    //计算各个键值之前的键值的出现次数
    for (int i = 1; i < length; i++) {
        count[i] += count[i - 1];
    }


    int sort[n];
    for (int i = 0; i < n; i++) {
        int index = keys[i] - min;
        sort[count[index]] = keys[i];
        count[index] += 1;
    }
    return sort;
}

int main(void) {
    return 0;
}