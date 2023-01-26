#include <bits/stdc++.h>
using namespace std;
long long good_rand() { return rand() * RAND_MAX + rand(); }
long long high_rand() {
  long long ran = rand() * RAND_MAX;
  ran *= RAND_MAX;
  ran += rand() * RAND_MAX + rand();
  return ran;
}
template <class A>
class myvector : public std::vector<A> {
 public:
  A &operator[](int pos) {
    if (pos < 0) pos = 0;
    while (this->size() <= pos) {
      this->push_back({});
    }
    return std::vector<A>::operator[](pos);
  }
  void print(bool b = false) {
    unsigned int si = this->size();
    if (b) std::cout << si << std::endl;
    for (unsigned int i = 0; i < si; ++i) {
      std::cout << this->operator[](i) << " ";
    }
  }
  void printendl(bool b = false) {
    print(b);
    std::cout << std::endl;
  }
  void good_random_shuffle() {
    unsigned int si = this->size();
    for (unsigned int i = 0; i < si - 1; ++i) {
      unsigned int j = good_rand() % (si - i);
      j += i;
      swap(this->operator[](i), this->operator[](j));
    }
  }
  template <class B>
  void read(B &n, bool b = false) {
    if (b) std::cin >> n;
    for (int i = 0; i < n; ++i) {
      std::cin >> this->operator[](i);
    }
  }
  void push_to(int pos, int val) {
    while (this->size() > pos) {
      int newval = this->operator[](pos);
      this->operator[](pos) = val;
      val = newval;
      ++pos;
    }
    this->operator[](pos) = val;
  }
};
template <class A>
class myqueue : public std::queue<A> {
 public:
  A front() const {
    if (this->empty()) return {};
    return std::queue<A>::front();
  }
  A top() const { return front(); }
  void pop() {
    if (this->empty()) return;
    std::queue<A>::pop();
  }
  A take() {
    A a = this->front();
    this->pop();
    return a;
  }
  void print(bool b = false) {
    while (!this->empty()) {
      std::cout << take() << " ";
    }
  }
  void printendl(bool b = false) {
    print(b);
    std::cout << std::endl;
  }
};
template <class A, class B = std::less<typename std::vector<A>::value_type>>
class mypriority_queue : public std::priority_queue<A, std::vector<A>, B> {
 public:
  A top() const {
    if (this->empty()) return {};
    return std::priority_queue<A, std::vector<A>, B>::top();
  }
  void pop() {
    if (this->empty()) return;
    std::priority_queue<A, std::vector<A>, B>::pop();
  }
  A take() {
    A a = this->top();
    this->pop();
    return a;
  }
  void print(bool b = false) {
    while (!this->empty()) {
      std::cout << take() << " ";
    }
  }
  void printendl(bool b = false) {
    print(b);
    std::cout << std::endl;
  }
};
class modll {
  static const long long mod = 998244353;
  long long modvalue = 0;

