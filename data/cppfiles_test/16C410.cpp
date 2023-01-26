#include <bits/stdc++.h>
using namespace std;
long long t, res, n;
string s;
void solve() {
  res = 0, n;
  cin >> n >> s;
  string temp = s;
  sort(s.begin(), s.end());
  for (int i = 0; i <= s.size() - 1; i++)
    if (temp[i] != s[i]) res++;
  cout << res << endl;
}
void inp() {
  cin >> t;
  while (t--) {
    solve();
    if (t == 0) return;
  }
}
int main() { inp(); }
