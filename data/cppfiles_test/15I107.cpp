#include <bits/stdc++.h>
using namespace std;
const int MX = 1e6 + 1;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
bool sortbysec(const pair<string, string>& a, const pair<string, string>& b) {
  if (a.second == b.second)
    return a.first < b.first;
  else
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
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    int star = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (v[i][j] == '*') star++;
      }
    }
    bool f = 0;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
        if (v[i][j] == '*' || v[i][j] == '1' && star) {
          int d = 1;
          while (d + j < m && i - d >= 0 && j - d >= 0 &&
                 (v[i - d][j + d] == '*' || v[i - d][j + d] == '1') &&
                 (v[i - d][j - d] == '*' || v[i - d][j - d] == '1')) {
            if (v[i - d][j + d] == '*') star--;
            if (v[i - d][j - d] == '*') star--;
            if (v[i][j] == '*') star--;
            v[i][j] = '1';
            v[i - d][j + d] = '1';
            v[i - d][j - d] = '1';
            d++;
          }
          d--;
          if (d < k && d) {
            f = 1;
          }
        }
      }
    }
    cout << ((f || star) ? "NO\n" : "YES\n");
  }
  return 0;
}
