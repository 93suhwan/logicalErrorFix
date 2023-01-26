#include <bits/stdc++.h>
using namespace std;
long long mod(long long x) {
  return ((x % 1000000007 + 1000000007) % 1000000007);
}
long long add(long long a, long long b) { return mod(mod(a) + mod(b)); }
long long mul(long long a, long long b) { return mod(mod(a) * mod(b)); }
template <class T>
void print(T a) {
  cerr << a;
}
template <class T, class V>
void print(pair<T, V> p);
template <class T>
void print(vector<T> v);
template <class T>
void print(set<T> v);
template <class T, class V>
void print(map<T, V> v);
template <class T>
void print(multiset<T> v);
template <class T, class V>
void print(pair<T, V> p) {
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
    cerr << ",";
  }
  cerr << "]";
}
template <class T>
void print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << ",";
  }
  cerr << "]";
}
template <class T>
void print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << ",";
  }
  cerr << "]";
}
template <class T, class V>
void print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    print(i);
    cerr << ",";
  }
  cerr << "]";
}
long long modPow(long long a, long long b) {
  if (b == 0) return 1LL;
  if (b == 1) return a % 1000000007;
  long long res = 1;
  while (b) {
    if (b % 2 == 1) res = mul(res, a);
    a = mul(a, a);
    b = b / 2;
  }
  return res;
}
const long long N = 2e5 + 2;
long long fact[N];
void precalc() {
  fact[0] = 1;
  for (long long i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
}
long long inv(long long x) { return modPow(x, 1000000007 - 2); }
long long divide(long long a, long long b) { return mul(a, inv(b)); }
long long nCr(long long n, long long r) {
  return divide(fact[n], mul(fact[r], fact[n - r]));
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  if ((s[n - 1] - '0') % 2 == 0) {
    cout << 1 << " " << n << " " << 1 << " " << n - 1 << endl;
  } else {
    string zeroOne = "";
    string oneZero = "";
    long long startzo = -1, endzo = -1;
    long long startoz = -1, endoz = -1;
    for (long long i = 0; i < n;) {
      string temp = "";
      long long start = -1;
      long long end = -1;
      while (i < n and s[i] == '0') {
        if (start == -1) start = i;
        end = i;
        temp += '0';
        i++;
      }
      while (i < n and s[i] == '1') {
        if (start == -1) start = i;
        end = i;
        temp += '1';
        i++;
      }
      if (temp.size() > zeroOne.size()) {
        zeroOne = temp;
        startzo = start;
        endzo = end;
      }
    }
    for (long long i = 0; i < n;) {
      string temp = "";
      long long start = -1;
      long long end = -1;
      while (i < n and s[i] == '1') {
        if (start == -1) start = i;
        end = i;
        temp += '1';
        i++;
      }
      while (i < n and s[i] == '0') {
        if (start == -1) start = i;
        end = i;
        temp += '0';
        i++;
      }
      if (temp.size() > oneZero.size()) {
        oneZero = temp;
        startoz = start;
        endoz = end;
      }
    }
    if (oneZero.size() >= zeroOne.size()) {
      cout << startoz + 1 << " " << endoz + 1 << " " << startoz + 1 << " "
           << endoz << endl;
    } else {
      long long count = 0;
      for (char i : zeroOne) count += (i == '1') ? 1 : 0;
      if (count % 2) zeroOne.pop_back();
      long long needed = count / 2;
      long long i = -1;
      for (i = startoz; i < endoz; i++) {
        if (s[i] == '1') needed--;
        if (needed == 0) break;
      }
      cout << startzo + 1 << " " << endzo + 1 << " " << startzo + 1 << " "
           << i + 1 << endl;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
