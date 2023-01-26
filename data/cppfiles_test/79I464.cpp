#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
}

int prime[100];

void check()
{
    prime[1] = 1;
    memset(prime,1,sizeof(prime));

    for(int i = 2; i < 100; i++)
    {
        if(prime[i])
        {
            for(int j = 2*i; j < 100; j+=i)
            {
                prime[j] = 0;
            }
        }
    }
    
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    check();

    for(int i = 0; i < n; i++)
    {
        if(s[i]=='1' || s[i]=='4' || s[i]=='6' || s[i]=='8')
        {
            cout << 1 << endl;
            cout << s[i] << endl;
            return;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            int x = (s[i]-'0')*10 + (s[j]-'0');
            if(!prime[x]) {
                cout << 2 << endl;
                cout << s[i] << s[j] << endl;
                return;
            }
        }
    }

}

int32_t main()
{
	c_p_c();
        int t;
        cin >> t;
        while(t--) {
            solve();
        }
	return 0;
}