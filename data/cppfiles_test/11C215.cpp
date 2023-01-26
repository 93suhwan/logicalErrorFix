#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
const long long int mxn = 1e5 + 1;
const string fuck = "fuck";
void solve() {
  long long int n;
  cin >> n;
  vector<vector<long long int> > g(n, vector<long long int>(5, 0));
  vector<string> s(n);
  for (long long int i = 0; i < n; i++) {
    cin >> s[i];
    for (long long int j = 0; j < s[i].size(); j++) {
      g[i][s[i][j] - 'a']++;
    }
  }
  long long int ans = 0;
  for (long long int i = 0; i < 5; i++) {
    vector<long long int> x;
    for (long long int j = 0; j < n; j++) {
      long long int cnt = 0;
      for (long long int k = 0; k < 5; k++) {
        if (k == i)
          cnt += g[j][k];
        else
          cnt -= g[j][k];
      }
      x.push_back(cnt);
    }
    sort(x.rbegin(), x.rend());
    long long int sum = 0;
    for (long long int j = 0; j < n; j++) {
      sum += x[j];
      if (sum > 0) ans = max(ans, j + 1);
    }
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long int cse = 1;
  cin >> cse;
  while (cse--) {
    solve();
    cout << endl;
  }
}
