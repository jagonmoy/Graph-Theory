- ## PREREQUISITE : Bellman-Ford 
- ### EXPLANATION :
 Suppose There is a cycle of 'E' edges which follows above condition that means, <br><br>
 where P<sub>i</sub> represents Profit of edge and L<sub>i</sub> represent loss of each edge. <br>
 (P<sub>1</sub> + P<sub>2</sub> +P<sub>3</sub> +... P<sub>E</sub>)/(L<sub>1</sub> + L<sub>2</sub> + L<sub>3</sub> +... L<sub>E</sub>) > R <br><br>
 => (P<sub>1</sub> + P<sub>2</sub> + P<sub>3</sub> + ... P<sub>E</sub>) > R(L<sub>1</sub> + L<sub>2</sub> + L<sub>3</sub> + ... L<sub>E</sub>) <br><br>
 =>  P<sub>1</sub> - RL<sub>1</sub> + P<sub>2</sub> - RL<sub>2</sub> +  P<sub>3</sub> -  RL<sub>3</sub> + ... +  P<sub>E</sub> -  RL<sub>E</sub> > 0 <br><br>
 => <sub><sub> **1<= i <= E** </sub></sub><span>&#8721;</span> P<sub>i</sub> - RL<sub>i</sub> > 0 <br><br>
 
 So that it Means, We need to find a positive weighted cycle where each edge of the Cycle will represent P<sub>i</sub> - RL<sub>i</sub> . It is the exact oppsite of Bellman ford 
 algorithm . That's Why we will take values of P<sub>i</sub> as negative value and L<sub>i</sub> as positive value . Basically we will mark each edge as <br>  -P<sub>i</sub>+RL<sub>i</sub>
 and then Find negative cycle via Bellman ford algoithm .
- ### RELATED PROBLEM :
[Light OJ 1221](http://lightoj.com/volume_showproblem.php?problem=1221)
