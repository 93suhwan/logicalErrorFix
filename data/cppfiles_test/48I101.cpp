#include "bits/stdc++.h"
#define int long long
using namespace std ;
const int mxN= 1e5 ;
int st[mxN+1][18] ;
signed main(){
  int n,q ;
  cin >> n >> q ;
  vector<int>a(n),b(n),c(n),p(n+1),ix(n) ,d;
  for(int &x:a)
    cin >> x  ;
  for(int &x:b)
    cin >> x  ;
  for(int i=0;i<n;i++)
    c[i]=a[i]-b[i] ;
  for(int i=0;i<n;i++)
    p[i+1]+=p[i]+c[i] ;
  vector<int>ci ;
  for(int i=0;i<n;i++)
    if(c[i]!=0)
      ci.push_back(i) ;
  ix[0]=0 ;int j=0,k=c[ci[0]];
  for(int i=1;i<ci.size();i++){
    if(c[ci[i-1]]*c[ci[i]]>0)
      ix[i]=j,k+=c[ci[i]] ;
    else{
      d.push_back(k) ;
      ix[i]=++j ;k=c[ci[i]] ;
    } 
  }
  d.push_back(k) ;
  n=c.size() ;
  vector<int>s(n),e(n) ;
  s[0]=0 ;
  for(int i=1;i<n;i++)
    s[i]=(ix[i]==ix[i-1]?s[i-1]:i) ;
  e[n-1]=n-1  ;
  for(int i=n-2;~i;--i)
    e[i]=(ix[i]==ix[i+1]?e[i+1]:i) ;
  n=d.size() ;
  for(int i=0;i<n;i++)
    st[i][0]=abs(d[i]) ;
  for(int j=1;j<18;j++)
    for(int i=0;i+(1<<j)<=n;i++)
      st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]) ;
  auto qry = [&](int l,int r){
    if(r<l)
      return -(int)1e18;
    int j =__lg(r-l+1) ;
    return max(st[l][j],st[r-(1<<j)+1][j]) ;
  }   ;
  while(q--){
    int l,r ;
    cin>> l >> r ; 
    if(p[r]-p[l-1]!=0){
      cout <<"-1\n" ;
      continue  ;
    }
    --l,--r  ;
    int lb = lower_bound(ci.begin(),ci.end(),l)-ci.begin() ;
    int rb = (--upper_bound(ci.begin(),ci.end(),r))-ci.begin() ;
    if(lb>rb){
      cout << 0 << '\n' ;
      continue  ;
    }
    if(d[ix[lb]]>0||d[ix[rb]]<0){
      cout << "-1\n" ;
      continue  ;
    }
    int cl = p[ci[e[ix[lb]]]+1]-p[ci[lb]] ;
    int cr = p[ci[rb]+1]-p[ci[s[ix[rb]]]] ;
    int ans = max({-cl,qry(ix[lb]+1,ix[rb]-1),cr}) ;
    cout << ans << '\n'  ;
  }
}
