## PREREQUISITE : DFS 

### QUESTION EXPLANATION : 
You are given a directed Graph where each edge has a cost for redirecting. The graph actually Represents a ring . Now Redirect the edges in such a Way so that it is possible to
visit every city to any other (make the graph strongly connected ) .

### EXPLANATION :
Suppose total Vertex is N and N edges in the Ring are 

Edge No     weight

1          1 5    4

2          5 3    8

3          2 4    15

4          1 6    16

5          2 3    23

6          4 6    42

1 --> 5 --> 3 <-- 2 --> 4 --> 6 <-- 1 
To build a Strongly Connected Ring , All the edges should be in one direction . 
here you see ,
Right Directed edges are 1,2,3,6 and their sum is 69 .
Left  Directed edges are 4,5 and their sum is 39 . 
Now see, 
To make all the edges in one direction You will have to redirect either the Right directed edges or the left directed edges . To minimize the Cost for Redirecting We will
Pick the minimum of 69 or 39 and that is our answer .
### IMPLEMENTATION 
We will make two graph , One graph is the given graph and other one is the Reversed graph of given graph . Now we will need a  map so that we can know which pair of nodes
represents which edge. We will also need four more arrays . One array is to check whether the node is visited , one array is to check whether the edge is visited , one array
is to store the cost of edge , One array is to know the direction of edges (we will use 0 and 1 to determine the direction ) .
We can pick a random node and start traversing from that node . Now we will check if it is possible to go to any other vertex through unvisited edge . We will mark such edge as 0 .
If it is not possible to go to any other vertex by given direction then we will check if it possible to go to any other vertex in the Reversed Graph through Unvisited edge and 
we will mark such edge as 1 . Now we will take the minimum sum ofvalue between edges which was marked 0 and which was marked 1 .
### RELATED PROBLEM :
Light OJ - 1049 : http://lightoj.com/volume_showproblem.php?problem=1049

