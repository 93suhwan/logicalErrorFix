#include <bits/stdc++.h>
using namespace std;
const long long MOD = pow(10, 9) + 7;
const long long MAX = LONG_LONG_MAX;
bool cut(long long n, long long m, long long k, long long l) {
  long long d = 0, e = 0;
  if (k == 0 && n == 1) {
    return false;
  }
  if (l == 0 && m == 1) {
    return false;
  }
  if (l) {
    d = l / m;
    l -= m * d;
    n -= 2 * d;
  }
  if (k) {
    e = k / n;
    k -= e * n;
    m -= 2 * e;
  }
  if (k || l) {
    if (d == 0 && e == 0) return false;
  }
  if (k > 0) {
    if (l >= 0) {
      bool alpha = cut(n, m, k, l);
      return alpha;
    } else {
      return false;
    }
  } else if (k == 0) {
    if (l < 0)
      return false;
    else if (l > 0) {
      bool aplha = cut(n, m, k, l);
      return aplha;
    }
  } else {
    return false;
  }
  return true;
}
void solve() {
  long long n, m, k, l;
  cin >> n >> m >> k;
  l = ((n * m) / 2) - k;
  if (cut(n, m, k, l)) {
    cout << "YES";
  } else
    cout << "NO";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t > 0) {
    solve();
    t--;
    cout << endl;
  }
}
