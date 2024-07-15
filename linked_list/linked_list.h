#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Create a linked list with the given values
struct ListNode* createLinkedList(int values[], int size);

// Free the memory allocated for the linked list
void freeLinkedList(struct ListNode* head);

// Print the linked list
void printLinkedList(struct ListNode* head);

// https://leetcode.com/explore/featured/card/top-interview-questions-easy/93/linked-list/553/

// Delete Node in a Linked List
// There is a singly-linked list head and we want to delete a node node in it.
//
// You are given the node to be deleted node. You will not be given access to the first node of head.
//
// All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.
//
// Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:
//
// The value of the given node should not exist in the linked list.
// The number of nodes in the linked list should decrease by one.
// All the values before node should be in the same order.
// All the values after node should be in the same order.
void deleteNode(struct ListNode* node);


// https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/603/

// Remove Nth Node From End of List
// Given the head of a linked list, remove the nth node from the end of the list and return its head.

struct ListNode* removeNthFromEnd(struct ListNode* head, int n);


// https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/560/

// Reverse Linked List
// Given the head of a singly linked list, reverse the list, and return the reversed list.
struct ListNode* reverseList(struct ListNode* head);

#endif // LINKED_LIST_H
