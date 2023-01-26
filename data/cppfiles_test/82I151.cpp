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
  if ((r + 1 - l) % 2)
    return -(qtd[l][0] - qtd[r + 1][1]) + (qtd[l][1] - qtd[r + 1][0]);
  return -(qtd[l][0] - qtd[r + 1][0]) + (qtd[l][1] - qtd[r + 1][1]);
}
int delta_chn(int ini, int l, int r) {
  int deltapos;
  if ((r - l) % 2)
    deltapos =
        2 * ((qtd[l + 1][0] - qtd[r + 1][1]) - (qtd[l + 1][1] - qtd[r + 1][0]));
  else
    deltapos =
        2 * ((qtd[l + 1][0] - qtd[r + 1][0]) - (qtd[l + 1][1] - qtd[r + 1][1]));
  if (s[l] == '+') {
    if ((l - ini) % 2)
      deltapos++;
    else
      deltapos--;
  } else {
    if ((l - ini) % 2)
      deltapos--;
    else
      deltapos++;
  }
  return deltapos;
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
        dif = delta(l, r);
      }
      if (!ok) cout << "1\n";
      int l_bin = l, r_bin = r;
      bool leave = false;
      while (l_bin + 1 < r_bin) {
        int m_bin = (l_bin + r_bin) / 2;
        int dl = (dif + delta_chn(l, l_bin, r));
        int dm = (dif + delta_chn(l, m_bin, r));
        int dr = (dif + delta_chn(l, r_bin, r));
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
        } else if (dl * dm < 0) {
          r_bin = m_bin;
        } else
          l_bin = m_bin;
      }
      if (!leave) {
        int dl = (dif + delta_chn(l, l_bin, r));
        int dr = (dif + delta_chn(l, r_bin, r));
        if (!dl)
          cout << l_bin + 1 << "\n";
        else
          cout << r_bin + 1 << "\n";
      }
    }
    for (int i = 0; i <= n; i++) qtd[i][0] = qtd[i][1] = 0;
  }
  return 0;
}
