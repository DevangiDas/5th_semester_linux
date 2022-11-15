#include <cpp>


int main() {
let count1 = 0;
  _ unweightedGraph = [](){
    let v;
    for(_ i=0; i<9; ++i) v <<= {IMAX, -1, i};
    let g = {v, {
      {1, 7}, {0, 2, 7}, {1, 8},
      {4, 5}, {3, 5}, {3, 4},
      {7, 8}, {0, 1, 6, 8}, {2, 6, 7}
    }};
    return __<2>(g);
  };

  _ weightedGraph = []() {
    let v;
    for(_ i=0; i<9; ++i) v <<= {IMAX, -1, i};
    let g = { v, {
      {{1, 4}, {7, 8}}, {{0, 4}, {2, 8}, {7, 11}},
      {{1, 8}, {3, 7}, {5, 4}, {8, 2}}, {{2, 7}, {4, 9}, {5, 14}},
      {{3, 9}, {5, 10}}, {{2, 4}, {3, 14}, {4, 10}, {6, 2}},
      {{5, 2}, {7, 1}, {8, 6}}, {{0, 8}, {1, 11}, {6, 1}, {8, 7}},
      {{2,2}, {6, 6}, {7, 7}}
    }};
    return g;
  };

  _ genGraph = [] (_ nv, _ ne, _ W, _ dir) {
    let v;
    for(_ i=0; i<nv; ++i) v <<= {IMAX, -1, i};
    let a;
    let adj;
    for(_ i=0; i<nv; ++i)
    for(_ j=0; j<nv; ++j)
      if((dir && i!=j)||(!dir && i<j))
      a <<= {i, j, random(1, W)[0]+1};
    _ count = 0;
    while(count<ne && len(a)>0) {
      swap(a[0], a[random(1,len(a))[0]]);
      let e = --a;
      _ [u, v, w] = __ <3>(e);
      adj[u] <<= {v, w};
      if(!dir) adj[v] <<= {u, w};
      ++count;
    }
    let g = {v, adj};
    return __<2>(g);
  };

  _ pathToStr = [](_ a, _ b, _ d, _& l) {
    let t = a + "-";
    l | $(x) {t += x + "-";};
    return t + b + " ["
      + (d==IMAX?"+inf":d==IMIN?
      "-inf":d) + " units]\n";
  };

  _ tracePaths = [&](_& v) {
    let t = "";
    v | $(x) {
      let l;
      _ j = x[1];
      while(j!=-1) {l = let{j}+l; j=v[j][1];}
      t += pathToStr(len(l)>0?--l:x[2], x[2], x[0], l);
    };
    return t;
  };

  //Dijkstra
  _ dijkstra = [&](_ g, _ s) {
    _ [V, Adj] = __ <2>(g);
    V[s][0] = 0;
    _ Q = V.index();
    while(len(Q)>0) {
    _ u = Q % $(x) {return V[x][0];};
    Adj[u] | $(e) {
    _ [v,w] = __ <2>(e);
    if(V[v][0] > V[u][0] + w) {
    V[v][0] = V[u][0] + w;
    V[v][1] = u;
    }
    };
    }
    print("Dijkstra, all shortest paths from", s, ":\n", tracePaths(V));
    print("count:-",count1);
  };

  _ g = weightedGraph();
  dijkstra(g, 0);

}
