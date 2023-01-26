#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long expo(long long a, long long b, long long mod) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
void extendgcd(long long a, long long b, long long *v) {
  if (b == 0) {
    v[0] = 1;
    v[1] = 0;
    v[2] = a;
    return;
  }
  extendgcd(b, a % b, v);
  long long x = v[1];
  v[1] = v[0] - v[1] * (a / b);
  v[0] = x;
  return;
}
long long mminv(long long a, long long b) {
  long long arr[3];
  extendgcd(a, b, arr);
  return arr[0];
}
long long mminvprime(long long a, long long b) { return expo(a, b - 2, b); }
bool revsort(long long a, long long b) { return a > b; }
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}
long long combination(long long n, long long r, long long m, long long *fact,
                      long long *ifact) {
  long long val1 = fact[n];
  long long val2 = ifact[n - r];
  long long val3 = ifact[r];
  return (((val1 * val2) % m) * val3) % m;
}
void google(int t) { cout << "Case #" << t << ": "; }
vector<long long> sieve(int n) {
  int *arr = new int[n + 1]();
  vector<long long> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long mod_div(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
long long phin(long long n) {
  long long number = n;
  if (n % 2 == 0) {
    number /= 2;
    while (n % 2 == 0) n /= 2;
  }
  for (long long i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      number = (number / i * (i - 1));
    }
  }
  if (n > 1) number = (number / n * (n - 1));
  return number;
}
int cmp(int a, int b) { return a > b; }
int bin_pow(int ind, int power) {
  if (power == 0) {
    return 1;
  }
  if (power & 1) {
    return ind * bin_pow(ind, power - 1) % 1000000007;
  } else {
    return bin_pow((ind * ind) % 1000000007, power / 2) % 1000000007;
  }
}
long long maxsubarraysum(long long *array, long long n) {
  long long best = 0, sum = 0;
  for (long long k = 0; k < n; k++) {
    sum = max(array[k], sum + array[k]);
    best = max(best, sum);
  }
  return best;
}
void printBinary(int num) {
  for (int i = 10; i >= 0; --i) {
    cout << ((num >> i) & 1);
  }
  cout << "\n";
}
int computeXOR(int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}
string toBinary(long long x) {
  if (x == 0)
    return "";
  else {
    string s = toBinary(x / 2);
    s.push_back(char('0' + x % 2));
    return s;
  }
}
class DSU {
 private:
  vector<int> parent, size;
  DSU(int n) {
    for (int i = 1; i <= n; i++) {
      parent.push_back(i);
      size.push_back(1);
    }
  }

 public:
  int findPar(int node) {
    if (parent[node] == node) return node;
    return parent[node] = findPar(parent[node]);
  }

 public:
  void unionOfNodes(int u, int v) {
    int pu = findPar(u);
    int pv = findPar(v);
    if (pu == pv) {
      return;
    }
    if (size[pu] < size[pv]) {
      parent[pu] = pv;
      size[pv] += size[pu];
    } else {
      parent[pv] = pu;
      size[pu] += size[pv];
    }
  }
};
void solve() {
  int q;
  cin >> q;
  int n = 5e5 + 5;
  vector<list<int>> v(n);
  int x, y;
  for (int i = 0; i < q; i++) {
    cin >> x;
    if (x == 1) {
      cin >> x;
      v[x].push_back(i);
    } else {
      cin >> x >> y;
      v[y].splice(v[y].end(), v[x]);
      v[x].begin() = v[x].end();
    }
  }
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    for (auto j : v[i]) {
      a.push_back({j, i});
    }
  }
  sort(a.begin(), a.end());
  for (auto i : a) {
    cout << i.second << ' ';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  auto start1 = high_resolution_clock::now();
  long long tc = 1;
  while (tc--) {
    solve();
  }
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
  return 0;
}
