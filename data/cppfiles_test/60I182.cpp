#include <bits/stdc++.h>
using namespace std;
long long int NchooseK(int n, int k) {
  if (k == 0) return 1;
  return (n * NchooseK(n - 1, k - 1)) / k;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    double s = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s += a[i];
    }
    double k = (double)s / n;
    sort(a.begin(), a.end());
    unordered_map<double, int> map;
    for (int i = 0; i < n; i++) {
      double dif = k - a[i];
      if (map.find(dif) == map.end()) {
        map.insert(make_pair(dif, 1));
      } else {
        map[dif]++;
      }
    }
    int pos = 0;
    long long int ans = 0;
    double prev = INT_MIN;
    while (pos < a.size() && (double)a[pos] <= k) {
      int v1, v2;
      double dif = k - a[pos];
      if (dif == prev) {
        pos++;
        continue;
      }
      prev = dif;
      v1 = map[dif];
      if (map.find(-dif) == map.end()) {
        pos++;
        continue;
      } else {
        v2 = map[-dif];
      }
      int v = min(v1, v2);
      if (k != (double)a[pos])
        ans += v1 * v2;
      else
        ans += NchooseK(v, 2);
      pos++;
    }
    cout << ans << endl;
  }
  return 0;
}
