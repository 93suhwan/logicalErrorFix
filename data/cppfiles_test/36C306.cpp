#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 2e5 + 5;
const int inf = 1e9 + 5;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "a" << endl;
      continue;
    }
    string ans;
    int len = n >> 1;
    ans.assign(len, 'a');
    ans += 'b';
    string temp;
    temp.assign(len - 1, 'a');
    ans += temp;
    if (n & 1) ans += 'c';
    cout << ans << endl;
  }
  return 0;
}
