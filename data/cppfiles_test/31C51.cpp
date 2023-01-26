#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int n;
int res[N];
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * b / gcd(a, b); }
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n % 2 == 0) {
    for (int i = 0; i < n / 2; i++) {
      int j = n - 1 - i;
      int t = lcm(a[i], a[j]);
      res[i] = t / a[i];
      res[j] = t / a[j];
      if (1) {
        res[i] *= -1;
      }
    }
    for (int i = 0; i < n; i++) cout << res[i] << " ";
    cout << endl;
  } else {
    for (int i = 0; i < n / 2 - 1; i++) {
      int j = n - 1 - i;
      int t = lcm(a[i], a[j]);
      res[i] = t / a[i];
      res[j] = t / a[j];
      if (1) {
        res[i] *= -1;
      }
    }
    res[n / 2 - 1] = 1;
    res[n / 2 + 1] = -1;
    int t = 1 * a[n / 2 - 1] + -1 * a[n / 2 + 1];
    if (t == 0) {
      t += a[n / 2 - 1];
      res[n / 2 - 1]++;
    }
    int t2 = lcm(t, a[n / 2]);
    res[n / 2] = t2 / a[n / 2];
    res[n / 2 - 1] *= t2 / t;
    res[n / 2 + 1] *= t2 / t;
    if (1) {
      res[n / 2] *= -1;
    }
    for (int i = 0; i < n; i++) cout << res[i] << " ";
    cout << endl;
  }
}
int main() {
  int K;
  scanf("%d", &K);
  while (K--) {
    solve();
  }
}
