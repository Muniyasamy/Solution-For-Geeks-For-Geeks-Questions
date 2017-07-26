#include<iostream>

using namespace std ;

int Max( int a , int  b ) {
    
    return a > b ? a : b ;
    
}

int MaxSum( int n , int *arr ) {
    
    int res ;
    res = arr[0] + arr[1] ;
    
    for ( int i = 1 ; i < n - 1 ; i++ )
       res = max(res,arr[i]+arr[i+1]) ;
    
        
  return res ;
    
}

int main() {
    
    int t,n,*arr;
    
    cin>>t ;
    
    while ( t-- ) {
        cin>>n ;
        arr = new int[n] ;
        
        for ( int i = 0 ; i < n ; i++ ) 
          cin>>arr[i] ;
        
        cout<<MaxSum(n,arr)<<endl ;
    }
    
    
    
    
    return 0 ;
}
