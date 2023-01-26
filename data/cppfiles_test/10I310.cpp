#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define endl ("\n")
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<lli>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repr(i, a, b) for (int i = a; i > b; i--)
#define mod 1000000007
#define all(s) s.begin(), s.end()
int main() {
    fast
    lli tt, n, k;
    tt = 1;
    cin>>tt;
    while (tt--) {
        cin>>n>>k;
        lli a[n], b[n] = {0};
        vector<pair<lli, lli>>v;
        vector<lli>ar[n + 1];
        rep (i, 0, n) cin>>a[i], ar[a[i]].pb(i);
        rep (i, 1, n + 1) {
            if (ar[i].size() > 0) {
                if (ar[i].size() < k) v.pb({ar[i].size(), i});
                else {
                    rep (j, 0, k) b[ar[i][j]] = j + 1;
                }
            }
        }
        sort(all(v));
        lli j = v.size() - 1;
        rep (i, 0, v.size()) {
            if (v[i].ff + v[j].ff >= k) {
                lli count = 1;
                rep (kk, 0, ar[v[i].ss].size()) b[ar[v[i].ss][kk]] = count, count++;
                rep (kk, 0, k - ar[v[i].ss].size()) b[ar[v[j].ss][kk]] = count, count++;
                j--;
            }
        }
        rep (ii, 0, n) cout<<b[ii]<<" ";
        cout<<endl;
    }
    return 0;
}