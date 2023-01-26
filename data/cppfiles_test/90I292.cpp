#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define mp make_pair
#define pb push_back
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
#define pi pair<int, int>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// Ordered Set Tree
typedef tree<int, null_type, less_equal<int>,
             rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int main()
{
    fast;
    tc
    {
        lli x, y, ans;
        cin >> x >> y;
        if (y % x == 0)
        {
            ans = x;
        }
        else if (x > y)
        {
            ans = x + y;
        }
        else
        {
            ans = y - (y % x);
        }
        cout << ans << endl;
    }
}