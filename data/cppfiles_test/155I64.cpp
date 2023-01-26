#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (auto &i : a) cin >> i;
  string s;
  cin >> s;
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == '1' && s[i + 1] == '0') swap(a[i], a[i + 1]), i++;
  }
  for (auto i : a) cout << i << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
