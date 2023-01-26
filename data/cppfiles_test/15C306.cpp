#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
bool sortbysec(const pair<string, string>& a, const pair<string, string>& b) {
  return a.second < b.second;
}
template <typename T>
void input(vector<T>& v) {
  for (auto& it : v) cin >> it;
}
long long binPow(long long b, long long p) {
  if (p == 0) return 1;
  long long sq = binPow(b, p / 2);
  sq *= sq;
  if (p & 1) sq *= b;
  return sq;
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> v(n);
    input(v);
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
        if (v[i][j] == '.') continue;
        int d = 0;
        while (j >= d && j + d < m && i >= d) {
          if (v[i - d][j - d] == '.' || v[i - d][j + d] == '.') break;
          d++;
        }
        d--;
        if (d >= k) {
          for (int k = 0; k <= d; k++) {
            v[i - k][j - k] = '1';
            v[i - k][j + k] = '1';
          }
        }
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (v[i][j] == '*') ok = false;
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
