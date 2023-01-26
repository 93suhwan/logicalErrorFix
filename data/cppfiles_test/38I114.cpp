#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int in;
  cin >> in;
  for (int i = 0; i < in; i++) solve();
  return 0;
}
void solve() {
  long long int n, time = 0;
  cin >> n;
  int a = 0, b = 0, c = 0, d, e, f, mi;
  a = n % 6;
  b = n % 8;
  c = n % 10;
  d = abs(n - 6 * ((n / 6) + 1));
  e = abs(n - 8 * ((n / 8) + 1));
  f = abs(n - 10 * ((n / 10) + 1));
  mi = min(min(min(min(min(a, b), c), d), e), f);
  if (mi == a) {
    time = time + (15 * (n / 6));
    n = n % 6;
  } else if (mi == b) {
    time = time + (20 * (n / 8));
    n = n % 8;
  } else if (mi == c) {
    time = time + (25 * (n / 10));
    n = n % 10;
  } else if (mi == d) {
    time = time + (20 * ((n / 6) + 1));
    n = n - 6 * (n / 6 + 1);
  } else if (mi == e) {
    time = time + (20 * ((n / 8) + 1));
    n = n - 8 * (n / 8 + 1);
  } else {
    time = time + (20 * ((n / 10) + 1));
    n = n - 10 * (n / 10 + 1);
  }
  if (n > 0) time += 15;
  cout << time << '\n';
}
