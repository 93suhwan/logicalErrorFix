#include <bits/stdc++.h>
using namespace std;
const int md = 1e9 + 7;
const long long inf64 = 1e18;
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    int left = n / 2 + 1;
    cout << s / left << '\n';
  }
  return 0;
}
