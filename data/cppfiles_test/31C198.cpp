#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
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
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
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
bool IsPrime(long long number) {
  if (number <= 1) return false;
  if (number == 2 || number == 3) return true;
  if (number % 2 == 0 || number % 3 == 0) return false;
  for (long long i = 5; i * i <= number; i += 2) {
    if (number % i == 0) return false;
  }
  return true;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  vector<long long> ans(n, 1);
  if (n % 2 == 0) {
    for (int i = 0; i < n; i += 2) {
      ans[i] = -arr[i + 1];
      ans[i + 1] = arr[i];
    }
    for (long long x : ans) cout << x << " ";
    cout << "\n";
  } else {
    long long sum1 = arr[1] + arr[2];
    if (sum1 == 0) {
      sum1 = arr[0] + arr[1];
      if (sum1 == 0) {
        sum1 = arr[0] + arr[2];
        ans[0] = -arr[1];
        ans[2] = -arr[1];
        ans[1] = sum1;
      } else {
        ans[0] = -arr[2];
        ans[1] = -arr[2];
        ans[2] = sum1;
      }
    } else {
      ans[0] = (sum1);
      ans[1] = -(arr[0]);
      ans[2] = -(arr[0]);
    }
    for (int i = 3; i < n; i += 2) {
      ans[i] = -arr[i + 1];
      ans[i + 1] = arr[i];
    }
    for (long long x : ans) cout << x << " ";
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
