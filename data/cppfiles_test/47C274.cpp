#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b, long long int m) {
  long long int ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
long long int solve(vector<long long int>& v, long long int k) {
  long long int n = v.size();
  if (n == 0) return 0;
  long long int dp[n + 2];
  multiset<long long int> s;
  for (long long int i = n - 1; i >= 0; i--) {
    if (i == n - 1) {
      dp[i] = v[n - 1];
      s.insert(dp[i]);
    } else {
      if (i >= (n - k)) {
        dp[i] = v[n - 1];
        s.insert((2 * v[i]) + dp[i + 1]);
      } else {
        if (i == (n - k - 1))
          s.erase(s.find(v[n - 1]));
        else
          s.erase(s.find(2 * v[i + k] + dp[i + k + 1]));
        s.insert((2 * v[i]) + dp[i + 1]);
        auto it = s.begin();
        dp[i] = *it;
      }
    }
  }
  return dp[0];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int k;
    cin >> k;
    vector<long long int> pos, neg;
    long long int zero = 0;
    for (long long int i = 1; i < n + 1; i++) {
      long long int x;
      cin >> x;
      if (x < 0)
        neg.push_back(abs(x));
      else
        pos.push_back(x);
      if (x == 0) zero++;
    }
    if (pos.size() == zero) {
      pos.clear();
      for (long long int i = 0; i < zero; i++) neg.push_back(0);
    }
    sort((neg).begin(), (neg).end());
    sort((pos).begin(), (pos).end());
    long long int ans = solve(pos, k) + solve(neg, k);
    if (pos.size() and neg.size()) ans += min(*pos.rbegin(), *neg.rbegin());
    cout << ans << endl;
  }
}
