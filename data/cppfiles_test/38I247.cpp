#include <bits/stdc++.h>
using namespace std;
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long mul(long long x, long long y) {
  long long res = x * y;
  return (res >= LLONG_MAX ? res % LLONG_MAX : res);
}
long long power(long long x, long long y) {
  long long res = 1;
  x %= LLONG_MAX;
  while (y) {
    if (y & 1) res = mul(res, x);
    y >>= 1;
    x = mul(x, x);
  }
  return res;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
bool helper(vector<vector<char>>& temp, int i, int j, int x) {
  if (i < 0 || j < 0 || temp[i][j] == 'X') {
    return false;
  }
  if (j == x || i == 0) {
    return true;
  }
  if (helper(temp, i - 1, j, x) == true) {
    return true;
  }
  if (helper(temp, i, j - 1, x) == true) {
    return true;
  }
  return false;
}
int main() {
  int m;
  cin >> m;
  int n;
  cin >> n;
  vector<vector<char>> temp(m, vector<char>(n, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> temp[i][j];
    }
  }
  int q;
  cin >> q;
  int x, y;
  while (q--) {
    cin >> x >> y;
    if (helper(temp, m - 1, y - 1, x - 1)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
