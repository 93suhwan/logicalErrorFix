#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)


void solve() {

    int m;
    cin >> m;
    int a[m];
    int b[m];
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    if (m == 1) {
        cout << 0 << endl;
        return;
    }
    int pre[m] = {0};
    int post[m] = {0};
    for (int i = 0; i < m; i++) {
        if (i == 0) {
            pre[i] = b[i];
            continue;
        }
        pre[i] = pre[i - 1] + b[i];
    }
    for (int i = m - 1; i >= 0; i--) {
        if (i == m - 1) {
            post[i] = a[i];
            continue;
        }
        post[i] = b[i] + post[i + 1];
    }
    int ans = INT_MAX;
    for (int i = 0; i < m; i++) {
        if (i == 0) {
            ans = min(ans, post[i + 1]);
            continue;
        }
        if (i == m - 1) {
            ans = min(ans, pre[i - 1]);
            continue;
        }
        ans = min(ans, max(pre[i - 1], post[i + 1]));
    }
    cout << ans << "\n";
    return;






}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t  << ": ";
        solve();
    }
}
