// Problem: C. Slay the Dragon
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Date / Time: 2021-09-20 11:52:31
// Author: cosenza
// всё что ни делается - всё к лучшему
// check list -> long long, special cases, array size, mod (a*b%p*c%p not a*b*c%p  ,  (a-b+p)%p not a-b )
// 
// Powered by CP Editor (https://cpeditor.org)

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//THESE ARE LAST DITCH EFFORTS!!!

#include <bits/stdc++.h>

#define int long long

using namespace std;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int sum = accumulate(v.begin(), v.end(), 0);
    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        int idx = lower_bound(v.begin(), v.end(), x) - v.begin();
        if(idx == n) {
            idx--;
        }
        long long ans = 0;
        if(idx > 0) {
            if(abs(x - v[idx - 1]) < abs(x - v[idx])) {
                idx--;
            }
        }
        if(x - v[idx] > 0) {
            ans += x - v[idx];
        }
        if(sum - v[idx] < y) {
            ans += y - sum + v[idx];
        }
        cout << ans << "\n";
    }
    return 0;
}