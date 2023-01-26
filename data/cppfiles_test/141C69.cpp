#include <bits/stdc++.h>
using namespace std;
void solve() {
  string a, s;
  cin >> a >> s;
  vector<int> b;
  long long int na = a.size(), ns = s.size();
  int i = na - 1, j = ns - 1;
  for (; j >= 0; --i, --j) {
    if (i < 0) {
      b.push_back(s[j] - '0');
    } else {
      if (a[i] > s[j]) {
        if (!j) {
          cout << "-1\n";
          return;
        }
        int num = atoi(s.substr(j - 1, 2).c_str());
        int d = a[i] - '0';
        if (num - d <= 0 || num - d > 9) {
          cout << "-1\n";
          return;
        } else {
          b.push_back(num - d);
          j--;
        }
      } else {
        b.push_back(int(s[j]) - int(a[i]));
      }
    }
  }
  if (i >= 0) {
    cout << "-1\n";
    return;
  }
  reverse(b.begin(), b.end());
  bool lead0 = true;
  for (auto first : b) {
    lead0 &= first == 0;
    cout << (lead0 ? "" : to_string(first));
  }
  cout << '\n';
}
int main() {
  cout.precision(12);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
