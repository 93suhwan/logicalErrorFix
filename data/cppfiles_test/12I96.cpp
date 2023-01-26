#include<bits/stdc++.h>
using namespace std ;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

// find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time.To find the first element k must be zero.
// Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
// *(s.find_by_order(2)) : 3rd element in the set i.e. 6
// *(s.find_by_order(4)) : 5th element in the set i.e. 88
// order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
// Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
// s.order_of_key(6) : Count of elements strictly smaller than 6 is 2.
// s.order_of_key(25) : Count of elements strictly smaller than 25 is 4.

#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define ar array
#define endl '\n'
#define lc id<<1
#define rc id<<1|1
#define REP(i,start,end,inc) for( ll i = start ; i < end ; i += inc )
const int Mxn = 11;
const ll mod = 1e9+7 ;
const ll INF = 1e18 ;
int dx[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dy[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };
	
void solve(){
	int n,m, k ;cin >> n >> m >> k ; 
	if( n%2 == 0 && m%2 == 0 ){
		if( k%2 == 0 ) cout << "YES\n" ; 
		else cout << "NO\n" ; 
	}else{
		if( n%2 == 0 ){ 
			if( k >= 0 && k%2 == 0 ) cout << "YES\n" ; 
			else cout << "NO\n" ; 
		}else{
			k -= m/2 ;
			if( k >= 0 && k%2 == 0 ) cout << "YES\n" ; 
			else cout << "NO\n" ; 
		}
		
	}
} 

int main(){
	int t ; cin >> t ;

	//clock_t start , finish ;
	//start = clock() ;
	while(t--){
		solve() ;
	}
	//finish = clock() ;
	//cout << fixed << setprecision(3) << (float)(finish - start)/CLOCKS_PER_SEC ;
	
}
