#include <bits/stdc++.h>
long long MOD = 1e9 + 7;
long long bigMOD = 998244353;
using namespace std;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
long long exp2(long long base, int power) {
  if (power == 0) return 1;
  if (power == 1) return (base + MOD) % MOD;
  long long ans = exp2(base, power / 2);
  ans = (ans * ans + MOD) % MOD;
  if (power % 2 == 1) ans = (ans * base + MOD) % MOD;
  return (ans + MOD) % MOD;
}
unsigned long long power(unsigned long long x, int y, int p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
unsigned long long modInverse(unsigned long long n, int p) {
  return power(n, p - 2, p);
}
unsigned long long nCr(unsigned long long n, int r, int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  vector<unsigned long long> fac;
  fac.resize(n + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
struct BIT {
  int n;
  vector<int> B;
  BIT(vector<int> A) {
    n = A.size();
    B.resize(n + 1);
    for (int k = 0; k < n; k++) {
      addValue(k, A[k]);
    }
  }
  int getSum(int m) {
    m++;
    int sum = 0;
    while (m > 0) {
      sum += B[m];
      m -= m & (-m);
    }
    return sum;
  }
  void addValue(int m, int increase) {
    m++;
    while (m <= n) {
      B[m] += increase;
      m += (m) & (-m);
    }
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int aa;
  cin >> aa;
  long long maxi = 0;
  vector<pair<int, int>> anss;
  for (int kk = 0; kk < aa; kk++) {
    int n, m;
    cin >> n >> m;
    vector<long long> ex;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      ex.push_back(a);
      sum += a;
    }
    vector<vector<char>> solved;
    for (int i = 0; i < n; i++) {
      solved.push_back(vector<char>());
      for (int j = 0; j < m; j++) {
        char a;
        cin >> a;
        solved[i].push_back(a);
      }
    }
    for (int k = 0; k < pow(2, n); k++) {
      vector<int> dig;
      int temp = k;
      for (int i = 0; i < 10; i++) {
        dig.push_back(temp % 2);
        temp /= 2;
      }
      vector<int> perQ;
      perQ.resize(m);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (solved[i][j] == '1') {
            if (dig[i] == 0) {
              perQ[j]--;
            } else {
              perQ[j]++;
            }
          }
        }
      }
      vector<pair<int, int>> order;
      for (int i = 0; i < m; i++) {
        order.push_back(make_pair(perQ[i], i));
      }
      sort(order.begin(), order.end());
      long long sum = 0;
      for (int i = 0; i < m; i++) {
        sum += (long long)order[i].first * (i + 1);
      }
      if (sum > maxi) {
        maxi = sum;
        anss = order;
      }
    }
    vector<int> ans;
    ans.resize(m);
    for (int i = 0; i < m; i++) {
      ans[anss[i].second] = i + 1;
    }
    for (int i = 0; i < m; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
}
