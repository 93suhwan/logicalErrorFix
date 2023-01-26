#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
vector<char*> tokenizer(const char* args) {
  char* token = new char[111];
  strcpy(token, args);
  token = strtok(token, ", ");
  vector<char*> v({token});
  while (token = strtok(NULL, ", ")) v.push_back(token);
  return reverse(v.begin(), v.end()), v;
}
void debugg(vector<char*> args) { cerr << "\b\b "; }
template <typename Head, typename... Tail>
void debugg(vector<char*> args, Head H, Tail... T) {
  debug() << " [" << args.back() << ": " << H << "] ";
  args.pop_back();
  debugg(args, T...);
}
const int mod = 1e9 + 7;
const int MX = 0x3f3f3f3f;
const int maxn = 5e3 + 1;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, i, j;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int> > lcp(n, vector<int>(n));
    for (i = n - 1; i >= 0; i--) {
      for (j = n - 1; j >= 0; j--) {
        if (s[i] == s[j])
          lcp[i][j] = 1 + (i + 1 < n and j + 1 < n ? lcp[i + 1][j + 1] : 0);
      }
    }
    vector<int> dp(n);
    dp[0] = n;
    for (i = 1; i <= n - 1; i++) {
      dp[i] = n - i;
      for (j = 0; j <= i - 1; j++) {
        if (s[j] < s[i])
          dp[i] = max(dp[i], dp[j] + n - i);
        else if (s[i] == s[j]) {
          if (lcp[i][j] + i < n and s[i + lcp[i][j]] > s[j + lcp[i][j]])
            dp[i] = max(dp[i], dp[j] + n - i - lcp[i][j]);
        }
      }
    }
    cout << *max_element((dp).begin(), (dp).end()) << "\n";
  }
  return 0;
}
