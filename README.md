**Question One**
***Solution One***
- This program uses a dynamic programming approach

- This program creates a table LCSuff[m+1][n+1] where m and n are the lengths of the two input strings. LCSuff[i][j] contains the length of the longest common suffix of substrings X[0..i-1] and Y[0..j-1]. The first row and first column entries have no logical meaning, they are used only for simplicity of the program.

- *Please note that this program is case sensitive. If you want it to be case insensitive, you can convert both strings to lower or upper case before calling printLCSubStr().*

run solution one by using:

    gcc solution1.c -o S1

***Solution Two***
- Dynamic Programming Approach:

- Create a 2D array dp where dp[i][j] represents the length of the LCS of the substrings Text1[0..i-1] and Text2[0..j-1].
    If the characters Text1[i-1] and Text2[j-1] are the same, then dp[i][j] = dp[i-1][j-1] + 1.
    If the characters are different, then dp[i][j] = max(dp[i-1][j], dp[i][j-1]).

Run solution one by using:

    gcc - solution2.c -o S2


**Question Two**

- This program first asks the user to enter the number of students. Then it asks the user to enter the full name and grade of each student. After that, it sorts the students by their grades from highest to lowest using merge sort. Finally, it prints the sorted list of students.

- Breadth-First Search (BFS) is an algorithm used for traversing or searching tree or graph data structures. It starts at the tree root (or an arbitrary node in the case of a graph) and explores the neighbor nodes at the present depth prior to moving on to nodes at the next depth level.

To run question two cd into question two,

    sudo apt install make 

Then run make to create student_sort file then run with

    ./student_sort


**Question Three**

- This program first creates a min heap with capacity equal to the size of the input arrays. Each node of the min heap contains a character and its frequency of occurrence. The nodes are sorted in the min heap according to their frequencies.

- The buildHuffmanTree function builds the Huffman tree by extracting two minimum frequency nodes from the min heap at a time, creating a new node with frequency equal to the sum of the two nodes’ frequencies, and inserting the new node back into the min heap. This process is repeated until there is only one node left in the min heap, which is the root of the Huffman tree.

To run question two cd into question three:

    sudo apt install make 

Then run make to create compress file then run with

    ./compress


**Question four**
- To solve the problem of finding the shortest path from node 0 to all other nodes in the graph, we can use Dijkstra's algorithm. Dijkstra's algorithm is well-suited for this task as it efficiently finds the shortest paths from a single source node to all other nodes in a weighted graph.

- Here is a step-by-step explanation and the implementation in C:

- Step-by-Step Explanation
- Graph Representation:

- Represent the graph using an adjacency matrix or an adjacency list. For simplicity, we will use an adjacency matrix.
- Dijkstra's Algorithm:

- Initialize the distance to the source node (node 0) as 0 and all other nodes as infinity.
- Use a min-priority queue (or a simple array for small graphs) to keep track of the minimum distance nodes.
- Repeatedly extract the node with the minimum distance, update the distance for its neighbors, and mark it as visited.
- Output the Results:

- After the algorithm completes, print the shortest distance from node 0 to all other nodes.

Run solution one by using:

    gcc - dijkstra.c -o dijkstra

The run

    ./dijkstra


**Repo Author: Frank Onyema Orji**