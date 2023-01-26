#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void logger(string vars, Args &&...values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
}
template <typename T>
void print(vector<T> &collection, bool newline = true) {
  for (auto &item : collection) {
    cout << item << " ";
  }
  if (newline) cout << "\n";
}
template <typename T>
void print(T _data, bool newline = true) {
  cout << _data;
  if (newline) cout << "\n";
}
long long f;
long long n, w, k, x, m, t, p;
long long cnt = 0;
long long getSetBitsFromOneToN(long long r, long long l) {
  long long two = 2, ans = INT_MAX;
  long long n1 = r, n2 = l;
  l--;
  long long n = r;
  while (n) {
    long long curr = 0;
    curr += (r / two) * (two >> 1);
    if ((r & (two - 1)) > (two >> 1) - 1)
      curr += (r & (two - 1)) - (two >> 1) + 1;
    n >>= 1;
    if (true) {
      curr -= (l / two) * (two >> 1);
      if ((l & (two - 1)) > (two >> 1) - 1)
        curr -= (l & (two - 1)) - (two >> 1) + 1;
    }
    two <<= 1;
    ans = min(ans, n1 - n2 + 1 - curr);
  }
  return ans;
}
long long helper(long long l, long long r) {
  long long ans = INT_MAX;
  for (long long bit = 31; bit >= 0; bit--) {
    long long curr = 0;
    for (long long num = l; num <= r; num++) {
      if (num & (1 << bit)) curr++;
    }
    ans = min(ans, r - l + 1 - curr);
  }
  return ans;
}
void Solve() {
  long long l, r;
  cin >> l >> r;
  cout << getSetBitsFromOneToN(r, l);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long test;
  cin >> test;
  for (long long _ = 0; _ < test; _++) {
    Solve();
    cout << "\n";
  }
}
