/*E23 Sum of elements of array by repeatedly dividing into two */
#include<stdio.h>
int func(int arr[], int low, int high);
main( )
{
    int arr[6]={1,2,3,4,8,10};
    printf("%d\n",func(arr,0,5) );
}

int func(int arr[], int low, int high)
{
	int mid, left, right;
	printf("Func Start : low :%d High :%d\n", low, high);
	if(low==high) {
		printf("RETURNING >>>> :%d\n", arr[low]);
		return arr[low];
	}
	mid = (low+high)/2;
	left = func(arr,low,mid);
	printf("Func END1 : LEFT :%d\n", left);
	right = func(arr,mid+1,high);
	printf("Func END2 : RIGHT :%d\n", right);
	printf(" FUNC **** Return l+r :%d\n", left+right);
	return left + right;
}

