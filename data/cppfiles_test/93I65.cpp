#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(a, n) for (int i = a; i < n; i++)
#define Fo(k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================
int dp[300002];
void solve()
{
    int a, b;
    cin >> a >> b;
    if (dp[a] == b)
    {
        cout << a << endl;
    }
    if ((dp[a] ^ b) == a)
    {
        cout << a + 2 << endl;
    }
    else
    {
        cout << a + 1 << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    dp[1] = 0;
    fo(2, 300002)
    {
        dp[i] = dp[i - 1] ^ (i - 1);
    }
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}