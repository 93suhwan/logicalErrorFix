#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
using namespace std;
void fastio(void);
bool comparator(vector<long long int> l, vector<long long int> r) {
  return l.size() >= r.size();
}
void solve() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  long long int i = 0;
  while (i < (n + 1) / 2) {
    if (s[i] == '0') {
      cout << i + 2 << " " << n << " " << i + 1 << " " << n << "\n";
      return;
    }
    i++;
  }
  i = (n + 1) / 2;
  if (s[i] == '0') {
    cout << 1 << " " << i + 1 << " " << 1 << " " << i << "\n";
  } else {
    cout << 2 << " " << i + 1 << " " << 1 << " " << i << "\n";
  }
}
signed main() {
  fastio();
  long long int t;
  cin >> t;
  long long int i = 1;
  while (i <= t) {
    solve();
    i++;
  }
  return 0;
}
void fastio(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
