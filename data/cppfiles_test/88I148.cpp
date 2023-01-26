// It's arseniyx92's code so u won't forget looking through it
// btw if u'll find out that I've never used "lol" or "kek" in this code
// please report on me on the codeforces platform for 'child abuse'

// ababba
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <map>
#include <set>
#include <tuple>
#include <cmath>
#include <cstdio>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <unordered_set>
#include <cstring>
#include <random>
#include <bitset>
#include <fstream>
#include <climits>

using namespace std;

//#define int long long
#define forn(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define rvec(arr) for (int i = 0; i < arr.size(); i++) cin >> arr[i];
#define ovec(arr) for (int i = 0; i < arr.size(); i++) cout << arr[i] << " "; cout << endl;
#define rep(i, s, e) for (int (i) = (s); (i) < (int)(e); ++(i))
#define all(a) (a).begin(), (a).end()
#define lolKEK(n) cin >> (n);
#define pb push_back
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int> >;
using vvvi = vector<vector<vector<int> > >;
using vvvvi = vector<vector<vector<vector<int> > > >;

struct Timer{
    clock_t start;
    Timer(){
        start = clock();
    };
    ~Timer(){
        clock_t finish = clock();
        cout << fixed << setprecision(15) << (ld)(finish-start)/CLOCKS_PER_SEC << endl;
    };
};

void solve(istream& cin, ostream& cout){
    int n, m;
    cin >> n >> m;
    vector<pii> a(n*m);
    forn(i, n*m) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a), [](const auto& a, const auto& b){
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    int cnt = 0;
    forn(i, n*m){
        cnt++;
        if (i == n*m-1 || a[i].first != a[i+1].first){
            pii fst_pos = {(i-cnt+1)/m, (i-cnt+1)%m};
            pii lst_pos = {i/m, i%m};
            if (fst_pos.first != lst_pos.first){
                vector<pii> lol;
                int sz = (i-cnt+1) + (lst_pos.second) + 1;
                int sz1 = i - (m-1-fst_pos.second + m*fst_pos.first);
                for (int j = sz1; j <= i; ++j)
                    lol.pb(a[j]);
                for (int j = sz; j < sz1; ++j)
                    lol.pb(a[j]);
                for (int j = i-cnt+1; j <= (i-cnt+1) + (lst_pos.second); ++j)
                    lol.pb(a[j]);
                for (int j = i-cnt+1; j <= i; ++j)
                    a[j] = lol[j-(i-cnt+1)];
            }
            cnt = 0;
        }
    }

    vector<pii> inverse(n*m); // {place, block}
    forn(i, n*m) inverse[a[i].second] = {i%m, i/m};

    vvi ft(n, vi(m, 0));
    auto set = [&](int block, int pos, int val){
        for(; pos < m; pos |= pos+1) ft[block][pos] += val;
    };
    auto get = [&](int block, int pos) -> int{
        int res = 0;
        for(; pos >= 0; pos = (pos&(pos+1))-1) res += ft[block][pos];
        return res;
    };
    int ans = 0;
    forn(i, n*m){
        int pos, block;
        tie(pos, block) = inverse[i];
        ans += get(block, pos);
        set(block, pos, 1);
    }
    cout << ans << '\n';
}


int32_t main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int tt = 1;
    lolKEK(tt);
    while (tt--){
        solve(cin, cout);
    }
    return 0;
}