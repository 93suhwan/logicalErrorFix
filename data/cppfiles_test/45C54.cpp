#include <bits/stdc++.h>
using namespace std;
void solveA() {
  long long k = 1;
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (auto &i : a) cin >> i;
  k += a[0];
  for (long long i = 1; i < n; i++) {
    if (a[i] == 1 && a[i - 1] == 1)
      k += 5;
    else if ((a[i] == 1 && a[i - 1] == 0))
      k++;
    else if (a[i - 1] != 0)
      continue;
    else {
      cout << -1 << "\n";
      return;
    }
  }
  cout << k << "\n";
}
void solveB() {}
void solveC() {}
signed main() {
  long long t = 1;
  cin >> t;
  while (t--) solveA();
}
