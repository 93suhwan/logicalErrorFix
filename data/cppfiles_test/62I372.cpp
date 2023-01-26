#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<int> inp(n);
    for (long long i = 0; i < n; ++i) cin >> inp[i];
    int f = -1;
    vector<int> res;
    int z = INT_MAX;
    for (long long i = 0; i < n; ++i) {
      if (inp[i] == 0) z = min((long long)z, i);
      if (i < n - 1 && inp[i] == 0 && inp[i + 1] == 1) {
        f = i;
        break;
      }
    }
    if (z == INT_MAX) {
      cout << -1 << endl;
      continue;
    }
    if (f != -1) {
      for (long long i = 0; i < f + 1; ++i) res.push_back(i + 1);
      res.push_back(n + 1);
      for (long long i = f + 1; i < n; ++i) res.push_back(i + 1);
    } else {
      for (long long i = z; i < n; ++i) res.push_back(i + 1);
      res.push_back(n + 1);
      for (long long i = 0; i < z; ++i) res.push_back(i + 1);
    }
    for (long long i = 0; i < n + 1; ++i) cout << res[i] << " ";
    cout << endl;
  }
  return 0;
}
