#include <bits/stdc++.h>
using namespace std;
const long long MOD = pow(10, 9) + 7;
const long long MAX = LONG_LONG_MAX;
void solve() {
  long long n;
  string s;
  cin >> s;
  n = s.size();
  long long c = 0;
  for (int i = 0; i < n; i += 1) {
    if (s[i] == 'N') c++;
  }
  if (c == 1)
    cout << "NO";
  else
    cout << "YES";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long _ = 1;
  cin >> _;
  while (_ > 0) {
    solve();
    _--;
    cout << endl;
  }
}
