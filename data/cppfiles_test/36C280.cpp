#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5, inf = 2e9 + 7;
const ll INF = 1e18, mod = 1e9 + 7, P = 6547;
void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "a\n";
    return;
  }
  if (n % 2 == 0) {
    for (int i = 1; i < n / 2; i++) {
      cout << 'a';
    }
    cout << 'b';
    for (int i = 1; i <= n / 2; i++) {
      cout << 'a';
    }
    cout << '\n';
    return;
  } else {
    n--;
    for (int i = 1; i < n / 2; i++) {
      cout << 'a';
    }
    cout << 'b';
    for (int i = 1; i <= n / 2; i++) {
      cout << 'a';
    }
    cout << 'c';
    cout << '\n';
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
