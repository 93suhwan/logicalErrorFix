#include <bits/stdc++.h>
using namespace std;


void jai_shree_ram()
{
   int n;
cin>>n;
int a,freq[n+1]={0},i,k=0,ans[n+1]={0};
stack<int> s;

for(i=0;i<n;i++)
{
  cin>>a;
  freq[a]++;
}

for(i=0;i<=n;i++)
{
  ans[i]=k+freq[i];
  
  while(freq[i]--)
  s.push(i);

if(s.size()==0)
{
  i++;
  break;
}
 
   k+=i-s.top();
  s.pop();

}

for(;i<=n;i++)
ans[i]=-1;

for(i=0;i<=n;i++)
cout<<ans[i]<<' ';
   
}

int main() {
	
	int t;
	cin>>t;
	
	while(t--)
	{
	    jai_shree_ram();
	    cout<<'\n';
	}
	return 0;
}