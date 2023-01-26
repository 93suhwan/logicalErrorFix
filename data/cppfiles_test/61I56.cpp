#include <bits/stdc++.h>
using namespace std;
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long int M = 1000000007;
long long int power(long long int x, long long int y) {
  if (y == 0)
    return 1;
  else if (y == 1)
    return x % M;
  else {
    long long int z = power(x, y / 2);
    long long int w = ((z % M) * (z % M)) % M;
    if (y % 2 == 1)
      return ((x % M) * (w % M)) % M;
    else
      return w;
  }
}
int main() {
  init_code();
  long long int t = 1;
  cin >> t;
  long long int o = 1;
  while (t--) {
    long long int m, n, a, i, j, k, l = 0, ans = 0;
    double sum = 0.0;
    cin >> n;
    map<long long int, long long int> mp, np;
    vector<pair<long long int, long long int>> v;
    for (i = 0; i < n; i++) {
      long long int b, c;
      cin >> b >> c;
      v.push_back({b, c});
      mp[b]++;
      np[c]++;
    }
    l = n;
    ans = (n * (n - 1) * (n - 2)) / 6;
    map<pair<long long int, long long int>, long long int> vb;
    for (i = 0; i < n; i++) {
      long long int x = v[i].first, y = v[i].second;
      l--;
      mp[x]--;
      np[y]--;
      if (mp[x] > 0 && np[y] > 0 && vb[{x, y}] == 0) {
        ans = ans - mp[x] * np[y];
      }
      vb[{x, y}]++;
    }
    cout << ans << endl;
  }
}
