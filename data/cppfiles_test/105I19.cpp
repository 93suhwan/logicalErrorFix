#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 2e5+5, inf = 1e9;

int n, a[N], b[N], m[N], x[N], y[N];

void solve() {
    cin >> n;
    vector<pii> ve;
    rep(i, 0, n) {
        cin >> a[i] >> b[i] >> m[i];
        ve.push_back({a[i]+b[i]-m[i], i});
    }
    sort(all(ve));

    int ans = 0;
    for (int i = 0; i < sz(ve);) {
        int cnt = 0;
        vector<pair<pii, int>> ve2;
        while (i < n && ve[i].first == ve[i-cnt].first) {
            int pos = ve[i].second;
            int l = max(0, a[pos]-m[pos]), r = a[pos] - max(0, m[pos] - b[pos]);
            ve2.push_back({{l, r}, pos});
            ++i, ++cnt;
        }
        sort(all(ve2), [](const auto &a, const auto &b) { return a.first.second < b.first.second; });

        pii I = {-inf, inf};
        int pre = -1;
        rep(j, 0, sz(ve2)) {
            int l = ve2[j].first.first, r = ve2[j].first.second;
            if (l > I.second) {
                int target = I.second;
                ++ans;
                rep(k, pre+1, j) {
                    int pos = ve2[k].second;
                    x[pos] = a[pos]-target;
                    y[pos] = m[pos] - x[pos];
                }
                pre = j-1;
                I = {-inf, inf};
            } else {
                I.first = max(I.first, l);
                I.second = min(I.second, r);
            }
        }

        int target = I.second;
        ++ans;
        rep(k, pre+1, sz(ve2)) {
            int pos = ve2[k].second;
            x[pos] = a[pos]-target;
            y[pos] = m[pos] - x[pos];
        }
    }

    
    cout << ans << '\n';
    rep(i, 0, n) {
        cout << x[i] << ' ' << y[i] << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

