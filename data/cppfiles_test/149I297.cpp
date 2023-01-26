#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> ans;
long long int dp[2005];
void go(long long int x) {
  if (x <= 0) return;
  int lo = 0;
  int hi = v.size() - 1;
  int z5 = 64;
  while (lo < hi) {
    z5--;
    if (z5 == 0) break;
    int mid = lo + (hi - lo + 1) / 2;
    if (dp[mid] < x) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  long long int cnt = 0;
  if (lo != 0) {
    cnt = x / (dp[lo - 1] + 1);
    x -= (cnt * (dp[lo - 1]));
  } else {
    cnt = x;
    x = 0;
  }
  if (x) {
    cnt++;
    x--;
  }
  ans[lo] = cnt;
}
void dynamic() {
  long long int n, k, x;
  cin >> n >> k >> x;
  string s;
  cin >> s;
  x--;
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') {
      int z = 0;
      while (i < n && s[i] == '*') {
        z++;
        i++;
      }
      i--;
      v.push_back(z);
    }
  }
  reverse(v.begin(), v.end());
  ans.resize(v.size());
  memset(dp, 0, sizeof(dp));
  long long int last = -1, cnt = 0, cnt_last = 0;
  for (int i = 0; i < v.size(); i++) {
    long long int z = k * (v[i]);
    if (i != 0) {
      dp[i] = ((dp[i - 1] + 1) * (z)) + dp[i - 1];
    } else {
      dp[i] = z;
    }
  }
  go(x);
  int z3 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') {
      while (i < n && s[i] == '*') {
        i++;
      }
      i--;
      int xy = ans[v.size() - 1 - z3];
      while (xy--) cout << "b";
      z3++;
    } else {
      cout << s[i];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    dynamic();
  }
}
