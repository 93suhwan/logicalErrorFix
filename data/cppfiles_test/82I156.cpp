#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9, PI = acos(-1.);
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 3e5 + 5;
int qtd[N][2];
int n, q;
string s;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.first.second == b.first.second) return a.first.first > b.first.first;
  return a.first.second > b.first.second;
}
int delta(int l, int r) {
  int deltar = 0;
  if ((r + 1 - l) % 2) {
    deltar += (qtd[l][1] - qtd[r + 1][0]) - (qtd[l][0] - qtd[r + 1][1]);
  } else {
    deltar += (qtd[l][1] - qtd[r + 1][1]) - (qtd[l][0] - qtd[r + 1][0]);
  }
  return deltar;
}
int delta_chn(int l, int m, int r) {
  int deltaleft = 0, deltar = 0;
  if ((r - m) % 2) {
    deltar += (qtd[m + 1][1] - qtd[r + 1][0]) - (qtd[m + 1][0] - qtd[r + 1][1]);
  } else {
    deltar += (qtd[m + 1][1] - qtd[r + 1][1]) - (qtd[m + 1][0] - qtd[r + 1][0]);
  }
  if ((m - l) % 2) {
    deltaleft += (qtd[l][1] - qtd[m][0]) - (qtd[l][0] - qtd[m][1]) - deltar;
  } else {
    deltaleft += (qtd[l][1] - qtd[m][1]) - (qtd[l][0] - qtd[m][0]) + deltar;
  }
  return deltaleft;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> q >> s;
    for (int i = n - 1; i >= 0; i--) {
      qtd[i][0] = qtd[i + 1][1];
      qtd[i][1] = qtd[i + 1][0];
      if (s[i] == '+')
        qtd[i][1]++;
      else
        qtd[i][0]++;
    }
    for (int i = 0; i < q; i++) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      int dif = delta(l, r);
      bool ok = false;
      if (dif == 0) {
        cout << "0\n";
        continue;
      }
      if (!((r - l + 1) % 2)) {
        cout << "2\n" << l + 1 << " ";
        ok = true;
        l++;
      }
      if (!ok) cout << "1\n";
      int l_bin = l, r_bin = r;
      bool leave = false;
      while (l_bin < r_bin) {
        int m_bin = (l_bin + r_bin) / 2;
        int dl = (delta_chn(l, l_bin, r));
        int dm = (delta_chn(l, m_bin, r));
        int dr = (delta_chn(l, r_bin, r));
        if (!dl) {
          cout << l_bin + 1 << "\n";
          leave = true;
          break;
        }
        if (!dm) {
          cout << m_bin + 1 << "\n";
          leave = true;
          break;
        }
        if (!dr) {
          cout << r_bin + 1 << "\n";
          leave = true;
          break;
        } else if (1ll * dl * dm < 0) {
          r_bin = m_bin;
        } else
          l_bin = m_bin;
      }
    }
    for (int i = 0; i <= n; i++) qtd[i][0] = qtd[i][1] = 0;
  }
  return 0;
}
