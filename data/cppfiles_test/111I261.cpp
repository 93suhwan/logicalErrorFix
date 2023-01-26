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
void _print(deque<T> v);
template <class T>
void _print(unordered_set<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(unordered_map<T, V> v);
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
void _print(deque<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(unordered_set<T> v) {
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
template <class T, class V>
void _print(unordered_map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
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
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
long long gcd(long long a, long long b) { return a == 0 ? b : gcd(b % a, a); }
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
long long countDigit(long long n) { return floor(log10(n) + 1); }
bool revsort(long long a, long long b) { return a > b; }
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}
void split(string str, char regex, vector<string> &v) {
  string word = "";
  for (auto x : str) {
    if (x == regex) {
      v.push_back(word);
      word = "";
    } else {
      word = word + x;
    }
  }
  v.push_back(word);
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cout << "()";
    }
    if (n == 1) {
      cout << "\n";
      continue;
    }
    cout << "\n";
    for (int i = 2; i < n; i++) {
      string str;
      for (int j = 1; j <= (n / 2); j++) {
        str += "(())";
      }
      if (n % 2 == 0) {
        str += "";
      } else {
        str += "()";
      }
      cout << str << "\n";
    }
    for (int i = 1; i <= n; i++) {
      cout << "(";
    }
    for (int i = 1; i <= n; i++) {
      cout << ")";
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  auto start1 = high_resolution_clock::now();
  solve();
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
  return 0;
}
