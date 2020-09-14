## PREREQUISITE : DFS , Finding Diameter of a Tree 
### EXPLANATION :
Very Similar to the Problem , **Finding Diameter of a Unweigheted tree** . Almost same actually . Diameter of a Unweighted Tree Means the Maximum distance between any two 
nodes in the Unweighted Tree . Only difference between these two problems is , In Diamater problem the tree is Unweighted And in this problem the tree is weighted . We need to 
handle this extra modification . Other than this All the concepts are same . First , We will pick a random node Then we will calculate the Maximum Possible Distance from this 
Source node and Pick the node which will have maximum distance from our source node . For this We will run  a DFS function . Other than Source vertex , Distance of every node will
be the Sum of the distance of it's parent and the Weight of the edge between the node and it's parent . After Finding the furthest Node from Source vertex we will again run another
DFS from the Furthest Node and then we will again check what is the maximum distance from this node and that will be our Answer .
## RELATED PROBLEM 
**Light OJ - 1094** : http://lightoj.com/volume_showproblem.php?problem=1094
