# PREREQUISITE : Topsort , Idea about STL bitset 

### Simplification of Problem Statement : 

Given a directed acyclic graph, we need to remove all the edges vi → vj if vj is reachable from vi by some other path. In a word we need to remove the extra edges which are already included in some other path . Resulted Total Number of Edges should be as minimum as possible .

### Explnation :

Just like Other DFS problem first we need to set the Graph,visited,toposrt Etc other vectors . Here we will use one more extra thing Known as *bitset* 
