#include <iostream>//task1, swapfunction:
/*void swapfoo(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int main(){
	int x = 5;
	int y = 6;
	std::cout<<"Befor swapping  ";

	std::cout<< "x ="<< x << "\n"<<"y =" << y<<"\n" ;
	swapfoo(&x, &y);
	std::cout<<"After swapping ";
	std::cout<<"x ="<<x<<"\n"<<"y ="<<y;
}*/
/*int sumArray(int *arr, int size){//task2, Sum of Array:
	int sum = 0;
	int *ptr = arr;
	for(int i = 0; i < size; ++i){
		sum = sum + *ptr;
		++ptr;
	}
	return sum;
}
int main(){
	int arr[]={4,6,7,8};
	int size = sizeof(arr) / sizeof(arr[0]);
	std::cout<<"Sum of the elements are  "<< sumArray(arr,size);

}*/void reverseArray(int* arr, int size) {//revers array using  ponters:
    int *start = arr; 
    int *end = arr + size - 1; 

    while (start < end) {
        
        int temp = *start;
        *start = *end;
        *end = temp;

       
        start++;
        end--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
     std::cout << "Before reversing: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    reverseArray(arr, size);

    std::cout << "After reversing: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
