#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
long long a[maxn];
long long quick_pow(long long a, long long b) {
  long long base = a, ans = 1;
  while (b) {
    if (b & 1) {
      ans *= base;
    }
    b >>= 1;
    base *= base;
  }
  return ans;
}
int tot = 1;
void init() {
  a[0] = 1;
  for (int i = 1; i < 40; i++) {
    a[i] = quick_pow(2, i);
  }
}
string Int_to_String(long long n) {
  ostringstream stream;
  stream << n;
  return stream.str();
}
int getResult(long long value, long long dest) {
  string val = Int_to_String(value);
  string des = Int_to_String(dest);
  int idx = 0;
  for (int i = 0; i < val.size(); i++) {
    if (val[i] == des[idx]) {
      idx++;
    }
  }
  int dele = val.size() - idx;
  int add = des.size() - idx;
  return dele + add;
}
void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 0 << endl;
  } else {
    int ans = 10000;
    for (int i = 1; i < 40; i++) {
      ans = min(ans, getResult(n, a[i]));
    }
    cout << ans << endl;
  }
}
int main() {
  int t;
  init();
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
