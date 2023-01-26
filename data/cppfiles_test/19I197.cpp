#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t, l, flag, od, ev, sum, ma, mi, i, j, k, n, m, ans, tot, count,
      x, y;
  cin >> t;
  while (t--) {
    cin >> n;
    map<long long int, long long int> l;
    flag = 0;
    long long int a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 0) flag = 1;
      if (l.find((-1) * a[i]) != l.end()) {
        flag = 1;
      }
      l[a[i]] = 1;
    }
    if (flag == 1)
      cout << "YES\n";
    else {
      vector<long long int> v;
      for (i = 0; i < n; i++) {
        v.push_back(a[i]);
        for (j = i + 1; j < n; j++) {
          v.push_back(a[i] - a[j]);
          v.push_back(a[j] - a[i]);
          v.push_back(a[j] + a[i]);
          v.push_back((-1) * (a[j] + a[i]));
        }
      }
      sort(v.begin(), v.end());
      if (v[0] == 0)
        cout << "YES\n";
      else {
        for (i = 0; i < v.size() - 1; i++) {
          if (v[i] == v[i + 1]) {
            flag = 1;
            break;
          }
        }
        if (flag == 1)
          cout << "YES\n";
        else
          cout << "NO\n";
      }
    }
  }
  return 0;
}
