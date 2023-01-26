#include <bits/stdc++.h>
using namespace std;
long long ans[100005];
vector<long long> factors[100005];
long long temp[100005];
long long tempans[100005];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(ans, 0, sizeof(ans));
  memset(temp, 0, sizeof(temp));
  memset(tempans, 0, sizeof(tempans));
  for (long long i = 1; i < 100005; i++) {
    for (long long j = i; j < 100005; j += i) {
      factors[j].push_back(i);
    }
  }
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = n; i >= 1; i--) {
    vector<long long> p;
    for (long long j = i; j <= n; j += i) {
      for (auto x : factors[a[j - 1]]) {
        if (temp[x] >= 1) {
          temp[x]++;
        } else {
          temp[x]++;
          p.push_back(x);
        }
      }
    }
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());
    for (auto x : p) {
      long long z = temp[x];
      z = (z * z);
      tempans[x] += z;
      for (auto y : factors[x]) {
        if (temp[y] && y != x) {
          tempans[y] -= tempans[x];
        }
      }
    }
    long long lol = 0;
    for (auto x : p) {
      lol += (x * tempans[x]);
      tempans[x] = 0;
      temp[x] = 0;
    }
    lol %= 1000000007;
    ans[i] += lol;
    ans[i] %= 1000000007;
    for (auto x : factors[i]) {
      if (x == i) {
        continue;
      }
      ans[x] -= ans[i];
      ans[x] += 1000000007;
      ans[x] %= 1000000007;
    }
  }
  long long finale = 0;
  for (long long i = 1; i <= n; i++) {
    finale += (i * ans[i]);
    finale %= 1000000007;
  }
  cout << finale;
}
