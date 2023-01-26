#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
long long pow(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  if (b % 2 == 0) {
    return pow((a * a) % MOD, b / 2);
  } else {
    return (pow(a, b - 1) * a) % MOD;
  }
}
long long fact[1000000];
long long obr_fact[1000000];
void init() {
  fact[0] = 1;
  for (long long i = 1; i < 200000; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= MOD;
  }
  for (long long i = 0; i < 200000; i++) {
    obr_fact[i] = pow(fact[i], MOD - 2);
  }
}
long long c(long long k, long long n) {
  long long ans = fact[n];
  ans *= obr_fact[k];
  ans %= MOD;
  ans *= obr_fact[n - k];
  ans %= MOD;
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  init();
  long long n;
  cin >> n;
  vector<string> arr(n);
  long long bal1 = 0;
  long long bal2 = 0;
  long long cnt1 = 0;
  long long cnt2 = 0;
  long long cnt3 = 0;
  bool was = false;
  bool can1 = false;
  bool can2 = false;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i][1] == 'B') {
      arr[i][1] = 'W';
    } else {
      if (arr[i][1] == 'W') {
        arr[i][1] = 'B';
      }
    }
    if (arr[i] == "WB" || arr[i] == "BW") {
      was = true;
    }
    if (arr[i][0] != 'W' && arr[i][1] != 'W') {
      can1 = true;
    }
    if (arr[i][0] != 'B' && arr[i][1] != 'B') {
      can2 = true;
    }
    if (arr[i][0] == 'B') {
      bal1++;
    }
    if (arr[i][0] == 'W') {
      bal2++;
    }
    if (arr[i][1] == 'B') {
      bal1--;
    }
    if (arr[i][1] == 'W') {
      bal2--;
    }
    if (arr[i][0] == '?') {
      cnt1++;
    }
    if (arr[i][1] == '?') {
      cnt2++;
    }
    if (arr[i] == "??") {
      cnt3++;
    }
  }
  long long ans = 0;
  for (long long i = 0; i <= cnt1; i++) {
    long long now_bal1 = bal1 + i;
    long long now_bal2 = bal2 + cnt1 - i;
    long long now = c(i, cnt1);
    if (now_bal1 + now_bal2 != cnt2) {
      continue;
    }
    now *= c(now_bal1, cnt2);
    now %= MOD;
    ans += now;
    ans %= MOD;
  }
  if (!was && can1 && can2) {
    long long lol = 1;
    for (long long i = 0; i < cnt3; i++) {
      lol *= 2;
      lol %= MOD;
    }
    ans -= lol;
    bool flag = false;
    for (long long i = 0; i < n; i++) {
      if (arr[i][0] == 'B' || arr[i][1] == 'B') {
        flag = true;
      }
    }
    if (!flag) {
      ans++;
    }
    flag = false;
    for (long long i = 0; i < n; i++) {
      if (arr[i][0] == 'W' || arr[i][1] == 'W') {
        flag = true;
      }
    }
    if (!flag) {
      ans++;
    }
    ans += MOD;
    ans %= MOD;
  }
  cout << ans;
}
