#include <bits/stdc++.h>
using namespace std;
void solve(long long i);
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  if (true) {
    long long t, p = 0;
    cin >> t;
    while (p < t) {
      p++;
      solve(p);
      cout << '\n';
    }
  } else {
    solve(1);
    cout << '\n';
  }
}
void solve(long long i) {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  long long o = 0, z = 0;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] == 0)
      z++;
    else if (arr[i] == 1)
      o++;
  }
  long long ans = o * pow(2, z);
  cout << ans;
}
