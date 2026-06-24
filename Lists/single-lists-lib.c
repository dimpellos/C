node *rotateSingleList(node *head, int rotations) {

}
node *mergeSingleSortedLists(node *list1, node *list2) {
    
}
node *mergeTwoSortedLists(node *list1, node *list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    struct ListNode *newList = NULL, *curr = NULL;
    // new Root
    if (list1->val < list2->val) {
        newList = curr = list1;
        list1 = list1->next;
    } else {
        newList = curr = list2;
        list2 = list2->next;
    }

    while (list1 != NULL || list2 != NULL) {
        if (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;                
            }
        } else if (list1 == NULL) {
            curr->next = list2;
            break;
        } else if (list2 == NULL) {
            curr->next = list1;
            break;
        }
        curr = curr->next;
    }
    return newList;
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
node *removeDuplicatesFromSortedList(node *head) {
        if (head == NULL || head->next == NULL)
        return head;
    
    while (head->next != NULL && head->next->val == head->val) {
        struct ListNode *cur2 = head->next;
        head->next = cur2->next;
        free(cur2);    
    }
    if (head->next == NULL) return head;

    struct ListNode *cur = head->next->next, *prev = head->next;
    while (cur != NULL) {
        if (prev->val == cur->val) {
            prev->next = cur->next;
            free(cur);     
        } else {
            prev = cur;
        }
        cur = prev->next;
    }
    return head;
}
node *removeAllDuplicatesFromSortedList(node *head);
node *convertSortedListToBinaryTree(node *head);
// RETURN MIDDLE NODE OF THE LIST
node *getMiddleNode(node *head) {
    if (!head || !head->next) return head;
    struct ListNode *slow = head->next, *fast = head->next->next;
    while (fast != NULL && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}