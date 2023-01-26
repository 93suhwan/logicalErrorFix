#include <bits/stdc++.h>
using namespace std;
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
int const N = 1e9 + 7;
vector<long long> seive(1000000, 1);
vector<long long> primes;
void doSeive() {
  for (long long i = 2; i < 1000000; i++) {
    if (seive[i]) {
      primes.push_back(i);
      for (long long j = i * i; j < 1000000; j += i) {
        seive[j] = 0;
      }
    }
  }
}
long long nCr(long long n, long long r) {
  if (n < r) return 0;
  if (r > n - r) {
    r = n - r;
  }
  long long res = 1;
  for (long long i = 0; i < r; i++) {
    res *= n - i;
    res /= i + 1;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return (b % a, a);
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long> > a(n);
  for (long long i = 0; i < n; i++) {
    long long k;
    cin >> k;
    a[i].second = k;
    long long mx = INT_MIN;
    for (long long j = 0; j < k; j++) {
      long long no;
      cin >> no;
      mx = max(mx, no + 1 - j);
    }
    a[i].first = mx;
  }
  sort(a.begin(), a.end());
  long long ans = a[0].first;
  long long curr = a[0].first;
  for (long long i = 0; i < n; i++) {
    if (i + 1 < n) {
      if (curr + a[i].second < a[i + 1].first) {
        ans += (a[i + 1].first - (curr + a[i].second));
        curr = a[i + 1].first;
        continue;
      }
    }
    curr += a[i].second;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
