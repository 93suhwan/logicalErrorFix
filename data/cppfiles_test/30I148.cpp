#include <bits/stdc++.h>
using namespace std;
int n;
int q;
vector<int> v;
vector<int> primes;
vector<int> smallestPrimeFactor;
void linearSieve(int n) {
  if (n < 1) n = 1;
  if ((int)smallestPrimeFactor.size() >= n + 1) return;
  int primePiBound = n < 20 ? n - 1 : (int)(n / (log(n * 1.) - 2) + 2);
  primes.assign(primePiBound + 1, numeric_limits<int>::max());
  int P = 0;
  smallestPrimeFactor.assign(n + 1, 0);
  smallestPrimeFactor[1] = 1;
  int n2 = n / 2, n3 = n / 3, n5 = n / 5;
  if (n >= 2) primes[P++] = 2;
  if (n >= 3) primes[P++] = 3;
  for (int q = 2; q <= n; q += 2) smallestPrimeFactor[q] = 2;
  for (int q = 3; q <= n; q += 6) smallestPrimeFactor[q] = 3;
  for (int q = 5; q <= n5; q += 2) {
    if (smallestPrimeFactor[q] == 0) primes[P++] = smallestPrimeFactor[q] = q;
    int bound = smallestPrimeFactor[q];
    for (int i = 2;; ++i) {
      int p = primes[i];
      if (p > bound) break;
      int pq = p * q;
      if (pq > n) break;
      smallestPrimeFactor[pq] = p;
    }
  }
  for (int q = (n5 + 1) | 1; q <= n; q += 2) {
    if (smallestPrimeFactor[q] == 0) primes[P++] = smallestPrimeFactor[q] = q;
  }
  primes.resize(P);
}
void primeFactors(int x, vector<pair<int, int> >& out_v) {
  linearSieve(x);
  out_v.clear();
  while (x != 1) {
    int p = smallestPrimeFactor[x], k = 0;
    x /= p, k++;
    while (x % p == 0) x /= p, k++;
    out_v.push_back(make_pair(p, k));
  }
}
void divisors(int num, vector<int>& v) {
  vector<pair<int, int> > pf;
  primeFactors(num, pf);
  queue<pair<int, int> > stk;
  stk.push(make_pair(1, 0));
  while (!stk.empty()) {
    pair<int, int> f = stk.front();
    stk.pop();
    if (f.second == pf.size()) {
      continue;
    }
    int cur = f.first;
    stk.push(make_pair(f.first, f.second + 1));
    for (int i = 1; i <= pf[f.second].second; i++) {
      cur *= pf[f.second].first;
      v.push_back(cur);
      stk.push(make_pair(cur, f.second + 1));
    }
  }
  v.push_back(1);
}
struct UF {
  vector<int> belong;
  vector<int> size;
  void resize(int n) {
    belong.assign(n + 1, -1);
    size.assign(n + 1, 1);
  }
  inline int root(int b) {
    if (belong[b] == -1) {
      return b;
    }
    belong[b] = root(belong[b]);
    return belong[b];
  }
  void merge(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return;
    belong[a] = b;
    size[b] += size[a];
  }
};
UF uf;
void connect(int s) {
  vector<pair<int, int> > a;
  primeFactors(s, a);
  for (int i = 0; i < a.size(); i++) {
    uf.merge(s, a[i].first);
  }
}
set<pair<int, int> > valid;
bool can[1000002];
int main() {
  linearSieve(1000002);
  uf.resize(1000002);
  cin >> n;
  cin >> q;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    v.push_back(a);
    connect(a);
  }
  for (auto it : v) {
    int a = uf.root(it);
    int b = uf.root(it + 1);
    valid.insert(make_pair(a, b));
    valid.insert(make_pair(b, a));
    vector<pair<int, int> > aa;
    primeFactors(it + 1, aa);
    for (int i = 0; i < aa.size(); i++) {
      for (int j = 0; j < aa.size(); j++) {
        valid.insert(make_pair(uf.root(aa[i].first), uf.root(aa[j].first)));
      }
    }
  }
  while (q--) {
    int s, t;
    scanf("%d%d", &s, &t);
    s--;
    t--;
    s = v[s];
    t = v[t];
    int a = uf.root(s);
    int b = uf.root(t);
    if (a == b) {
      puts("0");
      continue;
    }
    if (valid.count(make_pair(a, b))) {
      puts("1");
      continue;
    }
    puts("2");
  }
  return 0;
}
