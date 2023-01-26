#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, zerlast;
  bool zerflag = 0;
  cin >> n;
  long long arr[n + 5];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] == 0) {
      zerflag = 1;
      zerlast = i;
    }
  }
  if (!zerflag) {
    cout << "-1\n";
  } else {
    for (int i = 0; i <= zerlast; i++) {
      cout << i + 1 << ' ';
    }
    cout << n + 1 << ' ';
    for (int i = zerlast + 1; i < n; i++) {
      cout << i + 1 << '\n';
    }
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
