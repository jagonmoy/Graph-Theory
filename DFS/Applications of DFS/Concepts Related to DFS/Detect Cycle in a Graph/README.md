## PREREQUISITE : DFS 

#### EXPLANATION : 
Detecting Cycle in a graph is one of the Very important use of Depth First Search Algorithm .
To detect Cycle in a algorithm we need to modify the DFS algorithm a little bit every time when we check a adjacent node of Vertex **U** . Suppose the adjacent Node is **V** .
If **V** is a Node which work is still in progress that means if **it's Colour is GREY and it is not a parent of vertex U then there is a cycle** . It means that actually the 
**Vertex V is a ancestor of Vertex U** . Because in Depth First ALgorithm we go as deep we can . Then when there is no way to go further we backtrack to reach the earlier vertrex
where we started from . So during the time of checking adjacent vertices of **U** if we find such a vertex which work is still in progress and it's not a parent of U then the 
adjacent vertex V and the main vertex U is actually part of the same DFS tree and there is a cycle . So here we also need to pass the parent of the vertex in 
**DFSVISIT(u,vertex,parent[u])** that is one thing we need to add . And One more thing is, in DFSVISIT function we will also check one more thing that 
**if state[v] = GREY and parent[u] != v then we will be sure that there is a cycle.**


**In code if the value of f is 1 then there is a cycle else no** 

**Here if the graph is a undirected graph then the parent array is needed but when the graph is directed there is no need of parent array .
in place of (state[v] == GREY && parent[u] != v) we need to check state[v] == GREY .**
