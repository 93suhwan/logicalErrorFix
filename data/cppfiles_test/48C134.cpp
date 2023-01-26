#include <bits/stdc++.h>
using namespace std;
template <typename typC, int N>
struct bit {
  typC a[N], s[N];
  int n;
  bit() {
    memset(s, 0, sizeof s);
    memset(a, 0, sizeof a);
  }
  void init(int nn) {
    n = nn;
    memset(a + 1, 0, n * sizeof a[0]);
    memset(s + 1, 0, n * sizeof a[0]);
  }
  void init(int nn, typC *b) {
    n = nn;
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + b[i];
    memset(a + 1, 0, n * sizeof a[0]);
  }
  void mdf(int x, typC y) {
    a[x] += y;
    while ((x += x & -x) <= n) a[x] += y;
  }
  typC sum(int x) {
    typC r = a[x];
    while (x ^= x & -x) r += a[x];
    return r;
  }
  typC sum(int x, int y) { return sum(y) - sum(x - 1); }
};
const int N = 5e5 + 2;
bit<int, N> s;
int a[N], ss[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, i;
    long long r = 0;
    cin >> n;
    for (i = 1; i <= n; i++) cin >> a[i];
    for (i = 1; i <= n; i++) ss[i] = 0;
    for (i = 1; i <= n; i++) ss[a[i]]++;
    if (*max_element(ss + 1, ss + n + 1) > 1) {
      cout << "YES\n";
      continue;
    }
    s.init(n);
    for (i = 1; i <= n; i++) r += i - 1 - s.sum(a[i]), s.mdf(a[i], 1);
    if (r & 1)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
