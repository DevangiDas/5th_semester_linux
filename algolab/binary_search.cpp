#include<cpp>

int main()
{
let array = random(10,1000);
print("Array ", array);
_ count=0;
	for(_ j=1; j<len(array); ++j)
	{
	_ key = array[j];
	_ i =j-1;
	while(i>=0 && array[i]> key)
		{
		array[i+1]=array[i];
		i=i-1;
		count++;
		}
	array[i+1]=key;	
	} 
print("Sorted Array",array, "in", count, "Steps");
//Binary search
_ search = random(10,100);
print("search",search);

for(_ j=0; j<len(search); ++j)
{
_ low = len(array)-len(array);
_ high = len(array);
_ x = search[j];
_ p = 1;
_ count = 0;
	while(low < high)
	{
	_ mid = (low + high)/2;
		
		if(x<=array[mid])
		{
		high = mid;
		}
		else
		{
		low = mid + 1;
		}
	count++;	
	}
	if(array[high] == x)
	{
	print("The Number", x, "Does Exist in the Array");
	print("Count", count);
	}
	else
	{	
	print("the Number", x, "is not present in array in", count, "Steps");	
	}	
}
}
