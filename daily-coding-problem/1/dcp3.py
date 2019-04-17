# Kushal Jaligama
# Daily Coding Problem 3

# Asked by GOogle

# given root to binary tree, implement serialize(root) which serializes
# tree into a string, and deserialize(s) which deserializes the string to tree


class Node:

    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def serialize(root):
    pass


def deserialize(root):
    pass


def main():
    node = Node('root', Node('left', Node('left.left')), Node('right'))
    assert deserialize(serialize(node)).left.left.val == 'left.left'


if __name__ == '__main__':
    main()
