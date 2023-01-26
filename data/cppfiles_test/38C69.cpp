#include <bits/stdc++.h>
using namespace std;
long long int fact[500005];
long long int fact_(long long int n) {
  long long int ans = 1;
  fact[0] = fact[1] = 1;
  for (int i = 2; i <= n; i++) {
    ans = (ans * i) % 998244353;
    fact[i] = ans % 998244353;
  }
  return ans;
}
long long int mod_pow(long long int a, long long int b) {
  long long int ans = 1;
  while (b) {
    if (b % 2 == 1) ans = (ans * a) % 998244353;
    a = (a * a) % 998244353;
    b = b >> 1;
  }
  return ans;
}
long long int ncr(long long int n, long long int r) {
  if (n < 0 || r < 0) return 0;
  if (n == 0 && r == 0) return 1;
  if (n < r) return 0;
  if (r == 0) return 1;
  if (r == 1) return n;
  if (n == r) return 1;
  return ((((fact[n] % 998244353) *
            mod_pow(fact[r] % 998244353, 998244353 - 2)) %
           998244353) *
          mod_pow(fact[n - r] % 998244353, 998244353 - 2)) %
         998244353;
}
void affirm() { cout << "YES" << endl; }
void deny() { cout << "NO" << endl; }
template <typename T>
void print(T x) {
  cout << x << " ";
}
struct comp {
  bool operator()(const long long int &x, const long long int &y) const {
    return x < y;
  }
};
long long int nxt() {
  long long int x;
  cin >> x;
  return x;
}
struct DSU {
  vector<int> parent, size;
  DSU(int n) {
    parent.resize(n + 5);
    size.resize(n + 5);
    for (int i = 1; i <= n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }
  int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
  }
  void join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (size[x] < size[y]) swap(x, y);
    parent[y] = x;
    size[x] += size[y];
  }
};
void solve() {
  long long int n, m;
  cin >> n >> m;
  vector<int> pref(m + 5);
  char mat[n + 5][m + 5];
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++) {
      mat[i][j] = s[j - 1];
    }
  }
  pref[0] = 0;
  pref[1] = 0;
  for (int i = 2; i <= m; i++) {
    for (int j = 1; j < n; j++) {
      if (mat[j][i] == 'X' && mat[j + 1][i - 1] == 'X') pref[i]++;
    }
  }
  for (int i = 1; i <= m; i++) {
    pref[i] = pref[i] + pref[i - 1];
  }
  long long int q;
  cin >> q;
  while (q--) {
    long long int x1, x2;
    cin >> x1 >> x2;
    if (x1 == x2) {
      cout << "YES" << endl;
      continue;
    }
    if (pref[x2] - pref[x1] > 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
