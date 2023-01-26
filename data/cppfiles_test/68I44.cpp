#include <bits/stdc++.h>
using namespace std;
long long nextPerfectSquare(long long N) {
  long long nextN = floor(sqrt(N)) + 1;
  return nextN * nextN;
}
void solve() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << 1 << " " << 1 << "\n";
    return;
  }
  if ((float)sqrt(n) == (long long)sqrt(n)) {
    cout << sqrt(n) << " " << 1 << "\n";
    return;
  }
  long long next = nextPerfectSquare(n);
  long long diff = next - n;
  long long crossing = sqrt(next) - 1;
  long long x = sqrt(next) - 1, y = 0;
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
  long long T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
