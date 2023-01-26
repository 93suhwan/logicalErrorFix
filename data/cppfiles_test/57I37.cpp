#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    long long s, n, k;
    cin >> s >> n >> k;
    if (k > s)
      cout << "NO\n";
    else if (k == s)
      cout << "YES\n";
    else {
      long long r = (s - n) / 2;
      if (k >= s - r)
        cout << "NO\n";
      else
        cout << "YES\n";
    }
  }
  return 0;
}
