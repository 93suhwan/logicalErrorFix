#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
const int maxn = 1e6 + 7;
int n, m;
int k;
string solve() {
  cin >> n >> m;
  cin >> k;
  int val = ((n % 2) << 1) + (m % 2);
  if (val == 0) {
    if (k % 2 == 0) return "YES";
    return "NO";
  } else if (val == 1) {
    int have = n * m - k * 2;
    if (have < n) return "NO";
    if (m <= 1 && k > 0) return "NO";
    if (k % 2 == 0) return "YES";
    return "NO";
  } else if (val == 2) {
    int need = m / 2;
    if (k < need) return "NO";
    k -= need;
    if (n <= 1 && k > 0) return "NO";
    if (k % 2 == 0) return "YES";
    return "NO";
  } else {
    assert(false);
  }
  assert(false);
  return "NO";
}
void maker() {
  int val = ((n % 2) << 1) + (m % 2);
  vector<vector<char>> g(n, vector<char>(m, '.'));
  int ogn = n;
  int ogm = m;
  if (val == 0) {
  } else if (val == 1) {
    int cnt = 0;
    for (int i = 0; i < n; i += 2) {
      char let = (cnt % 2 == 0) ? 'z' : 'y';
      g[i][m - 1] = let;
      g[i + 1][m - 1] = let;
      cnt++;
    }
    m--;
  } else if (val == 2) {
    int cnt = 0;
    for (int j = 0; j < m; j += 2) {
      char let = (cnt % 2 == 0) ? 'z' : 'y';
      g[n - 1][j] = let;
      g[n - 1][j + 1] = let;
      cnt++;
    }
    n--;
  } else {
    assert(false);
  }
  int j = 0;
  int start = 0;
  for (; j < m; j += 2) {
    if (k == 0) break;
    start ^= 1;
    int i = 0;
    for (; i < n; i++) {
      if (k == 0) break;
      int totj = (start % 2 == 0) ? 'a' : 'r';
      char let = (char)(totj + i % 2);
      g[i][j] = let;
      g[i][j + 1] = let;
      k--;
    }
    for (int ti = i; ti < n; ti += 2) {
      char let = (char)(ti % 2 + 'c');
      g[ti][j] = let;
      g[ti + 1][j] = let;
    }
    for (int ti = i; ti < n; ti += 2) {
      char let = (char)(ti % 2 + 'e');
      g[ti][j + 1] = let;
      g[ti + 1][j + 1] = let;
    }
  }
  start = 0;
  for (; j < m; j++) {
    start ^= 1;
    int cnt = 0;
    for (int i = 0; i < n; i += 2) {
      int totj = (start % 2 == 0) ? 'g' : 'o';
      char let = (char)(cnt % 2 + totj);
      g[i][j] = let;
      g[i + 1][j] = let;
      cnt++;
    }
  }
  for (int i = 0; i < ogn; i++) {
    for (int j = 0; j < ogm; j++) {
      cout << g[i][j];
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string ans = solve();
    cout << ans << "\n";
    if (ans == "YES") {
      maker();
    }
  }
  return 0;
}
