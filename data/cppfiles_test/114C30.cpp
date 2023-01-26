#include <bits/stdc++.h>
using namespace std;
const int MAXN = 11;
const int MAXC = 2e5 + 10;
const int MAXM = 1e5 + 10;
const int Mod = 1e9 + 7;
const int base = 233 + rand();
inline void chk_mx(int &x, int y) {
  if (x < y) x = y;
}
int n, m;
int c[MAXN];
int a[MAXN][MAXC];
inline int get_hsh(vector<int> tmp) {
  int res = 0;
  for (int i = 1; i <= n; i++) res = ((long long)res * base + tmp[i]) % Mod;
  return res;
}
inline void get_val(vector<int> &tmp) {
  int sum = 0;
  for (int i = 1; i <= n; i++) sum += a[i][tmp[i]];
  tmp[0] = -sum;
}
void solve() {
  scanf("%d", &n);
  static vector<int> Mx_pos;
  Mx_pos.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
    for (int j = 1; j <= c[i]; j++) scanf("%d", &a[i][j]);
    Mx_pos[i] = c[i];
  }
  static set<vector<int> > s;
  static unordered_map<int, bool> mmp;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    vector<int> tmp;
    tmp.resize(n + 1);
    for (int j = 1; j <= n; j++) scanf("%d", &tmp[j]);
    mmp[get_hsh(tmp)] = true;
  }
  s.insert(Mx_pos);
  while (!s.empty()) {
    vector<int> vec = *s.begin();
    s.erase(s.begin());
    if (!mmp[get_hsh(vec)]) {
      for (int i = 1; i <= n; i++) printf("%d ", vec[i]);
      return;
    }
    for (int i = 1; i <= n; i++) {
      vec[i]--;
      if (vec[i] >= 1) {
        get_val(vec);
        s.insert(vec);
      }
      vec[i]++;
    }
  }
  assert(false);
}
int main() {
  srand(time(0));
  int T = 1;
  while (T--) solve();
  return 0;
}
