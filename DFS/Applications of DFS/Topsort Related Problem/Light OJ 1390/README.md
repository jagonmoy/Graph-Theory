# PREREQUISITE : Topsort , Idea about STL bitset 

### Simplification of Problem Statement : 

Given a directed acyclic graph, we need to remove all the edges vi → vj if vj is reachable from vi by some other path. In a word we need to remove the extra edges which are already included in some other path . Resulted Total Number of Edges should be as minimum as possible .

### Explnation :

Just like Other DFS problem first we need to set the Graph,visited,toposrt Etc other vectors . Here we will use one more extra thing Known as **bitset** . here we will take a vector of bitset and we will initialize the size of each bitset according to the Number of nodes and also we will initialize our vector size according to number of nodes.so our 
vector < bitset < numberOfnodes > > reachabe(numberOfNodes) will be actually more like e numberOfnodes * numberOfnodes 2D array .
here the bit of reachable[i][j] 
