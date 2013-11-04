# include < stdio .h >
# include < stdlib .h >
int f ( int n , int * max , int * sum , int depth )
{
int fnm1 ; /* f ( n - 1) */
int fnm2 ; /* f ( n - 2) */
int fsum ; /* f ( n - 1) + f ( n - 2) */
(* sum ) ++; /* how many times f is called ? */
if ((* max ) < depth )
{
* max = depth ;
}
if (( n == 0) || ( n == 1))
{
return 1;
}
fnm1 = f ( n - 1 , max , sum , depth + 1);
fnm2 = f ( n - 2 , max , sum , depth + 1);
fsum = fnm1 + fnm2 ;
return fsum ;
}
int main ( int argc , char * * argv )
{
int max = 0;
int sum = 0;
int val = 6;
int fv = f ( val , & max , & sum , 1);
printf (" f (% d ) = %d , max = %d , sum = % d \ n " , val , fv , max , sum );
return EXIT_SUCCESS ;
}
