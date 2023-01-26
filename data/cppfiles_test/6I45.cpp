#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

typedef long long ll;
typedef pair<int, int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


const int C = (int)1e5 + 5;
const ll MOD = (ll)1e9 + 7;

int mu[C], cnt[C], phi[C];
vector<int> divs[C];


// sum_{i, j} gcd(a_i, a_j)

ll brutesolve(const vector<int>& a) {
    ll res = 0;
    for (int x : a) {
        for (int y : a) {
            res += __gcd(x, y);
        }
    }
    return res;
}

ll solve(const vector<int>& a) {
    int n = sz(a);
    unordered_set<int> S;
    unordered_map<int, int> cnt_divs;
    
    for (int i = 0; i < n; ++i) {
        ++cnt[a[i]];
        S.insert(a[i]);
    }
    
    for (int x : S) {
        for (int d : divs[x]) {
            cnt_divs[d] += cnt[x];
        }
    }
    
    ll ans = 0;
    for (auto [t, cntd] : cnt_divs) {
        //cout << cntd << ' ' << t << '\n';
        ans += phi[t] * cntd * cntd;
    }
    
    for (int i = 0; i < n; ++i) {
        --cnt[a[i]];
    }
    
    /*
    ll brutesolve_ans = brutesolve(a);
    if (ans != brutesolve_ans) {
        cout << "a = ";
        for (int x : a) cout << x << ' ';
        cout << '\n';
        cout << "ans =  " << ans << '\n';
        cout << "bans = " << brutesolve_ans << '\n';
        cout << "\n";
    }
    */
    
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int x = 0; x < C; ++x) {
        mu[x] = 0;
        cnt[x] = 0;
        phi[x] = 0;
    }
    mu[1] = 1;
    for (int x = 1; x < C; ++x) {
        for (int y = x + x; y < C; y += x) {
            mu[y] -= mu[x];
        }
        for (int y = x; y < C; y += x) {
            phi[y] += y / x * mu[x];
            divs[y].push_back(x);
        }
    }
    
    
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    
    ll ans = 0;
    
    for (int k = 1; k <= n; ++k) {
        vector<int> t;
        for (int i = k; i <= n; i += k) {
            t.push_back(a[i]);
        }
        if (sz(t) <= 10) {
            ans += phi[k] * brutesolve(t);
        } else {
            ans += phi[k] * solve(t);
        }
    }
    
    
    cout << ans % MOD << '\n';
    
    return 0;
}
