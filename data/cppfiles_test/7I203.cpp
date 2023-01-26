#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourDirection = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<int>> eightDirection = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                                      {1, 0},  {1, -1}, {0, -1}, {-1, -1}};
long long int mod(long long int n, long long int M) { return (n % M + M) % M; }
long long int modAdd(long long int a, long long int b, long long int M) {
  return mod(mod(a, M) + mod(b, M), M);
}
long long int modMul(long long int a, long long int b, long long int M) {
  return mod(mod(a, M) * mod(b, M), M);
}
long long int modMinus(long long int a, long long int b, long long int M) {
  return mod(mod(a, M) - mod(b, M), M);
}
long long int modpow(long long int x, long long int n, long long int M) {
  if (n == 0) return 1 % M;
  if (n == 1) return x % M;
  long long int u = modpow(x, n / 2, M);
  u = modMul(u, u, M);
  if (n % 2) u = modMul(u, x, M);
  return u;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int extendedGcd(long long int a, long long int b, long long int &x,
                          long long int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long int x1, y1;
  long long int g = extendedGcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return g;
}
long long int modInverse(long long int a, long long int m) {
  long long int g, x, y;
  g = extendedGcd(a, m, x, y);
  if (g == 1) {
    return (x % m + m) % m;
  }
  return -1;
}
long long int crt(vector<long long int> &P, vector<long long int> &R) {
  int n = P.size();
  vector<long long int> X(n);
  long long int productOfAllP = 1;
  for (int i = 0; i < n; i++) productOfAllP *= P[i];
  for (int i = 0; i < n; i++) {
    X[i] = R[i];
    long long int mulOfInverse = 1;
    long long int mul = 1;
    for (int j = 0; j < i; j++) {
      mulOfInverse = modMul(mulOfInverse, modInverse(P[j], P[i]), P[i]);
      X[i] = modMinus(X[i], modMul(X[j], mul, P[i]), P[i]);
      mul = modMul(mul, P[j], P[i]);
    }
    X[i] = modMul(X[i], mulOfInverse, P[i]);
  }
  long long int finalX = 0;
  long long int mul = 1;
  for (int i = 0; i < n; i++) {
    finalX = modAdd(finalX, modMul(X[i], mul, productOfAllP), productOfAllP);
    mul = modMul(mul, P[i], productOfAllP);
  }
  return finalX;
}
bool isPrime(long long int n) {
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
int getParent(vector<int> &parent, int s) {
  if (parent[s] == s) return s;
  return getParent(parent, parent[s]);
}
vector<int> primeNumbers;
void sieve() {
  int limit = 1e5;
  vector<bool> prime(limit, true);
  for (long long int i = 2; i < limit; i++) {
    if (prime[i]) {
      primeNumbers.push_back(i);
      for (long long int j = i * i; j < limit; j = j + i) prime[j] = false;
    }
  }
}
bool insideGrid(int x, int y, int n, int m) {
  if (x >= 0 && x < n && y >= 0 && y < m) return true;
  return false;
}
vector<long long int> getMemAllocated(int n) {
  int ans = 1;
  while (n > ans) ans *= 2;
  ans = ans * 2 - 1;
  vector<long long int> result(ans, 0);
  return result;
}
long long int buildTree(vector<long long int> &tree,
                        vector<long long int> &data, int root, int start,
                        int end) {
  if (start != end) {
    int mid = (start + end) / 2;
    tree[root] = gcd(buildTree(tree, data, root * 2 + 1, start, mid),
                     buildTree(tree, data, root * 2 + 2, mid + 1, end));
  } else
    tree[root] = data[start];
  return tree[root];
}
long long int rangeQuery(vector<long long int> &tree, int root, int start,
                         int end, int rS, int rE) {
  if (start >= rS && end <= rE) return tree[root];
  if (start > rE || end < rS) return -1;
  int mid = (start + end) / 2;
  int v1 = rangeQuery(tree, root * 2 + 1, start, mid, rS, rE);
  int v2 = rangeQuery(tree, root * 2 + 2, mid + 1, end, rS, rE);
  if (v1 == v2) return v1;
  if (v1 == -1) return v2;
  if (v2 == -1) return v1;
  return gcd(v1, v2);
}
void solve() {
  int n;
  cin >> n;
  vector<long long int> data(n);
  for (int i = 0; i < n; i++) cin >> data[i];
  if (n == 1) {
    cout << 1 << "\n";
    return;
  }
  vector<long long int> dif;
  for (int i = 1; i < n; i++) dif.push_back(abs(data[i] - data[i - 1]));
  vector<long long int> T = getMemAllocated(dif.size());
  buildTree(T, dif, 0, 0, dif.size() - 1);
  int globalAns = 1;
  for (int i = 0; i < n - 1; i++) {
    int start = i;
    int end = n - 2;
    int qAns = i;
    while (start <= end) {
      int m = (start + end) / 2;
      long long int g = rangeQuery(T, 0, 0, dif.size() - 1, i, m);
      if (g == 1) {
        end = m - 1;
      } else {
        qAns = m;
        start = m + 1;
      }
    }
    globalAns = max(globalAns, qAns - i + 2);
  }
  cout << globalAns << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
