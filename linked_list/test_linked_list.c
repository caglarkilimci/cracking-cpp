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

// Test createLinkedList
void test_createLinkedList() {
    printf("Test createLinkedList\n");

    // Create a linked list with three nodes
    int values[] = {1, 2, 3};
    struct ListNode* head = createLinkedList(values, sizeof(values) / sizeof(values[0]));

    // Verify the linked list
    assert(head->val == 1);
    assert(head->next->val == 2);
    assert(head->next->next->val == 3);
    assert(head->next->next->next == NULL);

    // Free the memory allocated for the linked list
    freeLinkedList(head);
}

// Test reverseList
void test_reverseList() {
    printf("Test reverseList\n");

    // Create a linked list with five nodes
    int values[] = {1, 2, 3, 4, 5};
    struct ListNode* head = createLinkedList(values, sizeof(values) / sizeof(values[0]));

    // Print the original linked list
    printf("Original linked list: ");
    printLinkedList(head);

    // Reverse the linked list
    head = reverseList(head);

    // Verify the reversed linked list
    assert(head->val == 5);
    assert(head->next->val == 4);
    assert(head->next->next->val == 3);
    assert(head->next->next->next->val == 2);
    assert(head->next->next->next->next->val == 1);
    assert(head->next->next->next->next->next == NULL);

    // Print the reversed linked list
    printf("Reversed linked list: ");
    printLinkedList(head);

    // Free the memory allocated for the linked list
    freeLinkedList(head);
}

void test_mergeTwoLists() {
    printf("Test mergeTwoLists\n");

    // Create two linked lists
    int values1[] = {1, 3, 5};
    struct ListNode* list1 = createLinkedList(values1, sizeof(values1) / sizeof(values1[0]));

    int values2[] = {2, 4, 6};
    struct ListNode* list2 = createLinkedList(values2, sizeof(values2) / sizeof(values2[0]));

    // Print the original linked lists
    printf("List 1: ");
    printLinkedList(list1);
    printf("List 2: ");
    printLinkedList(list2);

    // Merge the two linked lists
    struct ListNode* mergedList = mergeTwoLists(list1, list2);

    // Verify the merged linked list
    assert(mergedList->val == 1);
    assert(mergedList->next->val == 2);
    assert(mergedList->next->next->val == 3);
    assert(mergedList->next->next->next->val == 4);
    assert(mergedList->next->next->next->next->val == 5);
    assert(mergedList->next->next->next->next->next->val == 6);
    assert(mergedList->next->next->next->next->next->next == NULL);

    // Print the merged linked list
    printf("Merged list: ");
    printLinkedList(mergedList);

    // Free the memory allocated for the linked lists
    freeLinkedList(mergedList);
}

int main() {
    test_deleteNode();
    test_removeNthFromEnd();
    test_createLinkedList();
    test_reverseList();
    test_mergeTwoLists();
    return 0;
}
