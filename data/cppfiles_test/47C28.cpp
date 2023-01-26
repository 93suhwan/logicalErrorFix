#include <bits/stdc++.h>
using namespace std;
class DisjSet {
  int *rank, *parent, n;

 public:
  DisjSet(int n) {
    rank = new int[n];
    parent = new int[n];
    this->n = n;
    makeSet();
  }
  void makeSet() {
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }
  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }
  void Union(int x, int y) {
    int xset = find(x);
    int yset = find(y);
    if (xset == yset) return;
    if (rank[xset] < rank[yset]) {
      parent[xset] = yset;
    } else if (rank[xset] > rank[yset]) {
      parent[yset] = xset;
    } else {
      parent[yset] = xset;
      rank[xset] = rank[xset] + 1;
    }
  }
};
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
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX;
const long double PI = 3.141592653589793238463;
void solve() {
  long long n, x;
  cin >> n >> x;
  vector<long long> a(n);
  {
    for (long long i = 0; i <= (long long)n - 1; i += 1) cin >> a[i];
  };
  sort(a.begin(), a.end());
  vector<long long> neg, pos;
  for (long long i = 0; i <= (long long)n - 1; i += 1) {
    if (a[i] > 0)
      pos.push_back(a[i]);
    else if (a[i] < 0)
      neg.push_back(-a[i]);
  }
  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());
  vector<long long> finDist;
  long long tot = 0;
  long long posLen = pos.size();
  long long negLen = neg.size();
  for (long long i = posLen - 1; i >= (long long)0; i -= 1) {
    if (tot % x == 0) {
      finDist.push_back(pos[i]);
    }
    tot++;
  }
  tot = 0;
  for (long long i = negLen - 1; i >= (long long)0; i -= 1) {
    if (tot % x == 0) {
      finDist.push_back(neg[i]);
    }
    tot++;
  }
  sort(finDist.begin(), finDist.end());
  long long ans = 0;
  long long len = finDist.size();
  for (long long i = 0; i <= (long long)len - 2; i += 1) ans += finDist[i] * 2;
  if (len > 0) ans += finDist[len - 1];
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T;
  T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
