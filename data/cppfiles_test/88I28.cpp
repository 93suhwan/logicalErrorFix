#include <bits/stdc++.h>
using namespace std;
const long long LINF = (long long)1e18 + 47;
const int INF = (int)1e9 + 47;
const int MOD = (int)1e9 + 7;
const int modulo = 998244353;
const int nax = 3 * (int)1e5 + 47;
const double EPS = 1e-10;
const int K = 26;
const double PI = acos(-1.0);
map<int, int> mp;
vector<vector<int> > res;
int seen[nax];
int should[nax];
int cnt[nax];
int ok[nax];
int n, m;
int put(int pos) {
  int id = pos / m;
  pos = pos % m;
  int ans = 0;
  for (int i = (0); i < (pos); i++) {
    if (res[id][i]) ans++;
  }
  res[id][pos] = 1;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int tt;
  cin >> tt;
  for (int test = (1); test < (tt + 1); test++) {
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    res.resize(n);
    for (int i = (0); i < (n); i++) res[i].resize(m);
    vector<int> vec;
    for (int i = (0); i < (n); i++)
      for (int j = (0); j < (m); j++) {
        cin >> a[i][j];
        vec.push_back(a[i][j]);
      }
    int val = 0;
    sort(vec.begin(), vec.end());
    for (int i = (0); i < ((int)vec.size()); i++) {
      mp[vec[i]] = val;
      if (i == (int)vec.size() - 1) break;
      if (vec[i] != vec[i + 1]) val++;
    }
    for (int i = (0); i < (n); i++)
      for (int j = (0); j < (m); j++) {
        a[i][j] = mp[a[i][j]];
        cnt[a[i][j]]++;
      }
    mp.clear();
    int pos = 0;
    int ans = 0;
    for (int i = (0); i < (val + 1); i++) {
      pos += cnt[i];
      should[i] = pos - 1;
    }
    for (int i = (0); i < (n); i++)
      for (int j = (0); j < (m); j++) {
        if (ok[a[i][j]]) {
          ans += put(should[a[i][j]] - seen[a[i][j]]++);
          continue;
        }
        int pos = (a[i][j] == 0 ? 0 : should[a[i][j] - 1] + 1) + seen[a[i][j]];
        int cur_id = pos / m;
        int pp = (a[i][j] == 0 ? 0 : should[a[i][j] - 1] + 1);
        if (cur_id == pp / m) {
          ans +=
              put(min((cur_id + 1) * m - 1, should[a[i][j]]) - seen[a[i][j]]++);
        } else if (cur_id == should[a[i][j]] / m) {
          if (!ok[a[i][j]]) {
            seen[a[i][j]] = 0;
            ok[a[i][j]] = 1;
          }
          ans += put(should[a[i][j]] - seen[a[i][j]]++);
        }
      }
    cout << ans << '\n';
    for (int i = (0); i < (val + 1); i++) {
      should[i] = 0, seen[i] = 0, cnt[i] = 0, ok[i] = 0;
    }
    for (int i = (0); i < (n); i++)
      for (int j = (0); j < (m); j++) res[i][j] = 0;
  }
}
