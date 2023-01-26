#include <bits/stdc++.h>
using namespace std;
bool cases = true;
void solve() {
  int a, b;
  cin >> a >> b;
  if (a > b) swap(a, b);
  int f = 2 * a + (b - a) / 2;
  if ((b - a) % 2 == 0) {
    int c = 0;
    for (int i = (b - a) / 2; i <= f; i += 2) {
      c++;
    }
    cout << c << '\n';
    for (int i = (b - a) / 2; i <= f; i += 2) {
      cout << i << ' ';
    }
    cout << '\n';
    return;
  } else {
    int s = f + 1;
    int c = 0;
    for (int i = (b - a) / 2; i <= s; i++) {
      c++;
    }
    cout << c << '\n';
    for (int i = (b - a) / 2; i <= s; i++) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  if (cases) cin >> t;
  while (t--) {
    solve();
  }
}
