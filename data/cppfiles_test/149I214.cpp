#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> ans;
long long int dp[2005];
bool ch[2005];
int lm;
void go(long long int x, long long int k) {
  if (x <= 0) return;
  int lo = 0;
  int hi = lm - 1;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (dp[mid] >= x) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  if (ch[lo] == true) {
    return;
  }
  ch[lo] = true;
  long long int cnt = 0;
  if (lo != 0) {
    x -= dp[lo - 1];
    cnt = x / (dp[lo - 1] + 1);
    x -= (cnt * (dp[lo - 1] + 1));
  } else {
    cnt = x;
    x = 0;
  }
  if (x == 0) {
    ans[lo] = cnt;
    lo--;
    for (int i = lo; i >= 0; i--) {
      ans[lo] = v[lo] * k;
    }
    return;
  }
  if (x > 0) {
    cnt++;
    x--;
  }
  ans[lo] = cnt;
  go(x, k);
}
void dynamic() {
  memset(ch, false, sizeof(ch));
  ans.clear();
  v.clear();
  long long int n, k, x;
  cin >> n >> k >> x;
  string s;
  cin >> s;
  x--;
  for (int i = 0; i < n; i++) {
    dp[i] = 0;
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
  lm = v.size();
  for (int i = 0; i < v.size(); i++) {
    long long int z = k * 1ll * (v[i]);
    if (i != 0) {
      dp[i] = ((dp[i - 1] + 1) * (z)) + dp[i - 1];
      if (dp[i] >= x) {
        lm = i + 1;
        break;
      }
    } else {
      dp[i] = z;
    }
  }
  go(x, k);
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
  cout << "\n";
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
