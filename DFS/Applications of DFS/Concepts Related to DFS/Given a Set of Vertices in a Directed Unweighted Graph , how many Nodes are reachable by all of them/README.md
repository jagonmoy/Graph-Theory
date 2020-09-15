## PREREQUISITE : DFS 
### EXPLANATION : 
Solution is very Much straight Forward . That's Why we need to be careful about the Constraint . If the size of the set is **K** , Number of nodes in the Graph is **V** and Number
of edges in the graph is **E** then the complexity is **O(K(V+E))** .
We will run DFS for every node in the set and maintain an extra array **visittimes** to mark the nodes how many times are they visited . We will increase the value of 
visittimes every time we visit a node . In the end, We will simply check How many nodes are there whose **visittimes** value is equal to **K** and that is our answer . 
It's Pretty much straight forward **DFS** problem just **we need to run DFS , K times** and **in the end we will check how many nodes are visited K times .**
### RELATED PROBLEM 
Light OJ - 1111 : http://lightoj.com/volume_showproblem.php?problem=1111
