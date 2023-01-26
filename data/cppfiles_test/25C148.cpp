#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
void solve() {
  string s, t;
  cin >> s >> t;
  bool found = false;
  long long n = 1LL * s.size();
  long long m = 1LL * t.size();
  for (long long i = 0; i < n && !found; i++) {
    if (s[i] != t[0]) continue;
    long long j = 0, k = 0;
    string trav;
    while (j <= m && !found) {
      trav = "";
      trav.push_back(s[i]);
      k = 0;
      while (k < j && i + k + 1 < n) {
        trav.push_back(s[i + k + 1]);
        k++;
      }
      k = 0;
      while (k < m - j - 1 && i + j - k - 1 >= 0) {
        trav.push_back(s[i + j - k - 1]);
        k++;
      }
      if (trav == t) found = true;
      j++;
    }
  }
  if (found)
    cout << "YES";
  else
    cout << "NO";
}
int main() {
  clock_t clk = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  cerr << '\n'
       << "Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC
       << '\n';
  return 0;
}
