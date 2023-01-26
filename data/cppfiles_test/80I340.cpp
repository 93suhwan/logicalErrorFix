#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
void solveCP311() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int m = n / 2;
  if (count(s.begin(), s.end(), '0')) {
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '0' && n - i > m) {
        cout << i + 2 << " " << n << " " << i + 1 << " " << n << endl;
        return;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '0') {
        cout << 1 << " " << i + 1 << " " << 1 << " " << i << endl;
        return;
      }
    }
  } else {
    cout << 1 << " " << m << " " << n - m + 1 << " " << n << endl;
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t = 1;
  ll test = 1;
  while (t--) {
    test++;
    solveCP311();
  }
  return 0;
}
