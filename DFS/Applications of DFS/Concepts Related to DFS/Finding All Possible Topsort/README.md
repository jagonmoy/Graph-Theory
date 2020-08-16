## PREREQUISITE : DFS 

### EXPLANATION :

Here Everytime Before taking A vertex **U** we will check two things . **We will check if the vartex U is unvisited and all it's adjacent vertices are unvisited** . Because See ,
Here adjacent vertices actually mean that **before doing the task of it's adjacent vertices first we need complete the task of vertex U. so if we see that it's adjacent vertices 
are visited earlier than it's not possible because adjcacent vertices depends on U **. So before completing the task of U we can not complete the tasks of it's adjacent vertices.
whenever  **vector's size is equal to the number of total vertex that means all of the vertices are visited properly and this is a possible topsort !! so we will make f = 1 .**
now i**f a cycle exists in DAG then this f will remain zero.** because vector size will be not equal to the number of vertices .
By this way we will try to check all possible combinations.
