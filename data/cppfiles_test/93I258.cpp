#include <bits/stdc++.h>
#define ll long long
#define RUNFAST  ios_base::sync_with_stdio(false);    cin.tie(NULL);
#define vec  vector<ll>
#define pi vector<pair<ll,ll>>
#define fi first
#define se second
#define pb push_back
#define sz(v) (ll)v.size()
#define pt1(a) cout<<a<<" ";
#define pt2(a,b) cout<<a<<" "<<b<<" ";
#define pt3(a,b,c) cout<<a<<" "<<b<<" "<<c<<" ";
#define sorti(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define issorted(v) is_sorted(v.begin(),v.end())
#define eb emplace_back
#define nl cout<<"\n";
#define map map<ll,ll>
#define mp make_pair
#define MOD 1000000007 // 998244353
using namespace std;

ll visited[210000] = {0};
vector<ll>vg[210000];
ll mem=0;
#ifndef ONLINE_JUDGE
#define cout if(mem++ && mem>210000){cout<<"\nOUT OF MEMORY";exit(0);}else cout
#endif
// Print vector

void printv(vector<ll> v)
{
    for (auto x : v)
        cout << x << " ";
}

// Important Functions

// DFS
void dfs(ll current)
{
    ll i, y;
    visited[current] = 1;
//   cout<<current<<" ";
    for (i = 0; i < vg[current].size(); i++)
    {
        y = vg[current][i];
        if (visited[y] == 0)
            dfs(y);
    }
}

// BFS

void bfs(ll current)
{
    ll x, y, i;
    queue<ll>q;
    q.push(current);
    visited[current] = 1;
    while (!q.empty())
    {
        x = q.front();
        //     cout<<x<<" ";
        q.pop();
        visited[x] = 1;
        for (i = 0; i < vg[x].size(); i++)
        {
            y = vg[x][i];
            if (visited[y] == 0)
            {
                visited[y] = 1;
                q.push(y);
            }
        }
    }
}

ll fact(ll n)
{
    ll p = 1;
    for (ll i = 1; i <= n; i++)
        p *= i;
    return p;
}

// Prime Numbers
void checkprime(ll N) {
    ll count = 0;
    for ( ll i = 1; i * i <= N; ++i ) {
        if ( N % i == 0) {
            if ( i * i == N )
                count++;
            else       // i < sqrt(N) and (N / i) > sqrt(N)
                count += 2;
        }
    }
    if (count == 2)
    {
        // prime number
    }
}
// Multiplicative Inverse

ll power(ll x, unsigned ll y, unsigned ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y / 2, m) % m;
    p = (p * p) % m;

    return (y % 2 == 0) ? p : (x * p) % m;
}

ll modInverse(ll a, ll m)
{
    return power(a, m - 2, m);

}

// LCM

ll lcm(ll a, ll b)
{   return (a * b) / __gcd(a, b);
}


/* ---------------------------------------------------------------------------------------------------------*/

void lakshay()
{
    ll i, z = 0, c, d, y = 0, x, l = 0, a, b, s = 0, j, m, n, p, q, k, maxi = INT_MIN, mini = INT_MAX;
    bool ok = true;
    cin >> a>>b;
    // vec v(n), v1;

    for(i=0;i<a;i++)
    {
        s=s^i;
    }

    if(s==b)
    {
        cout<<0;
        return;
    }
    else if(s==a)
    {
        cout<<a+2;
    }
    else
        cout<<a+1;
    

}

int main()
{   RUNFAST
    ll num;
    num = 1;
    cin>>num;
    while (num--)
    {
        lakshay();
        cout << "\n";
    }
#ifndef ONLINE_JUDGE
    cout << "\n\n";
    ll tim = 0;
    long double k = ((long double)tim / 10000000);
    cout << "Time Taken - ";
    cout << fixed << setprecision(8) << k << " seconds\n";
#endif
    return 0;
}