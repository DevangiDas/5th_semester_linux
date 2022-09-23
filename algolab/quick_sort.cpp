#include<cpp>

int main()
{	
	_ arr = random(10,1000);
	_ copy = arr;
	print("INPUT:",arr);
	_ count = 0;
	
	_ partition  = [](_& A,_ p ,_ r){
		_ x = A[r];
		_ i = p;
		for(_ j = p;j<r;++j)
			if(A[j]<=x){
			swap(A[i],A[j]);
			//i = i + 1;
			++i;
			}
		swap(A[i],A[r]);
		return i;
	};
	
	_ quickSort = [&](_& A, _ p, _ r, _ qs) ->void{
		if(p<r){
		_ q = partition(A,p,r);
		qs(A,p,q-1,qs);
		qs(A,q+1,r,qs);
		}
	};
	
	quickSort(arr,0,len(arr)-1,quickSort);
	//print("After partition:", arr);
	//print("q=",quickSort);
	print("\nSORTED:",arr);
	//print("\nSTEPS:",count);
	
	
	print("\nCOPY:", copy);
	let pivot;
	
	_ result = $$(
	$_(l) {          //base case
		$i = len(l)<2;
		return l;
	},
	
	$_(l) {          //split case
		pivot += l--;
		let a, b;
		l | $(x){
		++count;
		x<= *pivot? a+=x : b+=x;   //pivot[-1]
		};
		return{a, b};
	},
	
	$_(l) {          //combine case
		_ [a, b] = __<2>(l);
		return a + (pivot--) + b;
	},
	
	copy
	);
	print("\nSORTED",result);
	print("\nSTEPS:",count);
	
}
			
		
