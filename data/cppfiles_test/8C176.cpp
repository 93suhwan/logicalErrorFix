#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long t = n / 3;
  long long c1, c2;
  c1 = t;
  c2 = t;
  if (n % 3 == 2) {
    c2++;
  } else if (n % 3 == 1) {
    c1++;
  }
  cout << c1 << " " << c2 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
