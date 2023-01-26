#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define LOCAL
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<ll , null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define pbc push_back
#define pob pop_back()
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& v : a)
#define uin(a) for (auto& u : a)
#define pain(a) for (auto& [v, u] : a)
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
int t;
cin >> t;
while (t--)
{
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        a[i] = b[i];
    }
    sort(all(a));
    int col = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            col++;
    }
    if (col != 2)
        cout << "YES\n";
    else
        cout << "NO\n";
}
}
