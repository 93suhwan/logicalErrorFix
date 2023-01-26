#include <bits/stdc++.h>
using namespace std;
bool ask(int a, int b, int c) {
  cout << "? " << a << " " << b << " " << c << '\n';
  bool ans;
  cin >> ans;
  return ans;
}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n + 1);
  vector<int> b(n / 3);
  int cm = 0, im = 0;
  int eco, txc;
  for (int i = 0; i < n; i += 3) {
    b[i / 3] = ask(i + 1, i + 2, i + 3);
    if (!b[i / 3])
      txc = i;
    else
      eco = i;
  }
  {
    bool _145, _245, _345, _146, _246, _346;
    _145 = ask(eco + 1, txc + 1, txc + 2);
    _245 = ask(eco + 2, txc + 1, txc + 2);
    _345 = ask(eco + 3, txc + 1, txc + 2);
    _146 = ask(eco + 1, txc + 1, txc + 3);
    _246 = ask(eco + 2, txc + 1, txc + 3);
    _346 = ask(eco + 3, txc + 1, txc + 3);
    bool _124, _134;
    _124 = ask(eco + 1, eco + 2, txc + 1);
    _134 = ask(eco + 1, eco + 3, txc + 1);
    if (!_145 && !_245 && !_345) {
      v[txc + 1] = 2;
      v[txc + 2] = 2;
      v[txc + 3] = 1 + (!_146 && !_246 && !_346);
      im = txc + 1;
      if (_124) {
        v[eco + 1] = 1;
        v[eco + 2] = 1;
        v[eco + 3] = 2 - _134;
        cm = eco + 1;
      } else {
        if (_134) {
          v[eco + 1] = 1;
          v[eco + 2] = 2;
          v[eco + 3] = 1;
          cm = eco + 1;
        } else {
          v[eco + 1] = 2;
          v[eco + 2] = 1;
          v[eco + 3] = 1;
          cm = eco + 2;
        }
      }
    } else {
      if (!_146 && !_246 && !_346) {
        v[txc + 1] = 2;
        v[txc + 2] = 1;
        v[txc + 3] = 2;
        cm = txc + 2;
        im = txc + 1;
        v[eco + 1] = 2 - _145;
        v[eco + 2] = 2 - _245;
        v[eco + 3] = 2 - _345;
      } else {
        v[txc + 1] = 1;
        v[txc + 2] = 2;
        v[txc + 3] = 2;
        cm = txc + 1;
        im = txc + 2;
        v[eco + 1] = 2 - _145;
        v[eco + 2] = 2 - _245;
        v[eco + 3] = 2 - _345;
      }
    }
  }
  for (int i = 0; i < n; i += 3) {
    if (i == txc || i == eco) continue;
    if (b[i / 3]) {
      bool _12, _23;
      _12 = ask(i + 1, i + 2, im);
      _23 = ask(i + 2, i + 3, im);
      if (!_12 && !_23) {
        v[i + 1] = 1;
        v[i + 2] = 2;
        v[i + 3] = 1;
      } else {
        v[i + 2] = 1;
        v[i + 1] = 2 - _12;
        v[i + 3] = 2 - _23;
      }
    } else {
      bool _12, _23;
      _12 = ask(i + 1, i + 2, cm);
      _23 = ask(i + 2, i + 3, cm);
      if (_12 && _23) {
        v[i + 1] = 2;
        v[i + 2] = 1;
        v[i + 3] = 2;
      } else {
        v[i + 2] = 2;
        v[i + 1] = 2 - _12;
        v[i + 3] = 2 - _23;
      }
    }
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++)
    if (v[i] == 2) ans.push_back(i);
  cout << "! " << (int)ans.size() << " ";
  for (int i : ans) cout << i << " ";
  cout << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
