#include <bits/stdc++.h>
using namespace std;
long long int F(const vector<long long int> &v) {
  map<long long int, long long int> first;
  for (auto el : v) first[el]++;
  vector<long long int> a(first.size() + 2), dp(first.size() + 2),
      dp2(first.size() + 2), dp3(first.size() + 2);
  {
    int z = 0;
    for (auto temp : first) {
      a[z++] = temp.second;
    }
  }
  for (auto a : a) cout << a << " ";
  cout << endl;
  ;
  for (int i = (int)first.size() - 1; i >= 0; i--) {
    dp[i] = dp[i + 1] + a[i];
  }
  for (auto a : dp) cout << a << " ";
  cout << endl;
  ;
  for (int i = (int)first.size() - 1; i >= 0; i--) {
    dp2[i] = dp2[i + 1] + a[i] * dp[i + 1];
    dp3[i] = dp3[i + 1] + a[i] * dp2[i + 1];
  }
  return dp3[0];
}
long long int nc3(long long int n) { return ((n * (n - 1)) / 2 * (n - 2)) / 3; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    int n;
    cin >> n;
    vector<long long int> a(n), b(n);
    map<long long int, long long int> fA, fB;
    vector<pair<long long, long long> > Temp;
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      fA[a[i]]++;
      fB[b[i]]++;
      Temp.push_back({a[i], b[i]});
    }
    long long int res = nc3(n);
    for (auto temp : Temp) {
      res -= (fA[temp.first] - 1) * (fB[temp.second] - 1);
    }
    cout << res << "\n";
  }
}
