#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void solve() {
  long long int n;
  cin >> n;
  if (n < 9) {
    cout << "0\n";
    return;
  }
  if (n == 9) {
    cout << "1\n";
    return;
  }
  string ans = "";
  string num = to_string(n);
  ans = num.substr(0, num.size() - 1);
  long long int res = stoll(ans);
  if (num[num.size() - 1] == '9') {
    res++;
  }
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
