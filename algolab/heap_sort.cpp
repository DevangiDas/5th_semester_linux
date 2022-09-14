#include <cpp>

int main(){
	_ arr = random(10,1000);
	print("array:",arr);
	_ count = 0;
	_ maxheapify = [&](_& A,_ n,_ i,_ hpf)->void {
		_ l = 2*i+1;
		_ r = 2*i+2;
		_ max = i;
		if(l<n) ++count;
		if(r<n) ++count;
		if(l<n && A[l]>A[max])
		max = l;
		if(r<n && A[r]>A[max])
		max = r;
		if(max!=i){
		swap(A[i],A[max]);
		hpf(A,n,max,hpf);
		}
	};
	
	_ testheap = [](_& A, _ i, _ th)->int {
		_ l = 2*i+1, r = 2*i+2, n = len(A);
		_ lvalid = 1 , rvalid = 1;
		if(l<n) lvalid = A[l]<=A[i] ? th(A,l,th) : 0;
		if(r<n) lvalid = A[r]<=A[i] ? th(A,r,th) : 0;
		return lvalid && rvalid ? 1 : 0;
	};
	
	print(testheap(arr,0,testheap) ? "Valid heap:" : "NOt valid");
	
	//Build heap
	for(_ i = len(arr)/2; i>0; i--)
		maxheapify(arr, len(arr), i, maxheapify);
		print("HEAP:",arr);
		//print(testheap(arr,0,testheap) ? "Valid heap:" : "NOt valid");
		print("STEPS:",count);
		
		for(_ i = len(arr)-1;i>0;--i){
			swap(arr[0],arr[i]);
			maxheapify(arr,i,0,maxheapify);
		}
		
		print("Sorted:",arr);
		print("COMPARISIONS:",count);

}
