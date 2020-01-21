#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<string> split_string(string);

int getSubsetSum(vector<int>& set, stack<size_t> subset) {
  int sum = 0;
  cout << "getting sum of subset: [";
  while (!subset.empty()) {
    sum += set[subset.top()];
    cout << set[subset.top()] << " ";
    subset.pop();
  }
  cout << "]" << endl;

  return sum;
}

// subset is a stack of indices
int buildNonAdjSubset(vector<int>& set, stack<size_t> subset, size_t i) {
  // get the sum of the current subset
  int currSubsetSum = getSubsetSum(set, subset);

  if (i > set.size()) {
    return currSubsetSum;
  }

  // put something in the subset if we haven't built it yet
  if (subset.empty()) {
    subset.push(i);
  }

  // don't push i onto current subset, increment i
  // get sum of subset without the next non-adj elt added
  int sum1 = currSubsetSum + buildNonAdjSubset(set, subset, i + 1);

  // push i onto current subset if it's not adjacent to the last elt in subset
  if (subset.top() - i > 1) {
    subset.push(i);
  }

  // get the sum of the subset with the next non-adj elt added
  int sum2 = currSubsetSum + buildNonAdjSubset(set, subset, i + 1);

  if (sum1 > sum2) {
    return sum1;
  } else {
    return sum2;
  }
}

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
  stack<size_t> subset;
  int sum = buildNonAdjSubset(arr, subset, 0);

  return sum;
}

int main() {
  vector<int> arr = {-2, 1, 3, -4, 5};

  cout << "Max Sum: " << maxSubsetSum(arr) << endl;

  return 0;
}
