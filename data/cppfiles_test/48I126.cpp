#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long INF = 1e18;
const long long N = 500005;
int t[4 * N];
void update(int v, int l, int r, int pos) {
  if (l == r) {
    t[v] = 1 - t[v];
    return;
  }
  int m = (l + r) / 2;
  if (pos <= m) {
    update(2 * v, l, m, pos);
  } else {
    update(2 * v + 1, m + 1, r, pos);
  }
  t[v] = t[2 * v] + t[2 * v + 1];
}
int get(int v, int l, int r, int s, int e) {
  if (s > e) {
    return 0;
  }
  if (l == s and r == e) {
    return t[v];
  }
  int m = (l + r) / 2;
  return get(2 * v, l, m, s, min(m, e)) +
         get(2 * v + 1, m + 1, r, max(m + 1, s), e);
}
bool b[N];
long long x[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    bool check = false;
    long long ans = 0;
    for (long long i = (1); i < (n + 1); i++) {
      b[i] = 0;
    }
    for (long long i = (1); i < (n + 1); i++) {
      cin >> x[i];
      if (b[x[i]]) {
        check = true;
      }
      b[x[i]] = 1;
    }
    if (check) {
      cout << "YES" << endl;
      continue;
    }
    update(1, 1, n, x[1]);
    for (long long i = (2); i < (n + 1); i++) {
      ans += get(1, 1, n, x[i] + 1, n);
      update(1, 1, n, x[i]);
    }
    cout << ans << endl;
    for (long long i = (1); i < (n + 1); i++) {
      update(1, 1, n, x[i]);
    }
    cout << "NO\0YES" + 3 * (ans % 2 == 0) << endl;
  }
  return 0;
}
