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
vector<char> order;
map<char, long long> fc, mcur;
bool valid(string &s, string &t) {
  long long j = 0;
  string chkt = "";
  string res = s;
  while (long long(s.size()) && j < long long(order.size())) {
    string temp = "";
    chkt += s;
    for (long long i = 0; i < long long(s.size()); i++) {
      if (s[i] != order[j]) temp += s[i];
    }
    s = temp;
    j++;
  }
  return chkt == t;
}
void solve() {
  string t;
  cin >> t;
  ;
  set<char> taken;
  order.clear();
  for (long long i = long long(t.size()) - 1; i >= 0; i--) {
    if (taken.find(t[i]) == taken.end()) {
      order.push_back(t[i]);
      taken.insert(t[i]);
    }
  }
  reverse((order).begin(), (order).end());
  mcur.clear(), fc.clear();
  for (auto i : t) fc[i]++, mcur[i] += 0;
  map<char, long long> pos;
  for (long long i = 0; i < order.size(); i++) {
    pos[order[i]] = i + 1;
  }
  string temps = "";
  for (long long i = 0; i < long long(t.size()); i++) {
    mcur[t[i]]++;
    temps += t[i];
    bool flag = true;
    for (auto j : mcur) {
      if (j.second * (pos[j.first]) != fc[j.first]) {
        flag = false;
        break;
      }
    }
    if (flag && valid(temps, t)) {
      cout << t.substr(0, i + 1) << " ";
      for (auto j : order) {
        cout << j;
      }
      cout << endl;
      ;
      return;
    }
  }
  print(-1);
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
