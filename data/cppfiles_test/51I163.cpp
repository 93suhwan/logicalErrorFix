/*   ALLAH is Almighty.....  */

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define pi                                acos( -1.0 )
#define rep( i, a, n )                    for ( Long i = a; i < n; i++ )
#define per( i, a, n )                    for ( Long i = n - 1; i >= a; i-- )
#define all( x )                          ( x ).begin(), ( x ).end()
#define Long                              long long

#ifndef ONLINE_JUDGE
#define Debug( x )                        cout << "#[ " << #x << " = "; PrintForDebug( x ); cout << " ]\n";
#else
#define Debug( x )
#endif




template < class Type > void PrintForDebug( Type Var ) {
      cout << setprecision( 15 ) << Var;
}

template < class Type1, class Type2 > void PrintForDebug( pair < Type1, Type2 > Var ) {
      cout << "(";  PrintForDebug( Var.first );  cout << ",";  PrintForDebug( Var.second );  cout << ")";
}

template < class Type > void PrintForDebug( vector < Type > Var ) {
      cout << "{ ";
      for ( int i = 0; i < Var.size(); ++i ) {
            if ( i ) cout << ", "; PrintForDebug( Var[ i ] );
      } cout << " } Size = " << Var.size();
}

template < class Type > void PrintForDebug( set < Type > Var ) {
      cout << "{ "; int Size = Var.size();
      while ( !Var.empty() ) {
             PrintForDebug( *Var.begin() ); Var.erase( Var.begin() ); if ( !Var.empty() )  cout << ", ";
      } cout << " } Size = " << Size;
}


typedef tree < Long, null_type, less < Long >, rb_tree_tag, tree_order_statistics_node_update > Ordered_set;
const Long Nn = 2e5 + 9;
const Long MOD = 1e9 + 7;



void solve( int t )
{
      Long N;
      cin >> N;
      
      cout << N - 1 << " " << N << "\n";
}

int main()
{
      ios_base::sync_with_stdio( false );
      cin.tie( NULL );
      cout.tie( NULL );
      cout << setprecision( 12 );

      int t = 1;
      cin >> t;

      for ( int i = 1; i <= t; ++i )   solve( i );

      return 0;
}

