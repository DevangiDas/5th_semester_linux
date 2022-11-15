#include<cpp>

int main(){
	let hm = random(100,1000),
	//let hm = {45,13,12,16,9,5},
	//t = {"a=" , "b=" , "c=" , "d=" , "e=" , "f="},
	let t;
	index | $(x) { t+= "="; };
	index  = hm.index();
	_ count = 0;
	print(hm);
	while(len(index)>1) {
		_ k1 = index % $(x) { ++count; return hm[x]; };
		_ k2 = index % $(x) { ++count; return hm[x]; };
		hm[k1] += hm[k2];
		hm[k2] = IMAX;
		let s  = "";
		t[k1] | $(c) { s+=c; if(c=="=") s+="0"; };
		s += " ";
		t[k2] | $(c) { s+=c; if(c=="=") s+="1"; };
		t[k1] = s;
		index += k1;
	}
	//print(t[index[0]]);
	print(count, "steps:");	
	
	//_ count2 = 0;
	//let vec  = random(1000,1000000);
	
	//index = vec.index();
	//while(len(index)>0){
	//min = IMAX;
	//index | $(x) { if (x<min) min = x; };
	//index -= min;
	//++count2;
	//}
	//print(count2, "comparisions:");
	
	//while(len(vec)>0){
		//_ x = vec % $(x) { ++count2 ; return x; };
		//print(x);
	//}
	//print(count2, "comparisions:");
}
