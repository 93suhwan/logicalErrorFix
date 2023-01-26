//#define _GLIBCXX_DEBUG 1
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,tune=native")
// #pragma GCC target("avx,avx2")


#include <bits/stdc++.h>
//#include "optimization.h"
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < (ll)(n); i++)

random_device dev;
mt19937 rng(dev());
ll mod = 1e9 + 7;
uniform_int_distribution<> uid(1, 1'000'000'000);

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};



void timeS(const char *s = 0) {
    static double start = 0;
    fprintf(stderr, "%.2f : %s\n", 1. * (clock() - start) / CLOCKS_PER_SEC, s ? s : "");
    start = clock();
}


void solve() {
    // выбрали центр
    // посчитали число 
    // в каждой ветви не более 1 выбранного
    // посчитать глубины

    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n);
    forn(i, n - 1) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        a[x].push_back(y), a[y].push_back(x);
    }
    ll ans = 0;
    if (k == 2) {
        ans += n - 1;
    }

    for(int i = 0; i < n; ++i) {
        vector<int> d(n);
        if (a[i].size() < k) continue;

        {
            function<void(int, int)> dfs = [&](int v, int p) {
                if (v == i) {
                    d[v] = 0;
                }
                else {
                    d[v] = d[p] + 1;
                }

                for (auto it: a[v]) {
                    if (it != p) {
                        dfs(it, v);
                    }
                }
            };

            dfs(i, i);
            // посчитали высоты
        }

        {
            // выбираем длину
            for (int j = 1; j <= 100; ++j) {
                vector<int> in(n);

                function<void(int, int)> dfs = [&](int v, int p) {
                    if (d[v] == j) {
                        in[v]++;
                    }
                    
                    for (auto it: a[v]) {
                        if (it != p) {
                            dfs(it, v);
                            in[v] += in[it];
                        }
                    }
                };

                dfs(i, i);
                
                vector<ll> non;
                for(auto it: a[i]) {
                    if (in[it]) {
                        non.push_back(in[it]);
                    }
                }

                int n1 = non.size();
                if (n1 < k) continue;
                vector<vector<ll>> dp(n1 + 1, vector<ll>(k + 1, 0));

                dp[0][0] = 1;
                for(int i1 = 1; i1 < n1 + 1; ++i1) {
                    for(int j1 = 0; j1 < k + 1; ++j1) {
                        if (j1 > 0) {
                            dp[i1][j1] = (dp[i1 - 1][j1 - 1] * non[i1 - 1] % mod + dp[i1 - 1][j1]) % mod; 
                        }
                        else {
                            dp[i1][j1] = dp[i1 - 1][j1];
                        }
                    }
                }

                ans = (ans + dp[n1][k]) % mod;
            }

            
        }
    }
    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	//t = readInt();
	while (t--) {
		solve();
	}
	return 0;
}