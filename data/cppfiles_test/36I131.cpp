#include <bits/stdc++.h>
using namespace std;
const int SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
void test_case() {
  string S;
  int cur = 0;
  for (int i = 0; i < 26 * 25; i++) {
    S += (char)(cur + 'a');
    cur = cur + (i + 26) / 26;
    cur %= 26;
  }
  int n;
  cin >> n;
  int pos = 0;
  string ans;
  while (ans.size() < n) {
    string second;
    second += char(S[pos]);
    pos++;
    while (3 * second.size() + 2 + ans.size() <= n) {
      second = second + S[pos] + second + S[pos + 1] + second;
      pos += 2;
    }
    ans += second;
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    test_case();
  }
  return 0;
}
