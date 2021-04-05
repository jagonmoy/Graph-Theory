# Graph-Theory 
   
  ## Index
   
 <ul>
 <li> <h3> <a href = "#dfs" > Depth First Search and it's Variants </a> </h3> </li> 
 <br> 
 <li> <h4> <a href = "#dfst1" > 1. DFS Traversal  </a> </h3> </li> 
 <li> <h4> <a href = "#dfst2" > 2. Cycles,Topsort  </a> </h3> </li> 
 <li> <h4> <a href = "#dfst3" > 3. Connected Components, Strongly Connected Components </a> </h3> </li> 
 <li> <h4> <a href = "#dfst4" > 4. Articulation Points, Articulation Bridge </a> </h3> </li>  
 <li> <h4> <a href = "#dfst5" > 5. DFS on Tree </a> </h3> </li>
 <br><br>
   
 <li> <h3> <a href = "#sp" > Shortest Path Algorithms </a> </h3> </li>
 <br>
 <li> <h4> <a href = "#sp1" > 1. Breadth First Search  </a> </h3> </li> 
 <li> <h4> <a href = "#sp2" > 2. Dijkstra  </a> </h3> </li>
 <li> <h4> <a href = "#sp3" > 3. Bellman-Ford  </a> </h3> </li>
 <br><br>
 
 <li> <h3> <a href = "#mis" > Miscellaneous </a> </h3> </li>
 </ul>
 <br><br><br>

 - ## <h2 id = "dfs" > Depth First Search and it's Variants </h2> 
   ### Prequisite : Recursion .
   <p> Cycle Checking , Topsort , Connected Components , Strongly Connected Components , Articulation Points , Articulation Bridge etc various algorihms are actually application 
       of DFS .   </p>
       
   #### <h3 id = "dfst1" >TOPICS TO BE COVERED BEFORE NEXT SET OF PROBLEMS : DFS TRAVERSAL </h3>
   - #### [Basic DFS](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Basic%20DFS/)
   - #### [Given a Set of Vertices in a Directed Unweighted Graph , how many Nodes are reachable by all of them](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Given%20a%20Set%20of%20Vertices%20in%20a%20Directed%20Unweighted%20Graph%20%2C%20how%20many%20Nodes%20are%20reachable%20by%20all%20of%20them)
   - #### [Given a Source Vertex and a graph Consisting of Both Directed and Undirected Edges give direction to the existing undirected edges so that Number of visited vertices from Source vertex is maximized](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Given%20a%20Source%20Vertex%20and%20a%20graph%20Consisting%20of%20Both%20Directed%20and%20Undirected%20Edges%20give%20direction%20to%20the%20existing%20undirected%20eges%20so%20that%20Number%20of%20visited%20vertices%20from%20Source%20vertex%20is%20maximized/) 
   - #### [Given a Source Vertex and a graph Consisting of Both Directed and Undirected Edges give direction to the existing undirected edges so that Number of visited vertices from Source vertex is minimized](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Given%20a%20Source%20Vertex%20and%20a%20graph%20Consisting%20of%20Both%20Directed%20and%20Undirected%20Edges%20give%20direction%20to%20the%20existing%20undirected%20edges%20so%20that%20Number%20of%20visited%20vertices%20from%20Source%20vertex%20is%20minimized/) 

   
   #### DFS TRAVERSAL PROBLEMS
   
   [Light OJ 1049](https://lightoj.com/problem/one-way-roads) : [Solution](DFS/Applications%20of%20DFS/DFS%20Traversal%20Related%20Problems/LightOJ_1049.cpp)<br><br>
   [Light OJ 1111](https://lightoj.com/problem/best-picnic-ever) : [Solution](DFS/Applications%20of%20DFS/DFS%20Traversal%20Related%20Problems/LightOJ_1111.cpp) <br><br>
   [Light OJ 1185](https://lightoj.com/problem/escape) : [Solution](DFS/Applications%20of%20DFS/DFS%20Traversal%20Related%20Problems/LightOJ_1185.cpp) <br><br>
   [Codeforces 883G](https://codeforces.com/problemset/problem/883/G) : [Solution](DFS/Applications%20of%20DFS/DFS%20Traversal%20Related%20Problems/Codeforces_883G.cpp)<br><br>
   <br><br>
   
  #### <h3 id = "dfst2">TOPICS TO BE COVERED BEFORE NEXT SET OF PROBLEMS : CYCLES ,TOPSORT </h3>
   - #### [Detect Cycle in a Graph](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Detect%20Cycle%20in%20a%20Graph/)
   - #### [Topological Sorting of Nodes in Directed Graph ( Any )](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Topsort%20Using%20DFS/)
   - #### [Topological Sorting of Nodes in Directed Graph ( ALL)](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Finding%20All%20Possible%20Topsort/)
   - #### [Given a Directed Graph and a Source Vertex add minimum directed edges to the Graph So that All the Vertices are Reachable from Source Vertex](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Given%20a%20Directed%20Graph%20and%20a%20Source%20Vertex%20add%20minimum%20directed%20edges%20to%20the%20Graph%20So%20that%20All%20the%20Vertices%20are%20Reachable%20from%20Source%20Vertex/)   
    
  #### CYCLES,TOPSORT RELATED PROBLEM
   [Light OJ 1003](https://lightoj.com/problem/drunk) : [Solution](DFS/Applications%20of%20DFS/Cycle%20Related%20Problem/LightOJ_1003.cpp)<br><br>
   [Light OJ 1390](https://lightoj.com/problem/weight-comparison) : [Solution](DFS/Applications%20of%20DFS/Topsort%20Related%20Problem/Light%20OJ%201390)<br><br>
   [Codeforces 1385E](https://codeforces.com/problemset/problem/1385/E): [Solution](DFS/Applications%20of%20DFS/Topsort%20Related%20Problem/Codeforces%20_1385E.cpp)<br><br>
   [Codeforces 999E](https://codeforces.com/problemset/problem/999/E): [Solution](DFS/Applications%20of%20DFS/Topsort%20Related%20Problem/Codeforces_999E.cpp)<br><br>
   [Light OJ 1034](https://lightoj.com/problem/hit-the-light-switches): [Solution](DFS/Applications%20of%20DFS/Topsort%20Related%20Problem/Light_OJ_1034.cpp)<br><br>
   [UVA 10305](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1246): [Solution](DFS/Applications%20of%20DFS/Topsort%20Related%20Problem/UVA_10305.cpp)<br><br>
   [UVA 11060](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2001): [Solution](DFS/Applications%20of%20DFS/Topsort%20Related%20Problem/UVA_11060.cpp)<br><br>
   [UVA 11686](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2733): [Solution](DFS/Applications%20of%20DFS/Topsort%20Related%20Problem/UVA_11686.cpp)<br><br>
   [UVA 124](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=60): [Solution](DFS/Applications%20of%20DFS/Topsort%20Related%20Problem/UVA_124.cpp)<br><br>
   [UVA 872](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=813): [Solution](DFS/Applications%20of%20DFS/Topsort%20Related%20Problem/UVA_872.cpp)<br><br>
   
  #### <h3 id = "dfst3">TOPICS TO BE COVERED BEFORE NEXT SET OF PROBLEMS : CONNECTED COMPONENTS , STRONGLY CONNECTED COMPONENTS </h3>
  - #### [Finding Connected Components in an Undirected Graph](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Finding%20Connected%20Components%20in%20a%20Undirected%20Graph/)

  - #### [Finding Strongly Connected Components in a Directed graph](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Finding%20Strongly%20Connected%20Components%20in%20a%20Directed%20Graph/)
   
  - #### [Minimum Edges to make a Directed Graph Strongly Connected](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Minimum%20Edges%20to%20Make%20a%20Directed%20Graph%20Strongly%20Connected)
 
  - #### [Given a directed weighted Graph where Each edge has a cost for redirecting and the graph represents a Ring , Redirect the Edges with minimum cost so that the Graph becomes strongly connected](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Given%20a%20Directed%20Graph%20and%20a%20Source%20Vertex%20add%20minimum%20directed%20edges%20to%20the%20Graph%20So%20that%20All%20the%20Vertices%20are%20Reachable%20from%20Source%20Vertex/)  
  
  - #### [Given a Directed Graph is it possible to visit all edges at least once in one single path ? Edges and vertices can be visited more than once](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Given%20a%20Directed%20Graph%20is%20it%20possible%20to%20visit%20all%20edges%20at%20least%20once%20in%20one%20single%20path.%20Edges%20and%20vertices%20can%20be%20visited%20more%20than%20once/)
  - #### [Longest Path in an Unweighted Directed Acyclic Graph using DFS and DP](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Longest%20Path%20in%20an%20Unweighted%20Graph%20Using%20DFS%20and%20DP/)
    
   - #### [Given a Directed Graph Find Such node from where Maximum Number of Nodes can be visited](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Given%20a%20Directed%20Graph%20Find%20Such%20node%20from%20Where%20Maximum%20Number%20of%20Nodes%20Can%20be%20Visited/)
 
 
 #### CONNECTED COMPONENTS, STRONGLY CONNECTED COMPONENTS RELATED PROBLEM
   [Codeforces 1255D](https://codeforces.com/problemset/problem/1255/D) : [Solution](DFS/Applications%20of%20DFS/Connected%20Component%20Related%20Problems/Codeforces_1255D.cpp)<br><br>
   [Codeforces 327D](https://codeforces.com/problemset/problem/327/D) : [Solution](DFS/Applications%20of%20DFS/Connected%20Component%20Related%20Problems/Codeforces_327D)<br><br>
   [Light OJ 1009](https://lightoj.com/problem/back-to-underworld) : [Solution](DFS/Applications%20of%20DFS/Connected%20Component%20Related%20Problems/LightOJ_1009.cpp)<br><br>
   [Light OJ 1012](https://lightoj.com/problem/guilty-prince) : [Solution](DFS/Applications%20of%20DFS/Connected%20Component%20Related%20Problems/LightOJ_1012.cpp)<br><br>
   [Light OJ 1263](https://lightoj.com/problem/equalizing-money) : [Solution](DFS/Applications%20of%20DFS/Connected%20Component%20Related%20Problems/LightOJ_1263.cpp)<br><br>
   [Light OJ 1337](https://lightoj.com/problem/the-crystal-maze) : [Solution](DFS/Applications%20of%20DFS/Connected%20Component%20Related%20Problems/LightOJ_1337.cpp)<br><br>
   [UVA 1244](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3685) : [Solution](DFS/Applications%20of%20DFS/Connected%20Component%20Related%20Problems/UVA%20_1244.cpp)<br><br>
   [UVA 10336](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1277) : [Solution](DFS/Applications%20of%20DFS/Connected%20Component%20Related%20Problems/UVA_10336.cpp)<br><br>
   [UVA 10946](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1887) : [Solution](DFS/Applications%20of%20DFS/Connected%20Component%20Related%20Problems/UVA_10946.cpp)<br><br>
   [UVA 11094](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2035) : [Solution](DFS/Applications%20of%20DFS/Connected%20Component%20Related%20Problems/UVA_11094.cpp)<br><br>
   [UVA 11470](https://onlinejudge.org/external/114/11470.pdf) : [Solution](DFS/Applications%20of%20DFS/Connected%20Component%20Related%20Problems/UVA_11470.cpp)<br><br>
   [UVA 11518](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2513) : [Solution](DFS/Applications%20of%20DFS/Connected%20Component%20Related%20Problems/UVA_11518.cpp)<br><br>
   [UVA 11953](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3104) : [Solution](DFS/Applications%20of%20DFS/Connected%20Component%20Related%20Problems/UVA_11953.cpp)<br><br>
   [UVA 260](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=196) : [Solution](DFS/Applications%20of%20DFS/Connected%20Component%20Related%20Problems/UVA_260.cpp)<br><br>
   [UVA 459](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=400) : [Solution](DFS/Applications%20of%20DFS/Connected%20Component%20Related%20Problems/UVA_459.cpp)<br><br>
   [UVA 469](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=410) : [Solution](DFS/Applications%20of%20DFS/Connected%20Component%20Related%20Problems/UVA_469.cpp)<br><br>
   [UVA 657](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=598) : [Solution](DFS/Applications%20of%20DFS/Connected%20Component%20Related%20Problems/UVA_657.cpp)<br><br>
   [UVA 871](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=812) : [Solution](DFS/Applications%20of%20DFS/Connected%20Component%20Related%20Problems/UVA_871.cpp)<br><br>
   [Light OJ 1168](https://lightoj.com/problem/wishing-snake) : [Solution](DFS/Applications%20of%20DFS/Strongly%20Connected%20Component%20Related%20Problems/LightOJ_1168.cpp)<br><br>
   [Light OJ 1417](https://lightoj.com/problem/forwarding-emails) : [Solution](DFS/Applications%20of%20DFS/Strongly%20Connected%20Component%20Related%20Problems/LightOJ_1417.cpp)<br><br>
   [Light OJ 1210](https://lightoj.com/problem/efficient-traffic-system) : [Solution](DFS/Applications%20of%20DFS/Strongly%20Connected%20Component%20Related%20Problems/Light_OJ_1210.cpp)<br><br>
   [UVA 10731](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1672) : [Solution](DFS/Applications%20of%20DFS/Strongly%20Connected%20Component%20Related%20Problems/UVA_10731.cpp)<br><br>
   [UVA 11504](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2499) : [Solution](DFS/Applications%20of%20DFS/Strongly%20Connected%20Component%20Related%20Problems/UVA_11504.cpp)<br><br>
   [UVA 11709](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2756) : [Solution](DFS/Applications%20of%20DFS/Strongly%20Connected%20Component%20Related%20Problems/UVA_11709.cpp) <br><br>
   [UVA 11770](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2870) : [Solution](DFS/Applications%20of%20DFS/Strongly%20Connected%20Component%20Related%20Problems/UVA_11770.cpp)<br><br>
   [UVA 11838](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2938) : [Solution](DFS/Applications%20of%20DFS/Strongly%20Connected%20Component%20Related%20Problems/UVA_11838.cpp)<br><br>
   [UVA 247](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=183) : [Solution](DFS/Applications%20of%20DFS/Strongly%20Connected%20Component%20Related%20Problems/UVA_247.cpp)<br><br>
   
#### <h3 id = "dfst4"> TOPICS TO BE COVERED BEFORE NEXT SET OF PROBLEMS : ARTICULATION BRIDGE , ARTICULATION POINTS </h3>
   - #### [Finding Articulation Bridges in a graph](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Finding%20Articulation%20Bridges%20in%20a%20Graph/)
 
   - #### [Finding Articulation Points in a graph](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Finding%20Articulation%20Points%20in%20a%20Graph/)
   
   - #### [Making An Undirected Graph Directed So that Number of Strongly Connected Components is minimal](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Making%20A%20Undirected%20Connected%20Graph%20DIrected%20So%20that%20Number%20of%20SCC%20is%20minimal/)

   - #### [Making An Undirected Graph Strongly Connected By using Minimum Number of Bidirectional edge](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Making%20a%20Undirected%20Connected%20Graph%20Strongly%20Connected%20By%20giving%20Direction%20to%20Edges./)

   - #### [Number Of Components after deleting a vertex](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Number%20of%20Components%20after%20deleting%20a%20vertex/)
   
 #### Articulation Bridge and Articulation Point Related Problems
   [Codeforces 118E](https://codeforces.com/problemset/problem/118/E) : [Solution](DFS/Applications%20of%20DFS/Articulation%20Bridge%20Related%20Problems/Codeforces%20_118E.cpp)<br><br>
   [Light OJ 1026](https://lightoj.com/problem/critical-links) : [Solution](DFS/Applications%20of%20DFS/Articulation%20Bridge%20Related%20Problems/LightOJ_1026.cpp)<br><br>
   [UVA 610](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=551) : [Solution](DFS/Applications%20of%20DFS/Articulation%20Bridge%20Related%20Problems/UVA_610.cpp)<br><br>
   [UVA 796](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=737) : [Solution](DFS/Applications%20of%20DFS/Articulation%20Bridge%20Related%20Problems/UVA_796.cpp)<br><br>
   [Light OJ 1063](https://lightoj.com/problem/ant-hills) : [Solution](DFS/Applications%20of%20DFS/Articulation%20Point%20Related%20Problems/LightOJ_1063.cpp)<br><br>
   [UVA 10199](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1140) : [Solution](DFS/Applications%20of%20DFS/Articulation%20Point%20Related%20Problems/UVA_10199.cpp)<br><br>
   [UVA 10765](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1706) : [Solution](DFS/Applications%20of%20DFS/Articulation%20Point%20Related%20Problems/UVA_10765.cpp)<br><br>
   [UVA 315](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=251) : [Solution](DFS/Applications%20of%20DFS/Articulation%20Point%20Related%20Problems/UVA_315.cpp)<br><br>
   
 #### <h3 id = "dfst5" > TOPICS TO BE COVERED BEFORE NEXT SET OF PROBLEMS : DFS ON TREE </h3>
  - #### [Checking an Undirected Graph if it a tree or not ?](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Check%20if%20a%20Undirected%20Graph%20is%20a%20tree%20or%20not/)

  - #### [Shortest Path in a Tree using DFS](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Shortest%20Path%20in%20a%20Tree%20using%20DFS/)
    
  - #### [Given a Set of Vertices of a Tree show do they lie on the same path or not](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Given%20a%20Set%20of%20Vertices%20of%20a%20Tree%20show%20do%20they%20lie%20on%20the%20same%20path%20or%20not/)
     
  - #### [Diameter Of a Tree](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Diameter%20Of%20a%20Tree/)
  - #### [Finding Subtree size for Each Node in a Tree](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Finding%20Subtree%20size%20for%20Each%20Node%20in%20a%20Tree/)
  - #### [Given a tree Weighted and Undirected find two nodes in the tree whose distance is maximum amongst all nodes](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Given%20a%20tree%20Weighted%20and%20Undirected%20%20find%20two%20nodes%20in%20the%20tree%20whose%20distance%20is%20maximum%20amongst%20all%20nodes)
  - #### [Given a tree (a connected graph with no cycles), you have to find the cost to go to the farthest node from each node. The edges of the tree are weighted and undirected](DFS/Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Given%20a%20tree%20(a%20connected%20graph%20with%20no%20cycles),%20you%20have%20to%20find%20the%20cost%20to%20go%20to%20the%20farthest%20node%20from%20each%20node.%20The%20edges%20of%20the%20tree%20are%20weighted%20and%20undirected/)
 #### DFS ON TREE RELATED PROBLEMS
  [Codeforces 1328E](https://codeforces.com/problemset/problem/1328/E) : [Solution](DFS/Applications%20of%20DFS/DFS%20on%20Tree/Codeforces_1328E.cpp)<br><br>
  [Codeforces 1388C](https://codeforces.com/problemset/problem/1388/C) : [Solution](DFS/Applications%20of%20DFS/DFS%20on%20Tree/Codeforces_1388C.cpp)<br><br>
  [Codeforces 1405D](https://codeforces.com/problemset/problem/1405/D) : [Solution](DFS/Applications%20of%20DFS/DFS%20on%20Tree/Codeforces_1405D.cpp)<br><br>
  [Hackerearth Bishu and his Girlfriend](Link Not found) : [Solution](DFS/Applications%20of%20DFS/DFS%20on%20Tree/Hackerearth_Bishu_and_his_Girlfriend.cpp)<br><br>
  [LightOJ 1094](https://lightoj.com/problem/farthest-nodes-in-a-tree) : [Solution](DFS/Applications%20of%20DFS/DFS%20on%20Tree/LightOJ_1094.CPP)<br><br>
  [LightOJ 1257](https://lightoj.com/problem/farthest-nodes-in-a-tree-ii) : [Solution](DFS/Applications%20of%20DFS/DFS%20on%20Tree/LightOJ_1257.cpp)<br><br>
  [LightOJ 1357](https://lightoj.com/problem/corrupted-friendship) : [Solution](DFS/Applications%20of%20DFS/DFS%20on%20Tree/LightOJ_1357.cpp)<br><br>
  [SPOJ PT07Y](https://www.spoj.com/problems/PT07Y/) : [Solution](DFS/Applications%20of%20DFS/DFS%20on%20Tree/SPOJ_PTO7Y.cpp)<br><br>
    
    
- ## <h2 id = "sp" > Shortest Path Algorithms </h2>    
  ### Prequisite : It's better to have a idea about DFS . Because then it is easier to understand Shortest Path Algorithms.
  #### <h3 id = "sp1" >TOPICS TO BE COVERED BEFORE NEXT SET OF PROBLEMS : Breadth First Search </h3>
   - #### [Basic BFS](BFS/Concepts%20Related%20To%20BFS/Basic%20BFS%20Traversal)
   - #### [Given a Graph Find shortest path from source to the destination vertex . But if two or more path has same length then print the lexicographically smaller one](BFS/Concepts%20Related%20To%20BFS/Given%20a%20Graph%20Find%20shortest%20path%20from%20source%20to%20the%20destination%20vertex%20.%20But%20if%20two%20or%20more%20path%20has%20same%20length%20then%20print%20the%20lexicographically%20smaller%20one)         
  #### BFS TRAVERSAL PROBLEMS 
   [Light OJ 1039](https://lightoj.com/problem/a-toy-company) : [Solution](BFS/Problems%20Of%20Online%20Judges/Core%20BFS%20related%20Problems/LightOJ_1039.cpp) <br><br>
   [Light OJ 1046](https://lightoj.com/problem/rider) : [Solution](BFS/Problems%20Of%20Online%20Judges/Core%20BFS%20related%20Problems/LightOJ_1046.cpp) <br><br>
   [Light OJ 1066](https://lightoj.com/problem/gathering-food) : [Solution](BFS/Problems%20Of%20Online%20Judges/Core%20BFS%20related%20Problems/LightOJ_1066.cpp) <br><br>
   [Light OJ 1174](https://lightoj.com/problem/commandos) : [Solution](BFS/Problems%20Of%20Online%20Judges/Core%20BFS%20related%20Problems/LightOJ_1174.cpp) <br><br>
   [Light OJ 1175](https://lightoj.com/problem/jane-and-the-frost-giants) : [Solution](BFS/Problems%20Of%20Online%20Judges/Core%20BFS%20related%20Problems/LightOJ_1175.cpp) <br><br>
   [Light OJ 1238](https://lightoj.com/problem/power-puff-girls) : [Solution](BFS/Problems%20Of%20Online%20Judges/Core%20BFS%20related%20Problems/LightOJ_1238.cpp) <br><br>
   [Light OJ 1271](https://lightoj.com/problem/better-tour) : [Solution](BFS/Problems%20Of%20Online%20Judges/Core%20BFS%20related%20Problems/LightOJ_1271.cpp) <br><br>
   [SPOJ GRAVIITY](https://www.spoj.com/problems/GRAVITY/) : [Solution](BFS/Problems%20Of%20Online%20Judges/Core%20BFS%20related%20Problems/SPOJ_GRAVITY.cpp) <br><br>
   [UVA 10009](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=950) : [Solution](BFS/Problems%20Of%20Online%20Judges/Core%20BFS%20related%20Problems/UVA_10009.cpp) <br><br>
   [UVA 10653](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1594) : [Solution](BFS/Problems%20Of%20Online%20Judges/Core%20BFS%20related%20Problems/UVA_10653.cpp) <br><br>
   [UVA 10959](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1900) : [Solution](BFS/Problems%20Of%20Online%20Judges/Core%20BFS%20related%20Problems/UVA_10959.cpp) <br><br>
   [UVA 10997](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1938) : [Solution](BFS/Problems%20Of%20Online%20Judges/Core%20BFS%20related%20Problems/UVA_10997.cpp) <br><br>
   [UVA 1148](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3589) : [Solution](BFS/Problems%20Of%20Online%20Judges/Core%20BFS%20related%20Problems/UVA_1148.cpp) <br><br>
   [UVA 336](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=272) : [Solution](BFS/Problems%20Of%20Online%20Judges/Core%20BFS%20related%20Problems/UVA_336.cpp) <br><br>
   [UVA 383](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=319) : [Solution](BFS/Problems%20Of%20Online%20Judges/Core%20BFS%20related%20Problems/UVA_383.cpp) <br><br>
   [UVA 429](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=370) : [Solution](BFS/Problems%20Of%20Online%20Judges/Core%20BFS%20related%20Problems/UVA_429.cpp) <br><br>
   [UVA 439](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=380) : [Solution](BFS/Problems%20Of%20Online%20Judges/Core%20BFS%20related%20Problems/UVA_439.cpp) <br><br>
   [UVA 567](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=508) : [Solution](BFS/Problems%20Of%20Online%20Judges/Core%20BFS%20related%20Problems/UVA_567.cpp) <br><br>
   [UVA 762](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=703) : [Solution](BFS/Problems%20Of%20Online%20Judges/Core%20BFS%20related%20Problems/UVA_762.cpp) <br><br>
   [UVA 924](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=865) : [Solution](BFS/Problems%20Of%20Online%20Judges/Core%20BFS%20related%20Problems/UVA_924.cpp) <br><br>
   [UVA 945](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=886) : [Solution](BFS/Problems%20Of%20Online%20Judges/Core%20BFS%20related%20Problems/UVA_945.cpp) <br><br>
   [Light OJ 1055](https://lightoj.com/problem/going-together) : [Solution](BFS/Problems%20Of%20Online%20Judges/More%20than%202%20dimensional%20BFS/LightOJ_1055.cpp) <br><br>
   
 #### <h3 id = "sp2" >TOPICS TO BE COVERED BEFORE NEXT SET OF PROBLEMS : Dijkstra </h3>
   - #### [Basic Dijkstra Concept](Dijkstra/Concepts%20Related%20To%20Dijkstra/Basic%20Dijkstra%20Concept)
   - #### [Given a Directed Weighted Graph , a source vertex , a destination vertex and a weight limit L , Find a route from source to destination vertex such that the sum of weight of all the edges in the path is <= L and Print the maximum weight of edge presented in the path](Dijkstra/Concepts%20Related%20To%20Dijkstra/Given%20a%20Directed%20Weighted%20Graph%20%2C%20a%20source%20vertex%20%2C%20a%20destination%20vertex%20and%20a%20weight%20limit%20L%20%2C%20Find%20a%20route%20from%20source%20to%20destination%20vertex%20such%20that%20the%20sum%20of%20weight%20of%20all%20the%20edges%20in%20the%20path%20is%20<%3D%20L%20and%20Print%20the%20maximum%20weight%20of%20edge%20presented%20in%20the%20path)
  - #### [Given a Directed weighted Graph and a Source Vertex , Find K'th Shortest Distance from source to each vertex](Dijkstra/Concepts%20Related%20To%20Dijkstra/Given%20a%20Directed%20weighted%20Graph%20and%20a%20Source%20Vertex%20%2C%20Find%20K'th%20Shortest%20Distance%20from%20source%20to%20each%20vertex)
  - #### [Given a Number X you need to make it Number Y . In One Step, Suppose the Number is A ,You Can add the Prime factors of A with A .Find the Minimum Steps to transform X to Y](Dijkstra/Concepts%20Related%20To%20Dijkstra/Given%20a%20Number%20X%20you%20need%20to%20make%20it%20Number%20Y%20.%20In%20One%20Step%2C%20Suppose%20the%20Number%20is%20A%20%2CYou%20Can%20add%20the%20Prime%20factors%20of%20A%20with%20A%20.Find%20the%20Minimum%20Steps%20to%20transform%20X%20to%20Y)
  
  #### Dijkstra Related PROBLEMS 
   [Light OJ 1002](https://lightoj.com/problem/country-roads) : [Solution](Dijkstra/Problems%20of%20Online%20Judges/Core%20Dijkstra%20Problems/LightOJ_1002.cpp) <br><br>
   [Light OJ 1019](https://lightoj.com/problem/brush-5) : [Solution](Dijkstra/Problems%20of%20Online%20Judges/Core%20Dijkstra%20Problems/LightOJ_1019.cpp) <br><br>
   [Light OJ 1379](https://lightoj.com/problem/toll-management) : [Solution](Dijkstra/Problems%20of%20Online%20Judges/Core%20Dijkstra%20Problems/LightOJ_1379.cpp) <br><br>
   [UVA 10986](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927) : [Solution](Dijkstra/Problems%20of%20Online%20Judges/Core%20Dijkstra%20Problems/UVA_10986.cpp) <br><br>
   [UVA 1112](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3553) : [Solution](Dijkstra/Problems%20of%20Online%20Judges/Core%20Dijkstra%20Problems/UVA_1112.cpp) <br><br>
   [UVA 929](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=870) : [Solution](Dijkstra/Problems%20of%20Online%20Judges/Core%20Dijkstra%20Problems/UVA_929.cpp) <br><br>
   [Light OJ 1099](https://lightoj.com/problem/not-the-best) : [Solution](Dijkstra/Problems%20of%20Online%20Judges/K'th%20Shortest%20Distance/LightOJ_1099.cpp) <br><br>
   [Light OJ 1141](https://lightoj.com/problem/number-transformation) : [Solution](Dijkstra/Problems%20of%20Online%20Judges/Number%20Transformation%20Related%20Problems/LightOJ_1141.cpp) <br><br>
   
 #### <h3 id = "sp3" >TOPICS TO BE COVERED BEFORE NEXT SET OF PROBLEMS : Bellman-Ford </h3> 
   - #### [Bellman Ford Algorithm to Find negative Cycle from a source vertex](Bellman%20Ford/Concepts%20Related%20To%20bellman%20Ford/Bellman%20Ford%20Algorithm%20to%20Find%20negative%20Cycle%20from%20a%20source%20vertex)
   - #### [Bellman Ford algorithm if there is not any negative cycle](Bellman%20Ford/Concepts%20Related%20To%20bellman%20Ford/Bellman%20Ford%20algorithm%20if%20there%20is%20not%20any%20negative%20cycle)
   - #### [Bellman Ford algorithm to Find any negative cycle](Bellman%20Ford/Concepts%20Related%20To%20bellman%20Ford/Bellman%20Ford%20algorithm%20to%20Find%20any%20negative%20cycle)
   - #### [Given a Directed Graph , Where each node will have a weight (which can be both negative and positive) ,A traversal will start with energy level 100 and every time we reach a node we will add it's weight to current energy level .Is it possible to reach the finishing vertex with energy value greater than zero. In our path from start to end we also need to cross every vertex with energy level greater than zero](Bellman%20Ford/Concepts%20Related%20To%20bellman%20Ford/Given%20a%20Directed%20Graph%20%2C%20Where%20each%20node%20will%20have%20a%20weight%20(which%20can%20be%20both%20negative%20and%20positive)%20%20%2CA%20traversal%20will%20start%20with%20energy%20level%20100%20and%20every%20time%20we%20reach%20a%20node%20we%20will%20add%20it's%20weight%20to%20current%20energy%20level%20.Is%20it%20possible%20to%20reach%20the%20finishing%20vertex%20with%20energy%20value%20greater%20than%20zero.%20In%20our%20path%20from%20start%20to%20end%20we%20also%20need%20to%20cross%20every%20vertex%20with%20energy%20level%20greater%20than%20zero)
   - #### [Given a Directed Graph and a ratio R , Where each edge of the graph will contain both Profit and loss value , Is it possible to find such cycles where the ratio of sum of profit and loss will be strictly greater than R](Bellman%20Ford/Concepts%20Related%20To%20bellman%20Ford/Given%20a%20Directed%20Graph%20and%20a%20ratio%20R%20%2C%20Where%20each%20edge%20of%20the%20graph%20will%20contain%20both%20Profit%20and%20loss%20value%20%2C%20Is%20it%20possible%20to%20find%20such%20cycles%20where%20the%20ratio%20of%20sum%20of%20profit%20and%20loss%20will%20be%20strictly%20greater%20than%20R)
   - #### [Given a Directed weighted Graph ( Edges can contain both negative and positive weight ) , Find the Nodes from where if we start our traversing we can enter a negative cycle](Bellman%20Ford/Concepts%20Related%20To%20bellman%20Ford/Given%20a%20Directed%20weighted%20Graph%20(%20Edges%20can%20contain%20both%20negative%20and%20positive%20weight%20)%20%2C%20Find%20the%20Nodes%20from%20where%20if%20we%20start%20our%20traversing%20we%20can%20enter%20a%20negative%20cycle)
  
  #### Bellman-Ford Related PROBLEMS
   [Light OJ 1074](https://lightoj.com/problem/extended-traffic) : [Solution](Bellman%20Ford/Problems%20of%20Online%20judges/LightOJ_1074.cpp) <br><br>
   [Light OJ 1108](https://lightoj.com/problem/instant-view-of-big-bang) : [Solution](Bellman%20Ford/Problems%20of%20Online%20judges/LightOJ_1108.cpp) <br><br>
   [Light OJ 1221](https://lightoj.com/problem/travel-company) : [Solution](Bellman%20Ford/Problems%20of%20Online%20judges/LightOJ_1221.cpp) <br><br>
   [UVA 10449](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1390) : [Solution](Bellman%20Ford/Problems%20of%20Online%20judges/UVA_10449.cpp) <br><br>
   [UVA 10557](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1498) : [Solution](Bellman%20Ford/Problems%20of%20Online%20judges/UVA_10557.cpp) <br><br>
   [UVA 558](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=499) : [Solution](Bellman%20Ford/Problems%20of%20Online%20judges/UVA_558.cpp) <br><br>
      
