#include <algorithm>   
#include <cstring>
#include <deque>　　     
#include <iostream>     
#include <list>　　　　 
#include <map>　　     
#include <queue>　　   
#include <set>　　　　 
#include <stack>　　    　　
#include <string>　　   
#include <vector>　　   

#define fi first
#define se second
#define cl(a, b) memset(a, b, sizeof(a))
#define rapido ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
typedef long long int ll;
const int N = 1e5 + 10;

ll a[N];
int n, k;

void solve()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i ++ )
	cin >> a[i];
	
	ll res = - INF;
	if(n <= 1000)
	{
		for(int i = 1; i <= n; i ++ )
		{
			for(int j = i + 1; j <= n; j ++ )
			res = max(res, i * j - k * (a[i] | a[j]));
		}
	}
	else 
	{
		for(int i = n - 1000; i <= n; i ++ )
		{
			for(int j = i + 1; j <= n; j ++ )
			res = max(res, i * j - k * (a[i] | a[j]));
		}
	}
	cout << res << endl;
}

int main()
{
    rapido;
    int t;
    for(cin >> t; t; t -- )
    //for (t = 1; t; t -- )
        solve();
}