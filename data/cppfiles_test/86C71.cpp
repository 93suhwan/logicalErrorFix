#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  string bit1, bit2;
  cin >> bit1 >> bit2;
  vector<int> r;
  for (int i = 0; i < n; ++i) {
    if (bit1[i] == '1' && bit2[i] == '1')
      r.push_back(0);
    else if (bit1[i] == '0' && bit2[i] == '0')
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
      else if (r[i] != r[i + 1] && r[i + 1] != 2) {
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
