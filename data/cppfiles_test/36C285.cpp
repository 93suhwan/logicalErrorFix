#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long inf = 2e18;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << 'a' << endl;
      continue;
    }
    string answer;
    if (n % 2 == 1) {
      for (int i = 1; i <= n / 2; i++) answer += 'a';
      answer += 'b';
      for (int i = 1; i < (n / 2); i++) answer += 'a';
      answer += 'c';
    } else {
      for (int i = 1; i <= n / 2; i++) answer += 'a';
      answer += 'b';
      for (int i = 1; i < (n / 2); i++) answer += 'a';
    }
    cout << answer << endl;
  }
}
