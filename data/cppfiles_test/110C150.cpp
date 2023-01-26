#include <bits/stdc++.h>
using namespace std;
int expo(int x, int y) {
  int res = 1;
  while (y) {
    if (y % 2) res = (res * x % 1000000007) % 1000000007;
    x = (x * x) % 1000000007;
    y /= 2;
  }
  return res;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long nextPrime(long long N) {
  if (N <= 1) return 2;
  long long prime = N;
  bool found = false;
  while (!found) {
    prime++;
    if (isPrime(prime)) found = true;
  }
  return prime;
}
long long cl(long long n, long long d) { return (n + d - 1) / d; }
long long binToDec(string s) { return bitset<64>(s).to_ullong(); }
string decToBin(long long a) { return bitset<64>(a).to_string(); }
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / (gcd(a, b)); }
void print(pair<long long, long long> a) {
  cout << a.first << ' ' << a.second;
  cout << endl;
  ;
}
void print(long long a) {
  cout << a;
  cout << endl;
}
void print(std::vector<long long> a) {
  for (auto i : a) cout << i << ' ';
  cout << endl;
  ;
}
void print(string s) {
  cout << s;
  cout << endl;
  ;
}
void printr(std::vector<long long> a, long long start, long long end) {
  for (long long i = start; i < end; i++) cout << a[i] << ' ';
  cout << endl;
  ;
}
void print(long long a, long long b) { cout << a << ' ' << b; }
void amax(long long &a, long long b) { a = max(a, b); }
void amin(long long &a, long long b) { a = min(a, b); }
long long madd(long long a, long long b) {
  return ((a % 1000000007) + (b % 1000000007)) % 1000000007;
}
long long mmul(long long a, long long b) {
  return ((a % 1000000007) * (b % 1000000007)) % 1000000007;
}
long long msub(long long a, long long b) {
  return ((a % 1000000007) - (b % 1000000007) + 1000000007) % 1000000007;
}
long long fpow(long long x, long long y, long long p = 1000000007) {
  x %= p;
  long long sum = 1;
  while (y) {
    if (y & 1) sum = sum * x;
    sum %= p;
    y = y >> 1;
    x = x * x;
    x %= p;
  }
  return sum;
}
bool isPerSquare(long double a) {
  if (a < 0) return false;
  long long sr = sqrt(a);
  return (sr * sr == a);
}
bool isPalindrome(string str) {
  long long low = 0, high = long long(str.size()) - 1;
  while (low < high) {
    if (str[low] != str[high]) return false;
    low++, high--;
  }
  return true;
}
vector<set<long long> > indegree, out;
void solve() {
  long long n;
  cin >> n;
  ;
  indegree.resize(n + 1);
  out.resize(n + 1);
  for (__typeof(n + 1) i = (1) - ((1) > (n + 1));
       i != (n + 1) - ((1) > (n + 1)); i += 1 - 2 * ((1) > (n + 1))) {
    indegree[i].clear();
    out[i].clear();
  }
  for (__typeof(n + 1) i = (1) - ((1) > (n + 1));
       i != (n + 1) - ((1) > (n + 1)); i += 1 - 2 * ((1) > (n + 1))) {
    long long x;
    cin >> x;
    ;
    for (__typeof(x) j = (0) - ((0) > (x)); j != (x) - ((0) > (x));
         j += 1 - 2 * ((0) > (x))) {
      long long y;
      cin >> y;
      ;
      indegree[y].insert(i);
      out[i].insert(y);
    }
  }
  set<long long> sink;
  for (long long i = 1; i <= n; i++) {
    if (long long(out[i].size()) == 0) {
      sink.insert(i);
    }
  }
  long long ans = 1, removed = 0, top;
  if (long long(sink.size())) top = *sink.begin();
  while (1) {
    if (removed == n) {
      print(ans);
      return;
    }
    if (long long(sink.size()) == 0) {
      print(-1);
      return;
    }
    sink.erase(top);
    removed++;
    for (auto j : indegree[top]) {
      out[j].erase(top);
      if (long long(out[j].size()) == 0) {
        sink.insert(j);
      }
    }
    if (removed == n) {
      print(ans);
      return;
    }
    if (long long(sink.size()) == 0) {
      print(-1);
      return;
    }
    if (sink.upper_bound(top) == sink.end()) {
      top = *sink.begin();
      ans++;
    } else {
      top = *sink.upper_bound(top);
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) solve();
}
