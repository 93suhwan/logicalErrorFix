#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a;
  cin >> a;
  if (a == 5)
    cout << 2 << " " << 4 << endl;
  else
    cout << 2 << " " << (a - 1) / 2 << endl;
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
}
