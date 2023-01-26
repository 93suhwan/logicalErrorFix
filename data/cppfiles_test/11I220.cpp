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
struct Node {
  string s;
  map<char, long long> cnt;
};
char ele;
bool cmp(Node& p, Node& q) {
  long long p_diff = (long long)(p.s.size()) - p.cnt[ele];
  long long q_diff = (long long)(q.s.size()) - q.cnt[ele];
  return p_diff < q_diff;
}
void solve() {
  long long n;
  cin >> n;
  vector<Node> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i].s;
    for (char c : a[i].s) a[i].cnt[c]++;
  }
  long long ans = 0;
  for (ele = 'a'; ele <= 'e'; ele++) {
    long long prob_ans = 0;
    long long total = 0;
    long long len = 0;
    sort(a.begin(), a.end(), cmp);
    for (long long i = 0; i < n; i++) {
      long long total_len = (long long)(a[i].s.size());
      long long char_len = a[i].cnt[ele];
      if (char_len > (total_len - char_len)) {
        prob_ans++;
        total += total_len;
        len += char_len;
      } else if ((char_len + len) > ((total_len + total) - (char_len + len))) {
        prob_ans++;
        total += total_len;
        len += char_len;
      }
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
