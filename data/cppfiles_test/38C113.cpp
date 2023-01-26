#include <bits/stdc++.h>
using namespace std;
long long int modpwr(long long int x, long long int y, long long int m) {
  x %= m;
  if (x == 0) return 0;
  long long int ans = 1;
  while (y) {
    if (y % 2) {
      ans = (ans * x) % m;
    }
    x = (x * x) % m;
    y = y / 2;
  }
  return ans;
}
bool isPrime(long long int n) {
  for (long long int i = 2; i <= sqrt(n); i++) {
    if ((n % i) == 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  for (int tt = 1; tt <= t; tt++) {
    int n, m;
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    vector<int> check(m + 1, 0);
    for (int j = 1; j < m; j++) {
      for (int i = 1; i < n; i++) {
        if (a[i - 1][j] == 'X' && a[i][j - 1] == 'X') {
          check[j + 1] = 1;
        }
      }
    }
    for (int i = 2; i <= m; i++) {
      check[i] += check[i - 1];
    }
    int q;
    cin >> q;
    while (q--) {
      int x1, x2;
      cin >> x1 >> x2;
      int sum = check[x2] - check[x1];
      if (sum)
        cout << "NO\n";
      else
        cout << "YES\n";
    }
  }
}
