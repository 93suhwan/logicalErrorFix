#include <bits/stdc++.h>
using namespace std;
using namespace std;
int n;
inline void solve() {
  long long a, s;
  cin >> a >> s;
  vector<int> b;
  while (s > 0) {
    int ad = a % 10;
    int sd = s % 10;
    int bd = (sd - ad + 10) % 10;
    if (ad + bd == s % 10) {
      b.push_back(bd);
      a = a / 10;
      s = s / 10;
    } else if (ad + bd == s % 100) {
      b.push_back(bd);
      a = a / 10;
      s = s / 100;
    } else {
      cout << -1 << endl;
      return;
    }
  }
  if (a != 0) {
    cout << -1 << endl;
    return;
  }
  while (b.size() > 1 and b.back() == 0) {
    b.pop_back();
  }
  reverse(b.begin(), b.end());
  for (int i : b) cout << i;
  cout << endl;
}
int main() {
  cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}
