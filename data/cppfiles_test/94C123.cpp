#include <bits/stdc++.h>
using namespace std;
template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
void re(T &x) {
  cin >> x;
}
template <class Arg, class... Args>
void re(Arg &first, Args &...rest) {
  re(first);
  re(rest...);
}
template <class T>
void re(vector<T> &a) {
  for (int i = 0; i < (int)(a.size()); ++i) re(a[i]);
}
template <class T>
void pr(T &x) {
  cout << x << " ";
}
template <class Arg, class... Args>
void pr(Arg &first, Args &...rest) {
  pr(first);
  pr(rest...);
}
template <class T>
void pr(vector<T> &a) {
  for (int i = 0; i < (int)(a.size()); ++i) pr(a[i]);
}
void solve() {
  unsigned long long n, k;
  cin >> n >> k;
  vector<long long> a(10);
  for (int i = 0; i < n; i++) {
    int pos;
    cin >> pos;
    a[pos] = 1;
  }
  vector<long long> mult(18);
  unsigned long long curmult = 1;
  for (int i = 0; i < 18; i++) {
    mult[i] = curmult * 9;
    if (i + 1 < 10 && a[i + 1] == 1)
      curmult = 1;
    else
      curmult *= 10;
  }
  vector<long long> ans(18);
  for (int i = 17; i >= 0; i--) {
    unsigned long long rest = 0;
    for (int j = 0; j < i; j++) rest += mult[j];
    for (int j = i + 1; j < 18; j++) rest += mult[j];
    unsigned long long d = 9;
    while (d > 0 && rest + (mult[i] / 9) * (d - 1) > k) {
      d--;
    }
    if (rest + (mult[i] / 9) * (d) <= k) d++;
    mult[i] = (mult[i] / 9) * d;
    ans[i] = d;
  }
  unsigned long long make = 1;
  unsigned long long made = 0;
  for (int i = 0; i < (int)(18); ++i) {
    made += ans[i] * make;
    make *= 10;
  }
  pr(made);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
    cout << '\n';
  }
  return 0;
}
