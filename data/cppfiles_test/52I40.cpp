#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
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
void _print(unordered_set<T> v) {
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
template <class T, class V>
void _print(unordered_map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
const long long MOD = 1e9 + 7;
long long power(long long x, unsigned long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % MOD;
    y = y >> 1;
    x = (x * x) % MOD;
  }
  return res;
}
vector<long long> a;
set<long long> S;
long long n, k;
long long getSum(long long i) {
  long long sum = power(n, i);
  sum = (sum - 1ll + MOD) / MOD;
  long long D = power(n - 1ll, MOD - 2);
  return (sum * D) % MOD;
}
long long getClosest(long long x) {
  long long low = 0, high = 39;
  long long ans = 0;
  while (low <= high) {
    long long mid = (low + high) / 2;
    if (a[mid] <= x) {
      ans = mid;
      low = mid + 1;
    } else
      high = mid - 1;
  }
  return ans;
}
void solveTestCases() {
  cin >> n >> k;
  long long ans = 0ll;
  while (k) {
    long long X = getClosest(k);
    if (k == a[X]) {
      ans += getSum(a[X]);
      ans %= MOD;
      k -= a[X];
    } else {
      k -= (a[X] + 1);
      ans += power(n, X + 1);
      ans %= MOD;
    }
  }
  cout << ans << endl;
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  a.resize((long long)40);
  a[0] = 1ll;
  for (long long i = 1; i < a.size(); i++) a[i] = 2 * a[i - 1] + 1;
  for (auto it : a) S.insert(it);
  long long TESTCASES;
  cin >> TESTCASES;
  while (TESTCASES--) solveTestCases();
  return 0;
}
