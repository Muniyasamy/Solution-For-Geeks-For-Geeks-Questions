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
