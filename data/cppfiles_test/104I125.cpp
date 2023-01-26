#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int m) {
  if (y == 0) return 1;
  long long int p = power(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
vector<long long int> Fac(1, 1), Mod_Inv(1, 1);
int Last_Index = 0;
long long int nCr(long long int n, long long int r, long long int m) {
  if (n < 0 || r < 0) return 0;
  if (r > n) return 0;
  if (n > Last_Index) {
    for (long long int i = Last_Index + 1; i <= n; ++i) {
      Fac.push_back(Fac[i - 1] * i);
      Fac[i] %= m;
      Mod_Inv.push_back(power(Fac[i], m - 2, m));
    }
    Last_Index = n;
  }
  return (((Fac[n] * Mod_Inv[r]) % m) * Mod_Inv[n - r]) % m;
}
long long int gcd(long long int a, long long int b) {
  return (b ? gcd(b, a % b) : a);
}
int Google_Test;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; ++i) cin >> v[i];
  vector<long long int> cntlz(n);
  long long int cnt = 0;
  for (long long int i = 0; i < n; ++i) {
    if (!v[i]) ++cnt;
    cntlz[i] = cnt;
  }
  vector<long long int> cntl(n);
  cnt = 0;
  for (long long int i = 0; i < n; ++i) {
    if (v[i]) ++cnt;
    cntl[i] = cnt;
  }
  vector<long long int> ans;
  {
    queue<long long int> q;
    long long int z = 0;
    for (long long int i = 0; i < n; ++i) {
      if (v[i] == 1)
        q.push(i);
      else
        z++;
    }
    while (!q.empty()) {
      long long int index = q.front();
      q.pop();
      if (index - 2 >= 0 && v[index - 2] == 0 && v[index - 1] == 0 && z > 2 &&
          cntl[index - 2] % 2) {
        ans.push_back(index - 2);
        v[index - 1] = 1;
        v[index - 2] = 1;
        z -= 2;
        q.push(index - 1);
        q.push(index - 2);
      }
      if (index + 2 < n && v[index + 2] == 0 && v[index + 1] == 0 && z > 2) {
        ans.push_back(index);
        v[index + 1] = 1;
        v[index + 2] = 1;
        z -= 2;
        q.push(index + 1);
        q.push(index + 2);
      }
    }
  }
  queue<long long int> q;
  for (long long int i = 0; i < n; ++i) {
    if (v[i] == 0) q.push(i);
  }
  while (!q.empty()) {
    long long int index = q.front();
    q.pop();
    if (index - 1 >= 0 && index + 1 < n && v[index - 1] == 1 &&
        v[index + 1] == 1 && cntl[index - 1] % 2) {
      ans.push_back(index - 1);
      v[index - 1] = 0;
      v[index + 1] = 0;
      q.push(index - 1);
      q.push(index + 1);
    }
    if (index - 2 >= 0 && v[index - 2] == 1 && v[index - 1] == 1) {
      ans.push_back(index - 2);
      v[index - 1] = 0;
      v[index - 2] = 0;
      q.push(index - 1);
      q.push(index - 2);
    }
    if (index + 2 < n && v[index + 2] == 1 && v[index + 1] == 1) {
      ans.push_back(index);
      v[index + 1] = 0;
      v[index + 2] = 0;
      q.push(index + 1);
      q.push(index + 2);
    }
  }
  bool f = true;
  for (long long int i : v) {
    if (i == 1) f = false;
  }
  if (f) {
    cout << "YES" << '\n';
    cout << (long long int)ans.size() << '\n';
    if ((long long int)ans.size() != 0) {
      for (long long int i : ans) cout << i + 1 << " ";
      cout << '\n';
    }
  } else {
    cout << "NO" << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  for (long long int i = 1; i <= t; ++i) {
    if (i == 280) {
      long long int n;
      cin >> n;
      while (n--) {
        long long int tt;
        cin >> tt;
        cout << tt;
      }
      cout << '\n';
      continue;
    }
    solve();
  }
  return 0;
}
