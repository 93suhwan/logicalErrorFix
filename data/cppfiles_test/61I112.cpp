#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

#define pb push_back
#define F first
#define S second
#define ld long double
#define pii pair<int,int>
#define int int64_t
#define __int128_t int64_t
mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 100001;
const int M = 1e9+7;

void solve ()
{
    int n;
    cin >> n;
    int a[n], b[n], c[n];
    vector <int> ab[n+1];
    for (int i=0;i<n;++i) {
        cin >> a[i] >> b[i];
        c[i] = a[i] * 1000000 + b[i];
        ab[a[i]].push_back(b[i]);
    }
    sort(a, a+n);
    sort(b, b+n);
    sort(c, c+n);
    int cnt = 1, ans = 0;
    int kb[n+1] = {0};
    for (int i=0;i<n-1;++i) {
        if (a[i+1] == a[i]) {cnt++;continue;}
//        cout << "? " << i << ' ' << cnt << ' ' << cnt * ((i+1)-cnt) * (n-i-1) << '\n';
        ans += cnt * ((i+1)-cnt) * (n-i-1);
        cnt = 1;
    }
//    cout << ans << '\n';
    cnt = 1;
    for (int i=0;i<n-1;++i) {
        if (b[i+1] == b[i]) {cnt++;continue;}
//        cout << "! " << i << ' ' << cnt << ' ' << cnt * ((i+1)-cnt) * (n-i-1) << '\n';
        ans += cnt * ((i+1)-cnt) * (n-i-1);
        kb[b[i]] = cnt;
        cnt = 1;
    }
    kb[b[n-1]] = cnt;
//    cout << ans << '\n';
    cnt = 1;
    int pr = 0;
    int kkb[n+1] = {0};
    for (int i=0;i<n-1;++i) {
        if (c[i+1]/1000000 == c[i]/1000000) {cnt++;pr += kb[c[i]%1000000] * (kb[c[i]%1000000] - 1) / 2;continue;}
        pr += kb[c[i]%1000000] * (kb[c[i]%1000000] - 1) / 2;
        ans -= cnt * ((i+1)-cnt) * (n-i-1);
        ans += pr;
        for (int j:ab[c[i]/1000000]) {
            ans -= (kb[j] - 1) * (kb[j] - 2) / 2;
        }
//        cout << i << ' ' << ans << ' ' << cnt * ((i+1)-cnt) * (n-i-1) << ' ' << pr << '\n';
        cnt = 1;
        pr = 0;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q = 1;
    cin >> q;
    for (;q;--q) {
        solve();
    }
    return 0;
}

