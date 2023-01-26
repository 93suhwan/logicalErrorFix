#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mod = 7 + 1e9;
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }
void wabalabadubdub() {
  long long n, k, x;
  string s, res;
  cin >> n >> k >> x >> s;
  --x;
  for (int i = s.size() - 1; i >= 0; --i) {
    if (s[i] == 'a') {
      res.push_back('a');
    } else {
      int j = i + 1;
      while (j > 0 && s[j - 1] == s[i]) --j;
      int b = x % ((i - j + 1) * k + 1);
      x /= ((i - j + 1) * k + 1);
      while (b--) res.push_back('b');
      i = j;
    }
  }
  reverse(res.begin(), res.end());
  cout << res << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) wabalabadubdub();
}
