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
    int a[n], b[n];
    pii c[n];
    vector <int> p[n+1];
    for (int i=0;i<n;++i) {
        cin >> a[i] >> b[i];
        c[i] = {a[i], b[i]};
        p[b[i]].push_back(i);
    }
    sort(a, a+n);
    sort(b, b+n);
    sort(c, c+n);
    int ans = 0;
    vector <int> v;
    int cnt = 1;
    v.push_back(0);
    for (int i=0;i<n-1;++i) {
        if (a[i+1] == a[i]) {cnt++;continue;}
        ans += cnt * ((i+1)-cnt) * (n-i-1);
        v.push_back(i);
        cnt = 1;
    }
    cnt = 1;
    for (int i=0;i<n-1;++i) {
        if (b[i+1] == b[i]) {cnt++;continue;}
        ans += cnt * ((i+1)-cnt) * (n-i-1);
        cnt = 1;
    }
    v.push_back(n-1);
    int kp = 0;
    map <int, int> k1, k2;
    for (int i=0;i<=v[1];++i) {
        k1[c[i].S]++;
    }
    if (v.size() > 2) {
        for (int i=v[2]+1;i<n;++i) {
            ans -= k1[c[i].S]*k2[c[i].S];
            k2[c[i].S]++;
            ans += k1[c[i].S]*k2[c[i].S];
        }
    }
//    cout << v.size() << '\n';
    for (int z=2;z<v.size();++z) {
//        cout << z << endl;
        int i = v[z-1], j = v[z];
        int s = v[z-2];
        for (int x=i+1;x<=j;++x) {
            int l = -1, r = p[c[x].S].size();
            while (l < r) {
                int m = (l+r+1)/2;
                if (p[c[x].S][m] <= i)
                    l = m;
                else
                    r = m-1;
            }
            int k1 = l+1;
            l = -1, r = p[c[x].S].size();
            while (l < r) {
                int m = (l+r)/2;
                if (p[c[x].S][m] > j)
                    {
                        l = max(l, 0ll);
                        r = m;
                    }
                else
                    l = m+1;
            }
            int k2 = p[c[x].S].size() - l;
//            cout << kp << ' ' << (i-k1+1) * (n-j-k2-1)  << '\n';
            ans -= (i-k1+1) * (n-j-k2-1) - kp;
        }
        for (int x=i+1;x<=j;++x) {
            ans -= k1[c[x].S]*k2[c[x].S];
            k1[c[x].S]++;
            ans += k1[c[x].S]*k2[c[x].S];
        }
        if (z < v.size() - 1) {
            for (int x=v[z]+1;x<=v[z+1];++x) {
                ans -= k1[c[x].S]*k2[c[x].S];
                k2[c[x].S]--;
                ans += k1[c[x].S]*k2[c[x].S];
            }
        }
    }
    cout << ans << endl;
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

