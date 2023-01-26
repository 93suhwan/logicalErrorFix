#include <bits/stdc++.h>
using namespace std;
int ff() {
  int x = 0;
  int c = getchar(), n = 0;
  for (; !isdigit(c); c = getchar()) n = (c == '-');
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  if (n) x = -x;
  return x;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) { return l + rng() % (r - l + 1); }
int test;
int a[5];
int m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> test;
  while (test--) {
    for (int i = 1; i <= 3; ++i) cin >> a[i];
    cin >> m;
    sort(a + 1, a + 4);
    int z;
    if (a[1] + a[2] >= a[3] - 1)
      z = 0;
    else
      z = a[3] - a[1] - a[2] - 1;
    if (m >= z && m <= a[1] + a[2] + a[3] - 3)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}
