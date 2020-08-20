## PREREQUISITE : DFS,Topsort 

### PROBLEM STATEMENT :
A directed graph and a source vertex will be given . we need to tell what is the minimum number of edges we need to add so that all the verties are reachable from
source vertex .

### EXPLANATION :
We will run a dfs from source vertex to see how many vertices are reachable from source vertex with the given orientation . We will mark them as visited[node] = 1 . if all the
vertices are visited in that point then the answer is 0 because no need of adding edges here . Because with the given orientation of edges we can visit all the vertices from
source vertex . And if all the vertices can not be visited Then we will run a topsort among the remaining vertices and mark them as visited[node] = 2 . Because from Topsort we
will find a order that , which node should be visited first so that we can maximize the number of visited vertices from that particular vertex . After Topsort ,  the vertices 
with visited[node] = 2 we will make them 0 again . Then again according to the order of topsort we will run a dfs among the vertices which visited value is 0 . Because the vertices
with visited value 1 can be visited from source vertex by given orientation no need to add edges there . Now we will just keep a count how many times we need to run the DFS to
make all the vertices visited and that is our answer .

Look I have used only one DFS function with the help of a variable "kahini" . For different values of kahini I used some condition in DFS functions . But for the sake of simplicity
one can use three DFS function also .
