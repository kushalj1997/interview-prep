#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Takes in a root node, and a tree / subtree
// Breaks the tree into left and right subtrees and assigns to the root node
// If the passed in subtree is empty, then there are no more nodes to assign
//

TreeNode* create_node(int val) {
  TreeNode* t = new TreeNode(val);
  return t;
}

void find_max_helper(TreeNode* root, vector<int> nums) {
  // Base case:
  if (nums.empty()) {
    return;
  }
  root = create_node(root, )
      // Find the max node in the array and then construct a tree with that as
      // its root, and call find_max_helper on the left and right subtrees
      auto it = max_element(std::begin(nums), std::end(nums));
  size_t max_index = it - nums.begin();
  find_max_helper(root->left,
                  vector<int>(nums.begin(), nums.begin() + max_index));
  find_max_helper(root->right,
                  vector<int>(nums.begin() + max_index, nums.end()));
}

void printTree_helper(TreeNode* node, int level) {
  // Print a tree like this:
  //   p
  //  l r
  // a b c

  // For now:
  cout << "Level: " << level << " Root: " << node->val
       << " Left: " << node->left->val << " Right: " << node->right->val
       << "\n";
}

void printTree(TreeNode* tree) {}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
  TreeNode* root;
  find_max_helper(root, nums);
  printTree_helper(root, 0);

  return root;
}

int main(int argc, char** argv) {
  std::vector<int> sample;
  sample.push_back(3);
  sample.push_back(2);
  sample.push_back(1);
  sample.push_back(6);
  sample.push_back(0);
  sample.push_back(5);
  constructMaximumBinaryTree(sample);

  return 1;
}
