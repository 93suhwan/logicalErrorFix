#include <bits/stdc++.h>
using namespace std;
bool solve(vector<vector<long long>> &v) {
  long long n = v.size();
  for (long long i = 1; i < n; i++) {
    if (v[0][i] == 1 and v[1][i] == 1) return false;
  }
  return true;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n = 0;
    cin >> n;
    vector<vector<long long>> grid(2, vector<long long>(n));
    string s1 = "", s2 = "";
    cin >> s1;
    cin >> s2;
    for (long long i = 0; i < n; i++) {
      grid[0][i] = s1[i] - '0';
      grid[1][i] = s2[i] - '0';
    }
    if (solve(grid))
      cout << "YES";
    else
      cout << "NO";
    cout << "\n";
  }
  return 0;
}
