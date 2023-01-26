#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
const long long INF = (long long)1e9 + 2;
void run() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void solve() {
  int n, m;
  cin >> n >> m;
  int ara[m];
  int j = 0;
  int cost = 0;
  for (int i = 0; i < m; i++) ara[i] = 1000000001;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    if (i == 0)
      ara[0] = x;
    else {
      j++;
      int k;
      for (k = 0; k <= j; k++) {
        if (ara[k] >= x) {
          cost += k;
          break;
        }
      }
      for (int t = k + 1; t <= j; t++) {
        ara[t] = ara[t - 1];
      }
      ara[k] = x;
    }
  }
  cout << cost << endl;
}
int main() {
  run();
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}
