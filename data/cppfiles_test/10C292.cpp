#include <bits/stdc++.h>
using namespace std;
long long int power(long long int n, long long int x) {
  long long int res = 1;
  while (x > 0) {
    if (x % 2 == 0) {
      n = (n * n) % 998244353;
      x /= 2;
    } else {
      x--;
      res = (res * n) % 998244353;
    }
  }
  return res;
}
int main() {
  int t;
  cin >> t;
  while (t) {
    int n, k, h = 0;
    cin >> n >> k;
    vector<int> v(n);
    vector<pair<int, int>> a(n), v1(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      a[i].first = v[i];
      a[i].second = i;
    }
    sort(a.begin(), a.end());
    map<int, int> m, m1;
    bool b = true;
    for (int i = 0; i < n; i++) {
      if (m1[a[i].first] < k) {
        m1[a[i].first]++;
        h++;
      }
    }
    int x = h % k, y = 0;
    for (int i = 0; i < n; i++) {
      v1[i].first = a[i].second;
      if (h - y == x) {
        v1[i].second = 0;
        continue;
      }
      if (m[a[i].first] < k) {
        v1[i].second = y % k + 1;
        m[a[i].first]++;
        y++;
      } else {
        v1[i].second = 0;
      }
    }
    sort(v1.begin(), v1.end());
    for (int i = 0; i < n; i++) {
      cout << v1[i].second << " ";
    }
    cout << endl;
    t--;
  }
  return 0;
}
