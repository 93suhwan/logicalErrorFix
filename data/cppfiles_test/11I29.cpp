#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print(const T& v) {
  cerr << v << ' ';
}
template <typename T1, typename... T2>
void print(const T1& first, const T2&... rest) {
  print(first);
  print(rest...);
}
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
const int maxn = 2e5;
string s;
pii info[5][maxn + 1];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int q, n;
  cin >> q;
  while (q--) {
    cin >> n;
    int cnt[5] = {0}, tot = 0, ans = 0;
    for (int i = 0; i <= n - 1; ++i) {
      cin >> s;
      for (auto x : s) cnt[x - 'a']++, tot++;
      for (int k = 0; k <= 4; ++k) {
        info[k][i] = {0, 0};
        for (auto x : s) {
          if ((x - 'a') == k) info[k][i].first++;
          if ((x - 'a') != k) info[k][i].second++;
        }
      }
    }
    int curBakiLength[5] = {tot - cnt[0], tot - cnt[1], tot - cnt[2],
                            tot - cnt[3], tot - cnt[4]};
    for (int i = 0; i <= 4; ++i) {
      if (cnt[i] > curBakiLength[i]) {
        ans = n;
        goto output;
      }
    }
    for (int k = 0; k <= 4; ++k) {
      sort(info[k], info[k] + n, [](const pii& a, const pii& b) {
        return ((a.second - a.first) == (b.second - b.first))
                   ? a.first <= b.first
                   : ((a.second - a.first) >= (b.second - b.first));
      });
    }
    for (int i = 0; i <= n - 1; ++i) {
      for (int k = 0; k <= 4; ++k) {
        cnt[k] -= info[k][i].first;
        curBakiLength[k] -= info[k][i].second;
        if (cnt[k] > curBakiLength[k]) {
          ans = n - (i + 1);
          goto output;
        }
      }
    }
  output:
    cout << ans << endl;
  }
  return 0;
}
