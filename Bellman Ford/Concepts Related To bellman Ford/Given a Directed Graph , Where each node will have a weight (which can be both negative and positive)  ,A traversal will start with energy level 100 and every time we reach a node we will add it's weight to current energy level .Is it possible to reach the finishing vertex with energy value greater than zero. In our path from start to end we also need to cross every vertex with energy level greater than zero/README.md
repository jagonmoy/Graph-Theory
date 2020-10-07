- ### PREREQUISITE : Bellman-Ford

- ### EXPLANATION :
 We know that Bellman ford algorithm is used to find negative cycle . But in this scenerio we will use bellman-ford for opposite purpose . We will use bellman-ford algorithm to
 find positive cycle and we will add an extra condition so that every time we reach a node the current energy level becomes greater than zero . In traditional Bellman ford algorithm where we find negative cycle from our source node , Except the source node we initialize the distance value with INF value and our source node has zero value . And during relaxation we take the minimum value  . But in this case we will initialize every node with NEGINF value and initialize the source node with 100 . And in relaxation we will take the maximum value and ensure that the current energy value is greater than zero . The nodes having changable values in **n'th** phase is part of positive cycle . we can use positive cycle to increase
our current value as much as we need to enter the next nodes with positive enegery value . So , suppose if distance value of our destination vertex is still unreachable up to **n-1'th** phase we can still use these positive cycle to 
fullfill our condition . But for this we need to bear in mind two facts . First these Nodes which are presented in Positive cycles should be reachable from destination vertex.
Second , The nodes which are presented in positive cycle should have incoming edge connected to node which are reachable from start vertex . <br><br>
So, we need to take some steps - <br><br>
1. We will use our modifed Bellman ford algorithm to find maximum possible value for each node up to **n-1**th phase . If our destination vertex has distance value greater than 
NEGINF that means it is reachable . We don't need to go further . But if it is not then , <br><br>
2. We will find out the nodes which are changable in **n**th phase (I.E part of positive cycle) . Then we will run a Simple BFS from destination vertex in reverse graph so that
it is possible to find if the nodes presented in positive cycle have a path to destination vertex . Now for every edge in graph we will check three condition . One, First node
of the edge ( the node having outgoing edge ) should be reachable from our start vertex which we can determine via distance value  , two , Second node of the edge (the node having incoming edge ) should be part of positive cycle and three , the second node should be reachable from destination vertex . <br><br>
