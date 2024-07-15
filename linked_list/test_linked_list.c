#include <stdio.h>
#include <assert.h>
#include "linked_list.h"

// Test deleteNode
void test_deleteNode() {
    printf("Test deleteNode\n");

    // Create a linked list with three nodes
    int values[] = {1, 2, 3};
    struct ListNode* head = createLinkedList(values, sizeof(values) / sizeof(values[0]));

    // Print the linked list
    printLinkedList(head);

    // Delete the second node
    deleteNode(head->next);

    // Verify the linked list after deletion
    assert(head->val == 1);
    assert(head->next->val == 3);
    assert(head->next->next == NULL);

    // Print the linked list
    printLinkedList(head);

    // Free the memory allocated for the linked list
    freeLinkedList(head);
}

void test_removeNthFromEnd() {
    printf("Test removeNthFromEnd\n");

    // Create a linked list with five nodes
    int values[] = {1, 2, 3, 4, 5};
    struct ListNode* head = createLinkedList(values, sizeof(values) / sizeof(values[0]));

    // Print the linked list
    printLinkedList(head);

    // Remove the second node from the end
    head = removeNthFromEnd(head, 2);

    // Verify the linked list after removal
    assert(head->val == 1);
    assert(head->next->val == 2);
    assert(head->next->next->val == 3);
    assert(head->next->next->next->val == 5);
    assert(head->next->next->next->next == NULL);

    // Print the linked list
    printLinkedList(head);

    // Free the memory allocated for the linked list
    freeLinkedList(head);
}

int main() {
    test_deleteNode();
    test_removeNthFromEnd();
    return 0;
}