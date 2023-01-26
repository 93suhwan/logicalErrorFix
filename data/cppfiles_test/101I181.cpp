// Powered by CP Editor (https://cpeditor.org)

//						U+0950
//a+b = (a^b) + 2*(a&b)
//b^c = (a^b)^(a^c) 
//a+b = (a|b) + (a&b)
//gcd(x,y) = gcd(x-y,y)
//property of diameter = For every vertex u in the graph, one of the furthest vertex from u is either s or t(s,t are the nodes of diameter).
//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define mod 1000000007
//#define mod 998244353
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286
#define pb emplace_back
#define ll long long
#define fi first
#define se second
#define mk make_pair
#define vi vector<int> 
#define pii pair<int,int>
#define mii map<int,int>
#define loop(i,n) for(int i=0;i<n;i++) 
#define pp  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 
#define ass(a,b) memset(a, b, sizeof(a))
#define all(x) (x).begin(), (x).end()
 
#define en cout<<"\n"

#define trace(x) cout<<#x<<": "<<x<<" "<<endl
#define trace2(x,y) cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x,y,z) cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a,b,c,d) cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
 
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
const long long INF = 2000000000000000000;

long long power(long long a,long long b){
    long long ans=1;
    while(b>0){
        if(b&1){ans=(ans*a)%mod;}
                a=(a*a)%mod;
                b>>=1;
        }
    return ans; 
}

void solve()
{
	int n;
	cin>>n;
	int ar[n];
	loop(i,n) cin>>ar[i];
	string s;
	cin>>s;
	mii mp1,mp2;
	set<int> st;
	int vis[n] = {0};
	loop(i,n) st.insert(i+1);
	loop(i,n) 
	{
		if(st.count(ar[i]))
		{ st.erase(ar[i]);
		vis[i] = 1;}
	} 
	loop(i,n) mp1[ar[i]]++;
	// for(int i=0;i<n;i++)
	// {
		// if(s[i]=='B') mp[ar[i]]++;
		// else mp1[ar[i]]++;
		// if(ar[i]>n && s[i]=='R' )
		// {
			// cout<<"NO";
			// return;
		// }
		// if(ar[i]<1 && s[i] == 'B')
		// {
			// cout<<"NO";
			// return;
		// }
	// }
	for(int i=0;i<n;i++)
	{
		auto it = st.end();
		// it--;
		if(s[i]=='R' && vis[i] == 0)
		{
			if(st.size()==0)
			{
				cout<<"YES";
				return;
			}
			it--;
			// trace(*it);
			if(ar[i]< *it)
			ar[i] = *it;
			else 
			{
				cout<<"NO";
				return;
			}
			st.erase(it);
		}
	}
	for(int i=0;i<n;i++)
	{
		auto it = st.begin();
		// it--;
		if(s[i]=='B' && vis[i] == 0)
		{
			if(st.size()==0)
			{
				cout<<"YES";
				return;
			}
			if(ar[i] > *it)
			ar[i] = *it;
			else 
			{
				cout<<"NO";
				return;
			}
			st.erase(it);
		}
	}
	cout<<"YES";
	return;
}

int32_t main() 
{
pp;
int test=1;
cin>>test;
while(test--)
{
	solve();
	en;
}
return 0 ;
}
