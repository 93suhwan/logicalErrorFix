#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
const int mod = 1e9 + 7;
const int inf = 1e9;
int T;
int s, n;
int main() {
  std::ios::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> s >> n;
    cout << s - (n - 1) << " ";
    for (int i = 1; i < n; i++) cout << 1 << " ";
    cout << endl;
  }
  return 0;
}
