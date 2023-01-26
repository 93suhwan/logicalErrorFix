/** SmartCoder
________________$$$$__________________$$$$
 _______________$__$$_________________$$__$
 ______________$$___$_________________$___$$
 ______________$$___$_________________$___$$
 _____________$$___$$_________________$___$$
 ____________$$____$__________________$____$$
 __________$$$____$$__________________$$____$$$
 _________$$_____$$____________________$$_____$$
 ________$$______$$____________________$$______$$
 _______$$_______$_______________________$_______$$
 ______$$________$$$$$$$___________$$$$$$$________$$
 __$$$$$_______________$$$_______$$$_______________$$$$
 _$$$____________$$$$____$$_____$$____$$$$____________$$
 $$____________$$$__$$$___$_____$___$$$__$$$___________$
 $____________$$$________$$_____$$________$$$___________$
 $____________$$$$$$____$$_______$$____$$$$$$___________$
 $___________$$____$$$$$$$_______$$$$$$$____$$__________$
 $___________$$$$_______$$_______$$_______$$$$__________$
 $$_________$$__$$$$$$$$$_________$$$$$$$$$__$$________$
 _$$$$_____$$$$________$___________$________$$$$______$$
 __$$$$$____$$$$$$____$$___________$$____$$$$$$____$$$$
 ______$$__$$____$$$$$$_____________$$$$$$____$$__$$
 _______$$$_$$$_____$________________$_____$$$_$$$
 _________$$$$$$$$$$__________________$$$$$$$$$..
**/

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>  // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
using namespace std;

#define sz(a) int((a).size())
#define pb emplace_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define minei(x) min_element(x.begin(), x.end()) - (x).begin()
#define maxei(x) max_element(x.begin(), x.end()) - (x).begin()
#define LSOne(S) (S & (-S))

#define uns(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define acusum(x) accumulate(x.begin(), x.end(), 0ll)
#define acumul(x) accumulate(x.begin(), x.end(), 1, multiplies<int>());
#define bits(x) __builtin_popcount(x)
#define inf 1000000000
#define MAXN 1000007
#define MOD 1000000007
#define debug(x) cerr << (#x) << " = " << (x) << '\n';
typedef long long ll;

const double pi = acos(-1.0);
const double eps = 1e-11;
int n, m;
int dir_I[4] = {0, 0, -1, 1};
int dir_J[4] = {-1, 1, 0, 0};

void _solve() {
    cin >> n >> m;
    vector<string> mat(n);
    vector<vector<bool> > vis(n, vector<bool>(m, false));

    int x = -1, y = -1;
    for (int i = 0; i < n; i++) cin >> mat[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'L') {
                x = i, y = j;
            }
        }
    }
    queue<pair<int, int> > Q;
    for (int k = 0; k < 4; k++) {
        int ii = x + dir_I[k];
        int jj = y + dir_J[k];
        if (ii < 0 || ii >= n || jj < 0 || jj >= m || mat[ii][jj] != '.') continue;
        Q.push({ii, jj});
    }
    while (!Q.empty()) {
        pair<int, int> tp = Q.front();
        Q.pop();
        int i = tp.first;
        int j = tp.second;
        if (vis[i][j]) continue;
        vis[i][j] = true;
        // only if I have at most one direction valid
        int cnt = 0;
        for (int k = 0; k < 4; k++) {
            int ii = i + dir_I[k];
            int jj = j + dir_J[k];
            if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
            if (mat[ii][jj] == '.') cnt++;
        }
        // cout << i << " " << j << " " << cnt << "\n";
        if (cnt <= 1) {
            mat[i][j] = '+';
            vis[i][j] = true;
        }
        for (int k = 0; k < 4; k++) {
            int ii = i + dir_I[k];
            int jj = j + dir_J[k];
            if (ii < 0 || ii >= n || jj < 0 || jj >= m || vis[ii][jj] || mat[ii][jj] != '.') continue;
            Q.push({ii, jj});
        }
    }
    for (int i = 0; i < n; i++) {
        cout << mat[i] << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        _solve();
    }

    return 0;
}
