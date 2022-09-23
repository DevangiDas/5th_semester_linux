#include<cpp>

int main(){

	let start = {1,3,0,5,3,5,6,8,8,2,12},
	finish = {4,5,6,7,9,910,11,12,14,16};

	_ activityselection = [](_ s,_ f) {
		let A = {0};
		_ j = 0;
		for( _ i = 1 ;i<len(s); ++i){
			if(s[i]>=f[j]) {
				A += {i};
				j = i;
			}
		}
		
		return A;
	};
	print (activityselection(start , finish));
}
