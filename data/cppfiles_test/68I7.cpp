#include <bits/stdc++.h>
using namespace std;
int nextPerfectSquare(int N) {
  int nextN = floor(sqrt(N)) + 1;
  return nextN * nextN;
}
void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << " " << 1 << "\n";
    return;
  }
  if ((float)sqrt(n) == (int)sqrt(n)) {
    cout << sqrt(n) << " " << 1 << "\n";
    return;
  }
  int next = nextPerfectSquare(n);
  int diff = next - n;
  int crossing = sqrt(next) - 1;
  int x = sqrt(next) - 1, y = 0;
  while (y < crossing && diff) {
    diff--;
    y++;
  }
  while (diff--) {
    x--;
  }
  cout << x + 1 << " " << y + 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
