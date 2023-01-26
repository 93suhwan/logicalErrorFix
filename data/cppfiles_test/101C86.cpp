#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n), b(1), r(1);
  for (long long &x : a) cin >> x;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++)
    if (s[i] == 'B')
      b.push_back(a[i]);
    else
      r.push_back(a[i]);
  sort(b.begin(), b.end());
  sort(r.begin(), r.end());
  bool flag = true;
  for (int i = 1; i < b.size(); i++)
    if (b[i] < i) flag = false;
  long long c = b.size();
  for (int i = 1; i < r.size(); i++) {
    if (r[i] > c) flag = false;
    c++;
  }
  cout << (flag ? "Yes\n" : "No\n");
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
