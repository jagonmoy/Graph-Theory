## PREREQUISITE : DFS

### Explanation : 

Topsort Actually is the ordering of task . Suppose there are Bunch of tasks to do and one thing is related to another then which Task we should do first ?? what will be
the ordering ??? This is the goal of learning Topsort .One way to do topsort is by using Depth First Search .
Because see , in depth first search we go as deep as we can . when there is no way to go deep further then we backtrack . So basically **in a DFS tree a descendent 
turns black first than it's ancestor .**  So **the Task which we should do later turns black first** . so we will just store the vertices which turns black into a stack .then
we will just print the stack . because in stack what goes in first that comes out last . So the vertex which will turn black first will be in the bottom of a stack . 
that is what we want . we wanted to print the ancestor first . **Because to reach descendent we first need to do the task of the ancestor.** in place of stack we also can use 
vector then we can reverse it later . That is the logic of Topsort . So **Basically a topsort is nothing but reversed DFS order.**

one thing to be noted : **if there is a cycle in a graph we can not do topsort .** So **first we need to check if there is a cycle** we can check this by a slight modification 
it is described in other file .
