#include <bits/stdc++.h>
using namespace std;
string S;
bool f;
long long f1, n;
void solve() {
  cin >> n >> S;
  f = 0;
  f1 = LLONG_MAX;
  for (char i = 'a'; i <= 'z'; i += 1) {
    bool ok;
    long long Sr = 0, tom = 0, Eo = n - 2 + 1;
    ok = 1;
    while (Sr < Eo) {
      if (S[Sr] == S[Eo]) {
        Sr += 1;
        Eo -= 1;
      } else if (S[Sr] == i) {
        Sr += 1, tom += 1;
      } else if (S[Eo] == i) {
        Eo -= 1, tom += 1;
      } else {
        ok = 0;
        break;
      }
    }
    if (ok) {
      f = 1;
      f1 = min(tom, f1);
    }
  }
  if (f) {
    cout << f1 << '\n';
  } else
    cout << -1 << '\n';
}
int main() {
  ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
