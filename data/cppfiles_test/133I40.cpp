#include <bits/stdc++.h>
using namespace std;
long long int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, inf = 1e18 + 1;
bool valid(long long int x, long long int y, long long int n, long long int m) {
  return (x >= 0 and y >= 0 and x < n and y < m);
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<string> v(n - 2);
    for (long long int i = 0; i < n - 2; i++) cin >> v[i];
    string ans = "";
    ans.push_back(v[0][0]);
    for (long long int i = 1; i < n - 2; i++) {
      if (v[i][0] != v[i - 1][1]) ans.push_back(v[i - 1][1]);
      ans.push_back(v[i][0]);
      if (i == n - 3) ans.push_back(v[i][1]);
    }
    while (ans.length() < n) ans.push_back(ans.back());
    cout << ans << "\n";
  }
  return 0;
}
