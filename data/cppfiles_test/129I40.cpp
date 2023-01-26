
#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;

// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//         tree_order_statistics_node_update>PBDS;
// // can store duplicates
// typedef tree < pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
//         tree_order_statistics_node_update>PBDSdup;


#define pb push_back
#define fo(i,n) for(int i=0;i<n;i++)
#define foo(i,n) for(int i=1;i<=n;i++)

#define int  long long int
#define mod 1000000007
//long long inf = 100000000001;
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define ff first
#define ss second
const int MOD = 998244353;
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


// // map stores in sorted order in unordered_map no order but O(1) complexity
// // multimap multiple key can have same values in map every key should be unique
// // In map and multimap complexity is O(logN)
// // Priority queue push pop in O(logN)
// // priority_queue<int,vector<int>,greater<int>>pq;   priority queue in descending order
// // set insert remove in O(logN)


int  lcm(int  a, int  b) // Function to calculate Lcm
{
    return (a / __gcd(a, b)) * b;
}
// int highestPowerof2(int n) // Highest pow of two
// {
//   int p = (int)log2(n);
//   return (int)pow(2, p);
// }

int power(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = (res * a) % mod;

        }
        n /= 2;
        a = (a * a) % mod;
    }
    return res;
}


/*int binom(int n, int r, int mod)
{
    int res = fact[n];

    res =  (res * power(fact[n - r], mod - 2, mod)) % mod;
    res = (res * power(fact[r], mod - 2, mod)) % mod;

    return res;
}*/


/*int firstDigit(int n)
{
    // Find total number of digits - 1
    int digits = (int)log10(n);

    // Find first digit
    n = (int)(n / pow(10, digits));

    // Return first digit
    return n;
}*/

/*int ncr(int n, int r)
{
    if (r > n)
        return 0;

    int res = fact[n];
    res = (res * power(fact[r], mod - 2)) % mod;
    res = (res * power(fact[n - r], mod - 2)) % mod;

    return res;
}*/





int32_t main() {

    fast;
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif


    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;


        int a[n + 1];
        memset(a, -1, sizeof(a));
        vector<int>v;

        fo(i, n)
        {
            int x;
            cin >> x;
            if (x <= n)
            {
                a[x] = x;
            }
            else
            {
                v.pb(x);
            }
        }

        sort(v.begin(), v.end());
        debug(v);
        int j = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == -1)
            {
                a[i] = v[j];
                j++;
            }
        }
        int ans = 0;
        bool flag = true;
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << a[i] << " ";
        // }
        // cout << endl;


        for (int i = 1; i <= n; i++)
        {
            if (a[i] == i)
                continue;

            int can;
            if (a[i] % 2 == 0)
            {
                can = a[i] / 2;
                can--;
            }
            else
            {
                can = a[i] / 2;
            }


            if (can >= i)
            {
                ans++;
                continue;

            }
            else
            {
                flag = false;
            }
        }

        if (flag == true)
            cout << ans << endl;

        else
            cout << -1 << endl;

    }


}






