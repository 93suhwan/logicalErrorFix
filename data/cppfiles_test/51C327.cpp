#include <bits/stdc++.h>
using namespace std;
long long t, n;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    cout << (-1 * n + 1) << " " << n << endl;
  }
  return 0;
}
