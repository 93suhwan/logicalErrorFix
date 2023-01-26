#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int ll
#define pb  push_back
#define F   first
#define S   second
#define MOD 1000000007
#define nl  cout<<endl
#define mod 998244353
#define itn int
const int N=2e5+5;
int pf[26][N];
const double eps=1e-8;

ll fact[200001];
ll invf[200001];
ll inverse(ll a,ll b){
    if(b==0){
        return 1;
    }
    ll fk=inverse(a,b/2);
    fk=(fk*fk)%mod;
    if(b%2==1){
        fk=(fk*a)%mod;
    }
    return fk;
}
void ncr(){
    fact[0]=1;
    fact[1]=1;
    invf[0]=1;
    invf[1]=1;
    for(ll i=2;i<=N;i++){
        fact[i]=((fact[i-1])*i)%mod;
        invf[i]=inverse(fact[i],mod-2);
    }
}

int power(int a,int b)
{
	int cnt=1;
	while(b)
	{
		if(b&1)
		cnt=cnt*a;
		a=a*a;
		b>>=1;
	}
	return cnt;
}
int Xor(int a,int b,int k)
{
	int val=0,cnt=0;
	while(a||b)
	{
		val+=power(k,cnt)*((a%k-b%k+k)%k);
		a/=k;
		b/=k;
		cnt++;
	}
	return val;
}
int lcm(int a,int b)
{
	return a*b/(__gcd(a,b));
}

bool isSorted(vector<int>&v)
{
	for(int i=0;i<v.size()-1;i++)
	{
		if(v[i]>v[i+1])
		return false;
	}
	return true;
}

void solve()
{
    

    //           START



	int n,k;
	cin>>n>>k;
	vector<int>a(n);
	for(int i=0;i<n;i++)
	cin>>a[i];
	vector<int>ans(n,0);
	for(int i=0;i<n-1;i++)
	{
		int x=int((pow(10,a[i+1])-pow(10,a[i])))/int(pow(10,a[i]));
		if(k>=x)
		{
			ans[i]+=x;
			k-=x;
		}
		else
		{
			ans[i]=k+1;
			k=0;
			break;
		}
	}
	if(k!=0)
	{
		ans[n-1]=k+1;
	}
	int res=0;
	for(int i=0;i<n;i++)
	{
		res+=(ans[i]*(power(10,a[i])));
	}
	cout<<res;nl;
	//           END

}

signed main(){
//ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);	
 /* *#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
/* */
//sieve();

// for(int i=0;i<26;i++)
// 	{
// 		m[char('a'+i)]=i;
// 	}

int t=1;
cin>>t;
while(t--)
{
	
    solve();
}


    return 0;
}