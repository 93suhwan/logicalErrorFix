#include <bits/stdc++.h>
using namespace std;
const int N = 10001;
long long mas[1000001];
void solve() {
  long long n, m, i;
  cin >> n >> m;
  long long ans = n, sum = m;
  while (ans % 4) ans--;
  for (i = ans; i < n; i++) sum ^= i;
  cout << n + (sum > 0) + (sum == n) << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int g;
  cin >> g;
  while (g--) solve();
}
