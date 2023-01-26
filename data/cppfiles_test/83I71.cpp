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
    int n, i, j, k;
    cin >> n;
    string s;
    cin >> s;
    vector<int> dp(n + 1);
    for (i = 1; i <= n; i++) dp[i] = n - i + 1;
    for (i = 2; i <= n; i++) {
      string str = s.substr(i - 1);
      int offset = (int)str.size();
      str += '#';
      str += s;
      vector<int> pattern((int)str.size(), -1);
      j = 0;
      k = 1;
      while (k < (int)str.size()) {
        if (str[k] == str[j]) {
          pattern[k] = j;
          k++;
          j++;
        } else if (j > 0)
          j = pattern[j - 1] + 1;
        else
          k++;
      }
      for (j = offset + 1; j <= offset + i; j++) {
        if (pattern[j - 1] != -1 and pattern[j - 1] + 1 < offset and
            str[j] < str[pattern[j - 1] + 1])
          dp[i] = max(dp[i], dp[j - offset - pattern[j - 1] - 1] + n - i -
                                 pattern[j - 1]);
        if (pattern[j] == -1 and str[j] < str[0])
          dp[i] = max(dp[i], dp[j - offset] + n - i + 1);
      }
    }
    cout << *max_element((dp).begin(), (dp).end()) << "\n";
  }
  return 0;
}
