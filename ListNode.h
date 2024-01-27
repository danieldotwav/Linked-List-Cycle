#ifndef LISTNODE_H
#define LISTNODE_H

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

#endif