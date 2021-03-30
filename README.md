# Graph-Theory 
   
  ## Index
   
 <ul>
 <li> <h3> <a href = "#dfs" > Depth First Search and it's Variants </a> </h3> </li> 
 <li> <h3> <a href = "#bfs" > Breadth First Search </a> </h3> </li>
 <li> <h3> <a href = "#dijsktra" > Dijkstra </a> </h3> </li>
 <li> <h3> <a href = "#bellmanford" > Bellman Ford  </a> </h3> </li>
 <li> <h3> <a href = "#mis" > Miscellaneous </a> </h3> </li>
 </ul>
 <br><br><br>

 - ## <h2 id = "dfs" > Depth First Search and it's Variants </h2> 
   ### Prequisite : Recursion .
   <p> Cycle Checking , Topsort , Connected Components , Strongly Connected Components , Articulation Points , Articulation Bridge etc various algorihms are actually application 
       of DFS .   </p>
       
   #### TOPICS TO BE COVERED BEFORE NEXT SET OF PROBLEMS
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
   
  #### TOPICS TO BE COVERED BEFORE NEXT SET OF PROBLEMS
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
   
  #### TOPICS TO BE COVERED BEFORE NEXT SET OF PROBLEMS
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
   
#### TOPICS TO BE COVERED BEFORE NEXT SET OF PROBLEMS
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
   
 #### TOPICS TO BE COVERED BEFORE NEXT SET OF PROBLEMS
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
    
    

   
