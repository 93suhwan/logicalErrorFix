#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long l;
  cin >> l;
  long long r;
  cin >> r;
  if ((r / 2) + 1 >= l) {
    cout << r % ((r / 2) + 1) << '\n';
  } else
    cout << r % l << '\n';
}
int main() {
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
