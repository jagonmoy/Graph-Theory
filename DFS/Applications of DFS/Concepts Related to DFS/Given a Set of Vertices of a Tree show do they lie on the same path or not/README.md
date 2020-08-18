## PREREQUISITE : DFS , More precisely the idea of intime and endtime of a node in DFS Traversal.

### PROBLEM STATEMENT : A tree and a set of Vertices will be given . We have to tell if there exist any path in the tree consisting of all the vertices of the set .

### Explanation : 
It's Very Straight Forward DFS Problem . No need to change anything at all in the DFS function . For every Node in the DFS we will store the in time and end time
of that node . Now what actually intime and endtime means ? intime means that time when a DFS function reach a completely univisited Node **U** and Endtime is the time when we 
complete traversing all of the adjacent vertices of that node (the end of of DFS function for that node **U**) . All we need to solve this problem is a simple 
observation .     

See if there exist a path between node A,B,C,D  from node **A** DFS function will visit node **B** then from it DFS function will visit Node **C** then from it 
DFS function will visit node **D** then after Completing the task of Node **D** it will backtrack and return to Node **C** . Then after Completing the task of Node C it will 
return to node **B**and then after Completing the task of Node **B** Finally it will reach the vertex from where the path started Node **A** . 
Now , By definition of Intime and endtime what we can say is , 
according to the value of intime , **intime[A] < intime[B] < intime[C] < intime[D] ( intime will be Increasing)**
and according to the value of endtime, **endtime[A] > endtime[B] > entime[C] > endtime[D] ( endtime will be decreasing )**

So , **If we can sort the set of vertices in such order that intime of that set is strictly increasing and endtime of that array is strictly Decreasing at same order
than we can tell there is a path consisting of that set of vertices .**
To solve this first we will sort the array according to the value of intime in Increasing Order than in this sorted array we will check if the order is also Stricly Decreasing 
according to the value of endtime .
