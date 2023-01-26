#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int n;
string s;
vector<bool> prime(100, true);
void solve() {
  cin >> n;
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8') {
      cout << 1 << '\n';
      cout << s[i] << '\n';
      return;
    }
  }
  for (int i = 0; i < s.size(); ++i) {
    for (int j = i + 1; j < s.size(); ++j) {
      if (!prime[(s[i] - '0') * 10 + (s[j] - '0')]) {
        cout << 2 << '\n';
        cout << s[i] << s[j] << '\n';
        return;
      }
    }
  }
}
int main(int argc, const char** argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 2; i < 100; ++i) {
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        prime[i] = false;
      }
    }
  }
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
