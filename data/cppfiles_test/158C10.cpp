#include <bits/stdc++.h>
using namespace std;
const int MX = 10005;
int n, m, x[11], acu[MX], cn[22];
long long sum[MX];
string s[11];
vector<int> res;
void main_() {
  cin >> n >> m;
  for (int i = 0; i < int(n); i++) cin >> x[i];
  for (int i = 0; i < int(n); i++) cin >> s[i];
  long long mx = -1e18;
  int rm;
  for (int mk = 0; mk < int(1 << n); mk++) {
    memset(acu, 0, sizeof(acu));
    long long p = 0;
    for (int i = 0; i < int(n); i++) {
      int d = 0;
      if (mk & (1 << i)) {
        p -= x[i];
        d = 1;
      } else {
        p += x[i];
        d = -1;
      }
      for (int j = 0; j < int(m); j++)
        if (s[i][j] == '1') acu[j] += d;
    }
    memset(cn, 0, sizeof(cn));
    for (int j = 0; j < int(m); j++) cn[acu[j] + 10]++;
    for (int i = 20, x = 10, t = m; i >= 0; i--, x--) {
      p += x * sum[t];
      t -= cn[i];
      p -= x * sum[t];
    }
    if (mx < p) {
      mx = p;
      rm = mk;
    }
  }
  vector<pair<int, int> > v(m);
  for (int i = 0; i < int(m); i++) v[i].second = i;
  for (int i = 0; i < int(n); i++) {
    int d = (rm & (1 << i)) ? 1 : -1;
    for (int j = 0; j < int(m); j++)
      if (s[i][j] == '1') v[j].first += d;
  }
  sort(v.begin(), v.end());
  vector<int> res(m);
  for (int i = 0; i < int(m); i++) res[v[i].second] = i + 1;
  for (int i = 0; i < int(m); i++) cout << res[i] << " ";
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i < int(MX); i++) {
    sum[i] = i;
    if (i) sum[i] += sum[i - 1];
  }
  int t = 1;
  cin >> t;
  while (t--) main_();
  return 0;
}
