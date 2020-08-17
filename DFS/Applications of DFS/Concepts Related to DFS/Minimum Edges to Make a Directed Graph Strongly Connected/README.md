## PREREQUISITE : DFS,Strongly Connected Component .

### Explanation : 
#### STEP 1 :

We know that in Strongly Connected Component it's possible to go from one vertex to another . So in our given graph **if there exist a SCC then we don't need to add edges in this 
SCC .** So first we will execute Simple Finding SCC algorithm and All the vertex of a SCC will be regarded as a single vertex . we will use an array to mark which vertex belongs 
to which SCC . So now our Step 1 is done . We have minimised the graph by making all the vertex of a single SCC a single vertex by marking the vertices of that SCC by 
corresponding SCC number .

#### STEP 2 :
Now see , we know that **a Directed Acyclic Graph can be a strongly Connected Component (SCC) ( in other words ,it possible to move from one vertex to another ) if every vertex of 
the DAG has atleast one edge that's getting into the vertex and atleast one edge going out from the vertex . That means if A vertex has atleast one indegree and one outgree .**
Since we are now assuming the SCC'S as a single vertex so **we will calculate the indegree and outdegree of each SCC** . Now how to calculate it ???
we will run a DFS and check if two adjacent vertex are from different SCC ?? if they are from different SCC then we will increase the outdegree of the SCC where "node" belongs 
and increase the indegree of the SCC where "child" belongs .  

#### STEP 3 :

**now we will check how many SCC don't have atleast one indegree and then count How many SCC don't have atleast one
outgree . result will be the maximum of this two summation .**
