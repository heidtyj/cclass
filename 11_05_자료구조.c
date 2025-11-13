#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Stack {
    Node* arr[100];
    int top;
} Stack;

void initStack(Stack* s);
int isEmpty(Stack* s);
void push(Stack* s, Node* node);
Node* pop(Stack* s);
Node* createNode(int data);
Node* findNode(Node* nodes[], int nodeCount, int data);
Node* createTree(Node* nodes[], int nodeCount);     
void preorder(Node* root);
void inorder(Node* root);
void postorder(Node* root);
void inorderIterative(Node* root);

int main() {
    int n;
    printf("노드 수 입력: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("노드 수가 0 이하입니다.\n");
        return 0;
    }
    Node* nodes[100] = {NULL};
    Node* root = createTree(nodes, n);
    int choice;
    printf("\n순회 방법 선택 1:전위  2:중위(재귀)  3:후위  4:중위(반복): ");
    scanf("%d", &choice);
    printf("\n순회 결과: ");
    switch (choice) {
        case 1: preorder(root); break;
        case 2: inorder(root); break;
        case 3: postorder(root); break;
        case 4: inorderIterative(root); break;
        default: printf("retry\n"); break;
    }
    printf("\n");
    return 0;
}


void initStack(Stack* s) {
    s->top = -1; 
}

int isEmpty(Stack* s) {
    return s->top == -1; 
}

void push(Stack* s, Node* node) {
    s->arr[++s->top] = node; 
}

Node* pop(Stack* s) {
    return s->arr[s->top--]; 
}

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* findNode(Node* nodes[], int nodeCount, int data) {
    for (int i = 0; i < nodeCount; i++) {
        if (nodes[i] && nodes[i]->data == data)
            return nodes[i];
    }
    return NULL;
}

Node* createTree(Node* nodes[], int nodeCount) {
    int rootData;
    printf("루트 노드 data 입력: ");
    scanf("%d", &rootData);
    Node* root = createNode(rootData);
    nodes[0] = root;
    for (int i = 1; i < nodeCount; i++) {
        int data, parentData;
        char direction;
        printf("\n삽입할 노드 data: ");
        scanf("%d", &data);
        printf("부모 노드 data: ");
        scanf("%d", &parentData);
        printf("왼쪽(L) 또는 오른쪽(R)? ");
        scanf(" %c", &direction);
        Node* parent = findNode(nodes, i, parentData);
        if (!parent) {
            printf("부모 노드 %d 없음 다시 시도.\n", parentData);
            i--;
            continue;
        }
        if (direction == 'L' || direction == 'l') {
            if (parent->left) {
                printf("이미 왼쪽 자식 존재\n");
                i--;
                continue;
            }
            parent->left = createNode(data);
            nodes[i] = parent->left;
        } 
        else if (direction == 'R' || direction == 'r') {
            if (parent->right) {
                printf("이미 오른쪽 자식 존재\n");
                i--;
                continue;
            }
            parent->right = createNode(data);
            nodes[i] = parent->right;
        } 
        else {
            printf("입력 오류: L 또는 R로 입력\n");
            i--;
        }
    }

    return root;
}

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void inorderIterative(Node* root) {
    Stack s;
    initStack(&s);
    Node* current = root;
    while (current != NULL || !isEmpty(&s)) {
        while (current != NULL) {
            push(&s, current);
            current = current->left;
        }
        current = pop(&s);
        printf("%d ", current->data);
        current = current->right;
    }
}
