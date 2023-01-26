#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void Solve() {
  int n;
  cin >> n;
  cout << string(n, '(') << string(n, ')') << '\n';
  string s = string(n, '(');
  for (int i = 1; i < n; i++) {
    s[n - i] = ')';
    cout << s;
    for (int j = s.size() - 1; j >= 0; j--) {
      cout << (s[j] == '(' ? ')' : '(');
    }
    cout << '\n';
    s[n - i] = '(';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    Solve();
  }
}
