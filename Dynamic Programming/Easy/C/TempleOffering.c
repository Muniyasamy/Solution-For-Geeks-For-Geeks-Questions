/*
Link : http://practice.geeksforgeeks.org/problems/temple-offerings/0
Consider a devotee wishing to give offerings to temples along a mountain range. The temples are located in a row at different heights. Devotee is very religious and wants to offer each temple at least one offering. If two adjacent temples are at different altitudes, then the temple that is higher up should receive more offerings than the one that is lower down. If two adjacent temples are at the same height, then their offerings relative to each other does not matter. Find the minimum number of offerings to bring.

Input:
The first line of the input contains an integer T, denoting the number of test cases. Then T test cases follow. First line of each test case contains an integer N denoting the total number of temples. Next line contains N space seperated integers denoting the height of the respective temple.

Output:
For each test case output a single line denoting the minimum number of offering that the devotee should bring.

Constraints:
1<=T<=104
1<=N<=106
1<=templeHeight<=103

Example:
Input:
2
3
1 2 2
6
1 4 3 6 2 1

Output:
4
10

Explanation:

Test case 1:
All temples must receive at-least one offering. Now, the second temple is at a higher altitude compared to the first one. Thus it receives one extra offering. The second temple and third temple are at the same height, so we do not need to modify the offerings. Offerings given are therefore: 1, 2, 1 giving a total of 4.

Test case 2:
We can distribute the offerings in the following way, 1, 2, 1, 3, 2, 1. The second temple has to receive more offerings than the first due to its height being higher. The fourth must receive more than the fifth, which in turn must receive more than the sixth. Thus the total becomes 10.

*/
#include<stdio.h>
#include<stdlib.h>

int max( int left , int right ) {
	if ( left > right )
	    return left ;
	return right ;
}

int templeOffer ( int *arr, int n )  {
	int  i,count = 0 ;
	int *dp_left = (int *) malloc ( sizeof(int) * n ) ;
	int *dp_right = (int *) malloc ( sizeof(int) * n ) ;
	
	
	for ( i = 0 ; i < n ; i++ )
	   dp_left[i] = dp_right[i] = 1 ;
	
	for ( i = 1 ; i < n ; i++ )
	    if ( arr[i-1] < arr[i] )
	         dp_left[i] = dp_left[i-1] + 1 ;
	    
	for ( i = n - 2 ; i >= 0 ; i-- )
	    if ( arr[i+1] < arr[i] )
	         dp_right[i] = dp_right[i+1] + 1 ;
	
	for ( i = 0 ; i < n ; i++ )
	   count += max ( dp_left[i],dp_right[i] ) ;
	
	free(dp_left) ;
	free(dp_right) ;
	
	return count ;
}

int main() {
	int t ;
	int n ;
	int *arr ;
	int  i ;
	scanf("%d",&t) ;
	
	while ( t-- ) {
		
		scanf("%d",&n) ;
		arr = (int *) malloc ( sizeof(int) * n ) ;
		
		for ( i = 0 ; i < n ; i++ )
		scanf("%d",&arr[i]) ;
		printf("%d\n",templeOffer(arr,n));	
		free(arr) ;
	}
	return 0 ;
}
