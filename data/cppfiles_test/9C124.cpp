#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1e9 + 7;
long long int mpow(long long int base, long long int exp) {
  base %= MOD;
  long long int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long int)result * base) % MOD;
    base = ((long long int)base * base) % MOD;
    exp >>= 1;
  }
  return result;
}
void solver() {
  long long int n, m, k;
  cin >> n >> m >> k;
  vector<vector<long long int>> a(n, vector<long long int>(m));
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  vector<long long int> pos(k), res(k);
  for (long long int i = 0; i < k; i++) {
    cin >> pos[i];
  }
  for (long long int i = 0; i < k; i++) {
    long long int row = 0, col = pos[i] - 1;
    while (row < n) {
      if (a[row][col] == 1) {
        a[row][col] = 2;
        col++;
      } else if (a[row][col] == 2) {
        a[row][col] = 2;
        row++;
      } else {
        a[row][col] = 2;
        col--;
      }
    }
    res[i] = col + 1;
  }
  for (long long int i = 0; i < k; i++) {
    cout << res[i] << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  long long int t = 1;
  while (t--) {
    solver();
  }
  return 0;
}
