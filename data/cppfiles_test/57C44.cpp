#include <bits/stdc++.h>
using namespace std;
const long long N = 6e5 + 5;
const long long mod = 1e9 + 7;
void solve() {
  long long s, n, k;
  cin >> s >> n >> k;
  if (s == k) {
    cout << "YES" << endl;
  } else if (s < k) {
    cout << "NO" << endl;
  } else {
    if (n / k * k > s - n) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
