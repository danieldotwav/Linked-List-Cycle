## Introduction

This C++ project implements a cycle detection algorithm for linked lists. The main focus is to determine if a given linked list contains a cycle, which occurs when a node's next pointer points to a previous node in the list. This is particularly useful in various computer science and data structure applications to avoid infinite loops and optimize memory usage.

## Algorithms

### **1. Cycle Detection in Linked List**

#### Logic

- The algorithm iterates through the linked list, using a hash set (`std::unordered_set`) to store and track the addresses of visited nodes. If a node is revisited (i.e., its address is already in the set), a cycle is detected.

#### Complexity Analysis

- **Time Complexity:** O(n), where n is the number of nodes in the linked list. Each node is visited at most once.
- **Space Complexity:** O(n), as additional space is required for the hash set storing the node addresses.

### **2. Linked List Construction**

#### Logic

- Constructs a linked list from a vector of values and introduces a cycle at a specified index.

#### Complexity Analysis

- **Time Complexity:** O(n), primarily due to the list construction.
- **Space Complexity:** O(n), for storing the created nodes.

### Code Snippet

```cpp
bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) { return false; }
    std::unordered_set<ListNode*> nodeList;
    while (head != nullptr) {
        bool result = (nodeList.insert(head)).second;
        if (!result) { return true; }
        head = head->next;
    }
    return false;
}

ListNode* buildCyclicalList(const std::vector<int>& values, int cycleIndex) {
	if (values.empty()) { return nullptr; }
	
	ListNode dummy(0);
	ListNode* current = &dummy;
	std::vector<ListNode*> nodes;

	for (int element : values) {
		current->next = new ListNode(element);
		current = current->next;
		nodes.push_back(current);
	}

	// Create a cycle by linking the tail to the node specified by the cycleIndex
	if (cycleIndex >= 0 && cycleIndex < values.size()) {
		current->next = nodes[cycleIndex];
	}

	return dummy.next;
}

void deleteList(ListNode* head) {
	while (head != nullptr) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}
```