#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
long long md = 1000000007;
using namespace std;
template <typename T>
T pw(T a, T b) {
  T c = 1, m = a;
  while (b) {
    if (b & 1) c = (c * m);
    m = (m * m), b /= 2;
  }
  return c;
}
template <typename T>
T ceel(T a, T b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
template <typename T>
T my_log(T n, T b) {
  T i = 1, ans = 0;
  while (1) {
    if (i > n) {
      ans--;
      break;
    }
    if (i == n) break;
    i *= b, ans++;
  }
  return ans;
}
template <typename T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long pwmd(long long a, long long b) {
  long long c = 1, m = a;
  while (b) {
    if (b & 1) c = (c * m) % md;
    m = (m * m) % md;
    b /= 2;
  }
  return c;
}
long long modinv(long long n) { return pwmd(n, md - 2); }
long long inverse(long long i) {
  if (i == 1) return 1;
  return (md - ((md / i) * inverse(md % i)) % md + md) % md;
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t, n, a;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long> v, c(n + 1), ans(n + 1, -1);
    for (int i = 0; i < n; i++) cin >> a, v.push_back(a), c[a]++;
    stack<int> st;
    vector<long long> cnt(n + 1);
    for (int i = 0; i < n + 1; i++) {
      if (!c[i]) {
        if (!i) break;
        if (st.empty()) break;
        cnt[i] = i - st.top() + cnt[i - 1];
        st.pop();
      } else {
        for (int j = 0; j < c[i] - 1; j++) st.push(i);
        if (i) cnt[i] = cnt[i - 1];
      }
    }
    long long p = 0;
    for (int i = 0; i < n + 1; i++) {
      if (p < i) break;
      if (!i) {
        ans[i] = c[i];
        p += c[i];
        continue;
      }
      ans[i] = c[i] + cnt[i - 1];
      p += c[i];
    }
    for (auto x : ans) cout << x << " ";
    cout << "\n";
  }
}
