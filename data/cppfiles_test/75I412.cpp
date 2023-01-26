#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
template <typename... T>
void debug(T &&...args) {
  ((cerr << args << " "), ...);
  cerr << "\n";
}
long long int gcd(long long int a, long long int b) {
  return a ? gcd(b % a, a) : b;
}
long long int minv(long long int a, long long int b) { return a < b ? a : b; }
long long int maxv(long long int a, long long int b) { return a > b ? a : b; }
void swapv(long long int &a, long long int &b) {
  a = a + b;
  b = a - b;
  a = a - b;
}
long long int power(long long int a, long long int b, long long int m = mod) {
  if (a == 0 || b == 1) return a;
  if (b == 0) return 1;
  long long int ans = 1;
  while (b >= 1) {
    if (b & 1) {
      b--;
      ans = (ans * a) % m;
    }
    a = (a * a) % m;
    b = b >> 1;
  }
  return ans;
}
long long int logv(long long int x) {
  long long int ans = -1;
  while (x) {
    x = x >> 1;
    ans++;
  }
  return ans;
}
long long int inv(long long int a, long long int m) {
  return power(a, m - 2, m);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> mv;
    while (n--) {
      int k;
      cin >> k;
      int maxval = INT_MIN;
      for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        maxval = max(maxval, x - i + 1);
      }
      mv.push_back({maxval, k});
    }
    sort(mv.begin(), mv.end());
    int ans = mv[0].first;
    int curPow = ans;
    for (int i = 1; i < n; i++) {
      curPow += mv[i - 1].second;
      ans += max(mv[i].first - curPow, 0);
      curPow += max(mv[i].first - curPow, 0);
    }
    cout << ans;
    cout << "\n";
    ;
  }
  return 0;
}
