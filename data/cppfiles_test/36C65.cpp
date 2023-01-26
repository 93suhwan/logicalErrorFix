#include <bits/stdc++.h>
using namespace std;
template <typename T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (auto myval : v) cerr << myval << " ";
  cerr << "]";
}
template <typename T1, typename T2>
void _print(vector<T1, T2> v) {
  cerr << "[ ";
  for (auto myval : v) cerr << myval.first << " " << myval.second << " ";
  cerr << "]";
}
template <typename T>
void _print(set<T> v) {
  cerr << "[ ";
  for (auto myval : v) cerr << myval << " ";
  cerr << "]";
}
template <typename T1, typename T2>
void _print(map<T1, T2> v) {
  cerr << "[ ";
  for (auto myval : v) cerr << myval.first << " " << myval.second << " ";
  cerr << "]";
}
void _print(int a) { cerr << a; }
void _print(long long a) { cerr << a; }
void _print(unsigned long long a) { cerr << a; }
void _print(char a) { cerr << a; }
void _print(string a) { cerr << a; }
void _print(double a) { cerr << a; }
void _print(long double a) { cerr << a; }
template <typename A>
A MIN(A a, A b) {
  if (a < b) return a;
  return b;
}
template <typename A>
A MAX(A a, A b) {
  if (a > b) return a;
  return b;
}
template <typename A>
A gcd(A a, A b) {
  while (b) a %= b, swap(a, b);
  return a;
}
template <typename T>
T ABS(T a) {
  return (a < 0) ? (-a) : (a);
}
bool is_prime(long long a) {
  for (long long i = 2; i * i <= a; ++i) {
    if (a % i == 0) {
      return false;
    }
  }
  return true;
}
void solve() {
  long long n, sum{0};
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  sum = accumulate(begin(v), end(v), 0LL);
  if (!is_prime(sum)) {
    cout << n << "\n";
    for (int i = 0; i < n; ++i) {
      cout << i + 1 << " ";
    }
    return;
  }
  cout << n - 1 << "\n";
  long long index = -1;
  for (int i = 0; i < n; ++i) {
    if (!is_prime(sum - v[i])) {
      index = i;
      break;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i != index) cout << i + 1 << " ";
  }
}
int main() {
  cout << fixed << setprecision(0);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
