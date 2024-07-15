#include <stdio.h>
#include <assert.h>
#include "linked_list.h"

// Test deleteNode
void test_deleteNode() {
    printf("Test deleteNode\n");

    // Create a linked list with three nodes
    struct ListNode* head = createLinkedList(1, 2, 3);

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

int main() {
    test_deleteNode();
    return 0;
}