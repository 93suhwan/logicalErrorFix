#include <bits/stdc++.h>
using namespace std;
const long long MOD1 = 1e9 + 7;
const long long MAX = 1e17 + 7;
const long long VAR = 30;
const long long MOD2 = 998244353;
struct tup {
  long long first, second, third;
};
template <class third>
void show(vector<third> x) {
  for (auto it : x) cerr << it << " ";
}
template <class third>
void show(set<third> x) {
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
vector<long long> fact(VAR, 1);
void factpre() {
  for (long long i = 2; i < VAR + 1; i++) {
    fact[i] = (fact[i - 1] * i) % MOD2;
  }
}
void Yesno(bool p) {
  if (p)
    cout << "YES";
  else
    cout << "NO";
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
long long power(long long a, long long b) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b & 1) {
      x = (x * y);
      if (x > MOD1) x -= MOD1;
    }
    y = (y * y);
    if (y > MOD1) y -= MOD1;
    b >>= 1;
  }
  return x;
}
long long InverseEuler(long long n) { return power(n, MOD1 - 2); }
vector<bool> pr(VAR, 0);
long long C(long long n, long long r) {
  return (fact[n] *
          ((InverseEuler(fact[r]) * InverseEuler(fact[n - r])) % MOD1)) %
         MOD1;
}
vector<long long> pri;
void prime() {
  for (long long i = 2; i < VAR; i++) {
    if (pr[i] == 0) {
      pri.push_back(i);
      for (long long j = i * i; j <= VAR; j += i) pr[j] = 1;
    }
  }
}
vector<vector<long long>> v;
vector<long long> dist;
void dfs(long long pnt) {
  for (auto it : v[pnt]) {
    if (dist[pnt] + 1 < dist[it]) {
      dist[it] = dist[pnt] + 1;
      dfs(it);
    }
  }
}
void solve() {
  long long n, d;
  cin >> n >> d;
  long long a[n];
  bool flag = false;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i]) flag = true;
  }
  if (!flag)
    cout << 0;
  else {
    flag = false;
    for (long long i = 0; i < n; i++) {
      if (a[i] != a[(i + d) % n]) flag = true;
    }
    if (!flag)
      cout << -1;
    else {
      v.assign(n, vector<long long>());
      dist.assign(n, MAX);
      for (long long i = 0; i < n; i++) {
        v[(i + d) % n].push_back(i);
        if (!a[i]) dist[i] = 0;
      }
      for (long long i = 0; i < n; i++) {
        if (!a[i]) dfs(i);
      }
      long long ans = 0;
      for (long long i = 0; i < n; i++) {
        if (a[i]) ans = max(ans, dist[i]);
      }
      cout << ans;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long t;
  if (0)
    t = 1;
  else
    cin >> t;
  for (long long i = 0; i < t; i++) {
    solve();
    cout << '\n';
    cerr << '\n';
  }
  return 0;
}
