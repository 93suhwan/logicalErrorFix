#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
struct mycmp {
  bool operator()(pair<int, int> a, pair<int, int> b) const {
    return (a.first < b.first) || (a.first == b.first && a.second > b.second);
  }
};
const int bit = 31;
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  int flag = 0;
  int size = abs(a - b) * 2;
  int diff = abs(a - b);
  if (c > a and c > b) {
    flag = 1;
  }
  if (a > size or b > size) {
    flag = 1;
  }
  if (flag == 1) {
    cout << -1 << endl;
  } else {
    if (c + diff > size) {
      cout << c - diff << endl;
    } else {
      cout << c + diff << endl;
    }
  }
}
int main() {
  fast();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
