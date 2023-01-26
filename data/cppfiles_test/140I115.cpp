#include <bits/stdc++.h>
#define ll long long
#define lli long long int
#define li long int
#define pb push_back
#define mp make_pair
#define fr(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mod 1000000007
#define all(x) (x).begin(), (x).end()
#define triplet pair<ll, pair<ll, ll>>
#define goog(tno) cout << "Case #" << tno << ": "
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define read(x) \
    int x;      \
    cin >> x
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    fast_io;
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i = 1;
        int count = 0;
        while(pow(i, 6) < n){
            count++;
            i++;
        }
        int res = floor(sqrt(n)) + floor(cbrt(n)) - count;
        cout << res << "\n";
    }
    return 0;
}