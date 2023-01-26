#include <bits/stdc++.h>
using namespace std;
int a[500500], n;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = (1); i <= (n); i++) cin >> a[i];
  long long val = 0, sum = 0;
  stack<pair<long long, int> > s;
  for (int i = (1); i <= (n); i++) {
    val = sum + (i == 1);
    (sum += 998244353 - val * a[i] % 998244353) %= 998244353;
    while (!s.empty() && s.top().second > a[i]) {
      pair<long long, int> cur = s.top();
      s.pop();
      (sum += cur.first * (cur.second - a[i])) %= 998244353;
      (val += cur.first) %= 998244353;
    }
    s.push({val, a[i]});
  }
  cout << sum << endl;
  return 0;
}
