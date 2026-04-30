#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int size) {
    if (size <= 0) return NULL;
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < size; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void freeList(struct Node* head) {
    while (head) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, m;
    
    if (scanf("%d", &n) != 1) return 0;
    struct Node* head1 = createList(n);
    
    if (scanf("%d", &m) != 1) {
        freeList(head1);
        return 0;
    }
    struct Node* head2 = createList(m);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    if (n > m) {
        for (int i = 0; i < n - m; i++) ptr1 = ptr1->next;
    } else if (m > n) {
        for (int i = 0; i < m - n; i++) ptr2 = ptr2->next;
    }

    int found = 0;
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data) {
            printf("%d\n", ptr1->data);
            found = 1;
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    if (!found) {
        printf("No Intersection\n");
    }

    freeList(head1);
    freeList(head2);

    return 0;
}