#include <bits/stdc++.h>
using namespace std;
void _print(char x) { cerr << x; }
void _print(int x) { cerr << x; }
void _print(long long x) { cerr << x; }
void _print(float x) { cerr << x; }
void _print(double x) { cerr << x; }
void _print(long double x) { cerr << x; }
void _print(string x) { cerr << x; }
template <typename T, typename V>
void _print(const pair<T, V>& p);
template <typename T>
void _print(const vector<T>& v);
template <typename T, typename V>
void _print(const pair<T, V>& p) {
  cerr << "{ ";
  _print(p.first);
  cerr << ", ";
  _print(p.second);
  cerr << " }";
}
template <typename T>
void _print(const vector<T>& v) {
  long long n = v.size();
  cerr << "[ ";
  for (long long i = 0; i < n; i++) {
    _print(v[i]);
    cerr << (i < n - 1 ? ", " : " ");
  }
  cerr << "]";
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(int _t) {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  vector<long long> pos, neg;
  for (long long x : a)
    if (x > 0)
      pos.push_back(x);
    else
      neg.push_back(abs(x));
  reverse(neg.begin(), neg.end());
  long long ans1 = 0;
  {
    while (!pos.empty()) {
      ans1 += 2 * pos.back();
      for (long long i = 0; i < k && !pos.empty(); i++) pos.pop_back();
    }
    bool flag = false;
    while (!neg.empty()) {
      if (flag)
        ans1 += 2 * neg.back();
      else
        ans1 += neg.back();
      for (long long i = 0; i < k && !neg.empty(); i++) neg.pop_back();
      flag = true;
    }
  }
  for (long long x : a)
    if (x > 0)
      pos.push_back(x);
    else
      neg.push_back(abs(x));
  reverse(neg.begin(), neg.end());
  long long ans2 = 0;
  {
    while (!neg.empty()) {
      ans2 += 2 * neg.back();
      for (long long i = 0; i < k && !neg.empty(); i++) neg.pop_back();
    }
    bool flag = false;
    while (!pos.empty()) {
      if (flag)
        ans2 += 2 * pos.back();
      else
        ans2 += pos.back();
      for (long long i = 0; i < k && !pos.empty(); i++) pos.pop_back();
      flag = true;
    }
  }
  std::cout << min(ans1, ans2) << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt = 1;
  cin >> tt;
  for (int i = 1; i <= tt; i++) solve(i);
  return 0;
}
