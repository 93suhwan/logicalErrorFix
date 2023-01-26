#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void logger(string vars, Args&&... values) {}
template <typename T>
inline void maxa(T& a, T b) {
  a = max(a, b);
}
template <typename T>
inline void mina(T& a, T b) {
  a = min(a, b);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mxN = 2e5 + 5;
const int mod = 1e9 + 7;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  deque<int> a;
  vector<int> pref(n), suff(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  pref[0] = 1;
  suff[n - 1] = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] < a[i - 1])
      pref[i] = pref[i - 1] + 1;
    else
      pref[i] = 1;
  }
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] < a[i + 1])
      suff[i] = suff[i + 1] + 1;
    else
      suff[i] = 1;
  }
  string ans[2] = {"Alice", "Bob"};
  int prev = -1;
  int l = 0;
  int r = n - 1;
  for (int i = 0; i < n - 1; i++) {
    if (a.front() > a.back()) {
      if (suff[l] & 1) {
        cout << ans[i & 1] << "\n";
        return 0;
      }
      if (a.back() <= prev) {
        cout << ans[i & 1 ^ 1] << "\n";
        return 0;
      }
      prev = a.back();
      a.pop_back();
      r--;
    } else {
      if (pref[r] & 1) {
        cout << ans[i & 1] << "\n";
        return 0;
      }
      if (a.front() <= prev) {
        cout << ans[i & 1 ^ 1] << "\n";
        return 0;
      }
      prev = a.front();
      a.pop_front();
      l++;
    }
  }
  cout << ans[n & 1 ^ 1] << "\n";
}
