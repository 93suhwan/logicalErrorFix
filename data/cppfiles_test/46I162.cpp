#include <bits/stdc++.h>
using namespace std;
template <typename first, typename second>
ostream &operator<<(ostream &os, const pair<first, second> &v) {
  return os << "(" << v.first << ", " << v.second << ")";
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename first, typename second>
ostream &operator<<(ostream &os, const map<first, second> &v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}
const long long MOD = 1000000007;
const long long N = 100000;
vector<long long> ever(vector<long long> &a) {
  long long num = a.back();
  long long n = a.size();
  vector<long long> res;
  for (long long i = 0; i < n; i++) {
    if (a[i] <= num) {
      res.push_back(a[i]);
    }
  }
  for (long long i = 0; i < n; i++) {
    if (a[i] > num) {
      res.push_back(a[i]);
    }
  }
  return res;
}
long long brute(vector<long long> &a) {
  long long res = 0;
  while (true) {
    vector<long long> newOne = ever(a);
    if (newOne == a) {
      break;
    }
    res++;
    a = newOne;
  }
  return res;
}
long long fast(vector<long long> &a) {
  long long n = a.size();
  long long maxi = *max_element(a.begin(), a.end());
  long long foo = a[n - 1];
  long long res = 0;
  for (long long i = n - 1; i >= 0; i--) {
    if (a[i] == maxi or foo == maxi) break;
    res++;
    foo = max(foo, a[i] + 1);
  }
  cout << res << '\n';
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << fast(a) << '\n';
  }
  return 0;
}
