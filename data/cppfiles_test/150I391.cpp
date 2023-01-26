#include <bits/stdc++.h>

#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define watch(x) cout << (#x) << " : " << x << '\n'
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ll long long
#define point pair<ll, ll>

using namespace std;

const ll INF = 1e17 + 128;

vector <ll> a;
int n;

bool check(ll o, ll b, ll c) {
    for (ll i = 0; i < n; i++) {
        ll cur = a[i];
        ll x = min(cur / 3, c);
        cur -= x*3;
        if (!cur) continue;
        if (cur == 1) {
            if (o)
                continue;
            bool can = false;
            for (int t = 0; t < 3; t++) {
                cur = a[i];
                x = min(((cur-3*t)/3), c-t);
                if (x < 0) continue;
                cur -= 3*x;
                if (cur < 0) continue;
                if (!cur || (cur % 2 == 0 && cur / 2 <= b)) {
                    can = true;
                    break;
                }
            }
            if (can)
                continue;
            return false;
        }
        if (cur == 2) {
            if (b)
                continue;
            bool can = false;
            for (int t = 0; t < 3; t++) {
                cur = a[i];
                x = min(((cur-3*t)/3), c-t);
                if (x < 0) continue;
                cur -= 3*x;
                if (cur < 0) continue;
                if (!cur || cur <= o) {
                    can = true;
                    break;
                }
            }
            if (can)
                continue;
            return false;
        }
        if (cur > 2) {
            bool nice = false;
            for (int i = 0; i <= o; i++)
                for (int j = 0; j <= b; j++)
                    if (i + 2*j == cur)
                        nice = true;
            if (nice) continue;
            return false;
        }
    }
    return true;
}

void test_case() {
    cin >> n;
    a.assign(n, 0);
    for (auto &x : a)
        cin >> x;
    int ans = INF;
    for (int ones = 0; ones <= 3; ones++)
        for (int twos = 0; twos <= 3; twos++) {
            ll l = 0, r = 5e9 + 256;
            while (l + 1 < r) {
                ll mid = (l + r) >> 1;
                if (check(ones, twos, mid))
                    r = mid;
                else
                    l = mid;
            }
            ans = min(ans, ones+twos+(r - !check(ones, twos, r)));
        }
    cout << ans << '\n';
}

main () {
    boost;
    int t = 1;
    cin >> t;
    while (t--)
        test_case();
    return 0;
}
