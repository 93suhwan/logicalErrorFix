/**
 🍪 the_hyp0cr1t3
 🍪 25.10.2021 14:30:21
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int LG = 30, N = LG * 2e5 + 1;

    array<int, N> spf; iota(spf.begin(), spf.end(), 0);
    vector<int> primes{2}; primes.reserve(N);
    for(int z = 4; z < N; z += 2) spf[z] = 2;
    for(int z = 3; z*z < N; z += 2) if(spf[z] == z) {
        for(int y = z*z; y < N; y += z*2)
            if(spf[y] == y) spf[y] = z;
    }
    for(int z = 3; z < N; z += 2)
        if(spf[z] == z) primes.push_back(z);

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, j, n;
        cin >> n;
        array<int, LG> cnt{};
        for(i = 0; i < n; i++) {
            int a; cin >> a;
            for(j = 0; j < LG; j++)
                cnt[j] += a >> j & 1;
        }

        int g = 0;
        for(i = 0; i < LG; i++)
            g = gcd(g, cnt[i]);

        if(g == 0) {
            for(i = 1; i <= n; i++)
                cout << i << " \n"[i == n];
        } else {
            vector<int> ans;
            ans.reserve(n);
            while(g > 1)
                ans.push_back(g), g /= spf[g];
            ans.push_back(1);

            for(i = 0; auto x: ans | views::reverse)
                cout << x << " \n"[++i == ans.size()];
        }

    }();

} // ~W