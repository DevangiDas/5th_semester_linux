#include <cpp>

int main() {
  print(VER); //2206a

  //Welcome to C++
  let a = 10, b = "hello";
  print(a, b);

  //Generate 2 random numbers between 0 to 19
  _ a1 = random(2, 20);
  print("Random:", a1);

  //Swap the two numbers
  swap(a1[0], a1[1]);
  print("After swapping:", a1);

  //Reset the array
  a1 = {10, 20, 30};
  print("After reset:", a1);

  //Append elements
  a1 += {40, 50};
  print("After appending:", a1);
  print("Count:", len(a1));

  //Popping and peeking
  print("Popping first:", --a1);
  print(a1);
  print("Popping last:", a1--);
  print(a1);
  print("Peeking last:", *a1, "\n");

  //Applying a filter
  let a2;
  a1 | $(x) {a2+=x*x;};
  print("Filtered to squares:", a2);

  //Generating array index
  print("Index:", a2.index());
  print("Sorted index:", a2.index(1));
  print("Reverse sorted index:", a2.index(-1));

  //Linear search
  _ a3 = random(6, 10);
  _ a4 = random(6, 10);
  print("Linear search: find", a4, "in", a3);
  a4 | $(x) {printc(
    x, ":", a3 | $(y){if(y==x) stop;} ? "yes, ":"no, "
  );};
  print();

  //Extracting minimum based on function value
  print("Extracting minimum from", a3);
  print(a3 % $(x) {return x;});
  print("After extraction:", a3, "\n");

  //Loop invariant syntax
  print("List of squares through loop invariant syntax:");
  let squares;
  $$(
      $(l) {l += 1;},
      $(l) {l += (len(l)+1)*(len(l)+1);},
      $(l) {return len(l) < 12;},
      squares
  );
  print("first 12 squares", squares);

  //Loop invariant syntax to find primes
  let primes, k = 2;
  $$(
    $(l) {l += k;},
    $(l) {
      ++k;
      if (!(l | $(x) {if(k%x==0) stop;}))
        l+=k;
    },
    $(l) {return len(l)<12;},
    primes
  );
  print("first 12 primes:", primes, "\n");

  //Euclid's algorithm to find GCD
  let num;
  $$(
    $(l) {l = {112, 182};},
    $(l) {
      _[a, b] = __<2>(l);
      _ d = b; b=a%b; a=d;
    },
    $(l) {return l[1]!=0;},
    num
  );
  print("Euclid's algorithm, GCD:", num[0], "\n");

  //Insertion sort
  let mylist = random(10, 20), sorted;
  _ count = 0;
  mylist | $(x) {
    let temp, added = 0;
    sorted | $(y) {
      if(added==0) {
        ++count;
        if(y>x) {
          temp+=x;
          added=1;
        }
      }
      temp+=y;
    };
    if(added==0) temp+=x;
    sorted = temp;
  };
  print("insertion sort:", sorted, count, "comparisons");
}

