## PREREQUISITE : Articulation Bridge 

### Problme Statement :
A undirected Connected Graph will be Given we need to give direction to the Edges and need to ensure that Number of Stronly Connected Component is as Minimal 
as Possible .So the Output Will be the Number of Strongly Connected Component and Direction Of edges . 

### Explanation Link : It's Basically Known as Strong Orientation Of a graph . A good article Regarding this : https://cp-algorithms.com/graph/strong-orientation.html
             
### Explanation : 

It's Just a simple Modification of Finding Articulation Bridge Algorithm . Look **If there is a bridge in a graph That means there doesn't exist any back edge  from
the child to it's parent node or any of it's ancestor.** So even if we can go from  parent node 'U' to any of its descendant nodes connected through that edge or Bridge There is 
no way to come back from descendant nodes to that parent node 'U' . So we need to compromise atleast one direction . At this point we will increase the the value of the variable
which will keep the Count of Bridges . We need to Check if any of the edges is used before or not . **if the edge is from "Node to child" according to the variable used in 
Below code we will give a value "1"  and if the edge is from "Child to Node" we will give value "-1".** So this few things are extra which we need to check Apart from running the 
simple Articualtion Bridge Algorithm .
**Number Of total Strongly Connected Component Will be the Number of Bridges + Connected Components . Because If we remove the Bridges From 
the Graph We end up with some number of bridgeless components (exactly how many components there were at the beginning + how many bridges there were) .**
