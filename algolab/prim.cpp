#include <cpp>

int main() { _ count = 0;

  _ weightedGraph = []() {
    let v;
    for(_ i=0; i<9; ++i) v <<= {IMAX, -1, i};
    let gr = { v, {
      {{1, 4}, {7, 8}}, {{0, 4}, {2, 8}, {7, 11}},
      {{1, 8}, {3, 7}, {5, 4}, {8, 2}}, {{2, 7}, {4, 9}, {5, 14}},
      {{3, 9}, {5, 10}}, {{2, 4}, {3, 14}, {4, 10}, {6, 2}},
      {{5, 2}, {7, 1}, {8, 6}}, {{0, 8}, {1, 11}, {6, 1}, {8, 7}},
      {{2,2}, {6, 6}, {7, 7}}
    }};
    return __<2>(gr);
  };
  
  _ prim = [](_ g, _ s, _ count) {
    _ [V, Adj] = g;
    V[s][0]=0; /*distance of start vertex to 0*/
    _ Q = V.index();
    Q.SetCost($_(x) {return V[x][0];});
    while(len(Q)>0) {
      _ u = --Q;
    count++;
      print(V[u][1] != -1,u,V[u][0]);/* Let v be parent(u) and w be weight between them. 
        Print: v u (w) */
      Adj[u] | $(e) {
      _ [v , w] = __ <2>(e);
        if( w < V[v][0]/* if w is less than cost in v*/ ) { 
          V[v][0] = w;
          V[v][1] = u;/*update cost and parent of v */ 
          Q.signal(v);
          count++;
        }
      };
    }
    print("no of steps", count);
  };
  prim(weightedGraph(), 0, count);
            
}
