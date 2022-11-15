#include<cpp>
int main() { let count = 0;
_ Graph = [](){
    let v;
    for(_ i=0; i<9; ++i) 
    	v <<= {IMAX, -1, i};
 return  let{v, {{0, 1}, {1, 0}, {0, 7}, {7, 0}, {1, 2}, {2, 1}, {1, 7}, {7, 1}, {2, 8}, {8, 2}, {3, 4}, {4, 3}, {3, 5}, {5, 3}, {4, 5}, {5, 4}, {6, 7}, {7, 6}, {6, 8}, {8, 6}, {7, 8}, {8, 7}}, v.index()};
};
print("DFS All tree");
let stk;
	_ graph = Graph();
	graph[0].index() | $(x)
	{
	$$(
	   $(g)
		{	   
	   	if (g[0][x][2] != -1)
	   		{
	   		g[0][x][2] = -1;
	   		stk += x[1];
	   		print("| ",x[1],"");
	   		count = count + 1;
	   		
	   		}
		},
	   $(g)
	   {
	   	_ i = stk--;
	   	g[1] | $(e)
	   	{
	   		if(i == e[0] && g[0][e[1]][2] != -1)
	   		{
	   		   g[0][e[1]][2] = -1;
	   		   stk += e[1];
	   		   print(e[1], "");
	   		   count = count + 1;
	   		}
	   	};
	   	
	   }, 		
	$(g) { return len(stk) > 0;},
	graph  
	);
	};
	print();
	print("Number of steps: ", count);
	}
