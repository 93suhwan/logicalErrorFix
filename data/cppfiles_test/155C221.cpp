#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int md = 1e9 + 7;
const int maxn = 2e5 + 5;
const int maxm = 1e9;
int n, m;
int a[maxn], b[maxn], c[maxn];
string s;
void init() {}
inline void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> s;
  int cnt0 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') cnt0++;
  }
  set<int> st;
  for (int i = 0; i < n; i++) {
    if (a[i] <= cnt0 && s[i] == '0') st.insert(a[i]);
    if (a[i] > cnt0 && s[i] == '1') st.insert(a[i]);
  }
  int l = 1, r = n;
  for (int i = 0; i < n; i++) {
    if (a[i] <= cnt0 && s[i] == '1') {
      while (st.count(r)) r--;
      a[i] = r;
      st.insert(r);
    }
    if (a[i] > cnt0 && s[i] == '0') {
      while (st.count(l)) l++;
      a[i] = l;
      st.insert(l);
    }
  }
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int __ = 1;
  cin >> __;
  while (__--) solve();
  return 0;
}
