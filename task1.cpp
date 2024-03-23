#include <iostream>
struct IntPair{
	int first;
	int second;

};
IntPair* zip(const int array1[], const int array2[], int size ){
	IntPair*result = new IntPair[size];
	    
	for (int i = 0; i < size; ++i){
		result[i].first = array1[i];
		result[i].second = array2[i];
	}
	return result;
}
int main()
{
	int array1[] = {2,3,4,1};
	int array2[] = {6,7,8,9,10};
	int size = sizeof(array1) / sizeof(array1[0]);
	IntPair* zippedArray = zip(array1, array2, size);

	for(int i = 0; i <size; ++i){
		std::cout << zippedArray[i].first<<" "<<zippedArray[i].second<<"";
	}
	std::cout<<std::endl;
	delete[] zippedArray;
	return 0;
}
