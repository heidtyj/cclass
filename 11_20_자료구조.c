#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    struct Node* par;
    int data;
    struct Node* left;
    struct Node* right;
}NODE;

void insert(NODE** root, int n);
void inorder(NODE* root);
NODE* delete(NODE** root, NODE* now, int n);
NODE* create(int n);
NODE* search(NODE* root, int n);
NODE* findMin(NODE* root);

int main() {
    int n, num, i;
    NODE* root = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        insert(&root, num);
    }
    inorder(root);
    printf("\n");
    int data;
    scanf("%d", &data);
    NODE* m = search(root, data);
    printf("%d\n", m->data);
    return 0;
}

NODE* create(int n) {
    NODE* p = (NODE*)malloc(sizeof(NODE));
    p->data = n;
    p->left = NULL;
    p->right = NULL;
    p->par = NULL;
    return p;
}

void insert(NODE** root, int n) {
    NODE* p = create(n);
    NODE* parent = NULL;
    NODE* cur = *root;
    if (*root == NULL) {
        *root = p;
        return;
    }
    while (cur != NULL) {
        parent = cur;
        if (n < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }
    p->par = parent; 
    if (n < parent->data)
        parent->left = p;
    else
        parent->right = p;
}

NODE* search_loot(NODE* root, int n){
    while(root != NULL){
        if (root == NULL || root->data == n)
            return root;
        if (n < root->data)
            root = root->left;
        else
            root = root->right;
    }
}

NODE* search(NODE* root, int n) {
    if (root == NULL || root->data == n)
        return root;
    if (n < root->data)
        return search(root->left, n);
    else
        return search(root->right, n);
}

NODE* delete(NODE** root, NODE* now, int n) {
    if (now == NULL)
        return;
    if (n < now->data) {
        delete(root, now->left, n);
    }
    else if (n > now->data) {
        delete(root, now->right, n);
    }
    else {
        if (now->left == NULL && now->right == NULL) {
            if (now->par != NULL) {
                if (now->par->left == now)
                    now->par->left = NULL;
                else if (now->par->right == now)
                    now->par->right = NULL;
            }
            else {
                *root = NULL;
            }
            free(now);
        }
        else if (now->left == NULL) {
            NODE* temp = now->right;
            temp->par = now->par;
            if (now->par != NULL) {
                if (now->par->left == now)
                    now->par->left = temp;
                else if (now->par->right == now)
                    now->par->right = temp;
            }
            else {
                *root = temp;
            }
            free(now);
        }
        else if (now->right == NULL) {
            NODE* temp = now->left;
            temp->par = now->par;
            if (now->par != NULL) {
                if (now->par->left == now)
                    now->par->left = temp;
                else if (now->par->right == now)
                    now->par->right = temp;
            }
            else {
                *root = temp;
            }
            free(now);
        }
        else {
            NODE* temp = findMin(now->right);
            now->data = temp->data;
            delete(root, now->right, temp->data);
        }
    }
	return root;
}

NODE* findMin(NODE* root) {
	while (root->left != NULL)
		root = root->left;
	return root;
}

void inorder(NODE* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int height(NODE* root) {
    if (root == NULL)
        return -1; 
    int lh = height(root->left);
    int rh = height(root->right);
    if (lh > rh) {
        return lh + 1;
    } 
    else {
        return rh + 1;  
    }
}

NODE* LCA(NODE* root, int A, int B) {
    while (root != NULL) {
        if (A < root->data && B < root->data) {
            root = root->left;
        }
        else if (A > root->data && B > root->data) {
            root = root->right;
        }
        else {
            return root;
        }
    }
    return NULL;
}
