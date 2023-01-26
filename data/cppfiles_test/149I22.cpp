#include <bits/stdc++.h>
using namespace std;
vector<vector<long long int>> adj(4000005);
vector<bool> vis(4000005);
void dfs(long long int vertex, long long int par = 0) {
  vis[vertex] = true;
  for (auto child : adj[vertex]) {
    if (vis[child]) continue;
    dfs(child, vertex);
  }
}
void ans(vector<long long int> dp, vector<long long int> star, long long int x,
         vector<pair<char, long long int>> &vp, long long int n,
         long long int &flag) {
  if (x <= 1) {
    return;
  }
  long long int starpos = upper_bound((dp).begin(), (dp).end(), x) - dp.begin();
  x -= dp[starpos - 1];
  if (x == 0) {
    for (long long int i = star[starpos - 1]; i < n; i++) {
      if (vp[i].first == '*') {
        vp[i].first = 'b';
      }
    }
  } else {
    for (long long int i = star[starpos]; i < n; i++) {
      while (i < n && vp[i].first == '*') {
        vp[i].first = 'b';
        i++;
      }
      break;
    }
    ans(dp, star, x, vp, n, flag);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int T = 1;
  cin >> T;
  while (T--) {
    long long int n, k, x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    vector<pair<char, long long int>> vp(4000005);
    string b = "";
    for (long long int i = 0; i < k; i++) {
      b += 'b';
    }
    long long int cnt = 0;
    for (long long int i = 0; i < n; i++) {
      if (s[i] == '*') {
        long long int t = cnt;
        for (long long int j = cnt; j < t + k; j++) {
          vp[cnt] = {'*', cnt};
          cnt++;
        }
      } else {
        vp[cnt] = {'a', cnt};
        cnt++;
      }
    }
    s.clear();
    s = "";
    for (long long int i = 0; i < cnt; i++) {
      s += vp[i].first;
    }
    cout << s << "\n";
    vector<long long int> dp;
    vector<long long int> star;
    star.push_back(-1);
    dp.push_back(1);
    long long int prev = 1;
    long long int curr = 1;
    for (long long int i = cnt - 1; i >= 0; i--) {
      long long int flag = 0;
      while (i >= 0 && vp[i].first == '*') {
        dp.push_back((curr + 1) * prev);
        star.push_back(i);
        i--;
        curr++;
        flag = 1;
      }
      if (flag) {
        prev = curr * prev;
        curr = 1;
      }
    }
    for (long long int i = 0; i < dp.size(); i++) {
      cout << dp[i] << " ";
    }
    cout << "\n";
    long long int flag = 1;
    ans(dp, star, x, vp, cnt, flag);
    for (long long int i = 0; i < cnt; i++) {
      if (vp[i].first == '*') continue;
      cout << vp[i].first;
    }
    cout << "\n";
  }
  return 0;
}
