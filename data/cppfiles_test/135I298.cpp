#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define ll long long
#define PI 3.1415926535897932384626
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define br printf("\n")
#define fo(i, n) for (i = 0; i < n; i++)
#define fox(i, a, b) for (i = a; i <= b; i++)
#define reps(i, a, b) for (int i = a; i <= b; i++)
#define repe(i, a, b) for (int i = a; i >= b; i--)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define deba(i, a, n) \
    fo(i, n) { cout << a[i] << " "; }
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, x) for (auto it = x.begin(); it != x.end(); it++)
#define trr(it, x) for (auto it = x.rbegin(); it != x.rend(); it +)
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
    uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}

const int mod = 1'000'000'007;
void read(ll *a, ll n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

/* ========== YOUR CODE HERE ========= */
bool isprime(long long int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {

            return false;
        }
    }
    return true;
}

ll calculate(ll n, ll *prime)
{
    set<ll> s;
    //  cout << n << endl;
    s.insert(n);
    map<ll, ll> mi;
    while (n > 1)
    {
        mi[prime[n]]++;
        n = n / prime[n];
    }
    map<ll, ll>::iterator itr;
    ll ans = 1;
    for (itr = mi.begin(); itr != mi.end(); itr++)
    {

        ans = ans * (itr->second + 1);
    }
    return ans;
}
void SieveOfEratosthenes(ll n, ll *prime)
{

    for (int p = 2; p * p <= n; p++)
    {

        if (prime[p] == 0)
        {

            prime[p] = p;
            for (int i = p * p; i <= n; i += p)
                prime[i] = p;
        }
    }
}

void solution()
{
    ll n, p, q, m, k, sum = 0;
    string s, t = "";
    cin >> n >> m;
    ll a[n], b[n];
    read(a, n);
    ll ans1 = 0, ans2 = 0;

    reps(i, 0, n - 1)
    {
        b[i] = a[i];
    }
    k = m;
    ll i = 0, j = n - 1;
    sort(a, a + n);
    sort(b, b + n);
    while (i < j && k > 0)
    {
        ans1 += a[i] / a[j];
        a[i] = -1;
        a[j] = -1;
        i++;
        j--;
        k--;
    }
    // cout << ans1 << endl;
    reps(i, 0, n - 1)
    {
        if (a[i] != -1)
        {
            ans1 += a[i];
        }
    }
    k = m;
    for (int i = n - 1; i >= 0; i = i - 2)
    {
        // cout << i << endl;
        if (k > 0)
        {
            ans2 += b[i - 1] / b[i];
            k--;
            b[i - 1] = -1;
            b[i] = -1;
            //  cout << ans2 << endl;
        }
    }
    //  cout << ans2 << endl;
    reps(i, 0, n - 1)
    {
        // cout << b[i] << endl;
        if (b[i] != -1)
        {
            ans2 += b[i];
        }
    }
    // cout << ans2 << endl;
    cout << min(ans1, ans2) << endl;
}

/* ========== YOUR CODE HERE ========= */

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }

    return 0;
}