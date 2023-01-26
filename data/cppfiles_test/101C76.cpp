#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  }
  return b;
}
long long min(long long a, long long b) {
  if (a > b) {
    return b;
  }
  return a;
}
long long ceilab(long long a, long long b) {
  if (a % b == 0) {
    return a / b;
  }
  return (a / b) + 1;
}
long long grecomdiv(long long a, long long b) {
  if (b == 0) return a;
  return grecomdiv(b, a % b);
}
long long dp[200005];
void solve() {
  long long a;
  cin >> a;
  vector<long long> v;
  for (long long i = 0; i < a; i++) {
    long long a1;
    cin >> a1;
    v.push_back(a1);
  }
  string s;
  cin >> s;
  vector<long long> v1;
  vector<long long> v2;
  for (long long i = 0; i < a; i++) {
    if (s[i] == 'B') {
      if (v[i] < 1) {
        cout << "NO" << endl;
        return;
      } else {
        v1.push_back(v[i]);
      }
    }
    if (s[i] == 'R') {
      if (v[i] > a) {
        cout << "NO" << endl;
        return;
      } else {
        v2.push_back(v[i]);
      }
    }
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  long long count1 = 0;
  long long count2 = 0;
  for (long long i = 0; i < a; i++) {
    long long ind = i + 1;
    if (count1 < v1.size()) {
      if (v1[count1] < ind) {
        cout << "NO" << endl;
        return;
      }
      count1 = count1 + 1;
    } else {
      if (v2[count2] > ind) {
        cout << "NO" << endl;
        return;
      }
      count2 = count2 + 1;
    }
  }
  cout << "YES" << endl;
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
