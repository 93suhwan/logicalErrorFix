#include <bits/stdc++.h>
using namespace std;
long long n;
long long v[100001];
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> v[i];
  }
  long long maxi = -1, poz = 0, p1 = 0, p2 = 0;
  for (long long i = 1; i <= n; i++) {
    if (v[i] > maxi) {
      maxi = v[i];
      poz = i;
      p1 = i - 1;
      p2 = i + 1;
    }
  }
  if (n == 2) {
    cout << v[1] * v[2] << '\n';
    return;
  } else {
    long long rasp = 0;
    for (long long i = 1; i <= n; i++) {
      rasp = max(rasp, 1LL * (v[i] * v[i - 1]));
    }
    cout << rasp << '\n';
  }
}
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
