#include"bits/stdc++.h"
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;
using namespace chrono;


#define fastio                        ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define int                           long long
#define rep(i,k,n)                    for (int i = k; i < n; i++)
#define per(i,n, k)                   for (int i = n; i >= k; i--)
#define fauto(a,x)                    for (auto& a : x)
#define pb                            push_back 
#define sz                            size()
#define all(var)                      var.begin(), var.end()
#define present(c, x)                 (c.find(x) != c.end())
#define desc                          greater<int>()
#define spc                           <<" "<<
#define YES                           cout << "YES\n";
#define NO                            cout << "NO\n";
#define Yes                           cout << "Yes\n";
#define No                            cout << "No\n";
#define minus1                        cout << "-1\n";
#define ndl                           cout << "\n";
#define endl                          "\n"
#define gcd(a, b)                     __gcd(a, b)
#define PI                            3.1415926535897932384626
#define imin                          LLONG_MIN
#define imax                          LLONG_MAX
#define fi                            first
#define se                            second
#define lb                            lower_bound
#define ub                            upper_bound 
#define set_bits                      __builtin_popcountll
#define setpr(i)                      cout << setprecision(i);
#define mems(t,x)                     memset(t , x , sizeof(t)) ;                        

typedef set<int>                      seti    ;
typedef unordered_set<int>            useti   ;          
typedef map<int, int>                 mapii   ;    
typedef unordered_map<int, int>       umapii  ;               
typedef vector <pair<int , int> >     vpi     ;                 
typedef vector<int>                   vi      ;   
typedef vector<bool>                   vb      ;   
typedef pair<int , int >              pi      ;        
typedef vector<vector<int>>           vvi     ;   
typedef long long                     ll      ;
// typedef int long            ull     ;
typedef long double                   ld      ;

//typedef tree<int,null_type,less<int>,rb_tree_tag,
//tree_order_statistics_node_update> pbds ; 
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)

int M=1e9+7;
int power(int a , int n );
int minv(int a){ return power(a , M-2 ); }
int mod(int n) { return (n % M + M) % M; }
int modM( int n, int m ) { return ( (ll) (n % M) * (m % M) ) % M; }
int modA( int n, int m ) { return ( (ll) (n % M) + (m % M) ) % M; }
int modS( int n, int m ) { return ( ((ll) (n % M) - (m % M) ) + M) % M; }
int modD( int n, int m ) { return ( (ll) (n % M) * (minv(m) % M) ) % M; }
int lcm ( int a, int b ) { return ( (ll)a*b )/gcd(a,b) ;}
void minz( int &a , int &b ){ a = min( a , b ) ; } 
void maxz( int &a , int &b ){ a = max( a , b ) ; }

//====================================DEBUG FINCTIONS=============================================//

#define ndr cerr<<"\n" ;
#define path(x) cerr<<"Path->"<<x<<"\n";

#ifndef XINYSTER
#define deb(x) cerr << #x <<" = "; _print(x); cerr << endl;
#else
#define deb(x)
#endif

template <class T> void _print( T x){ cerr<<x; }
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#define debug(x,n)  cerr <<#x<<" = "  ; _print(x,n); cerr <<endl;
template <class T> void _print( T arr[] ,int n){ cerr<<"[ "; for(int i=0; i<n; i++) { cerr<<arr[i]<<" ";} cerr<<"]";}

//==========================================XINYSTER=============================================//
const int MN = 1001 ;


string intToBinaryString( int n )
{

      /*
      * Create char array of size = 32+1
      * (1 for null terminated string) =33 to
      * accommodate 32 byte chars as int range
      *  0 to 4,294,967,295 can be accommodated int to it
      * 
      * Size of int is 4 bytes, hence for
      * 32 byte char array, we need to multiply by 8
      */     

      char     bArray[ (sizeof( int ) * 8) + 1 ];

      //index = 32 to fetch each 32 slots
      unsigned index  = sizeof( int ) * 8;

      char temp =0;
      bArray[ index ] = '\0';

      do{          

            //bArary[ --index ] = '0' + (n & 1);

            //Breaking above line to understand better.
            temp = (n & 1); // Finding 0 or 1 in LSB
            // Adding ASCII 0 to convert Binary to ASCII
            temp = temp + '0';

            // Copying final ASCII equivalent BIT value (0 or 1)
            bArray[ --index ] = temp;

            //In while expression :n >>= 1 or equivalent to it is n =n>>1
            //can be used. Shifting the Value to RIGHT by one
            //to check the NEXT LSB bit.
            //Exits when n becomes ZERO.

      }while (n >>= 1);

      //bArray contains base address. So, jump to
      //base address + current index to fetch
      //the binary representation.


      return string( bArray + index );
}


void solve(){
        
        int x , y ;
        cin >> x >> y ;
        int tx = x , ty = y ;

        string xx , yy ;

        xx = intToBinaryString(x) ;
        yy = intToBinaryString(y) ;

        // for(int i=60; i>=0; i--){

        //         if( x >= (1ll<<i)){
        //                 x -= (1ll<<i) ;
        //                 xx.pb('1');
        //         }
        //         else{
        //                 if(tx==x) continue ;
        //                 xx.pb('0');
        //         }

        //         if( y >= (1ll<<i)){
        //                 deb(y)
        //                 // deb(i)
        //                 y -= (1ll<<i) ;
        //                 deb(y)
        //                 yy.pb('1');
        //         }

        //         else{
        //                 if(ty==y) continue;
        //                 yy.pb('0');
        //         }

        // }

        deb(xx)deb(yy)

        while(xx.back()=='0'){
                xx.pop_back();
        }
        // deb(yy.find(xx))
        if(tx==ty){
                YES return ;
        }
        if(ty%2==0){
                NO return ;
        }
        if(yy.find(xx)<yy.size() ){ //path(1)
                YES
                return ;
        }
        reverse(all(xx)) ;
        if(yy.find(xx)<yy.size() ){ //path(2)
                YES
                return ;
        }

        NO

}



int32_t main(){

    #ifndef XINYSTER
        freopen("Error.txt", "w", stderr);
    #endif
    fastio 
    auto start1 = high_resolution_clock::now();
    

    
    int t = 1;
    // cin >> t;

    //funct calls : 
    


    //
    
    for(int i=1; i<=t; i++){
        //cout<<"Case #"<<i<<": \n";
        solve();
    }

    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    
    #ifndef XINYSTER
    cerr << "Time: " << duration . count()/1000  << endl;
    #endif
}



// FUNCTION DEFINITIONS : 
//===================================================================//

int power(int a , int n ){
    int result = 1;
    while(n){
        if(n & 1) result = (result * (ll) a)  % M;
        n >>= 1;
        a = (a * (ll) a) % M;
    }
    return result;
}
