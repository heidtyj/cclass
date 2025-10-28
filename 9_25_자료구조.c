#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createList(int n);
void findPosition(Node* head, int value);

int main() {
    int n, num;
    printf("노드 개수 입력: ");
    scanf("%d", &n);
    Node *head = createList(n);
    printf("찾을 정수 입력: ");
    scanf("%d", &num);
    findPosition(head, num);
    return 0;
}

Node* createList(int n) {
    Node *head = NULL, *temp = NULL, *newNode = NULL;
    for (int i = 0; i < n; i++) {
        newNode = (Node*)malloc(sizeof(Node));
        printf("%d번째 노드 데이터 입력: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;
        temp = newNode;
    }
    return head;
}

void findPosition(Node* head, int value) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == value) {
            printf("%d는 %d번째 노드에 있습니다.\n", value, pos);
            return;
        }
        head = head->next;
        pos++;
    }
    printf("%d는 리스트에 없습니다.\n", value);
}
//2
typedef struct Node {
    char data[100];
    struct Node *next;
} Node;

Node* createList(int n);
void printList(Node* head);

int main() {
    int n;
    printf("노드 개수 입력: ");
    scanf("%d", &n);
    Node *head = createList(n);
    printList(head);
    return 0;
}

Node* createList(int n) {
    Node *head = NULL, *temp = NULL, *newNode = NULL;
    for (int i = 0; i < n; i++) {
        newNode = (Node*)malloc(sizeof(Node));
        printf("%d번째 문자열 입력: ", i + 1);
        scanf("%s", newNode->data);
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;
        temp = newNode;
    }
    return head;
}

void printList(Node* head) {
    printf("전체 문자열: ");
    while (head != NULL) {
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}

//3
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createList(int n);
int getLength(Node* head);
Node* insertNode(Node* head, int mode, int value);
void printList(Node* head);

int main() {
    int n, mode, val;
    printf("노드 개수 입력: ");
    scanf("%d", &n);
    Node *head = createList(n);
    printList(head);
    printf("1: 처음, 2: 중간, 3: 마지막 삽입 중 선택: ");
    scanf("%d", &mode);
    printf("삽입할 데이터 입력: ");
    scanf("%d", &val);
    head = insertNode(head, mode, val);
    printList(head);
    return 0;
}

Node* createList(int n) {
    Node *head = NULL, *temp = NULL, *newNode = NULL;
    for (int i = 0; i < n; i++) {
        newNode = (Node*)malloc(sizeof(Node));
        printf("%d번째 데이터 입력: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;
        temp = newNode;
    }
    return head;
}

int getLength(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node* insertNode(Node* head, int mode, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    int len = getLength(head);
    if (mode == 1) {
        newNode->next = head;
        head = newNode;
    }
    else if (mode == 2) {
        int mid = len / 2;
        Node *temp = head;
        for (int i = 0; i < mid - 1; i++)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else if (mode == 3) {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    else {
        printf("잘못된 입력입니다.\n");
    }
    return head;
}

void printList(Node* head) {
    printf("현재 리스트: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

//4
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createList(int n);
int getLength(Node* head);
Node* deleteNode(Node* head, int pos);
void printList(Node* head);

int main() {
    int n, pos;
    printf("노드 개수 입력: ");
    scanf("%d", &n);
    Node *head = createList(n);
    printList(head);
    printf("삭제할 노드 위치 입력: ");
    scanf("%d", &pos);
    head = deleteNode(head, pos);
    printList(head);

    return 0;
}

Node* createList(int n) {
    Node *head = NULL, *temp = NULL, *newNode = NULL;
    for (int i = 0; i < n; i++) {
        newNode = (Node*)malloc(sizeof(Node));
        printf("%d번째 데이터 입력: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;
        temp = newNode;
    }
    return head;
}

int getLength(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node* deleteNode(Node* head, int pos) {
    int len = getLength(head);
    if (pos < 1 || pos > len) {
        printf("에러: 유효하지 않은 위치입니다.\n");
        return head;
    }
    Node *temp = head, *prev = NULL;
    if (pos == 1) {
        head = head->next;
        free(temp);
    } else {
        for (int i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }

    return head;
}

void printList(Node* head) {
    printf("현재 리스트: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

//5
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createList(int n);
void printReverse(Node* head);

int main() {
    int n;
    printf("노드 개수 입력: ");
    scanf("%d", &n);
    Node *head = createList(n);
    printf("역순 출력: ");
    printReverse(head);
    printf("\n");
    return 0;
}

Node* createList(int n) {
    Node *head = NULL, *temp = NULL, *newNode = NULL;
    for (int i = 0; i < n; i++) {
        newNode = (Node*)malloc(sizeof(Node));
        printf("%d번째 데이터 입력: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;
        temp = newNode;
    }
    return head;
}

void printReverse(Node* head) {
    if (head == NULL) return;
    printReverse(head->next);
    printf("%d ", head->data);
}

//6
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createList(int n);
Node* reverseList(Node* head);
void printList(Node* head);

int main() {
    int n;
    printf("노드 개수 입력: ");
    scanf("%d", &n);
    Node *head = createList(n);
    head = reverseList(head);
    printf("역순으로 변환된 리스트: ");
    printList(head);
    return 0;
}

Node* createList(int n) {
    Node *head = NULL, *temp = NULL, *newNode = NULL;
    for (int i = 0; i < n; i++) {
        newNode = (Node*)malloc(sizeof(Node));
        printf("%d번째 데이터 입력: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;
        temp = newNode;
    }
    return head;
}

Node* reverseList(Node* head) {
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

