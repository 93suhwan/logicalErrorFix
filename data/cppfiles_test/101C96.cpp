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
  long long n;
  cin >> n;
  vector<long long> a(n);
  re(a);
  string c;
  cin >> c;
  vector<long long> A, B;
  for (int i = 0; i < (int)(n); ++i) {
    if (c[i] == 'B')
      A.push_back(a[i]);
    else
      B.push_back(a[i]);
  }
  sort((A).begin(), (A).end());
  sort((B).begin(), (B).end());
  for (int i = 0; i < (int)(A.size()); ++i) {
    if (A[i] < i + 1) {
      cout << "NO";
      return;
    }
  }
  for (int i = 0; i < (int)(B.size()); ++i) {
    if (B[B.size() - 1 - i] > n - i) {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
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
