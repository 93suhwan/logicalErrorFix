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
string s[maxn + 1];
int dif[maxn + 1], n;
int solve(char ch) {
  int chTot = 0, otherTot = 0;
  for (int i = 0; i <= n - 1; ++i) {
    int chCount = 0, otherCount = 0;
    for (auto x : s[i]) (x == ch) ? chCount++ : otherCount++;
    dif[i] = otherCount - chCount;
    chTot += chCount, otherTot += otherCount;
  }
  int differ = otherTot - chTot;
  if (chTot > otherTot) return n;
  sort(dif, dif + n, greater<int>());
  for (int i = 0; i <= n - 1; ++i) {
    differ -= dif[i];
    if (differ < 0) return n - i - 1;
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int q;
  cin >> q;
  while (q--) {
    cin >> n;
    for (int i = 0; i <= n - 1; ++i) cin >> s[i];
    int ans = 0;
    for (int i = 0; i <= 4; ++i) ans = max(ans, solve(i + 'a'));
    cout << ans << endl;
  }
  return 0;
}
