#include <bits/stdc++.h>
using namespace std;
long long a[200005];
const double eps = 1e-6;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, n;
  cin >> t;
  while (t--) {
    map<double, long long> m1, m2;
    int n;
    cin >> n;
    double avg = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      avg += a[i];
    }
    avg = (double)(avg * 1.0 / n);
    for (int i = 0; i < n; i++)
      if (avg >= a[i])
        m1[avg - a[i]]++;
      else
        m2[a[i] - avg]++;
    long long sum = 0;
    for (auto &x : m1)
      if (x.first) {
        if (m2[x.first] > 0) sum += m2[x.first] * x.second;
      } else
        sum += x.second * (x.second - 1) / 2;
    cout << sum << endl;
  }
}
