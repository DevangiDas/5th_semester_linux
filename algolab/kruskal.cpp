#include <cpp>

int main() {

  _ weightedGraph = []() {
    let v;
    for(_ i=0; i<9; ++i) v <<= {IMAX, -1, i};
    return _2({ v, {
      {{1, 4}, {7, 8}}, {{0, 4}, {2, 8}, {7, 11}},
      {{1, 8}, {3, 7}, {5, 4}, {8, 2}}, {{2, 7}, {4, 9}, {5, 14}},
      {{3, 9}, {5, 10}}, {{2, 4}, {3, 14}, {4, 10}, {6, 2}},
      {{5, 2}, {7, 1}, {8, 6}}, {{0, 8}, {1, 11}, {6, 1}, {8, 7}},
      {{2,2}, {6, 6}, {7, 7}}
    }});
  };
  
  _ kruskal = [&](_ g) {
    _[V, Adj] = g;

    let Q;
    V.index() | $(u) {
      /* For each neighbor v of u and weight w between them,
      insert into Q the tuple {u, v, w} */
    Adj[u] | $$(v, w)	{
    Q <<= {u, v, w};
    };
    };

    Q.setCost($_(e) {return e[2];});

    while(len(Q)>0) {
      _[u, v, w] = _3(--Q);
      
      if(V[v][2] != V[u][2]/colors of u and v are different/) {
       print(v, u ,"("+w+")"); /* print: u v (w) */
        _ old = V[v][2], newc = V[u][2];
        V | $(x) {
        if(x[2] == old)
        	{
          x[2] = newc;
        	}
        };
        /* for each old color vertex, set its color to newc */
      }
    }
  };
  kruskal(weightedGraph());
}
