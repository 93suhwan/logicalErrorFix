#include <bits/stdc++.h>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define endl "\n"
#define asc(i, a, n) for (int i = a; i < n; i++)
#define dsc(i, a, n) for (int i = n - 1; i >= a; i--)
#define pf push_front
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define mod 1000000007
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define readi(x) \
    int x;       \
    cin >> x
#define reads(x) \
    string x;    \
    cin >> x
#define readd(x) \
    double x;    \
    cin >> x
#define debug cout << " HERE " << endl
#define deb(x) cout << #x << " " << x << endl
#define vi vector<long long>
#define all(x) x.begin(), x.end()
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;            // erase doesn't works
// typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

template <typename... T>
void read(T &...args)
{
    ((cin >> args), ...);
}

template <typename... T>
void write(T... args)
{
    ((cout << args << " "), ...);
    cout << endl;
}

int gcd(int a, int b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int add(int a, int b)
{
    a = a % mod;
    b = b % mod;
    return (((a + b) % mod) + mod) % mod;
}

int sub(int a, int b)
{
    a = a % mod;
    b = b % mod;
    return (((a - b) % mod) + mod) % mod;
}

int mul(int a, int b)
{
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}

int power(int x, int y)
{
    int res = 1;
    x = x % mod;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
        {
            res = (res * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

int find(vi &parent, int x)
{
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void join(vi &parent, vi &rank, int x, int y)
{
    int xParent = find(parent, x);
    int yParent = find(parent, y);
    if (xParent == yParent)
        return;
    if (rank[xParent] > rank[yParent])
    {
        parent[yParent] = xParent;
    }
    else if (rank[xParent] < rank[yParent])
    {
        parent[xParent] = yParent;
    }
    else
    {
        parent[xParent] = yParent;
        rank[yParent]++;
    }
}

// #################################################   SOLUTION STARTS HERE   #################################################

void solve()
{
    readi(n);
    readi(h);
    vi arr(n);
    asc(i, 0, n) cin >> arr[i];
    double temp = 1.0;
    int ans = ceil((temp * h) / n);
    int rem = ans * n - h;
    vi attack(n - 1, 0);
    dsc(i, 0, n - 1)
    {
        attack[i] = arr[i + 1] - arr[i];
    }
    sort(all(attack));
    asc(i, 0, n - 1)
    {
        if (attack[i] < ans)
        {
            if (rem >= ans - attack[i])
            {
                rem -= ans - attack[i];
            }
            else
            {
                attack[i] += rem;
                rem = 0;
                if ((ans - attack[i]) % (n - i - 1) != 0)
                    rem++;
                ans += ceil(temp * (ans - attack[i]) / (n - i - 1));
            }
        }
        else
            break;
    }
    write(ans);
}

signed main()
{
    fast_io;
    readi(iter);
    // int iter = 1;
    // precompute();
    while (iter--)
    {
        solve();
    }
}

// ###########################################################################################################
// ###########################################################################################################
// ##########################################      END OF CODE      ##########################################
// ###########################################################################################################
// ###########################################################################################################

// If solution failing on a later test case try using register int instead of int , it helps in improving speed