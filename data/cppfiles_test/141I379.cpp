#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int a, s;
  cin >> a >> s;
  string x = to_string(a);
  string y = to_string(s);
  long long int i = x.size() - 1, j = y.size() - 1;
  string b;
  while (i >= 0 && j >= 0) {
    long long int d1 = x[i] - '0';
    long long int d2 = y[j] - '0';
    if (d2 >= d1) {
      b.push_back(char(48 + d2 - d1));
      i--;
      j--;
    } else {
      if (j == 0) {
        cout << -1 << endl;
        return;
      }
      long long int d = (y[j - 1] - '0') * 10 + d2;
      long long int diff = d - d1;
      if (diff > 9) {
        cout << -1 << endl;
        return;
      }
      b.push_back(char(48 + diff));
      i--;
      j -= 2;
    }
  }
  if (i >= 0) {
    cout << -1 << endl;
    return;
  }
  while (j >= 0) {
    b.push_back(y[j]);
    j--;
  }
  while (b.size() > 0 && b.back() == '0') b.pop_back();
  reverse(b.begin(), b.end());
  cout << b << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
