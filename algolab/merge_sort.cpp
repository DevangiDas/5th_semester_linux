#include<cpp>

int main()
	{
	_ arr = random(10000,10000);
	print("INPUT ARRAY:", arr);
	_ count = 0;
	
	_ result = $$(
	$_(l) {            //base case
	$i = len(l)<2;
	return l;
	},
	
	$_(l) {                  //split
	let a,b;
	l | $(x) {
		if (len(a)<len(l)/2)
		a += x;
		else b += x;
		};
		return {a,b};
	},
	
	$_(m) {
	_ [a, b] = __ <2>(m);
	_ n = len(a) + len(b);
	a += IMAX;
	b += IMAX;
	let c;
	while(len(c)<n){
		++count;
		a[0]<=b[0] ? c+=--a : c
		+=--b;
		}
		
		return c;
	
	},
	
	arr
	);
	
	print("SORTED ARRAY:",result, "\nSTEPS:",count);
	}
	
	/*std::vector v = {10,20,30};
	for(_ x: v)
		std::cout << x*x <<
		"\n";
		std::cout << random() <<
		"\n"*/
