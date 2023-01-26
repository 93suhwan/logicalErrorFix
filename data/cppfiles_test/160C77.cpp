#include <bits/stdc++.h>
using namespace std;
long long int M = 1e9 + 7;
long long int M1 = 998244353;
long long int dr[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
long long int dc[8] = {0, 1, -1, 0, -1, 1, -1, 1};
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
void setdecimals(long long int x) { cout << fixed << setprecision((int)x); }
long long int setbits(long long int x) {
  long long int c = __builtin_popcountll(x);
  return c;
}
long long int stoi(string &s) {
  long long int c = 0;
  for (auto i : s) c = c * 10 + i - '0';
  return c;
}
void print(long long int a) { cerr << a; }
void print(char a) { cerr << a; }
void print(string a) { cerr << a; }
void print(bool a) { cerr << a; }
void print(double a) { cerr << a; }
void print(float a) { cerr << a; }
template <class T, class X>
void print(pair<T, X> p);
template <class T>
void print(vector<T> v);
template <class T>
void print(set<T> v);
template <class T, class X>
void print(map<T, X> v);
template <class T>
void print(multiset<T> v);
template <class T, class X>
void print(pair<T, X> p) {
  cerr << "{";
  print(p.first);
  cerr << ",";
  print(p.second);
  cerr << "}";
}
template <class T>
void print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class X>
void print(map<T, X> v) {
  cerr << "[ ";
  for (auto i : v) {
    print(i);
    cerr << " ";
  }
  cerr << "]";
}
long long int power(long long int x, long long int y, long long int m) {
  if (y == 0) return 1;
  long long int p = power(x, y / 2, m) % m;
  p = p * p % m;
  if (y % 2 == 0) return p;
  return x * p % m;
}
long long int modInverse(long long int a, long long int m) {
  return power(a, m - 2, m);
}
vector<long long int> primes(long long int n) {
  vector<long long int> sieve(n + 1, 1);
  vector<long long int> arr;
  for (long long int i = 2; i * i <= n; i++) {
    for (long long int j = i * i; j <= n; j = j + i) {
      if (sieve[j] == 1) sieve[j] = 0;
    }
  }
  for (long long int i = 2; i < n + 1; i++) {
    if (sieve[i] && i != 1) arr.push_back(i);
  }
  return arr;
}
class DSU {
  long long int n;
  vector<long long int> parent, rank;

 public:
  DSU(long long int x) {
    n = x;
    parent.resize(n);
    rank.resize(n, 0);
    for (long long int i = 0; i < n; i++) parent[i] = i;
  }
  long long int get(long long int a) {
    return parent[a] = parent[a] == a ? a : get(parent[a]);
  }
  void merge(long long int a, long long int b) {
    a = get(a);
    b = get(b);
    if (a == b) return;
    if (rank[a] == rank[b]) rank[a]++;
    if (rank[a] > rank[b])
      parent[b] = a;
    else
      parent[a] = b;
  }
};
const int N = 200001;
long long int factorialNumInverse[N + 1];
long long int naturalNumInverse[N + 1];
long long int fact[N + 1];
void InverseofNumber(long long int p) {
  naturalNumInverse[0] = naturalNumInverse[1] = 1;
  for (int i = 2; i <= N; i++)
    naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial(long long int p) {
  factorialNumInverse[0] = factorialNumInverse[1] = 1;
  for (int i = 2; i <= N; i++)
    factorialNumInverse[i] =
        (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
void factorial(long long int p) {
  fact[0] = 1;
  for (int i = 1; i <= N; i++) {
    fact[i] = (fact[i - 1] * i) % p;
  }
}
long long int Binomial(long long int N, long long int R, long long int p) {
  long long int ans =
      ((fact[N] * factorialNumInverse[R]) % p * factorialNumInverse[N - R]) % p;
  return ans;
}
vector<long long int> KMP(string &s) {
  long long int n = (long long int)s.length();
  vector<long long int> pi(n, 0);
  for (long long int i = 1; i < n; i++) {
    long long int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
long long int sz(vector<long long int> &v) { return (long long int)v.size(); }
long long int sz(string &s) { return (long long int)s.size(); }
void input() {}
void read(vector<long long int> &arr) {
  for (long long int i = 0; i < (long long int)arr.size(); i++) cin >> arr[i];
}
long long int testcases() {
  long long int testcase = 1;
  cin >> testcase;
  return testcase;
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  long long int x, y, c, d;
  cin >> x >> y >> c >> d;
  x--;
  y--;
  c--;
  d--;
  long long int f = 0;
  long long int ans = 0;
  long long int dr = 1, dc = 1;
  while (1) {
    if (x == c || y == d) {
      break;
    }
    if (x == -1 || x == n) {
      ans--;
      y -= dc;
      x -= dr;
      dr = -dr;
    } else if (y == -1 || y == m) {
      ans--;
      x -= dr;
      y -= dc;
      dc = -dc;
    } else {
      x += dr;
      y += dc;
      ans++;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  input();
  setdecimals(5);
  long long int t, i;
  t = testcases();
  i = 1;
  while (i <= t) {
    solve();
    i++;
  }
  return 0;
}
