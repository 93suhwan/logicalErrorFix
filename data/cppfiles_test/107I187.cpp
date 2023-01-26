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
        int n, a, b;
        cin >> n >> a >> b;
        int f = 0;
        if (a > (n - 1) / 2 || b > (n - 1) / 2 || abs(a - b) > 1)
        {
            f = 1;
        }

        if (f)
        {
            cout << -1 << endl;
        }
        else
        {
            int arr[n + 1];
            for (int i = 0; i < n + 1; i++)
            {
                arr[i] = i;
            }
            int lp = 1, rp = n;
            int c = max(a,b);
            if (a > b)
            {
                while (c > 0)
                {
                    int tmp = arr[rp];
                    arr[rp] = arr[rp - 1];
                    arr[rp - 1] = tmp;
                    rp=rp-2;
                    c--;
                }
            }
            else
            {
                while (c > 0)
                {
                    int tmp = arr[lp];
                    arr[lp] = arr[lp + 1];
                    arr[lp + 1] = tmp;
                    lp=lp+2;
                    c--;
                }
                if(a==b)
                {
                    int tmp = arr[lp];
                    arr[lp] = arr[lp + 1];
                    arr[lp + 1] = tmp;
                }
            }
            for (int i = 1; i < n + 1; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
}