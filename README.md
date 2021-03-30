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
   - #### [Given a Source Vertex and a graph Consisting of Both Directed and Undirected Edges give direction to the existing undirected edges so that Number of visited vertices from Source vertex is maximized](Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Given%20a%20Source%20Vertex%20and%20a%20graph%20Consisting%20of%20Both%20Directed%20and%20Undirected%20Edges%20give%20direction%20to%20the%20existing%20undirected%20eges%20so%20that%20Number%20of%20visited%20vertices%20from%20Source%20vertex%20is%20maximized/) 
   - #### [Given a Source Vertex and a graph Consisting of Both Directed and Undirected Edges give direction to the existing undirected edges so that Number of visited vertices from Source vertex is minimized](Applications%20of%20DFS/Concepts%20Related%20to%20DFS/Given%20a%20Source%20Vertex%20and%20a%20graph%20Consisting%20of%20Both%20Directed%20and%20Undirected%20Edges%20give%20direction%20to%20the%20existing%20undirected%20edges%20so%20that%20Number%20of%20visited%20vertices%20from%20Source%20vertex%20is%20minimized/) 

   
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
   
     
