#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
int setBit(int num, int idx, int value = 1) {
  return (value) ? (num | (1 << idx)) : (num & ~(1 << idx));
}
int getBit(int num, int idx) { return ((num >> idx) & 1) == 1; }
int cntBits(int num) {
  int ret = 0;
  while (num) {
    if (num % 2) ret++;
    num /= 2;
  }
  return ret;
}
int is_prime[1000001];
void Sieve() {
  for (int i = 0; i <= 1000000; i++) {
    is_prime[i] = 1;
  }
  is_prime[0] = 0;
  is_prime[1] = 0;
  for (int i = 2; i * i <= 1000000; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= 1000000; j += i) {
        is_prime[j] = 0;
      }
    }
  }
}
vector<int> get_bin(int n) {
  vector<int> ret;
  while (n > 0) {
    if (n % 2 == 0)
      ret.push_back(0);
    else
      ret.push_back(1);
    n /= 2;
  }
  return ret;
}
unordered_map<long long, long long> factorise(long long n) {
  unordered_map<long long, long long> map;
  if (n % 2 == 0) {
    while (n % 2 == 0) {
      if (map.find(2) != map.end())
        map[2]++;
      else
        map[2] = 1;
      n = n / 2;
    }
  }
  for (long long i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      while (n % i == 0) {
        if (map.find(i) != map.end())
          map[i]++;
        else
          map[i] = 1;
        n = n / i;
      }
    }
  }
  if (n > 1) map[n] = 1;
  return map;
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
vector<vector<long long> > mat_mul(vector<vector<long long> > mat,
                                   vector<vector<long long> > mat1) {
  vector<vector<long long> > ret{{0, 0}, {0, 0}};
  ret[0][0] =
      ((mat[0][0] * mat1[0][0]) % MOD + (mat[0][1] * mat1[1][0]) % MOD) % MOD;
  ret[0][1] =
      ((mat[0][0] * mat1[1][0]) % MOD + (mat[0][1] * mat1[1][1]) % MOD) % MOD;
  ret[1][0] =
      ((mat[1][0] * mat1[0][0]) % MOD + (mat[1][1] * mat1[1][0]) % MOD) % MOD;
  ret[1][1] =
      ((mat[1][0] * mat1[1][0]) % MOD + (mat[1][1] * mat1[1][1]) % MOD) % MOD;
  return ret;
}
vector<vector<long long> > mat_exp(vector<vector<long long> > mat,
                                   long long ex) {
  if (ex == 0) return {{1, 1}, {1, 1}};
  if (ex == 1) return mat;
  if (ex % 2 == 0)
    return mat_exp(mat_mul(mat, mat), ex / 2);
  else
    return mat_mul(mat, mat_exp(mat, ex - 1));
}
int main() {
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    if (n % 2 == 0) {
      cout << "YES\n";
    } else {
      bool fnd = false;
      vector<pair<int, int> > thlth;
      vector<pair<int, int> > thltw;
      vector<pair<int, int> > thlon;
      for (int i = 0; i <= n - 3; i++) {
        if (arr[i] >= arr[i + 1] || arr[i + 1] >= arr[i + 2]) {
          fnd = true;
          break;
        }
        if (arr[i] >= arr[i + 1] && arr[i + 1] >= arr[i + 2]) {
          thlon.push_back({i, i + 2});
        } else if (arr[i] < arr[i + 1] && arr[i + 1] < arr[i + 2])
          thlth.push_back({i, i + 2});
        else
          thltw.push_back({i, i + 2});
      }
      vector<pair<int, int> > inc;
      vector<pair<int, int> > els;
      for (int i = 0; i <= n - 2; i++) {
        if (arr[i + 1] > arr[i])
          inc.push_back({i, i + 1});
        else
          els.push_back({i, i + 1});
      }
      if (thltw.size() != 0 && inc.size() != 0) {
        if ((thltw[0].second < inc[inc.size() - 1].first) ||
            (thltw[thltw.size() - 1].first > inc[0].second))
          fnd = true;
      }
      if (thlon.size() != 0 && els.size() != 0) {
        if ((thlon[0].second < els[els.size() - 1].first) ||
            (thlon[thlon.size() - 1].first > els[0].second))
          fnd = true;
      }
      if (thlth.size() != 0 && els.size() != 0 && inc.size() != 0) {
        if ((thlth[0].second < inc[inc.size() - 1].first) ||
            (thlth[thlth.size() - 1].first > inc[0].second))
          fnd = true;
      }
      if (fnd)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
