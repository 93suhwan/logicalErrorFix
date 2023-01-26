#include <bits/stdc++.h>
using namespace std;
const long long MOD = pow(10, 9) + 7;
const long long MAX = LONG_LONG_MAX;
void solve() {
  string s;
  cin >> s;
  long long n = s.size();
  long long i = n - 2;
  while (s[i] == 'E' && i >= 0) {
    i--;
  }
  i++;
  if (i == 0) {
    if (s[n - 1] != 'E') {
      cout << "NO";
      return;
    }
  }
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
