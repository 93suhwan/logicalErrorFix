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
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        if (s[j] == '*') v[i][j] = 1;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
        if (v[i][j] == 0) continue;
        int d = -1;
        int l = j, r = j, u = i;
        while (l >= 0 && r < m && u >= 0) {
          if (v[u][l] == 0 || v[u][r] == 0) break;
          u--;
          l--;
          r++;
          d++;
        }
        if (d >= k) {
          u++;
          l++;
          r--;
          while (l <= r) {
            v[u][r] = 2;
            v[u][l] = 2;
            u++;
            l++;
            r--;
          }
        }
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (v[i][j] == 1) ok = false;
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
