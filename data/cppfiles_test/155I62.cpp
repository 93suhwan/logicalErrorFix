#include <iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{ ll n,k;
  cin>>n>>k;
  ll a[n];
  ll sm=0;
  for(ll i=0;i<n;i++)
  { cin>>a[i];
    sm+=a[i];
  }
  sort(a,a+n);
  if(sm<=k)
  {
      cout<<"0"<<endl;
      return;
  }
  ll pre[n]={0};
  for(ll i=1;i<n;i++) pre[i]=pre[i-1]+a[i];
  ll ans=(sm-k);
  ll c=0;
  for(ll i=n-1;i>=1;i--)
  { c++;
    ll x=((k-pre[i-1])/c+1);
    if((k-pre[i-1])%(c+1)!=0 && ((k-pre[i-1])<0))x--;
    ll y=c;
    if(x<a[0])y+=(a[0]-x);
    ans=min(y,ans);
  }
  cout<<ans<<endl;
}

int main()
{ ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll tt;
  cin>>tt;
  while(tt--)
  solve();

 return 0;
}
