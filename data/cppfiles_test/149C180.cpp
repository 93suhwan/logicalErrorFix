#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mod = 7 + 1e9;
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }
void wabalabadubdub() {
  long long n, k, x;
  string s;
  cin >> n >> k >> x >> s;
  --x;
  if (k == 0) {
    for (char i : s)
      if (i != '*') cout << i;
    cout << endl;
    return;
  }
  vector<long long> a;
  for (char i : s) {
    if (i == '*') {
      if (a.empty() || a.back() == 0)
        a.push_back(k);
      else
        a.back() += k;
    } else {
      a.push_back(0);
    }
  }
  long long per = 1;
  string res;
  for (int i = a.size() - 1; i >= 0; --i) {
    if (a[i] == 0) {
      res.push_back('a');
      continue;
    }
    int b = x % (a[i] + 1);
    x /= (a[i] + 1);
    while (b--) res.push_back('b');
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
