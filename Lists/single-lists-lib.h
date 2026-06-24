 

struct node typedef {
int val;
struct node *next;
} node;

node *mergeTwoSortedLists(node *list1, node *list2);
node *rotateList(node *head, int rotations);
bool hasCycle(node *head);
bool valueExists(node *head, int val);
node *getCycleStart(node *head);
void *breakCycle(node *head);
node *reverseList(node *head);
int countNodes(node *head);
node *sortList(node *head, bool order = true);
node *initList(int val);
void addNode(node *head);
void deleteNode(node *head, int val);
void destroyList(node *head);
void swapNodes(node *head, int val1, int val2);
node *removeDuplicatesFromSortedList(node *head);
node *removeAllDuplicatesFromSortedList(node *head);
node *convertSortedListToBinaryTree(node *head);
// RETURN MIDDLE NODE OF THE LIST
node *getMiddleNode(node *head);

/*

  ------------------ REODER LIST ----------------------------
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
*/
void *reorderList(node *head);
