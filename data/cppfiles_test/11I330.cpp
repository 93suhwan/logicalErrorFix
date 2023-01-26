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
  if (p_diff == q_diff)
    return (long long)(p.s.size()) > (long long)(q.s.size());
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
    vector<Node> arr;
    long long total = 0;
    long long len = 0;
    long long prob_ans = 0;
    for (long long i = 0; i < n; i++) {
      if (a[i].cnt[ele] > ((long long)(a[i].s.size()) - a[i].cnt[ele])) {
        prob_ans++;
        total += (long long)(a[i].s.size());
        len += a[i].cnt[ele];
      } else {
        arr.push_back(a[i]);
      }
    }
    sort(arr.begin(), arr.end(), cmp);
    for (long long i = 0; i < (long long)(arr.size()); i++) {
      total += (long long)(arr[i].s.size());
      len += arr[i].cnt[ele];
      if (len <= (total - len)) break;
      prob_ans++;
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
