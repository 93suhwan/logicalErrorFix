#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;
template <typename... Args>
void readln(Args &...args) {
  ((cin >> args), ...);
}
template <typename... Args>
void writeln(Args... args) {
  ((cout << args << " "), ...);
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  readln(n, m);
  ;
  vpii a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
    a[i].second += a[i].first;
    a[i].first = a[i].second - a[i].first;
  }
  vint lst(n + 1, -1);
  struct Info {
    int s, e, i;
  };
  vector<Info> v;
  for (int i = 1; i <= m; i++) {
    int first, second;
    readln(first, second);
    ;
    if (lst[second] > 0) {
      if (lst[second] < i) v.push_back({lst[second], i, second});
      lst[second] = -1;
    } else
      lst[second] = i + a[second].second - a[second].first;
  }
  for (int i = 1; i <= n; i++)
    if (0 < lst[i] && lst[i] < m + 1) v.push_back({lst[i], m + 1, i});
  vint sum(m + 2);
  const static int B = 200;
  vector<vint> bsum(B, vint(m + B + 2));
  for (Info &t : v) {
    pii c = a[t.i];
    if (c.second >= B || t.e - t.s <= 5 * B) {
      for (int i = t.s; i < t.e; i += c.second) {
        sum[i]++;
        sum[min(t.e, i + c.first)]--;
      }
    } else {
      int ee = t.s + (t.e - t.s) / c.second * c.second;
      while (ee < t.e) ee += c.second;
      for (int i = 0; i < c.first; i++) {
        bsum[c.second][t.s + i]++;
        if (ee - c.second + i >= t.e) ee -= c.second;
        bsum[c.second][ee + i]--;
      }
    }
  }
  for (int i = 1; i <= m; i++) sum[i] += sum[i - 1];
  for (int i = 2; i < B; i++) {
    for (int j = 1; j <= m; j++) {
      if (i <= j) bsum[i][j] += bsum[i][j - i];
      sum[j] += bsum[i][j];
    }
  }
  for (int i = 1; i <= m; i++) cout << sum[i] << '\n';
  return 0;
}
