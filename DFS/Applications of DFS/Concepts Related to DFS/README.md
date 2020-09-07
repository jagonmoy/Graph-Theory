##PREREQUISITE : DFS 
### EXPLANATION LINK : 
Diameter of a tree means the Longest Path between any two nodes of the tree . It is very Obvious that , Longest Path in a tree will be the path between two leaf nodes .
So , all we need to do is first we will run a DFS from any node in the tree and the Node which will have maximum distance surely will be a Leaf node . Then We will run another
DFS from that Leaf node and find another leaf node by mentioned process . The distance to that leaf node will be the diameter of the tree .
