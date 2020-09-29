- ## PREREQUISITE : Basic Idea about Tree .
- ### Explanation : 
Suppose , The sum of weights of all the edges in a tree is **S** , Total Number of Leaf nodes in a Tree is **L** and and Total Number of **E** edges . Then Minimum Diameter of the weighted tree will be 
**2S/L** . 
- #### Proof :
Suppose , two nodes are **X** and **Y** then let us use a term **dist(X,Y)** to represent the distance between these two nodes . <br><br>
Suppose , there are **L** Number of leaf Nodes . Then how many ways we can pick two different leaf nodes from these **L** nodes ?? The answer is **L<sub>C<sub>2</sub></sub>** ways . which
is actually **L(L-1)/2** . Now Let us assume Maximum distance between any two leaf nodes in any of these possible combinations  (i.e Diameter) is **MAXDIS** . If we assume that,
All the **L<sub>C<sub>2</sub></sub>** Combinations has a distance of **MAXDIS** then obviously their sum will be greater then Normal Sum of all the **L<sub>C<sub>2</sub></sub>** 
distances which we can represent as **<span>&#8721;dis</span>X<sub>i</sub>Y<sub>j</sub> (Here 1<= i , j <= L and i != j)**  <br><br>
Now we can say that ,<br><br> **( L.(L-1)/2 ).MAXDIS >= <span>&#8721;dis</span>X<sub>i</sub>Y<sub>j</sub> (Here 1<= i , j <= L and i != j) .... EQ(1)** <br><br>
Now If there is **L** Leaf Nodes in a Tree then any edge can not be presented more than **L-1** times in these  **L<sub>C<sub>2</sub></sub>** Combintations . So let us assume that,
Every edge is presented total Number of **L-1** times then we can say that , <br><br>
**<span>&#8721;dis</span>X<sub>i</sub>Y<sub>j</sub> (Here 1<= i , j <= L and i != j) >=  <span>&#8721;Weight<sub>i</sub></span>(L-1)   (here , 1 <= i <= E )** <br><br>
**=> <span>&#8721;dis</span>X<sub>i</sub>Y<sub>j</sub> (Here 1<= i , j <= L and i != j) >=  (L-1).<span>&#8721;Weight<sub>i</sub></span> (here , 1 <= i <= E )** <br><br>
**=> <span>&#8721;dis</span>X<sub>i</sub>Y<sub>j</sub> (Here 1<= i , j <= L and i != j) >= (L-1).S ...EQ(2)** <br><br>
Now from EQ(1) and EQ(2) , We can say that , <br><br>
 **( L.(L-1)/2 ).MAXDIS >= (L-1).S** <br><br>
 **=> MAXDIS => 2S/L** <br><br>
 so, now we can say that Maximum Distance between any these **L<sub>C<sub>2</sub></sub>** Combinations will be greather or equals than **2S/L** . And we know the **maximum distance
 between any of the two leaf nodes in a tree is called diameter of the tree** . So that is our answer . <br><br>
 So , we just need to Know the Number of Total Leaf nodes that is **L** and then divide **2S** by **L** .  So we will give **S/L** to all the edges that are connected to leaf nodes and **0** weight to edges that are not connected to leaf nodes .  Then distance between any of the two leaf nodes will be **2S/L** . Beacause other than two edges all the 
 edges will be **0** . That's why there sum will be **2S/L** .
 - #### RELATED PROBLEMS :
  [Codeforces 1087D](https://codeforces.com/problemset/problem/1087/D?locale=en)
