## PREREQUISITE : DFS,Strongly Connected Component , Longest Path in a Unweighted Directed Acyclic Graph ( using DFS and DP ) 

### SIMILAR PROBLEM : LightOJ 1417 . 

### PROBLEM STATEMENT :

A directed Graph is Given We need to find an index From where highest number of Vertices can be visited .If there is more than one possible answer (There are More than one 
vertex from where highest Number of vertex can be visited) then we need to pick the vertex which has lower id.In this solution we will get to know both from which node 
maximum number of nodes can be visited and what is the maximum result .

### EXPLANATION :
The Explanation is the solution of lightOj 1417 .

#### STEP 1 : 

Now, See the Graph can contain Cycles and The graph can also be disconnected . There are various Possiblites . Therefore first we need to find the Strongly Connected Components
of Graph . Because we know in a Strongly Connected Component we can travel from any vertex to another . For every Strongly Connected Component we will give them an Index ,
we will store the size of that Strongly Component and the minimum vertex which is presented in that SCC . Bcause in Question there is a point if There are multiple Possible 
answer we need to find the vertex has less id . Here by dfs1 function we will topsort the vertices and then according to the Sorting we will run dfs2 and execute the above steps .

#### STEP 2 :

Now we will minimise the Graph That means we will create a new graph where we will treat one SCC as one vertex . to create this SCCgraph we will run dfs3 function .
in this function whenever we find two adjacent vertex which has different SCC number we will create and edge between those two SCC . But to create an Edge first we will
check if there is an edge presented already which was created earlier .

#### STEP 3 :

now , we need to find a path from SCC graph which contain maximum number of vertices . to find this we will run DFS and use dynamic Programming for Memoraisation .
For this we will first initialize a dpSCC array with the capacity of each SCC . Which indicates intially How many Number of vertex can be visited From Each SCC . Now we
will dun dfs4 function in SCCgraph . Whenever an Adjacent vertex (child) of a parent vertex (node) is not visited we will send him in dfs4 function and if it is visited than 
we willadd it's dpSCC value to the dpSCC value of parent vertex . from this Above method using DFS and DP we can find the final dpSCC value of all the vertices .

#### STEP 4 :

Now the final Step , here we will simply run a loop check which SCC has maximum dpSCC value and if there are multiple SCC who has same maximum dpSCC value then we will take that
SCC who has a vertex which id is minimum .

### SUMMARY : 
1. Find SCC's of the graph .
2. Create a SCC graph .
3. Run a DFS on SCC graph and with help of DP find from which SCC highest number of vertex can be visited .
4. print the maximum number of vertex and minimum vertex of that SCC
