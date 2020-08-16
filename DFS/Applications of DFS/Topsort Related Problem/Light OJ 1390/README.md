# PREREQUISITE : Topsort , Idea about STL bitset 

### Simplification of Problem Statement : 

Given a directed acyclic graph, we need to remove all the edges vi → vj if vj is reachable from vi by some other path. In a word we need to remove the extra edges which are already included in some other path . Resulted Total Number of Edges should be as minimum as possible .

### Explanation :

##### STEP 1 : 
Just like Other DFS problem first we need to set the Graph,visited,toposrt Etc other vectors . Here we will use one more extra thing Known as **bitset** . suppose the Number Of nodes is **N** . Here we will take a vector of bitset and we will initialize the size of each bitset according to the Number of nodes and also we will initialize our vector size according to number of nodes. So **vector < bitset < N > > reachable(N)** will be actually more like a N * N 2D array . Here each bit of reachable[i][j] will indicate us if it is possible to reach node j from node i by any route . now we will initialize all i from 1 to N reachable[i][i] = 1 . Because it is possibe for each node to visit itself . 

##### STEP 2 :

Now we will call the DFS function to topsort the vertices . Here in the DFS function we will use a Extra line **reachable[node] |= reachable[child]** . Now what does that actually mean ? Every Reachable Vertex from Child vertex will be added to the bitset of Parent vertex as well . That's why we are using OR operation . In simple word , Suppose there is a route from City B to City C,D,E,G . Now if there is Route from City A to City B it's also possible to reach City C,D,E,G from City A .
Now a question will arise ? how do you know which vertices are reachable from the child vertex if you don't traverse them ? In DFS method we go as deep as we can . so before adding the reachable vertices fo child vertex known as **reachable[child]** to it's parent vertex we will traverse the child vertex first . That's why **reachable[node] |= reachable[child]** this line is after the line **dfs(child)** in code . So that before adding the reachable vertices from child vertex to it's parent we will traverse the child vertex first . 
Now after Completing the topsort we will set the value of each node in **priorityarray** according to the order of topsort . 

##### STEP 3 :

Now in this step we will Sort every Adjacent Vertex **child** of a node **i** according to their Priorityarray value . we will take a bitset for every node **i** known as **reachable_Set_of_from_i** . Then we will check if adjacent vertex **child** is already added in the **bitset**  of **i** or not . If it is not added then we will insert the edge
**i->child** in our result vector . after that we will add the bitset of the adjcant vertex **child** to the bitset **reachable_Set_of_from_i** by an OR operation **reachable_Set_of_from_i |= reachable[child]** . 
