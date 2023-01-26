#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k, x;
  cin >> n >> k >> x;
  x--;
  string s;
  cin >> s;
  vector<long long> v;
  bool started = 0;
  long long curcnt = 0;
  for (int i = 0; i < n; i++) {
    if (!started && s[i] == '*') {
      started = 1;
    }
    if (s[i] == '*') {
      curcnt++;
    } else {
      if (curcnt > 0) v.push_back(curcnt * k + 1);
      started = 0;
      curcnt = 0;
    }
  }
  if (curcnt > 0) v.push_back(curcnt * k + 1);
  if (v.size() == 0) {
    cout << s << endl;
    return;
  }
  vector<long long> mod;
  long long prod = 1;
  for (int i = int(v.size() - 1); i >= 0; i--) {
    mod.push_back(x % v[i]);
    x /= v[i];
  }
  reverse(mod.begin(), mod.end());
  int pt = 0;
  bool outputting = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      outputting = 0;
      cout << 'a';
      continue;
    } else {
      if (!outputting) {
        for (int j = 0; j < mod[pt]; j++) cout << 'b';
        outputting = 1;
        pt++;
      }
    }
  }
  cout << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
