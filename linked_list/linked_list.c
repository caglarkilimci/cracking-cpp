#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct ListNode* createLinkedList(int values[], int size) {
    struct ListNode* head = NULL;
    struct ListNode* current = NULL;
    for (int i=0; i<size; i++) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = values[i];
        node->next = NULL;
        if (head == NULL) {
            head = node;
            current = node;
        } else {
            current->next = node;
            current = node;
        }
    }
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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    struct ListNode* fastNode = head;
    for (int i=0; i<n; i++) {
        fastNode = fastNode->next;
    }
    
    if (fastNode == NULL) {
        // Need to remove head
        return head->next;
    }
    
    // We need to move once more to delete the next node
    fastNode = fastNode->next;
    
    struct ListNode* processing = head;
    while (fastNode != NULL) {
        processing = processing->next;
        fastNode = fastNode->next;
    }
    
    // We need to delete next node of the processing node
    processing->next = processing->next->next;
    
    return head;       
}

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* reversedList = head;
    head = head->next;
    reversedList->next = NULL;
    
    struct ListNode* temp = NULL;
    
    while (head != NULL) {
        temp = (head->next) ? head->next : NULL;
        head->next = reversedList;
        reversedList = head;
        head = (temp) ? temp : NULL;
    }
    
    return reversedList;
}

