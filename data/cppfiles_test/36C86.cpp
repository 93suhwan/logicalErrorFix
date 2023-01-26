#include <bits/stdc++.h>
using namespace std;
int n, a[1000], sm;
bool iscomp(int num) {
  for (int i = 2; i * i <= num; i++)
    if (num % i == 0) return 1;
  return 0;
}
void solve() {
  cin >> n;
  sm = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sm += a[i];
  }
  if (iscomp(sm)) {
    cout << n << "\n";
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << "\n";
  } else {
    bool ac = 0;
    cout << n - 1 << "\n";
    for (int i = 1; i <= n; i++) {
      if (a[i] % 2 && (!ac))
        ac = 1;
      else
        cout << i << " ";
    }
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) solve();
}
