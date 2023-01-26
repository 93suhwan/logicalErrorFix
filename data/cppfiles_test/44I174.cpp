#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long 
#define db double
#define INF 1e18 
#define F first
#define S second 
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define debug(a) cout << #a <<" = "<< a << '\n'
using namespace std ; 
void solve(int T)
{
    ll c,d ; cin >> c >> d ; 
    if( (c-d)%2!=0 ) cout << "-1\n"; 
    else if( c ==d) cout << "1\n" ;  
    else cout << "2\n" ; 
}
int main()
{
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    ll T ; cin >> T ; 
    while (T--) 
    solve(T); 
    return 0; 
}