#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <set>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <regex>
#include <cmath>
#include <map>
#include <iterator>
#include <climits>
#include <numeric>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <array>
#include <valarray>
#include <complex>
#include <random>
#include <functional>
#include <cassert>
#include <chrono>
#include <memory>

using namespace std;

#define int long long
//region TEMPLATE
////@formatter:off
typedef long long ll;
typedef unsigned long long ull;
template<typename T>void __read(T&a){cin >> a;}
template<typename T,typename ... Args>void __read(T&a,Args&... args){cin >> a;__read(args...);}
#define make(t, ...) t __VA_ARGS__; __read(__VA_ARGS__)
#define makev(a, n) VI a(n); for(auto&v:(a)) cin >> v;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define FOR(i, n) for (signed i = 0 ; i < n; ++i)
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef pair<int, int> PII;
constexpr ll M7 = 1000000007;
constexpr ll M9 = 1000000009;
constexpr ll MFFT = 998244353;
constexpr double PI = 3.14159265358979323846;
template<class T> void outv(const T&a,char d=' ', bool nl=false){for(auto&x:a)cout<<x<<d;if(nl)cout<<'\n';}
static mt19937_64 rnd(static_cast<unsigned>(chrono::steady_clock::now().time_since_epoch().count())); // NOLINT(cert-err58-cpp)
auto __fast_io__=(ios_base::sync_with_stdio(false),cin.tie(nullptr)); // NOLINT(cert-err58-cpp,cppcoreguidelines-interfaces-global-init)
////@formatter:on
//endregion



void solve(int32_t testNumber) {
    make(int, n);
    vector<tuple<int, int, int>> a(n);
    map<int, vector<tuple<int, int, int>>> ev;
    for (int i = 0; i < n; ++i) {
        auto&[x, y, m] = a[i];
        cin >> x >> y >> m;
        int mn_x = max(0ll, x - m);
        int mx_x = x - (m - min(y, m));
        ev[x + y - m].emplace_back(mn_x, mx_x, i);
    }
    int ans = 0;
    vector<pair<int, int>> b(n);
    for (auto &[key, e]: ev) {
        sort(ALL(e));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        for (auto&[mn_x, mx_x, i]: e) {
            if (!q.empty() && q.top().first < mn_x) {
                ans++;
                int x = q.top().first;
                while (!q.empty()) {
                    auto& [vv, ind] = q.top();
                    q.pop();
                    b[ind].first = x;
                    b[ind].second = get<1>(a[ind]) - (get<2>(a[i]) - (get<0>(a[i]) - x));
                }
            }
            q.emplace(mx_x, i);
        }
        if (!q.empty()) {
            ans++;
            int x = q.top().first;
            while (!q.empty()) {
                auto [vv, ind] = q.top();
                q.pop();
                b[ind].first = x;
                b[ind].second = get<1>(a[ind]) - (get<2>(a[ind]) - (get<0>(a[ind]) - x));
            }
        }
    }
    cout << ans << '\n';
    for(int i = 0; i < n;++i){
        cout << get<0>(a[i]) - b[i].first << ' '  << get<1>(a[i]) - b[i].second << '\n';
    }


}


int32_t main() {
    make(int32_t, testCount);
    for (int32_t testNumber = 0; testNumber < testCount; ++testNumber) {
        solve(testNumber);
    }
    return 0;
}