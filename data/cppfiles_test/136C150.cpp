#include <bits/stdc++.h>
using namespace std;
long long n;
long long b[500010], a[500010];
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> b[i];
  long long sum = 0, flag = 1;
  for (int i = 0; i < n; i++) sum += b[i];
  if (sum % (n * (n + 1) / 2)) flag = 0;
  sum /= n * (n + 1) / 2;
  for (int i = 0; i < n; i++) {
    long long dx = sum - b[(i + 1) % n] + b[i];
    if (dx % n || dx <= 0)
      flag = 0;
    else
      a[(i + 1) % n] = dx / n;
  }
  if (flag) {
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << '\n';
  } else
    cout << "NO" << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int _;
  cin >> _;
  while (_--) solve();
  return 0;
}
