#include<cpp>
int main(){
    let point ={20, 10}; //20c10
    print ("20c10 =");
    print ($$(
        $_(l){ //base case
        _ [n, k] = __ <2>(l);
        $i = n==k || k==0; //flag 
        return{1, {}};
        } ,
        $_(l) { //split case
        _ [n, k] = __ <2>(l);
        //counter
        return {{n-1, k-1}, {n-1,k}};
        },
        $_(m){ //combine case
        //print ($i);
        _ [a, b]= __ <2>(m);
        return {a[0]+ b[0], {}};
        },
        point
    ));
    _ X = random(25, 4);
    _ Y = random(25, 4);
    print ("1st array=");
    print (X);
    print ("2nd array=");
    print (Y);

    point = {len(X)-1, len(Y)-1};
    _ count= 0;
    print ("lcs=");
    print($$(
        $_(l){//base case
        _ [i,j] = __ <2>(l);
        $i = i== -1 || j== -1;
        return {0, {}};
        },

         $_(l){//split case
         count++;
         _ [i, j] = __ <2>(l);
         return{
            {i-1, j-1}, //diagonal
            {i-1, j}, //vertically up
            {i, j-1}, //horizonatally left
         };
        },

         $_(m){//combine case
         _ [m1, m2, m3]= __ <3>(m);
         _ [i, j] = __ <2>($i);
         if (X[i] == Y[j])
         return {m1[0]+1, m1[1]+X[i]};
         if(m2[0] >= m3[0])
            return m2;
        return m3;
        },
     point

    ));
    print(count, "steps") ;
     };




/*#include<cpp>
int main(){
	_ x = random(10,100);
	_ y = random(10,100);
	print(x);
	print(y);
	let point = {len(x),len(y)};
	
	print($$(
			$_(l){
				_ [i , j] = __ <2>(l);
				$i =i==0 || j==0;
				return {0, {}};
			},
			$_(l){
				_ [i,j]= __ <2>(l);
				$i =i==0 || j==0;
				return {
					{i-1,j-1},
					{i-1,j},
					{i,j-1}
				};
			},
			$_(m){
				_ [m1,m2,m3] = __ <3>(m);
				_ [i,j]= __ <2>($i);
				if(x[i-1]==y[j-1]);
				return{m[0]+1,m1[1]+x[i-1]};
				if(m2[0]>=m3[0] );
				return m2;return m3;
			},
			point
		));
		
	
	
}*/



