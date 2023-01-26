#include <bits/stdc++.h>
using namespace std;
int t, n, a;
int main() {
  std::ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    int emplace_back = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> a;
      if (a > i + emplace_back) emplace_back += (a - (i + emplace_back));
    }
    cout << emplace_back << '\n';
  }
}
