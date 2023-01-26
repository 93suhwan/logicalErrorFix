#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
vector<long long> dp(55);
void pre() {
  dp[0] = 0;
  dp[1] = 1;
  for (long long i = 2; i < dp.size(); i++) dp[i] = dp[i - 1] + dp[i - 2];
}
long long inv(long long k) {
  long long p = mod - 2;
  long long ans = 1;
  for (; p; p >>= 1) {
    if (p & 1) ans = (ans * k) % mod;
    k = (k * k) % mod;
  }
  return ans;
}
long long power(long long k, long long p) {
  long long ans = 1;
  for (; p; p >>= 1) {
    if (p & 1) ans = (ans * k) % mod;
    k = (k * k) % mod;
  }
  return ans;
}
bool cmp(pair<long long, long long> &a, pair<long long, long long> &b) {
  return a.second < b.second;
}
void fun(long long ab1, long long bc1, long long ac1, long long ab2,
         long long bc2, long long ac2, vector<long long> &v) {
  long long a, b, c;
  for (long long i = 0; i < 63; i++) {
    if ((ab2 >> i) & 1) a += 1 << i;
  }
  b = a;
  for (long long i = 0; i < 63; i++) {
    if (!((ab2 >> i) & 1) && ((ab1 >> i) & 1)) {
      if ((ac2 >> i) & 1) {
        a += 1 << i;
      } else if ((bc2 >> i) & 1) {
        b += 1 << i;
      } else {
        a += ((ac1 >> i) & 1) << i;
        b += ((bc1 >> i) & 1) << i;
      }
    }
  }
  c = (a ^ (ac1)) | ac2;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  return;
}
void funless(long long a, long long ac1, long long ac2, vector<long long> &v) {
  long long c = (a ^ (ac1)) | ac2;
  v.push_back(c);
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> v;
  long long ab1, bc1, ac1, ab2, bc2, ac2;
  for (long long i = 0; i < n - n % 3; i += 3) {
    cout << "or"
         << " " << i + 1 << " " << i + 2 << endl;
    cout.flush();
    cin >> ab1;
    cout << "or"
         << " " << i + 2 << " " << i + 3 << endl;
    cout.flush();
    cin >> bc1;
    cout << "or"
         << " " << i + 1 << " " << i + 3 << endl;
    cout.flush();
    cin >> ac1;
    cout << "and"
         << " " << i + 1 << " " << i + 2 << endl;
    cout.flush();
    cin >> ab2;
    cout << "and"
         << " " << i + 2 << " " << i + 3 << endl;
    cout.flush();
    cin >> bc2;
    cout << "and"
         << " " << i + 1 << " " << i + 3 << endl;
    cout.flush();
    cin >> ac2;
    fun(ab1, bc1, ac1, ab2, bc2, ac2, v);
  }
  long long k1 = n % 3;
  long long st = n - n % 3;
  while (k1--) {
    cout << "or"
         << " " << 1 << " " << st + k1 + 1 << endl;
    cout.flush();
    cin >> ac1;
    cout << "and"
         << " " << 1 << " " << st + k1 + 1 << endl;
    cout.flush();
    cin >> ac2;
    funless(v[0], ac1, ac2, v);
  }
  sort(v.begin(), v.end());
  cout << "finish"
       << " " << v[k - 1] << endl;
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
