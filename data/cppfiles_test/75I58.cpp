#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast","unroint-loops","omit-frame-pointer","inline","03")
#endif // ONLINE_JUDGE

#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rnk(x, y) upper_bound(all((x)), (y)) - (x).begin()

typedef long double ld;
typedef long long ll;
typedef pair <int, int> ii;
typedef tuple <ll, ll, ll> tri;
typedef __int128 LL;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

static int rnd(int lo, int hi) {
    return uniform_int_distribution <int> (lo, hi)(rng);
}

const ld eps = 1e-6;
const ll oo = 1e18;

const int MAX = 2e5 + 5;
const ll mod = 1e9 + 7;

int n, a[MAX], l[MAX], r[MAX];

bool win(int x, int y, int ult) {
    if(x == y)return a[x] > ult;
    int ok = 0;
    if(a[x] > a[y]) {
        if(ult >= a[x])return 0;
        if(ult >= a[y])return !win(x + 1, y, a[x]);
        int k = min(r[x], y - x + 1);
        if(k & 1)return 1;
        return !win(x, y - 1, a[y]);
    }
    if(a[x] < a[y]) {
        if(ult >= a[y])return 0;
        if(ult >= a[x])return !win(x, y - 1, a[y]);
        int k = min(l[y], y - x + 1);
        if(k & 1)return 1;
        return !win(x + 1, y, a[x]);
    }
    int k = y - x + 1;
    if(min(k, r[x]) & 1)return 1;
    if(min(k, l[y]) & 1)return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        l[i] = r[i] = 1;
        if(a[i] < a[i - 1])
            l[i] += l[i - 1];
    }

    for(int i = n; i >= 1; i--) {
        if(a[i] < a[i + 1])
            r[i] += r[i + 1];
    }

    if(win(1, n, -1))
        cout << "Alice\n";
    else
        cout << "Bob\n";
}
//2 1 2
