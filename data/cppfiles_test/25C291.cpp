#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e+9 + 7;
string s, t;
int arr[505][1010][2];
bool dp(int i, int j, bool right) {
  if (j == t.size()) return 1;
  if (i == s.size() || i == -1) return 0;
  if (arr[i][j][right] != -1) return arr[i][j][right];
  if (s[i] != t[j]) return 0;
  bool v1 = 0, v2 = 0;
  if (right) v1 = dp(i + 1, j + 1, 1);
  v2 = dp(i - 1, j + 1, 0);
  return arr[i][j][right] = v1 || v2;
}
void MAIN() {
  memset(arr, -1, sizeof arr);
  cin >> s >> t;
  for (int i = 0; i < s.size(); i++)
    if (dp(i, 0, 1)) {
      cout << "YES\n";
      return;
    }
  cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout << setprecision(10);
  int t;
  cin >> t;
  while (t--) MAIN();
}
