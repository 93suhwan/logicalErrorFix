#include <bits/stdc++.h>
using namespace std;
bool prime[10000007];
void SieveOfEratosthenes() {
  memset(prime, true, sizeof(prime));
  for (long long int p = 2; p * p <= 10000007; p++) {
    if (prime[p] == true) {
      for (long long int i = p * p; i <= 10000007; i += p) prime[i] = false;
    }
  }
}
long long int ceil1(long long int a, long long int b) {
  if (a >= 0)
    return ((a + b - 1) / b);
  else {
    long long int x = abs(a);
    return (-1 * x / 2);
  }
}
long long int factorial(long long int n) {
  return (n == 1 || n == 0) ? 1 : (n * factorial(n - 1)) % 998244353;
}
const long long int MAX = 100001;
long long int factor[MAX] = {0};
void generatePrimeFactors() {
  factor[1] = 1;
  for (long long int i = 2; i < MAX; i++) factor[i] = i;
  for (long long int i = 4; i < MAX; i += 2) factor[i] = 2;
  for (long long int i = 3; i * i < MAX; i++) {
    if (factor[i] == i) {
      for (long long int j = i * i; j < MAX; j += i) {
        if (factor[j] == j) factor[j] = i;
      }
    }
  }
}
long long int calculateNoOFactors(long long int n) {
  if (n == 1) return 1;
  long long int ans = 1;
  long long int dup = factor[n];
  long long int c = 1;
  long long int j = n / factor[n];
  while (j != 1) {
    if (factor[j] == dup)
      c += 1;
    else {
      dup = factor[j];
      ans = ans * (c + 1);
      c = 1;
    }
    j = j / factor[j];
  }
  ans = ans * (c + 1);
  return ans;
}
long long int nCrModp(long long int n, long long int r, long long int p) {
  if (r > n - r) r = n - r;
  long long int C[r + 1];
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j - 1]) % p;
  }
  return C[r];
}
long long int check(long long int mid, long long int arr[], long long int n) {
  map<long long int, long long int> mp, mp2;
  std::vector<long long int> v, v1;
  for (long long int i = 0; i < mid; i++) {
    mp[arr[i]]++;
  }
  for (auto it : mp) {
    if (it.second) {
      v.push_back(it.second);
    }
  }
  sort(v.begin(), v.end());
  if (v.size() <= 1) return 1;
  long long int flag = 0;
  for (long long int i = 1; i < v.size(); i++) {
    if (v[i] == v[i - 1]) continue;
    flag = 1;
  }
  if (!flag) {
    if (v[0] == 1) return 1;
    return 0;
  }
  for (long long int i = 0; i < v.size(); i++) mp2[v[i]]++;
  long long int cnt = 0;
  long long int flag2 = 0;
  for (auto it : mp2) {
    if (it.second) {
      if (it.second == (v.size() - 1) || it.second == (v.size())) flag2 = 1;
    }
  }
  if (!flag2) return 0;
  long long int left = v[1] - v[0];
  long long int right = v[v.size() - 1] - v[v.size() - 2];
  if (right == 1) return 1;
  if (v[0] == 1) {
    long long int whatiamdoing = 0;
    map<long long int, long long int> again2;
    for (long long int i = 2; i < v.size(); i++) {
      if (v[i] != v[i - 1]) return 0;
    }
    return 1;
  }
  return 0;
}
void solve() {
  long long int a, b;
  cin >> a >> b;
  if (a == b) {
    cout << 0 << "\n";
    return;
  }
  if (((b / 2) + 1) >= a) {
    cout << (b % ((b) / 2 + 1)) << "\n";
    return;
  }
  cout << b % a << "\n";
  return;
}
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
signed main() {
  init_code();
  long long int t = 1;
  cin >> t;
  long long int i = 1;
  while (t--) {
    solve();
    i++;
  }
  return 0;
}
