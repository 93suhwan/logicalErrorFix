#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
using namespace std;
bool check(int a, long long b) {
  for (long long i = b; i >= 2; i--) {
    if (a % i != 0) return 0;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    bool flag = true;
    for (int i = 0; i < n; i += 1) {
      cin >> a[i];
    }
    for (long long i = 0; i < n; i++) {
      if (a[i] % (i + 2) == 0) {
        if (check(a[i], i + 1)) {
          flag = false;
          break;
        }
      }
    }
    if (flag)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
