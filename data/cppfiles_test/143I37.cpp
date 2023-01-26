#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("abm,fma,mmx,avx,popcnt,avx2,sse,sse2,sse3")

#include <bits/stdc++.h>

#define int int_fast64_t

using namespace std;
namespace RR = ranges;

void Seeyouagain() {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
                cin >> a[i];
                ++cnt[a[i]];
        }
        vector<int> out(n + 1, -1);
        set<int> z;
        if (cnt[0]) {
                out[0] = cnt[0];
                --cnt[0];
                if (cnt[0]) z.insert(0);
        } else out[0] = 0;
        int dx = 0, done = 0;
        for (int i = 1; i <= n; ++i) {
                if (out[i - 1] == -1) break;
                if (cnt[i]) {
                        --cnt[i];
                        if (cnt[i]) z.insert(i);
                        done = i;
                        out[i] = cnt[i] + dx + 1;
                } else {
                        if ((done + 1) == i) {
                                out[i] = dx;
                                if (!z.empty()) {
                                        int Z = *(--z.end());
                                        --cnt[Z];
                                        if (!cnt[Z]) z.erase(Z);
                                        dx += (i - Z);
                                        done = i;
                                } else break;
                        }
                }
        }
        for (int i = 0; i <= n; ++i) cout << out[i] << " ";
}

signed main() {
        ios_base::sync_with_stdio(!cin.tie(nullptr));
        int testc = 1;
        cin >> testc;
        while (testc--) {
                Seeyouagain();
                cout << "\n";
        }
        return 0;
}