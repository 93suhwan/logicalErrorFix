#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define ordered_set tree<pii, null_type, less<pii >,rb_tree_tag, tree_order_statistics_node_update>
# define ll long long
#define ld long double
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
using namespace std;
const ll N = 2e5 + 9, mod = 1e9 + 7;
vector<string> ans(105, string(105, '.'));
bool sw;

string fch(int i, int j) {
    set<char> st;
    if (i) {
        st.insert(ans[i - 1][j]);
        st.insert(ans[i - 1][j + 1]);
    }
    if (j) {
        st.insert(ans[i][j - 1]);
        st.insert(ans[i + 1][j - 1]);
    }
    string res;
    char cur = 'a';
    while (res.size() < 2) {
        if (st.find(cur) == st.end()) {
            res += cur;
        }
        cur++;
    }
    return res;
}

void calc(int n, int m, int h, int v, int i0, int j0) {
    for (int i = i0; i < n; i += 2) {
        for (int j = j0; j < m; j += 2) {
            string ch = fch(i, j);
            if (h) {
                ans[i][j] = ans[i][j + 1] = ch[0];
                ans[i + 1][j] = ans[i + 1][j + 1] = ch[1];
                h -= 2;
            } else {
                ans[i][j] = ans[i + 1][j] = ch[0];
                ans[i][j + 1] = ans[i + 1][j + 1] = ch[1];
                v -= 2;
            }
        }
    }
}

void bld(int n, int m, int h, int v) {
    if (n % 2 == 0 && m % 2 == 0) {
        calc(n, m, h, v, 0, 0);
    } else {
        for (int i = 0; i < m; i += 2) {
            if (i == 0 || ans[0][i - 1] == 'b') ans[0][i] = ans[0][i + 1] = 'a';
            else ans[0][i] = ans[0][i + 1] = 'b';
            h -= 2;
        }
        calc(n, m, h, v, 1, 0);
    }
    if(sw){
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << ans[j][i];
            }
            cout << "\n";
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        sw = 0;
        int n, m, h, v;
        cin >> n >> m >> h;
        v = n * m / 2 - h;
        if (n % 2 == 0 && m % 2 == 0) {
            if (v % 2 == 0 && h % 2 == 0)cout << "YES\n", bld(n, m, h, v);
            else cout << "NO\n";
            continue;
        }
        if (m & 1)swap(n, m), swap(h, v), sw = 1;
        if (h < m / 2)cout << "NO\n";
        else {
            h -= m / 2;
            if (v % 2 == 0 && h % 2 == 0)cout << "YES\n", bld(n, m, h + m / 2, v);
            else cout << "NO\n";
        }
    }

    return 0;
}