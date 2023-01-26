#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  string s;
  cin >> s;
  vector<long long> p, q;
  for (long long i = 0; i < n; i++)
    if (s[i] == '0')
      p.push_back(a[i]);
    else
      q.push_back(a[i]);
  long long i = 0, j = 0;
  for (auto i : q) cout << i << " ";
  for (auto j : p) cout << j << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
