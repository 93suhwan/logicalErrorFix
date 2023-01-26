#include<bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
 
 
 
 
 
#define f(x,n) for(int i=x;i<n;i++)
#define F(x,n) for(int j=x;j<n;j++)
#define ll long long
#define pb push_back
#define pf push_front
#define ff first
#define ss second


const int M=1e9+7;
const int mx=1e5+1;

 
void solve(){

  int n;
  string s;
  cin>>n>>s;
  int c=0;
  f(0,n)c+=(s[i]=='2'?1:0);
  if(c==1){
    cout<<"NO\n";
    return;
  }
  cout<<"YES\n";
  string a="";
  f(0,n)a+="=";
  vector<string> l(n,a);

  f(0,n)l[i][i]='X';
  f(0,n){
    if(s[i]=='1')continue;
    F(0,n){
      if(i==j)continue;
      else if(s[j]=='2'&&l[i][j]=='='){l[i][j]='+';l[j][i]='-';break;}
    }
  }
  f(0,n){
    F(0,n)cout<<l[i][j];
    cout<<endl;
  }
}
 
 
void init_code(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);    
  #endif
}
 
 
int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  init_code();

  int t;
  cin>>t;
  while(t--)
  solve();

}