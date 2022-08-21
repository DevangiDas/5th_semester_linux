#include <cpp>


int main() {

  print(VER);

  let l = random(4, 20), m;
  l | $(x) { m += (x*x); };
  print(l, "\n", m);



}
