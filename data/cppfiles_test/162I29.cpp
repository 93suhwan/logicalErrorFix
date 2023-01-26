#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 5;
const int oo = 1e9;
const long long OO = 1e17;
const long long MOD = 1e9 + 7;
int start = 1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
void input1(vector<T> &x) {
  for (int i = int(start); i <= int(x.size() - 1); ++i) cin >> x[i];
}
template <class T>
void input2(vector<T> &x) {
  for (int i = int(start); i <= int(x.size() - 1); ++i) input1(x[i]);
}
template <class T>
void print1(vector<T> &x) {
  for (int i = int(start); i <= int(x.size() - 1); ++i) cout << x[i] << ' ';
  cout << '\n';
}
template <class T>
void print2(vector<T> &x) {
  for (int i = int(start); i <= int(x.size() - 1); ++i) print1(x[i]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> h(n + 1);
    input1(h);
    long long l = 1, r = 1e9 + 1;
    while (r - l > 1) {
      vector<long long> a(n + 1);
      long long mid = (l + r) / 2;
      bool flag = 1;
      for (int i = int(n); i >= int(2); --i) {
        long long d = 0;
        if (a[i] >= mid) {
          d = h[i] / 3;
        } else {
          d = floor(1.0L * (h[i] - (mid - a[i])) / 3);
        }
        if (d < 0) {
          flag = 0;
          break;
        }
        a[i - 1] += d;
        a[i - 2] += 2 * d;
      }
      for (int i = int(1); i <= int(n); ++i) {
        if (h[i] + a[i] < mid) {
          flag = 0;
          break;
        }
      }
      if (flag)
        l = mid;
      else
        r = mid;
    }
    cout << l << '\n';
  }
}
