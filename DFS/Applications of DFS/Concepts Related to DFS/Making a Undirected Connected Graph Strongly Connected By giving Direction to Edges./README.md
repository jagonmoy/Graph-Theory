## PREREQUISITE : Articulation Bridge 

### Problme Statement : 

A undirected Connected Graph will be Given we need to give direction to the Edges and need to ensure that Number of Undirected Edges is minimal to make it 
a Strongly Connected Graph .
To make it simple , Suppose A road map is given initially all the roads are two way roads we need to minimise the Number of Two Way roads So that The Graph is Strongly Connected
that means , we can go from any node to another. So the Output Will be Direction Of edges . 

### Explanation Link : 
Very Similar to Strong Orientation of Graph Algorithm Described Algorithm . A good article Regarding this : https://cp-algorithms.com/graph/strong-orientation.html
             
### Explanation : 
It's Just a simple Modification of Finding Articulation Bridge Algorithm . Look If there is a bridge in a graph That means there doesn't exist any back edge  from
the child to it's parent node or any of it's ancestor .  So even if we can go from  parent node 'U' to any of its descendant nodes connected through that edge or Bridge There is 
no way to come back from descendant nodes to that parent node 'U' . So we Can not Give a sinle direction in this edge and thus we will make it bidirectional and give
it a value "2". We need to Check if any of the edges is used before or not .if the edge is from "Node to child" according to the variable used in Below code we will give a 
value "1"  and if the edge is from "Child to Node" we will give value "-1" . So this few things are extra which we need to check Apart from running the 
simple Articualtion Bridge Algorithm .
