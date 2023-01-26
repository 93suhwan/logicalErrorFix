#include <bits/stdc++.h>
using namespace std;
const long long MOD1 = 1e9 + 7;
const long long MAX = 1e17 + 7;
const long long VAR = 1e6 + 7;
const long long MOD2 = 998244353;
template <class third>
void show(vector<third> x) {
  for (auto it : x) cerr << it << " ";
}
template <class third>
void show(set<third> x) {
  for (auto it : x) cerr << it << " ";
}
template <class third>
void show(unordered_set<third> x) {
  for (auto it : x) cerr << it << " ";
}
template <class third>
void show(multiset<third> x) {
  for (auto it : x) cerr << it << " ";
}
template <class third>
void show(vector<vector<third>> x) {
  for (auto it : x) {
    for (auto i : it) cerr << i << " ";
    cerr << '\n';
  }
}
template <class third>
void show(map<third, third> x) {
  for (auto it : x) cerr << it.first << " " << it.second << '\n';
}
template <class third>
void show(third x) {
  cerr << x << " ";
}
struct tup {
  long long first, second, third;
};
vector<long long> fact(VAR, 1);
vector<long long> pri, sum(VAR, 0);
void factpre() {
  for (long long i = 2; i < VAR; i++) {
    fact[i] = (fact[i - 1] * i) % MOD2;
  }
}
long long gcd(long long a, long long b) {
  if (a == b) return a;
  if (a % b == 0) return b;
  if (b % a == 0) return a;
  if (b > a) return gcd(a, b % a);
  if (a > b) return gcd(a % b, b);
  return 0;
}
long long nPr(long long n, long long r) {
  return ((fact[n] % MOD1) / (fact[n - r] % MOD1));
}
long long nCr(long long n, long long r) {
  return ((fact[n] % MOD2) / ((fact[n - r] % MOD2) * (fact[r] % MOD2)));
}
long long power(long long a, long long b) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b & 1) {
      x = (x * y);
      x %= MOD2;
    }
    y = (y * y);
    y %= MOD2;
    b >>= 1;
  }
  return x;
}
long long InverseEuler(long long n) { return power(n, MOD2 - 2); }
vector<bool> pr(VAR, 0);
long long C(long long n, long long r) {
  return (fact[n] *
          ((InverseEuler(fact[r]) * InverseEuler(fact[n - r])) % MOD2)) %
         MOD2;
}
void prime() {
  for (long long i = 2; i < VAR; i++) {
    if (pr[i] == 0) {
      sum[i] = i;
      for (long long j = i * 2; j <= VAR; j += i) {
        pr[j] = 1;
        sum[j] += i;
      }
    }
  }
}
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (long long i = 0; i < (n / 2); i++)
    cout << a[i + 1] << " " << a[0] << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long third;
  if (0)
    third = 1;
  else
    cin >> third;
  for (long long i = 0; i < third; i++) {
    solve();
    cerr << '\n';
  }
  return 0;
}
