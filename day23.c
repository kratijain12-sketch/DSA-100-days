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

struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1) tail->next = l1;
    if (l2) tail->next = l2;

    return dummy.next;
}

void printAndFreeList(struct Node* head) {
    struct Node* temp;
    while (head) {
        printf("%d%s", head->data, (head->next == NULL) ? "" : " ");
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("\n");
}

int main() {
    int n, m;
    
    if (scanf("%d", &n) != 1) return 0;
    struct Node* list1 = createList(n);
    
    if (scanf("%d", &m) != 1) {
        printAndFreeList(list1);
        return 0;
    }
    struct Node* list2 = createList(m);

    struct Node* mergedList = mergeLists(list1, list2);
    
    printAndFreeList(mergedList);

    return 0;
}