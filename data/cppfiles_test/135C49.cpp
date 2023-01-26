#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1000000007;
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
unsigned long long power(unsigned long long x, long long int y,
                         long long int p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
unsigned long long modInverse(unsigned long long n, long long int p) {
  return power(n, p - 2, p);
}
unsigned long long nCrModPFermat(unsigned long long n, long long int r,
                                 long long int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  unsigned long long fac[n + 1];
  fac[0] = 1;
  for (long long int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
long long int find_set(long long int i, vector<long long int> &parent) {
  if (parent[i] == -1) {
    return i;
  } else {
    parent[i] = find_set(parent[i], parent);
    return parent[i];
  }
}
void union_set(long long int i, long long int j, vector<long long int> &parent,
               vector<long long int> &rank) {
  long long int s1 = find_set(i, parent);
  long long int s2 = find_set(j, parent);
  if (s1 != s2) {
    if (rank[s1] > rank[s2]) {
      parent[s2] = s1;
      rank[s1] += rank[s2];
    } else {
      parent[s1] = s2;
      rank[s2] += rank[s1];
    }
  } else {
    return;
  }
}
void solve() {
  long long int n, i, j;
  long long int k;
  cin >> n >> k;
  long long int arr[n];
  multiset<long long int> s;
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
    s.insert(arr[i]);
  }
  long long int sum = 0;
  vector<long long int> v;
  for (i = 0; i < k; i++) {
    auto it1 = --s.end();
    long long int val = (*it1);
    s.erase(it1);
    v.push_back(val);
  }
  for (i = 0; i < k; i++) {
    long long int val = v[i];
    auto it2 = s.upper_bound(val);
    if (it2 != s.begin()) {
      it2--;
    }
    sum += (*it2) / val;
    s.erase(it2);
  }
  for (auto z : s) {
    sum += z;
  }
  cout << sum << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) solve();
}
