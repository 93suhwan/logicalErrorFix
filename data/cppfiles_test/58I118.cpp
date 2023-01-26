#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
using namespace __gnu_pbds;
// Policy based data structure 
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
#define int long long
#define ll long long 
#define pb push_back
#define pii pair<int,int>
#define rep(i,st,en) for(int i=st;i<en;i++)
#define vi vector<int>
#define vii vector<pii>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define eb emplace_back
#define yes cout<<"YES"<<endl; return;
#define no cout<<"NO"<<endl; return;
#define flus fflush(stdout);
#define gin(x) cerr<<#x<<" : "<<x<<" ";
#define fin cerr<<endl;
#define F first
#define S second
#define np next_permutation
#define inf 1e18
#define mod 1000000007
#define N 200009
#define PI 3.14159265358979323846
#define minpq priority_queue <ll, vector<ll>, greater<ll>>
void solve(){
   int n;
   cin >> n;
   string s[2];
   for(int i=0;i<2;i++) cin >> s[i];
   for(int i=1;i<s[0].length();i++)
   {
       if(s[0][i]=='1' && s[1][i]=='1' && (s[0][i-1]=='1' || s[1][i-1]=='1'))
       {
           cout << "NO" << endl;
           return;
       }
   }
   cout << "YES" << endl;
}
signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

 