#include <bits/stdc++.h>
using namespace std;
int toD(string b) {
  int n = 0;
  for (int i = 0; i < b.size(); ++i) {
    if (b[b.size() - 1 - i] == '1') n += pow(2, i);
  }
  return n;
}
void solve() {
  int n;
  cin >> n;
  string bit1, bit2;
  cin >> bit1 >> bit2;
  int a, b;
  a = toD(bit1);
  b = toD(bit2);
  vector<int> r;
  for (int i = 1; i <= n; ++i) {
    if ((a) & (1 << (n - i)) && (b) & (1 << (n - i)))
      r.push_back(0);
    else if (!((a) & (1 << (n - i))) && !((b) & (1 << (n - i))))
      r.push_back(1);
    else
      r.push_back(2);
  }
  int sum = 0;
  for (int i = 0; i < r.size(); i++) {
    if (r[i] == 2)
      sum += 2;
    else {
      if (i == r.size() - 1)
        sum += r[i];
      else if (r[i] != r[i + 1]) {
        sum += 2;
        i++;
      } else
        sum += r[i];
    }
  }
  cout << sum << '\n';
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
}
