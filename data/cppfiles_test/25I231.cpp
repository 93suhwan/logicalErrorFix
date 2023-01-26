#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
void solve() {
  string s, t;
  cin >> s >> t;
  bool found = false;
  long long n = s.size(), m = t.size();
  for (long long i = 0; i < n && !found; i++) {
    if (s[i] != t[0]) continue;
    long long j = i, k = 0;
    string trav = "";
    while (j < n && k < m && s[j] == t[k]) {
      trav.push_back(s[j]);
      j++;
      k++;
    }
    j = j - 2;
    while (j >= 0 && k < m && s[j] == t[k]) {
      trav.push_back(s[j]);
      j--;
      k++;
    }
    if (trav == t) found = true;
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
