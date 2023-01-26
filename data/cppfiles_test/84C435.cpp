#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, s;
  cin >> n >> s;
  if (n == 1) {
    cout << s;
    return;
  }
  if (s == 1) {
    cout << 0;
    return;
  }
  cout << s / (n / 2 + 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
}
