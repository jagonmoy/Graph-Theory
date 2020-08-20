## PREREQUISITE : DFS 

### PROBLEM STATEMENT : 

A graph consisting of both Directed and Undirected egdes and a source vertex will be given . We need to give direction to the existing Undirected edges so that Number of visited
Vertcies from source vertex is maximized . Print both the Number of vertices which can be visited from source vertex and the direction of undirected edges . we will Print '+' as 
the j-th symbol of the string if the j-th undirected edge (u, v) from the input should be oriented from u to v. Print '-' to signify the opposite direction (from v to u) .

### input :
The first line contains three integers n, m and s  — number of vertices and edges in the graph, and the source vertex .The following m lines contain information about the graph 
edges. Each line contains three integers ti, ui and vi — edge type and vertices connected by the edge. If ti = 1 then the edge is directed and goes from the vertex ui to the 
vertex vi. If ti = 2 then the edge is undirected and it connects the vertices ui and vi.
It is guaranteed that there is at least one undirected edge in the graph.

### Explanation : 
We will run a dfs from our source vertex and see how far we can go during the traversal . Suppose if we visit a vertex **U** now during the moment of checking it's adjacent 
vertices if we find a edge which is undirected and connected to a vertex **V** which is not visited then we will give direction to the edge and If **U** equals to the first vertex 
of that edge then we will give a **+** else we will give **-** and visit the adjacent node . but If the vertex **V** is visited then we will just give direction to the edge but 
we will not visit the adjacent node **V**. If the edge is directed and **V** is not visited then we will just visit the vertex **V** .

Those vertices which are reachable from source vertex is our first desired result .
Now after running the DFS from source vertex those vertex which are not visited they are out of our considertation . Now the undirected edges which are connecting those vertices
whatever orientation they have will not effect our result at all because they can not be visited from our source vertex . That's why we can give any sign **+** or **-** to that 
edges .
