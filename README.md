# CSC212ProjectGroup11
B-Tree

**_Implement the Data Structure (using classes)_**

- ensure at least `insert` & `search` methods are correct
  - `search` must also return/print the count

- generate a DOT file for visualization

**_Store the words of an input text file_**

- for the word ($node$) in the tree, a count with the number of repeats must also be stored

**Insertion**
- `insert(key, value)`: Inserts a new key-value pair into the B-tree while maintaining the B-tree properties (such as balanced nodes and  sorted keys).

**Deletion**
- `delete(key)`: Removes a key from the B-tree while preserving the B-tree properties.

**Search**
- `search(key)`: Searches for a key in the B-tree and returns the associated value, or indicates if the key is not present.

**Traversal**
- `inOrderTraversal()`: Traverses the B-tree in ascending order, visiting all nodes.
- `preOrderTraversal()`: Traverses the B-tree in a pre-order manner (visits the node before its child nodes).
- `postOrderTraversal()`: Traverses the B-tree in a post-order manner (visits the node after its child nodes).

**Splitting and Merging Nodes**
- `splitChild(node, index)`: Splits a full child node into two nodes when inserting a key, ensuring that the B-tree properties are maintained.
- `mergeNodes(node1, node2)`: Merges two nodes when deleting a key, ensuring that the B-tree properties are preserved.

**Node Splitting**
- `split()`: Splits a node into two nodes when it becomes full, ensuring that the B-tree properties are maintained.

**Node Merging**
- `merge()`: Merges a node with its sibling when it becomes underflowed, ensuring that the B-tree properties are preserved.

**Finding Successor/Predecessor**
- `findSuccessor(key)`: Finds the successor key (the smallest key greater than the given key) in the B-tree.
- `findPredecessor(key)`: Finds the predecessor key (the largest key smaller than the given key) in the B-tree.

**Range Queries**
- `rangeQuery(start, end)`: Retrieves all key-value pairs within the given range.

**Node Splitting and Merging Adjustments**
- `adjustAfterDelete(node)`: Adjusts the B-tree structure after a deletion operation, ensuring that the B-tree properties are preserved.
- `adjustAfterInsert(node)`: Adjusts the B-tree structure after an insertion operation, ensuring that the B-tree properties are maintained.

**Height Calculation**
- `getHeight()`: Calculates and returns the height of the B-tree.

**Displaying B-tree**
- `printTree()`: Prints the structure of the B-tree for visualization and debugging purposes.
