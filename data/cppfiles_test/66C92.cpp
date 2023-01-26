#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<long long, long long>;
using pd = pair<ld, ld>;
long long NEG_INF = -1e12;
long long POS_INF = 1e12;
long long MAX = 1.5 * 1e6 + 5;
using long long = long long;
using ld = long double;
int mod = 1e9 + 7;
int getMid(int s, int e) { return s + (e - s) / 2; }
ld PI = 3.14159265358979323846;
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si) {
  if (qs <= ss && qe >= se) return st[si];
  if (se < qs || ss > qe) return 0;
  int mid = getMid(ss, se);
  return getSumUtil(st, ss, mid, qs, qe, 2 * si + 1) +
         getSumUtil(st, mid + 1, se, qs, qe, 2 * si + 2);
}
void updateValueUtil(int *st, int ss, int se, int i, int diff, int si) {
  if (i < ss || i > se) return;
  st[si] = st[si] + diff;
  if (se != ss) {
    int mid = getMid(ss, se);
    updateValueUtil(st, ss, mid, i, diff, 2 * si + 1);
    updateValueUtil(st, mid + 1, se, i, diff, 2 * si + 2);
  }
}
void updateValue(int arr[], int *st, int n, int i, int new_val) {
  if (i < 0 || i > n - 1) {
    cout << "Invalid Input";
    return;
  }
  int diff = new_val - arr[i];
  arr[i] = new_val;
  updateValueUtil(st, 0, n - 1, i, diff, 0);
}
int getSum(int *st, int n, int qs, int qe) {
  if (qs < 0 || qe > n - 1 || qs > qe) {
    cout << "Invalid Input";
    return -1;
  }
  return getSumUtil(st, 0, n - 1, qs, qe, 0);
}
int constructSTUtil(int arr[], int ss, int se, int *st, int si) {
  if (ss == se) {
    st[si] = arr[ss];
    return arr[ss];
  }
  int mid = getMid(ss, se);
  st[si] = constructSTUtil(arr, ss, mid, st, si * 2 + 1) +
           constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);
  return st[si];
}
int *constructST(int arr[], int n) {
  int x = (int)(ceil(log2(n)));
  int max_size = 2 * (int)pow(2, x) - 1;
  int *st = new int[max_size];
  constructSTUtil(arr, 0, n - 1, st, 0);
  return st;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int fast_pow(int a, int p) {
  int res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = a * 1ll * a % mod;
      p /= 2;
    } else {
      res = res * 1ll * a % mod;
      p--;
    }
  }
  return res;
}
int fact(int n) {
  int res = 1;
  for (int i = 1; i <= n; i++) {
    res = res * 1ll * i % mod;
  }
  return res;
}
int C(int n, int k) {
  return fact(n) * 1ll * fast_pow(fact(k), mod - 2) % mod * 1ll *
         fast_pow(fact(n - k), mod - 2) % mod;
}
vector<long long> primeFactors(long long n) {
  vector<long long> facts;
  while (n % 2 == 0) {
    n = n / 2;
    facts.push_back(2);
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      facts.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) facts.push_back(n);
  return facts;
}
long long inv(long long a, long long m) {
  if (a == 1) return 1;
  return inv(m % a, m) * (m - m / a) % m;
}
vector<long long> getDivisors(long long n) {
  vector<long long> res;
  for (int i = 1; i * i < n; i++) {
    if (n % i == 0) res.push_back(i);
  }
  for (int i = sqrt(n); i >= 1; i--) {
    if (n % i == 0) res.push_back(n / i);
  }
  return res;
}
vector<long long> bin(long long n) {
  vector<long long> ban;
  long long i;
  ban.push_back(0);
  for (i = 1 << 30; i > 0; i = i / 2) {
    if ((n & i) != 0) {
      ban.push_back(1);
    } else {
      ban.push_back(0);
    }
  }
  return ban;
}
int factorial(long long n) {
  if (n > 1)
    return n * factorial(n - 1);
  else
    return 1;
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
unsigned long long nCrModPFermat(unsigned long long n, int r, int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  unsigned long long fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
bool check(vector<long long> c) {
  for (int i = 0; i < c.size() - 1; i++) {
    if (c[i] > c[i + 1]) return 0;
    c[i + 1] -= c[i];
  }
  if (c[c.size() - 1] == 0) return 1;
  return 0;
}
long long ceil(long long x, long long y) {
  if (x != 0) {
    return 1 + ((x - 1) / y);
  } else {
    return 0;
  }
}
ld distance(ld x1, ld y1, ld x2, ld y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
using namespace std;
void makeCombiUtil(vector<vector<int>> &ans, vector<int> &tmp, int n, int left,
                   int k) {
  if (k == 0) {
    ans.push_back(tmp);
    return;
  }
  for (int i = left; i <= n; ++i) {
    tmp.push_back(i);
    makeCombiUtil(ans, tmp, n, i + 1, k - 1);
    tmp.pop_back();
  }
}
vector<vector<int>> makeCombi(int n, int k) {
  vector<vector<int>> ans;
  vector<int> tmp;
  makeCombiUtil(ans, tmp, n, 1, k);
  return ans;
}
void PartitionSub(int arr[], int i, int N, int K, int nos,
                  vector<vector<int>> &v, vector<vector<vector<int>>> &combs) {
  if (i >= N) {
    if (nos == K) {
      vector<vector<int>> comb;
      for (int x = 0; x < v.size(); x++) {
        vector<int> temp;
        for (int y = 0; y < v[x].size(); y++) {
          temp.push_back(v[x][y]);
        }
        comb.push_back(temp);
      }
      combs.push_back(comb);
    }
    return;
  }
  for (int j = 0; j < K; j++) {
    if (v[j].size() > 0) {
      v[j].push_back(arr[i]);
      PartitionSub(arr, i + 1, N, K, nos, v, combs);
      v[j].pop_back();
    } else {
      v[j].push_back(arr[i]);
      PartitionSub(arr, i + 1, N, K, nos + 1, v, combs);
      v[j].pop_back();
      break;
    }
  }
}
vector<vector<vector<int>>> partKSubsets(int arr[], int N, int K) {
  vector<vector<int>> v(K);
  vector<vector<vector<int>>> combs;
  if (K == 0 || K > N) {
    cout << "Not Possible" << endl;
  } else {
    PartitionSub(arr, 0, N, K, 0, v, combs);
  }
  return combs;
}
void dfs(long long node, vector<vector<long long>> &edges,
         vector<bool> &visited) {
  visited[node] = true;
  if (edges[node].empty()) return;
  long long v;
  for (auto v : edges[node]) {
    if (!visited[v]) {
      dfs(v, edges, visited);
    }
  }
  return;
}
long long numDivisors(long long n, vector<long long> primes) {
  long long res = 1;
  for (auto p : primes) {
    if (n == 1) break;
    long long count = 1;
    while (n % p == 0) {
      n /= p;
      count++;
    }
    res *= count;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  vector<long long> cand;
  for (int i = 1; i <= 100000; i++) {
    if (i % 3 == 0 || i % 10 == 3) continue;
    cand.push_back(i);
  }
  long long t, n, a, b, c, d;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << cand[n - 1] << endl;
    ;
  }
}
