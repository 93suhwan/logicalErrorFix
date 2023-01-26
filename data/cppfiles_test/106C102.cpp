#include <bits/stdc++.h>
using namespace std;
void output() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    if (!i)
      cout << "2 ";
    else
      cout << 1 + i * 2 << " ";
  }
  cout << "\n";
}
signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  bool testcases = true;
  if (testcases) {
    int tc;
    cin >> tc;
    while (tc--) output();
  } else
    output();
}
