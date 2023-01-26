#include <bits/stdc++.h>
using namespace std;
vector<char> vp(4000005);
void ans(vector<long long int> &dp, vector<long long int> &star,
         long long int x, vector<char> &vp, long long int n) {
  if (x <= 1) {
    return;
  }
  long long int starpos = upper_bound((dp).begin(), (dp).end(), x) - dp.begin();
  x -= dp[starpos - 1];
  if (x == 0) {
    for (long long int i = star[starpos - 1]; i < n; i++) {
      if (vp[i] == '*') {
        vp[i] = 'b';
      }
    }
  } else {
    for (long long int i = star[starpos]; i < n; i++) {
      while (i < n && vp[i] == '*') {
        vp[i] = 'b';
        i++;
      }
      break;
    }
    ans(dp, star, x, vp, n);
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
    string b = "";
    for (long long int i = 0; i < k; i++) {
      b += 'b';
    }
    long long int cnt = 0;
    for (long long int i = 0; i < n; i++) {
      if (s[i] == '*') {
        long long int t = cnt;
        for (long long int j = cnt; j < t + k; j++) {
          vp[cnt] = '*';
          cnt++;
        }
      } else {
        vp[cnt] = 'a';
        cnt++;
      }
    }
    s.clear();
    vector<long long int> dp;
    vector<long long int> star;
    star.push_back(-1);
    dp.push_back(1);
    long long int prev = 1;
    long long int curr = 1;
    long long int flag1 = 1;
    for (long long int i = cnt - 1; i >= 0 && flag1; i--) {
      long long int flag = 0;
      while (i >= 0 && vp[i] == '*') {
        if (x < (curr + 1) * 1ll * prev) {
          dp.push_back((curr + 1) * 1ll * prev);
          star.push_back(i);
          flag1 = 0;
          break;
        }
        dp.push_back((curr + 1) * 1ll * prev);
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
    long long int flag = 1;
    ans(dp, star, x, vp, cnt);
    for (long long int i = 0; i < cnt; i++) {
      if (vp[i] == '*') continue;
      cout << vp[i];
    }
    cout << "\n";
  }
  return 0;
}
