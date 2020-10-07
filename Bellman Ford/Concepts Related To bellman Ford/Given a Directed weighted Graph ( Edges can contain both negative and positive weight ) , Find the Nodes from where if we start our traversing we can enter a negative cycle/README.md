- ## PREREQUISITE : DFS,Bellman-ford
- ### QUESTION EXPLANATION : 
     A directed weighted Graph will be given . The edges can contain both Negative and positive weight . Find out all the possible starting nodes such that if we
     start traversing from there we can enter a negative weight cycle .
- ### EXPLANATION :
 1. Make a reverse graph of the given graph . Because If a node is presented in those negative cycles then obviously if we start from those nodes we can enter a negative cycle .
 Another Case is , Those nodes which are not part of negative cycles but if we start from there we can reach the negative cycle . So, we also need to know the Incoming nodes from 
 where negative cycles can be reached also . They are also part of our consideration . For this we need to build a reverse graph . Because In reverse graph the Incoming edges will
 turn into outgoing edges . And if we start DFS traversal from theese Nodes which are part of negative cycles we can also track down the nodes which are outgoing nodes for reverse 
 graph but they are incoming nodes for Main graph . And that is our goal . So, now we know both type of nodes .Type One, which are part of negative cycles and type two, which are 
 not part of negative cycle but from where we can reach negative cycles<br><br>
 2. So, in a nut shell , We will run Bellman-ford algorithm in reverse graph . We will find the nodes which are changing in **n'th** phase and then find out the negative cycles 
 and the nodes presented in those cycles . We will mark the nodes which are presented in negative cycles. Finally, we will run a DFS traversal in reverse graph starting from the Marked nodes which are presented in those negative cycles and 
 we will mark these nodes too.
 
