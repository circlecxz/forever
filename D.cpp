/*
 题解：
 插入节点建树
 广度遍历搜索树，同时记录子节点的父亲节点值
 */

#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

vector<int> father;
struct Node {
    int data;
    Node *left, *right;
};

int n;
void insert(Node* &root, int data) {
    if(root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        root->data = data;
        root->left = root->right = NULL;
        return;
    }
    if(data < root->data) insert(root->left, data);
    else insert(root->right, data);
}

void BFS(Node* root) {
    queue<Node*> q;
    q.push(root);
    father[root->data] = 0;
    while(!q.empty()) {
        Node* now = q.front();
        q.pop();
        if(now->left) {
            father[now->left->data] = now->data;
            q.push(now->left);
        }
        if(now->right) {
            father[now->right->data] = now->data;
            q.push(now->right);
        }
    }
}

void freeTree(Node* root) {
    if(root == NULL) return;
    Node* lchild = root->left;
    Node* rchild = root->right;
    free(root);
    freeTree(lchild);
    freeTree(rchild);
}

int main() {
    int data;
    Node* root = NULL;
    scanf("%d", &n);
    father.resize(n + 1);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &data);
        insert(root, data);
    }
    BFS(root);
    for(int i = 1; i <= n; ++i) {
        printf("%d", father[i]);
        if(i < n) printf(" ");
        else printf("\n");
    }
    freeTree(root);
    return 0;
}

