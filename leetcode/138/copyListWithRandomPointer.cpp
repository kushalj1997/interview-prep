// Copy List With Random Pointer
// Leetcode 138
// Kushal Jaligama

#include <iostream>
#include <vector>

// Definition for a Node.
class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node() {}

  Node(int _val, Node* _next, Node* _random) {
    val = _val;
    next = _next;
    random = _random;
  }

  void print() {
    std::cout << this << " val: " << val << " next: " << next
              << " random: " << random << std::endl;
  }
};

class Solution {
 public:
  //     Node* recurseAndCopy(Node* n) {
  //         // This function will recurse as far down as possible and create
  //         copies of the node passed in

  //     }

  Node* copyRandomList(Node* head) {
    // each node contains a random ptr that can point to any node in list or
    // null return a deep copy of the list

    // iterator in first linked list
    Node* og_it = head;

    if (!og_it) {
      return nullptr;
    }

    // head of the new linked list
    Node* new_head = new Node(og_it->val, nullptr, nullptr);

    // iterator in the new linked list
    Node* new_it = new_head;
    size_t num_nodes = 0;

    // Copy over all the nodes
    while (new_it) {
      // assign values for current node
      new_it->val = og_it->val;

      // copy over the next nodes only if they exist
      if (og_it->next) {
        new_it->next = new Node(og_it->next->val, nullptr, nullptr);
      }

      // move to the next nodes in each linked list
      new_it = new_it->next;
      og_it = og_it->next;

      // keep track of how many nodes we're creating
      num_nodes++;
    }

    // Update the pointers to all of the random nodes in the linked list
    // has to be after creation of list so we can assign to pointers that have
    // been created
    og_it = head;
    new_it = new_head;

    while (new_it) {
      // only assign a random if one exists
      if (og_it->random) {
        // count how many nodes to iterate to get the random ptr
        size_t counter = 0;
        Node* old_rand = head;
        while (old_rand != og_it->random) {
          counter++;
          old_rand = old_rand->next;
        }

        // find the random node to point to in new list
        Node* new_rand = new_head;
        for (size_t i = 0; i < counter; ++i) {
          new_rand = new_rand->next;
        }

        // assign the random ptr of the current node in the copied list
        new_it->random = new_rand;
      }

      new_it = new_it->next;
      og_it = og_it->next;
    }

    return new_head;
  }
};

Node* buildLinkedListFromVector(std::vector<int>& nums) {
  Node* head = new Node(nums[0], nullptr, nullptr);
  Node* it = head;
  for (size_t i = 1; i < nums.size(); ++i) {
    Node* next = new Node(nums[i], nullptr, nullptr);
    if (i == 1) {
      next->random = next;
    }
    it->next = next;
    it = it->next;
  }

  return head;
}

void printLinkedList(Node* head) {
  std::cout << "Linked List" << std::endl;

  int count = 0;
  Node* it = head;
  while (it) {
    std::cout << "Node " << count << ": ";
    it->print();
    it = it->next;
    count++;
  }
}

int main(int argc, char** argv) {
  Solution s;

  // create a linked list using the node class and a vector of values
  std::vector<int> nums = {1, 2};
  Node* head = buildLinkedListFromVector(nums);
  printLinkedList(head);

  Node* new_head = s.copyRandomList(head);
  Node* new_it = new_head;
  printLinkedList(new_head);

  return 0;
}
