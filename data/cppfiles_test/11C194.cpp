#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
void get_schwifty() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  long long n;
  cin >> n;
  vector<string> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long ans = 0;
  for (char ch = 'a'; ch <= 'e'; ch++) {
    vector<long long> v;
    for (long long i = 0; i < n; i++) {
      long long cnt = 0;
      for (char c : a[i]) {
        if (c == ch)
          cnt++;
        else
          cnt--;
      }
      v.push_back(cnt);
    }
    sort(v.begin(), v.end(), greater<long long>());
    long long prob_ans = 0;
    long long sum = 0;
    for (long long val : v) {
      sum += val;
      if (sum > 0)
        prob_ans++;
      else
        break;
    }
    ans = max(ans, prob_ans);
  }
  cout << ans << "\n";
}
int32_t main() {
  get_schwifty();
  long long tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
