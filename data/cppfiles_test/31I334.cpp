#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> b(n, 1);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[i] = {x, i};
      if (x < 0) b[i] *= (-1);
    }
    sort(a.begin(), a.end());
    if (n % 2 != 0) {
      pair<int, int> x0 = a[a.size() - 1];
      pair<int, int> x1 = a[a.size() - 2];
      pair<int, int> x2 = a[a.size() - 3];
      int l = lcm(lcm(abs(x0.first), abs(x1.first)), abs(x2.first));
      b[x0.second] *= (-(l / x0.first) * 2);
      b[x1.second] *= (l / x1.first);
      b[x2.second] *= (l / x2.first);
      n -= 3;
    }
    for (int i = 0; i < n - 1; i += 2) {
      int l = lcm(abs(a[i].first), abs(a[i + 1].first));
      b[a[i].second] *= (l / a[i].first);
      b[a[i + 1].second] *= (-(l / a[i + 1].first));
    }
    for (int i = 0; i < (int)b.size(); i++) cout << b[i] << " ";
    cout << "\n";
  }
  return 0;
}
