"""
BST Construction
Write a BST class for a Binary Search Tree. The class should support:
• Inserting values with the insert method.
• Removing values with the remove method; this method should only remove the first instance of a given value.
• Searching for values with the contains method.
Note that you can't remove values from a single-node tree. In other words, calling the remove method
on a single-node tree should simply not do anything.
Each BST node has an integer value, a left child node, and a right child node. A node is said to be a valid BST node if and only if it satisfies the BST property: its value is strictly greater than the values of every node to its left; its value is less than or equal to the values of every node to its right; and its children nodes are either valid
BST nodes themselves or
None null.
"""


# Do not edit the class below except for
# the insert, contains, and remove methods.
# Feel free to add new properties and methods
# to the class.


class BST:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def insert(self, value):
        # Write your code here.
        # Do not edit the return statement of this method.
        cur = self
        traverse = True

        while traverse:
            if value < cur.value:
                if cur.left is None:
                    cur.left = BST(value)
                    traverse = False
                else:
                    cur = cur.left
            else:
                if cur.right is None:
                    cur.right = BST(value)
                    traverse = False
                else:
                    cur = cur.right

        return self

    def contains(self, value):
        # Write your code here.

        cur = self
        traverse = True

        while traverse:
            if value == cur.value:
                return True
            elif value < cur.value:
                cur = cur.left
            else:
                cur = cur.right

        return False

    def remove(self, value):
        # Helper function to find min value node in a subtree
        def get_min_node(node):
            while node.left:
                node = node.left
            return node

        cur = self
        parent = None

        while cur:
            if value < cur.value:
                parent = cur
                cur = cur.left
            elif value > cur.value:
                parent = cur
                cur = cur.right
            else:
                # Found the node to remove
                # Case 1: No children (leaf node)
                if not cur.left and not cur.right:
                    if parent:
                        if parent.left == cur:
                            parent.left = None
                        else:
                            parent.right = None
                    else:
                        # Deleting root node (single-node tree)
                        return None

                # Case 2: One child
                elif cur.left and not cur.right:
                    if parent:
                        if parent.left == cur:
                            parent.left = cur.left
                        else:
                            parent.right = cur.left
                    else:
                        # Replace root node
                        self.value = cur.left.value
                        self.left = cur.left.left
                        self.right = cur.left.right

                elif not cur.left and cur.right:
                    if parent:
                        if parent.left == cur:
                            parent.left = cur.right
                        else:
                            parent.right = cur.right
                    else:
                        # Replace root node
                        self.value = cur.right.value
                        self.left = cur.right.left
                        self.right = cur.right.right

                # Case 3: Two children
                else:
                    successor = get_min_node(cur.right)
                    val = successor.value
                    # Recursively remove successor
                    self.remove(successor.value)
                    # Replace current node's value with successor's value
                    cur.value = val

                break

        return self

    def find_node(self, value):
        cur = self
        traverse = True

        while traverse:
            if value < cur.value:
                if value == cur.left.value:
                    return cur.left, cur
                else:
                    cur = cur.left
            else:
                if value == cur.right.value:
                    return cur.right, cur
                else:
                    cur = cur.right

        return None, None



# import program
import unittest


BST = BST


class TestProgram(unittest.TestCase):
    def test_case_1(self):
        root = BST(10)
        root.left = BST(5)
        root.left.left = BST(2)
        root.left.left.left = BST(1)
        root.left.right = BST(5)
        root.right = BST(15)
        root.right.left = BST(13)
        root.right.left.right = BST(14)
        root.right.right = BST(22)

        root.insert(12)
        self.assertTrue(root.right.left.left.value == 12)

        root.remove(10)
        self.assertTrue(not root.contains(10))
        self.assertTrue(root.value == 12)
        #
        self.assertTrue(root.contains(15))

