#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, k, sum = 0, x, p, q, index, a, s, m, u, g;
    cin >> n >> k;
    vector<long long int> v;
    for (i = 0; i < n; i++) {
      cin >> x;
      sum += x;
      v.push_back(x);
    }
    s = sum;
    m = sum;
    sort(v.begin(), v.end());
    index = n - 1;
    a = k;
    while (a--) {
      p = v[index];
      index--;
      q = v[index];
      index--;
      s = s - p - q;
      s = s + q / p;
    }
    u = n - 1;
    g = 0;
    a = k;
    while (a--) {
      p = v[u];
      u--;
      q = v[g];
      g++;
      m = m - p - q;
      m = m + q / p;
    }
    cout << min(m, s) << endl;
  }
}
