#include <bits/stdc++.h>
using namespace std;
const long long int huge = 1e17;
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int abbs(long long int a, long long int b) {
  if (a - b < 0) return b - a;
  return a - b;
}
long long int lowerB(vector<long long int> &v, long long int val) {
  long long int ind = v.size(), l = 0, r = v.size(), mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if (v[mid] >= val) {
      ind = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ind;
}
void solve() {
  long long int k;
  cin >> k;
  auto valid = [&](long long int n) {
    long long int s = 0;
    long long int t = n;
    while (t) {
      s += t % 10;
      t /= 10;
    }
    string second = to_string(n);
    if (second.back() == '3' || (s % 3 == 0)) return false;
    return true;
  };
  long long int i = 1, c = 0;
  while (1) {
    if (valid(i)) {
      c++;
    }
    if (c == k) break;
    i++;
  }
  cout << i << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
