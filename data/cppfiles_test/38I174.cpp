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
  if (temp[i][j] == 'X') {
    return false;
  }
  if (j == x || i == 0) {
    return true;
  }
  if (i - 1 >= 0 && helper(temp, i - 1, j, x) == true) {
    return true;
  }
  if (j - 1 >= 0 && helper(temp, i, j - 1, x) == true) {
    return true;
  }
  return false;
}
int main() {
  int n;
  cin >> n;
  int m;
  cin >> m;
  vector<vector<char>> temp(n, vector<char>(m, 'D'));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> temp[i][j];
    }
  }
  vector<int> col(m, 0);
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (temp[j][i] == '.' && temp[j - 1][i] == 'X' && temp[j][i - 1] == 'X') {
        col[i]++;
      }
    }
  }
  for (int i = 1; i < m; i++) {
    col[i] += col[i - 1];
  }
  int q;
  cin >> q;
  int x, y;
  while (q--) {
    cin >> x >> y;
    if (col[y - 1] - col[x - 1] > 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}
