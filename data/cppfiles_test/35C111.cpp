#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void logger(string vars, Args&&... values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
  cout << endl;
}
vector<bool> getBinary(int n) {
  vector<bool> res(32, false);
  int in = 31;
  while (n) {
    if (n & 1) res[in] = true;
    in--;
    n /= 2;
  }
  return res;
}
long long getDec(vector<bool> arr) {
  long long res = 0;
  for (int i = 0; i < arr.size(); i++) {
    res *= 2;
    if (arr[i]) {
      res += 1;
    }
  }
  return res;
}
void print(vector<bool> arr) {
  for (int i : arr) {
    cout << i;
  }
  cout << endl;
}
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n > m) {
    cout << "0" << endl;
    return;
  }
  vector<bool> nbin = getBinary(n);
  vector<bool> mbin = getBinary(m);
  vector<bool> res(32, false);
  bool found = false;
  for (int i = 0; i < 32; i++) {
    res[i] = nbin[i] ^ mbin[i];
    if (res[i] && nbin[i]) {
      res[i] = 0;
      found = true;
      break;
    }
  }
  if (!found) {
    for (int i = 31; i >= 0; i--) {
      if (!mbin[i]) {
        res[i] = 1;
        break;
      } else {
        res[i] = 0;
      }
    }
  }
  long long ans = getDec(res);
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
