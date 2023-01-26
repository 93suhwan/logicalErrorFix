#include <bits/stdc++.h>
using namespace std;
void create_bit(vector<int> &a, unsigned long long x) {
  while (x) {
    if (x & 1)
      a.push_back(1);
    else
      a.push_back(0);
    x = x >> 1;
  }
}
unsigned long long no(vector<int> &a) {
  unsigned long long ans = 0;
  int n = a.size();
  for (int i = 0; i < n; i++) {
    ans += a[i] << i;
  }
  return ans;
}
bool pallin(vector<int> &a) {
  int n = a.size();
  for (int i = 0; i < n >> 1; i++) {
    if (a[i] != a[n - 1 - i]) return false;
  }
  return true;
}
unsigned long long y;
bool rec(unsigned long long x) {
  vector<int> bx, by;
  create_bit(bx, x);
  create_bit(by, y);
  for (int i = 0; i < by.size(); i++) {
    int same_no = 0;
    for (int j = i; j < by.size(); j++) {
      if (same_no >= bx.size()) break;
      if (bx[same_no] == by[j]) {
        same_no++;
      } else
        break;
    }
    if (same_no == bx.size()) {
      bool ok1 = true, ok2 = true;
      for (int j = i + same_no; j < by.size(); j++) {
        if (by[j] != 1) {
          ok1 = false;
          break;
        }
      }
      for (int j = i - 1; j >= 1; j--) {
        if (by[j] != 1) {
          ok2 = false;
          break;
        }
      }
      if (ok1 && ok2) return true;
    }
  }
  return false;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  unsigned long long x;
  cin >> x >> y;
  unsigned long long x1 = x;
  while (x1 % 2 == 0) x1 = x1 / 2;
  vector<int> bx1;
  create_bit(bx1, x1);
  reverse(bx1.begin(), bx1.end());
  if (rec(x) || rec(no(bx1)))
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
