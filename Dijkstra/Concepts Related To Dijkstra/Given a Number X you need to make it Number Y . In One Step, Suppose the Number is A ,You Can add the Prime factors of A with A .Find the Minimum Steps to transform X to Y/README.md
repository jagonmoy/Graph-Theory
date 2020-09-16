## PREREQUISITE : Dijsktra .
### EXPLANATION : 
First we will Use **Least prime method** so that in Each step the Prime factoraization can become Faster . we will Store Least prime for evey Number up to Y . we need to Maintain a 
array **dis** which will keep track of the minimum number of steps to make the Number **dis[i]** ( here, X <= i <= Y ) from X . But at first you need to initialize te **dis** 
array with **inf** value .Now we will run simple Dijktra Algorithm . **In Traditional Graph Problem We check Adjacent Nodes of Current Node but in this problem we will 
prime factoraize our current Number . We will check if the Current Number + prime factor is in the range of Y and If the dis[CurrentNumber]+1 < dis[currentNumber+primefactor] . 
If it is So then we will modify the dis[currentNumber+primefactor] with the dis[CurrentNumber]+1 and we will push currentNumber+primefactor and it's dis value in Priority Queue . 
 At last we will check the dis value of Y if it's dis value is infinite then we can not make Y from X . But if it is not then the dis value of Y is our answer .**
 
 ### RELATED PROBLEM 
 
 Light OJ - 1141 : http://lightoj.com/volume_showproblem.php?problem=1141
