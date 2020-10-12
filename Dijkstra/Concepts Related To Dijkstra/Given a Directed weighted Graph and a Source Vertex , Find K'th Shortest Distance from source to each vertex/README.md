- ## PREREQUISITE : Dijkstra 
- ### EXPLANATION :
    We use Dijkstra algorithm to find the shortest distance from source to all other vertices in a graph . But we can modify this Dijkstra algorithm to find the K'th Shortest
    distance .In this example we will explain how to find 2nd shortest distance . But using the same method you can find 2nd/3rd/.../k'th shortest distance. <br><br>
    We just need to make 2/3 changes in the Code . For Basic Dijkstra Algorithm we use a one dimensional array but to find K'th or 2nd Shortest distance we will need a two 
    dimensional distance array . here , distance[2][5] will mean , 2nd shortest distance from source to 5 number node . Similiarly , distance[1][3] will mean, 1st shortest 
    shortest distance from source to 3rd vertex . Same as, Dijkstra algorithm will initialize the whole distance array with a INF value . But for Source vertex the 1st shortest
    distance will be zero . Suppose, our Source vertex is 1 then distance[1][1] = 0 . In the Priority Queue we will also add the value of K . So our Priority Queue will 
    first sort according to the value of K, then distance . But in Basic Dijkstra algorithm , it was only about the distance .<br><br>
    Now in place of one condition we will have K conditions in Dijkstra algorithm . In case of finding 2nd shortest distance ,<br><br>
    if distance[current_state_of_parent][parent] + edgeweight < distance[1][child] then ,<br>
    temp = distance[1][child] <br>
    distance[1][child] = distance[current_state_of_parent_node][parent] + edgeweight <br>
    distance[2][child] = temp <br><br>
    if distance[current_state_of_parent][parent] + edgeweight > distance[1][child] && distance[current_state_of_parent][parent] + edgeweight < distance[2][child] then ,<br>
    distance[2][child] = distance[current_state_of_parent][parent] + edgeweight <br><br>
    
    This is the method to find 2nd shortest distance . In the same way you can add K condition to find up to K'th shortest distance <br><br>
    [Detailed Explanation](http://lbv-pc.blogspot.com/2012/06/not-best.html) 
- ### RELATED PROBLEM :
   [Light OJ 1099](http://lightoj.com/volume_showproblem.php?problem=1099)
