#include <bits/stdc++.h>
using namespace std;
int cs = 0;
const int mod = 1e9 + 7;
void code() {
  int n;
  cin >> n;
  int x = n / 3, y = x;
  if (x * 3 != n) y = x + 1;
  if (x % 2 != n % 2) swap(x, y);
  cout << x << ' ' << y << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) code();
  return 0;
}
