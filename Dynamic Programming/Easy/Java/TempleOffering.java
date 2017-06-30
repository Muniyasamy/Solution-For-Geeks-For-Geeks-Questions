import java.lang.* ;
import java.util.Scanner ;


class Offer {
	
	private int max( int a , int b ) {
		  if ( a > b )
		     return a ;
		   return b ;
	}
	
	public int offer ( int arr[] , int n ) {
		
		int dp_left[]  = new int[n] ;
		int dp_right[] = new int[n] ;
		int count = 0 , i =  0 ;
		
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
	 
		return count ;
	}
	
}

public class TempleOffer {
	
	public static void main ( String[] args ) {
		
		int n , t ;
		int arr[] ;
		Offer offer = new Offer() ;
		
		Scanner input = new Scanner(System.in) ;
		t = input.nextInt() ;
		
		while( t > 0 ) {
			
			n = input.nextInt() ;
			arr = new int[n] ;
			
			for ( int i = 0 ; i < n ; i++ )
               arr[i] = input.nextInt() ;			
			
			System.out.println(offer.offer(arr,n)) ;
			t-- ;
		}
		
	}
	
}
