#include <bits/stdc++.h>
using namespace std;
int f(long long num) { return log2(num) + 1; }
vector<int> bin(long long num) {
  vector<int> v;
  while (num > 0) {
    v.push_back(num % 2);
    num = num / 2;
  }
  vector<int> ans;
  int i = v.size() - 1;
  while (i >= 0) {
    ans.push_back(v[i]);
    i--;
  }
  return ans;
}
bool g(long long x, long long y) {
  int len = f(x);
  while (x < y || x <= 0) {
    long long xnew = 0;
    vector<int> v = bin(x);
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == 0) {
        continue;
      }
      xnew = xnew + (1ll << (i));
    }
    if (y == xnew) {
      return 1;
    }
    xnew = xnew + (1ll << len);
    len++;
    x = xnew;
  }
  if (x == y) {
    return 1;
  }
  return 0;
}
void solve() {
  long long x, y;
  cin >> x >> y;
  if (x == y) {
    cout << "YES"
         << "\n";
    return;
  }
  int len = f(x);
  long long xnew = 0;
  vector<int> v = bin(x);
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == 0) {
      continue;
    }
    xnew = xnew + (1ll << (i));
  }
  bool b1 = g(x, y);
  bool b2 = g(xnew, y);
  if (b1 || b2) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