 public:
  modll() { this->modvalue = 0; }
  modll(int x) { this->modvalue = x % mod; }
  modll(long long x) { this->modvalue = x % mod; }
  modll(const modll &x) { this->modvalue = x.modvalue; }
  long long getmodvalue() const { return modvalue; }
  static long long modpow(long long z, long long u) {
    if (u == 0) return 1;
    if (u == 1) return z;
    if (u % 2 == 0) {
      long long sa = modpow(z, u / 2);
      return (sa * sa) % mod;
    }
    return (z * modpow(z, u - 1)) % mod;
  }
  static modll fastpow(long long z, long long u) {
    modll a = modpow(z, u);
    return a;
  }
  static modll fact(long long z) {
    modll a = 1;
    for (long long i = 2; i <= z; ++i) {
      a *= i;
    }
    return a;
  }
  static modll choose(long long n, long long k) {
    modll a = 1;
    for (long long i = n; n - i + 1 <= k; --i) {
      modll b = i;
      a = a * b;
    }
    for (long long i = 2; i <= k; ++i) {
      modll b = i;
      a = a / b;
    }
    return a;
  }
  long long rec() const { return modll::modpow(modvalue, mod - 2); }
  modll operator+(const modll &x) const {
    modll a;
    a.modvalue = (this->modvalue + x.modvalue) % mod;
    return a;
  }
  modll operator-(const modll &x) const {
    modll a;
    a.modvalue = (mod + this->modvalue - x.modvalue) % mod;
    return a;
  }
  modll operator*(const modll &x) const {
    modll a;
    a.modvalue = (this->modvalue * x.modvalue) % mod;
    return a;
  }
  modll operator/(const modll &x) const {
    modll a;
    if (x.modvalue == 0) return a;
    a.modvalue = (this->modvalue * x.rec()) % mod;
    return a;
  }
  template <class A>
  modll operator+(A x) const {
    if (x < 0) return this->operator-(-x);
    modll a;
    a.modvalue = (this->modvalue + x % mod) % mod;
    return a;
  }
  template <class A>
  modll operator-(A x) const {
    if (x < 0) return this->operator+(-x);
    modll a;
    a.modvalue = (this->modvalue - (x % mod) + mod) % mod;
    return a;
  }
  template <class A>
  modll operator*(A x) const {
    if (x < 0) {
      long long y = x / mod;
      y *= mod;
      y = x - y;
      x = y;
    }
    x %= mod;
    modll a;
    a.modvalue = (this->modvalue * x) % mod;
    return a;
  }
  template <class A>
  modll operator/(A x) const {
    if (x < 0) {
      long long y = x / mod;
      y *= mod;
      y = x - y;
      x = y;
    }
    x %= mod;
    modll a;
    if (x == 0) return a;
    modll b = x;
    a = *this / b;
    return a;
  }
  void operator=(modll x) { this->modvalue = x.modvalue; }
  template <class A>
  void operator=(A x) {
    this->modvalue = x % mod;
  }
  bool operator==(modll x) const { return (this->modvalue == x.modvalue); }
  template <class A>
  bool operator==(A x) const {
    return (this->modvalue == x);
  }
  bool operator<(modll x) const { return (this->modvalue < x.modvalue); }
  template <class A>
  bool operator<(A x) const {
    return (this->modvalue < x);
  }
  bool operator>(modll x) const { return (this->modvalue > x.modvalue); }
  template <class A>
  bool operator>(A x) {
    return (this->modvalue > x);
  }
  bool operator<=(modll x) const { return (this->modvalue <= x.modvalue); }
  template <class A>
  bool operator<=(A x) const {
    return (this->modvalue <= x);
  }
  bool operator>=(modll x) const { return (this->modvalue >= x.modvalue); }
  template <class A>
  bool operator>=(A x) const {
    return (this->modvalue >= x);
  }
  void operator+=(const modll &x) {
    this->modvalue += x.modvalue;
    this->modvalue %= mod;
  }
  template <class A>
  void operator+=(A x) {
    if (x < 0) this->operator+=(-1 * x);
    this->modvalue += x % mod;
    if (modvalue < 0) {
      this->modvalue *= -1;
      if (modvalue % mod == 0)
        modvalue = 0;
      else
        modvalue = mod - (modvalue % mod);
    }
    this->modvalue %= mod;
  }
  void operator-=(const modll &x) {
    this->modvalue -= x.modvalue;
    while (this->modvalue < 0) this->modvalue += mod;
    this->modvalue %= mod;
  }
  template <class A>
  void operator-=(A x) {
    if (x < 0) this->operator+=(-1 * x);
    this->modvalue -= x % mod;
    if (modvalue < 0) {
      this->modvalue *= -1;
      if (modvalue % mod == 0)
        modvalue = 0;
      else
        modvalue = mod - (modvalue % mod);
    }
    this->modvalue %= mod;
  }
  void operator*=(const modll &x) {
    this->modvalue *= x.modvalue;
    this->modvalue %= mod;
  }
  template <class A>
  void operator*=(A x) {
    bool neg = false;
    if (x < 0) {
      neg = true;
      x *= -1;
    }
    this->modvalue *= x % mod;
    if (modvalue < 0) {
      this->modvalue *= -1;
      if (modvalue % mod == 0)
        modvalue = 0;
      else
        modvalue = mod - (modvalue % mod);
    }
    this->modvalue %= mod;
    if (neg) {
      this->modvalue = mod - modvalue;
      this->modvalue %= mod;
    }
  }
  void operator/=(const modll &x) {
    if (x.modvalue == 0) {
      this->modvalue = 0;
      return;
    }
    this->modvalue = this->modvalue / x.modvalue;
    this->modvalue %= mod;
  }
  template <class A>
  void operator/=(A x) {
    bool neg = false;
    if (x < 0) {
      neg = true;
      x *= -1;
    }
    modll se = x % mod;
    this->operator/=(se);
    if (modvalue < 0) {
      this->modvalue *= -1;
      if (modvalue % mod == 0)
        modvalue = 0;
      else
        modvalue = mod - (modvalue % mod);
    }
    this->modvalue %= mod;
    if (neg) {
      this->modvalue = mod - modvalue;
      this->modvalue %= mod;
    }
  }
  modll operator++() {
    modvalue++;
    if (modvalue == mod) modvalue = 0;
  }
  modll operator--() {
    modvalue--;
    if (modvalue < 0) modvalue += mod;
  }
  void print() const { std::cout << this->modvalue; }
  void printspace() const { std::cout << this->modvalue << " "; }
  void printendl() const { std::cout << this->modvalue << std::endl; }
};
string yes = "YES\n";
string no = "NO\n";
myvector<long long> w;
long long n, m, k, l, r;
mypriority_queue<long long, std::greater<long long>> pq;
myqueue<long long> q;
int main() {
  std::ios_base::sync_with_stdio(false);
  long long te = 1;
  cin >> te;
  while (te--) {
    set<long long> s;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      s.insert(i);
    }
    long long a, b, c;
    for (int i = 0; i < m; ++i) {
      cin >> a >> b >> c;
      s.erase(b);
    }
    r = (*s.begin());
    for (int i = 1; i <= n; ++i) {
      if (r != i) cout << r << " " << i << "\n";
    }
  }
}
