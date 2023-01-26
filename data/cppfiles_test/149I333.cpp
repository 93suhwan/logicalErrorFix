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
  if (s.find('*') == string::npos) {
    cout << s << endl;
    return;
  }
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
  long long per = 1, start = 0, en = a.size();
  for (int i = a.size() - 1; i >= start; --i) {
    if (sqrt(x) <= sqrt(per) * sqrt(a[i] + 1)) {
      for (int j = start; j <= i; ++j) {
        if (a[j] == 0) cout << 'a';
      }
      while (x - 1 >= per) {
        cout << 'b';
        x -= per;
      }
      start = i + 1;
      i = a.size();
      per = 1;
      continue;
    }
    if (a[i] != 0) per *= (a[i] + 1);
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) wabalabadubdub();
}
