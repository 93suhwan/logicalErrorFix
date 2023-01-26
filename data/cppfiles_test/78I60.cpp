#include<bits/stdc++.h>
#define int ll
#define sz(x) int((x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int minf = 0xc0c0c0c0c0c0c0c0;







signed main() {
    ios::sync_with_stdio(0); cin.tie(0);



    int TC; cin >> TC;
    while (TC--) {

        int n; cin >> n;
        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }

        if (count(all(a), 0) == n) {
            for (int i = 1; i <= n; i++) {
                cout << i << ' ';
            }
            cout << '\n';
            continue;
        }

        int g = n - count(all(a), 0);

        for (int j = 0; j < 30; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] & (1LL << j)) {
                    ++cnt;
                }
            }
            g = gcd(g, cnt);
        }

        vector<int> res;

        for (int i = 1; i * i <= g; i++) {
            if (g % i == 0) {
                res.push_back(i);
                if (i * i != g) {
                    res.push_back(g / i);
                }
            }
        }

        sort(all(res));

        for (auto i : res) {
            cout << i << ' ';
        }
        cout << '\n';







    }






    return 0;
}