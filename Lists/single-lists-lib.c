node *rotateSingleList(node *head, int rotations) {

}
node *mergeSingleSortedLists(node *list1, node *list2)
node *mergeTwoSortedLists(node *list1, node *list2) {

}
node *rotateList(node *head, int rotations) {
    struct ListNode *cur = head;
    int n = countNodes(cur);
    cur = head;
    if (k == 0 || n == 0 || k%n == 0 || !head || !head->next) return head;
    k %= n;
    for (int i = 1; i != (n-k); ++i) {
        cur = cur->next;
    }
    struct ListNode *rot_cur = cur->next;
    cur->next = NULL; cur = rot_cur;
    while (rot_cur->next != NULL) rot_cur = rot_cur->next;
    rot_cur->next = head;
    return cur;
}
bool hasCycle(node *head) {
    struct ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            return true;
    }
    return false;
}
bool valueExists(node *head, int val) {

}
node *getCycleStart(node *head) {

}
void *breakCycle(node *head) {

}
node *reverseList(node *head) {
    if (!head || !head->next) return head;
    struct ListNode *last = NULL, *cur = head, *nxt = head->next;

    while (nxt != NULL) {
        cur->next = last;
        last = cur;
        cur = nxt;
        nxt = nxt->next;
    }
    cur->next = last;
    return cur;
}
int countNodes(node *head) {
    int n = 0;
    while (head != NULL) {
        head = head->next;
        n++;
    }
    return n;
}
node *sortList(node *head, bool order = true) {
    if (!head || !head->next) return head;
    struct ListNode *newHead = head, *prev = head->next;
    head = head->next;
    while (head != NULL) {
        
        if (head->val <= newHead->val) {
            struct ListNode *cur = head->next;
            head->next = newHead;
            newHead->next = cur;
            newHead = head;
            head = cur;
        } else {
            struct ListNode *cur2 = head->next;
            while (cur2 != NULL) {
                if (cur2->val <= head->val) {
                    cur2 = cur2->next;
                }
                if (cur2->next == NULL) {
                    cur2->next = head;
                    head->next = NULL;
                } else {
                    struct ListNode *temp = cur2->next;
                    cur2->next = head;
                    head = head->next;
                    prev->next = temp;
                }
            }
            prev = head;
        }
    }
    return newHead;
}
node *initList(int val) {

}
void addNode(node *head) {

}
void deleteNode(node *head, int val) {

}
void destroyList(node *head);
void swapNodes(node *head, int val1, int val2);
node *removeDuplicatesFromSortedList(node *head);
node *removeAllDuplicatesFromSortedList(node *head);
node *convertSortedListToBinaryTree(node *head);
// RETURN MIDDLE NODE OF THE LIST
node *getMiddleNode(node *head);