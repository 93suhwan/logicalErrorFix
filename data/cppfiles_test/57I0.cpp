#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pii pair<int, int>
#define pb push_back
#define ll long long
#define S second
#define ull unsigned long long
#define F first
#define ld long double
#define TIME 1.0*clock()/CLOCKS_PER_SEC

using namespace std;
using namespace __gnu_pbds;


template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 gen(time(0));

main() {

#ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
////    freopen("trains.in","r",stdin);
//    freopen("trains.out","w",stdout);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
#endif LOCAL

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, s, k;
        cin >>s >> n >> k;

        if (s < k || n > s)
        {
            cout << "NO\n";
            continue;
        }


        if (s == k)
        {
            cout << "YES\n";
            continue;
        }

        if (n == 1)
        {
            cout << "NO\n";
            continue;
        }


        s-= n;

        n -= n % k;

        if (n > s)
        {
            cout << "YES\n";
        }
        else cout << "NO\n";

    }
    return 0;
}
