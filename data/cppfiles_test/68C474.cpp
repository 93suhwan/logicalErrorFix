#include <bits/stdc++.h>
using namespace std;
long long nextPerfectSquare(long long N) {
  long long nextN = floor(sqrt(N)) + 1;
  return nextN * nextN;
}
bool isPerfectSquare(long double x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
void solve() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << 1 << " " << 1 << "\n";
    return;
  }
  if (isPerfectSquare(n)) {
    cout << sqrt(n) << " " << 1 << "\n";
    return;
  }
  long long next = nextPerfectSquare(n);
  long long useful = sqrt(next);
  long long diff = next - n;
  long long crossing = useful - 1;
  long long x = useful - 1, y = 0;
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
