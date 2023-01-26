#include <bits/stdc++.h>
using namespace std;
void rohansolve() {
  string a, s;
  cin >> a >> s;
  string b;
  while (a.size() && s.size()) {
    long long x = a.back() - '0';
    a.pop_back();
    long long y = s.back() - '0';
    s.pop_back();
    if (y >= x) {
      long long d = y - x;
      b.push_back(d + '0');
    } else {
      long long dy = s.back() - '0';
      s.pop_back();
      if (dy != 1) {
        cout << "-1\n";
        return;
      }
      long long d = 10 + (y - x);
      b.push_back(d + '0');
    }
  }
  if (a.size()) {
    cout << "-1\n";
    return;
  }
  while (s.size()) {
    long long y = s.back() - '0';
    s.pop_back();
    b.push_back(y + '0');
  }
  while (b.size()) {
    if (b.back() == '0') {
      b.pop_back();
    } else {
      break;
    }
  }
  if (b.empty()) {
    b.push_back('0');
  }
  reverse(b.begin(), b.end());
  cout << b << '\n';
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long x;
  cin >> x;
  while (x--) {
    rohansolve();
  }
}
