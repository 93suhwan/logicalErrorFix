#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define arrinit \
    int n;      \
    cin >> n;   \
    int arr[n]; \
    loop(i, n) { cin >> arr[i]; }
#define warrinit(n) \
    int arr[n];     \
    loop(i, n) { cin >> arr[i]; }
#define init(arr, n, val)       \
    for (int i = 0; i < n; i++) \
        arr[i] = val;
#define ret return
#define cont continue
#define endl "\n"
#define ll long long

#define loops(i, s, n) for (int i = s; i < n; i++)
#define loop(i, n) for (int i = 0; i < n; i++)
#define loopr(i, s, e) for (int i = s; i >= e; i--)
#define loopitr(mp) for (auto itr = mp.begin(); itr != mp.end(); itr++)

#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define pub push_back
#define pob pop_back
#define vpii vector<pair<int, int>>
#define vall(v) v.begin(), v.end()
#define mkp make_pair
#define ff first
#define ss second

#define print(arr)        \
    for (auto x : arr)    \
        cout << x << " "; \
    cout << endl;
#define cnt_bits __builtin_popcountll
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define eps 1e-9
const int mod = 1000000007;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define hello cout << "hello" << endl

int main()
{
    fastio;
    int t;
    cin >> t;

    loop(T, t)
    {
        string a, b;
        cin >> a >> b;
        int i = 0;
        // odd
        for (; i < a.length(); i++)
        {
            if (i % 2 == 0 && a[i] == b[0])
                break;
        }

        int j = 0;
        while (j < b.length() && i < a.length())
        {
            if (a[i] == b[j])
            {
                i++, j++;
            }
            else
            {
                i+=2;
            }
        }

        if (j == b.length())
        {
            YES;
            cont;
        }

        j = 0;
        i = 0;
        // even
        for (; i < a.length(); i++)
        {
            if (i % 2 == 1 && a[i] == b[0])
                break;
        }

        j = 0;
        while (j < b.length() && i < a.length())
        {
            if (a[i] == b[j])
            {
                i++, j++;
            }
            else
            {
                i+=2;
            }
        }

        if (j == b.length())
            YES;
        else
            NO;
    }
}