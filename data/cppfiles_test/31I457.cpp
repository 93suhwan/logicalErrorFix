#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <class T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)
#define int long long
typedef pair<int, int> II;
typedef vector<II> VII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(), a.end()
#define SET(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define si(n) scanf("%d", &n)
#define dout(n) printf("%d\n", n)
#define sll(n) scanf("%lld", &n)
#define lldout(n) printf("%lld\n", n)
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
const long long mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    if (n % 2 == 0)
    {
        for (int i = 0; i < n; i += 2)
        {
            if (A[i] > 0 && A[i + 1] > 0)
            {
                cout << A[i + 1] << " " << -A[i] << ' ';
            }
            else if (A[i] < 0 && A[i + 1] < 0)
            {
                cout << A[i + 1] << " " << -A[i] << ' ';
            }
            else if (A[i] > 0)
            {
                cout << -A[i + 1] << " " << A[i] << ' ';
            }
            else
            {
                cout << A[i + 1] << " " << -A[i] << ' ';
            }
        }
        cout << endl;
    }
    else
    {
        for (int i = 0; i < n - 3; i += 2)
        {
            if (A[i] > 0 && A[i + 1] > 0)
            {
                cout << A[i + 1] << " " << -A[i] << ' ';
            }
            else if (A[i] < 0 && A[i + 1] < 0)
            {
                cout << A[i + 1] << " " << -A[i] << ' ';
            }
            else if (A[i] > 0)
            {
                cout << -A[i + 1] << " " << A[i] << ' ';
            }
            else
            {
                cout << A[i + 1] << " " << -A[i] << ' ';
            }
        }
        int a = A[n - 3];
        int b = A[n - 2];
        int c = A[n - 1];
        if (a > 0)
        {
            if (b > 0 && c > 0)
            {
                cout << (b + c) << " " << -a << " " << -a << endl;
            }
            else if (b < 0 && c < 0)
            {
                cout << (-b - c) << " " << a << " " << a << endl;
            }
            else if (b > 0)
            {
                cout << (b - c) << " " << -a << " " << a << endl;
            }
            else
            {
                cout << (-b + c) << " " << a << " " << -a << endl;
            }
        }
        else
        {
            if (b > 0 && c > 0)
            {
                cout << -(b + c) << " " << -a << " " << -a << endl;
            }
            else if (b < 0 && c < 0)
            {
                cout << -(-b - c) << " " << a << " " << a << endl;
            }
            else if (b > 0)
            {
                cout << -(b - c) << " " << -a << " " << a << endl;
            }
            else
            {
                cout << -(-b + c) << " " << a << " " << -a << endl;
            }
        }
    }
}

signed main()
{
    fast_io;
    //  freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    int totalTests = 1;
    cin >> totalTests;
    for (int testNo = 1; testNo <= totalTests; testNo++)
    {
        // cout << "Case #" << testNo << ": ";
        solve();
    }
    return 0;
}