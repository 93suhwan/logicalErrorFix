#include <bits/stdc++.h>
const int N = 1e7 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-10;
const long long inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;
void solve() {
  int res = 0, n;
  cin >> n;
  string s, temp;
  cin >> s;
  temp = s;
  sort(s.begin(), s.end());
  for (int i = 0; i < s.size(); i++)
    if (s[i] != temp[i]) res++;
  cout << res << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
