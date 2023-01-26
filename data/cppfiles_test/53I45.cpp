#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ff                 first
#define ss                 second
#define ll                 long long
#define int                long long
#define ld                 long double
#define pb                 push_back
#define all(x)             x.begin(), x.end()
#define clr(x,y)           memset(x, y, sizeof(x))
#define setbits(x)         __builtin_popcountll(x)
#define mod                1000000007
#define inf                1e18
#define ps(x,y)            fixed<<setprecision(y)<<x
#define deb(x)             cout << #x << "=" << x << endl;
#define deb2(x, y)         cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl;
template <typename T>      using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
const int N = 1000005;
vector<ll> prime;
bool ar[N];

//ll dp[N];
//ll arr[N];
// map<ll,ll> dp;
//vector<ll> dp(N);
/******************************************************************************************************************************/

void seive()
{
	for (ll i = 0; i < N; i++) ar[i] = true;
	ar[0] = ar[1] = false;
	for (ll i = 2; i < N; i++)
	{
		if (ar[i] == true)
		{
			prime.push_back(i);
			for (ll j = i * i ; j < N; j += i)
			{
				ar[j] = false;
			}
		}
	}

}

ll power(ll a, ll b)
{
	ll    ans = 1;
	while (b)
	{
		if (b & 1)
			ans *= a;
		//ans %= c;
		a *= a;
		//a %= c;
		b /= 2;
	}
	return ans;//%c;
}



ll gcd(ll a, ll b)
{
	return  b == 0 ? a : gcd(b, a % b);
}


int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);



	ll t = 1, n,k, i, j, m, l, ans = 0, x = 0, y = 0, sum = 0, c, d, a = 0, b = 0;


	cin>>t;

	while(t--)
    {
cin>>n>>k;
vector<ll> v(n);

for(i=0;i<n;i++)
{

    cin>>v[i];
}

if(k==n)
{
    cout<<"YES"<<endl;
}
else
{
   x=0;
   for(i=1;i<n;i++)
   {
       if(v[i]<v[i-1])
       {
           x++;
       }
   }
   x++;
   if(k<x)
    cout<<"NO"<<endl;
   else
    cout<< "YES"<<endl;
}



    }


}

