#include <bits/stdc++.h>
using namespace std;
long long int MOD = 1e9 + 7, MOD1 = 998244353;
void _print(long long int t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long int t) { cerr << t; }
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
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int sum = 0;
void check(const vector<long long int> &v) {
  long long int s = sum, op = sum;
  long long int d, a;
  cin >> d >> a;
  long long int idx = lower_bound(v.begin(), v.end(), d) - v.begin();
  if (idx == 0) {
    long long int take = v[idx];
    s = s - take;
    long long int ans = 0;
    if (take < d) {
      ans += d - take;
    }
    if (s < a) {
      ans += a - s;
    }
    cout << ans << "\n";
    return;
  } else if (idx == v.size()) {
    long long int take = v[idx - 1];
    s = s - take;
    long long int ans = 0;
    if (take < d) {
      ans += d - take;
    }
    if (s < a) {
      ans += a - s;
    }
    cout << ans << "\n";
    return;
  } else {
    long long int ans1 = 0, ans2 = 0;
    long long int first = idx - 1;
    long long int second = idx;
    long long int take = v[first];
    s = s - take;
    if (take < d) {
      ans1 += d - take;
    }
    if (s < a) {
      ans1 += a - s;
    }
    take = v[second];
    op = op - take;
    if (take < d) {
      ans2 += d - take;
    }
    if (op < a) {
      ans2 += a - op;
    }
    cout << min(ans1, ans2) << "\n";
    return;
  }
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  sort((v).begin(), (v).end());
  long long int m;
  cin >> m;
  while (m--) {
    check(v);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1, i = 1;
  while (t--) {
    solve();
  }
}
