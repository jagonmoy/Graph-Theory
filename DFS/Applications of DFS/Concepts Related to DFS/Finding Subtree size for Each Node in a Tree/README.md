## PREREQUISITE : DFS , Basic Idea of Memoraization
### EXPLANATION : 
First, We will store 1 as primary value of Subtree size for Each node . Then Whenever we find a child of a Node we add child's subtree size to the Parent's Subtree size .
That means, Suppose we have node **U** and it's Subtree size is **X** . One of it's Child is node **V** and it's Subtree size is **Y** . Then we will add this **Y** to **X** .So 
subtree size of node **U** will be **X+Y** . This we can calculate Subtree size for every Node . Because Child's Descendant is also a Descendant of Parent . 
