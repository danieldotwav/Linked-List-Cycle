#include <iostream>
#include <unordered_set>
#include "ListNode.h"
using namespace std;

bool hasCycle(ListNode* head);
ListNode* buildCyclicalList(const std::vector<int>& values, int cycleIndex);
void deleteList(ListNode* head);

int main() {
	cout << std::boolalpha; // set the boolalpha flag for cout

	// Test Case 1
	cout << "Input: head = [3, 2, 0, -4], pos = 1\nExpected Output: true\nActual Output: "
		<< hasCycle(buildCyclicalList({ 3, 2, 0, -4}, 1)) << "\n\n";

	// Test Case 2
	std::cout << "Input: head = [1, 2], pos = 0\nExpected Output: true\nActual Output: "
		<< hasCycle(buildCyclicalList({ 1, 2 }, 0)) << "\n\n";

	// Test Case 3
	std::cout << "Input: head = [1], pos = -1\nExpected Output: false\nActual Output: "
		<< hasCycle(buildCyclicalList({ 1 }, -1)) << "\n\n";

	// Test Case 4
	std::cout << "Input: head = [], pos = -1\nExpected Output: false\nActual Output: "
		<< hasCycle({}) << "\n\n";

	// Test Case 5
	std::cout << "Input: head = [0], pos = 1\nExpected Output: false\nActual Output: "
		<< hasCycle({}) << "\n\n";
	
	return 0;
}

bool hasCycle(ListNode* head) {
	// Edge Cases
	if (head == nullptr || head->next == nullptr) { return false; }

	// Containers
	unordered_set<ListNode*> nodeList;

	while (head != nullptr) {
		// The insert method returns a pair, with the second element of the pair indicating whether the insertion was successful
		bool result = (nodeList.insert(head)).second;

		// If false, the address is not unique, and the linked list contains a cycle
		if (!result) {
			return true;
		}

		// Get the next node
		head = head->next;
	}

	return false;
}

// To test our algorithm, we will construct a method that generates a cyclical linked list at the specified index
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