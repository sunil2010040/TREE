# TREE

A tree data structure is a hierarchical structure that is used to represent and organize data in a way that is easy to navigate and search. 
It is a collection of nodes that are connected by edges and has a hierarchical relationship between the nodes. 
The topmost node of the tree is called the root, and the nodes below it are called the child nodes. 
Each node can have multiple child nodes, and these child nodes can also have their own child nodes, forming a recursive structure.

The data in a tree are not stored in a sequential manner i.e, they are not stored linearly. 
Instead, they are arranged on multiple levels or we can say it is a hierarchical structure. 
For this reason, the tree is considered to be a non-linear data structure.


PROPERTIES:-

Number of edges: An edge can be defined as the connection between two nodes. If a tree has N nodes then it will have (N-1) edges. There is only one path from each node to any other node of the tree.

Depth of a node: The depth of a node is defined as the length of the path from the root to that node. Each edge adds 1 unit of length to the path. So, it can also be defined as the number of edges in the path from the root of the tree to the node.

Height of a node: The height of a node can be defined as the length of the longest path from the node to a leaf node of the tree.

Height of the Tree: The height of a tree is the length of the longest path from the root of the tree to a leaf node of the tree.

Degree of a Node: The total count of subtrees attached to that node is called the degree of the node. The degree of a leaf node must be 0. The degree of a tree is the maximum degree of a node among all the nodes in the tree.
