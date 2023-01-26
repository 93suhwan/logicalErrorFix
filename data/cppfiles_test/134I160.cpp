#include <bits/stdc++.h>
#define int long long
#define double long double
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define pii pair<int,int>
#define pdd pair<double,double>
#define F first
#define S second
#define ls rt<<1
#define rs rt<<1|1
#define debug(x) cerr << #x << " = " << x << "\n"
#define re register
#define shaman ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);
using namespace std;
signed main(){shaman;
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n + 5);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int g = a[1], G = a[2];
        for (int i = 1; i <= n; i += 2)
            g = __gcd(g, a[i]);
        for (int i = 2; i <= n; i += 2)
            G = __gcd(G, a[i]);
        if (g > G){
            bool ok = true;
            for (int i = 2; i <= n; i += 2)
                if (a[i] % g == 0)
                    ok = false;
            if (ok)
                cout << g << '\n';
            else
                cout << "0\n";
        }
        else{
            bool ok = true;
            for (int i = 1; i <= n; i += 2)
                if (a[i] % G == 0)
                    ok = false;
            if (ok)
                cout << G << '\n';
            else
                cout << "0\n";
        }
    }
}