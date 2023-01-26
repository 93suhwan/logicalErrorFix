#ifdef prabhav_
    // #define TERMINAL
    #include "Headers/debug.cpp"
#else
    #define d(...) 0
    #pragma GCC optimize("O3")
    #pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#endif
#include <bits/stdc++.h>
using namespace std; 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v) { for (auto &it : v) cin >> it; return istream; }

#define int long long int
#define vi vector<int>
#define pii pair<int, int>
#define ld long double
#define forp(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define sz(a) (int)a.size()
#define fora(x) for(auto &it: x)
#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define uniq(a) (a).erase(unique(all(a)), (a).end())
#define fix(f,n) fixed << setprecision(n) << f
#define setbits(x) __builtin_popcount(x)
#define setbitsll(x) __builtin_popcountll(x)
#define MSB(n) (32 - __builtin_clz(n))
#define pb push_back
#define ff first
#define ss second
const int INF = 2e18;
#define M 1000000007
int ceil(int a, int b) { return (a + b - 1)/b; }


void prabhav() {
    int n, temp;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    a.push_back(1);
    int f = 0;
    forp(i, 0, n) {
        if(a[i] != a[i + 1] && a[i] == 0) {
            f = 1;
            break;
        }
    }
    if(!f) {
        cout << "-1\n";
        return;
    }
    else {
        vector<int> ans;
        if(a[n - 1] == 0) {
            forp(i, 1, n + 2)
                ans.pb(i);
        }
        else {
            int x = 0;
            forp(i, 0, n) {
                if(!x && a[i] != a[i + 1] && !a[i]) {
                    ans.pb(i + 1);
                    ans.pb(n + 1);
                    x = 1;
                }
                else ans.pb(i + 1);
                // d(ans);
            }
        }
        for(auto it: ans)
            cout << it << " ";
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--)
        prabhav();
    return 0;
}