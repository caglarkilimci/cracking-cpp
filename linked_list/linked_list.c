#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct ListNode* createLinkedList(int val1, int val2, int val3) {
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = val1;

    struct ListNode* second = malloc(sizeof(struct ListNode));
    second->val = val2;

    struct ListNode* third = malloc(sizeof(struct ListNode));
    third->val = val3;

    head->next = second;
    second->next = third;
    third->next = NULL;

    return head;
}

void freeLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* next = current->next;
        free(current);
        current = next;
    }
}


void printLinkedList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");

}

void deleteNode(struct ListNode* node) {
    struct ListNode* nextNode = node->next;
    node->val = nextNode->val;
    node->next = nextNode->next;
    free(nextNode);
}
