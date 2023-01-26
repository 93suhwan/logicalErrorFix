#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int
#define lld long double
#define fo(i,a,b) for(i=a;i<b;i++)
#define pb push_back 
#define wt while(t--) 
#define vll vector<ll>
#define INF 999999999999999999
#define endl "\n"
#define MOD 1000000007
#define vls vector<string>
#define mp map<string,string>
#define ff first
#define ss second
void solve()
{
ll t=1;
cin>>t;
while(t--)
{
ll n,i;
cin>>n;
string s,s1;
cin>>s;
cin>>s1;

ll mark[n]={0};
ll ans=0;
for(i=0;i<n;i++)
{
  if(s1[i]=='0')
  {
  	continue;
  }
  if(s1[i]=='1' && s[i]=='0')
  {
  	ans++;
  	
  }
  else
  {
  	
  		if(i-1>=0 && s[i-1]=='1' && mark[i-1]==0)
  		{
  			mark[i-1]=1;
  			ans++;
  		} 
  		if(i+1<n && s[i+1]=='1' && mark[i+1]==0) 
  		{
  			mark[i+1]=1;
  			ans++;
  		} 		
  	
  }

}
cout<<ans<<endl;
 
}
 
}
int main()
{
  ios::sync_with_stdio(0);
cin.tie(0); 
solve();
cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
return 0;
} 