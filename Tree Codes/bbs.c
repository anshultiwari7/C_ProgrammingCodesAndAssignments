void sort()

{

 int n = 1 , p , q , i , j ;

 temp = root ;

 while( temp -> next != NULL )

 {

 temp = temp-> next ;

 n++ ;

 }


 for( i=0 ; i < n-1 ; i++ )

{

 temps = root ;

 temp = root -> next ;

 for( j=0 ; j < n-i-1 ; j++ )

{

if( temps -> x > temp -> x)

 {

 q = temps -> ch ;

 temps -> ch = temp -> ch ;

 temp -> ch = q ;

 p = temps -> x ;

 temps -> x = temp -> x ;

 temp -> x = p ;

 }

 temps = temps -> next ;

 temp = temp -> next ;

}

}

}
