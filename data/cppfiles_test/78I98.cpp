#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        vector<int> a(30);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;

            for (int j = 0; j < 30; ++j) {
                if ((x >> j) & 1) {
                    a[j]++;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < 30; ++i) {
            ans = gcd(ans, a[i]);
        }
    
        if (ans == 0) {
            for (int i = 0; i < n; ++i) {
                cout << 0 << " ";
            }
            cout << '\n';
        } else {
            for (int i = 1; i <= n; ++i) {
                if (ans % i == 0) cout << i << " ";
            }
            cout << '\n';
        }

    } 
}
