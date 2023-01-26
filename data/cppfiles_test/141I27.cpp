#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>    //s.find_by_order(i),  st.order_of_key(x) elements strictly less then x
#define speed ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define ll  long long int
#define ul unsigned long long int
#define PI 3.14159265
#define mod 1000000007
const int Max = 2000006;
#define ff first
#define ss second
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
vector<int> graph[Max], vis(Max);

ll power(ll x, ll y)
{
    ll res = 1;
    while (y > 0) {
        if (y & 1)
            res = (res * x)%mod;
        y = y >> 1;
        x = (x * x)%mod;
    }
    return res;
}
ll inverse(ll a)
{
	return power(a, mod-2);
}

void solve()
{
	string a, s;
	cin>>a>>s;
	int n = a.size(), ns = s.size();
	int r = ns-1;
	vector<int> ans;
	for(int i = n-1; i>=0; i--)
	{
		if(r < 0)
		{
			cout<<-1<<'\n';
			return;
		}
		int c = s[r]-'0';
		int p = a[i]-'0';
//		trace2(c, p);
		if(c >= p)
		{
			ans.push_back(c-p);
			r--;
		}
		else if(r-1 >= 0)
		{
			int bc = 10*(s[r-1]-'0') + s[r]-'0';
//			trace3(c, p, bc);
			if(bc >= p && bc <= 9+p)
			ans.push_back(bc-p), r -= 2;
			else
			{
				cout<<-1<<'\n';
				return;
			}
		}
		else
		{
			cout<<-1<<'\n';
			return;
		}
	}
	
//	
	for(int i = 0; i<=r; i++)  ans.push_back(s[i]-'0');
	reverse(ans.begin(), ans.end());
	
	int idx = -1;
	for(int i = 0; i<ans.size(); i++)
	{
		if(ans[i] != 0)
		{
			idx = i;
			break;
		}
	}
	vector<int> v;
	if(idx == -1)
	{
		cout<<0<<'\n';
	}
	else
	for(int j = idx; j<ans.size(); j++)
	{
		cout<<ans[j];
	}
	cout<<'\n';

}
int main()
{
    speed;
    int t;
    cin>>t;
    while(t--) solve();

   return 0;
}
