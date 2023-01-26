#include <bits/stdc++.h>
using namespace std;
void _print(long long int t) { cerr << t; }
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
template <class T>
void _print(unordered_set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T, class V>
void _print(multimap<T, V> v);
template <class T, class V>
void _print(unordered_map<T, V> v);
template <class T, class V>
void _print(unordered_multimap<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T>
void _print(unordered_multiset<T> v);
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
template <class T>
void _print(unordered_multiset<T> v) {
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
void _print(multimap<T, V> v) {
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
template <class T, class V>
void _print(unordered_multimap<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <typename T>
T gcd(T a, T b) {
  if (a % b) return gcd(b, a % b);
  return b;
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
template <typename T>
void inline in(vector<T> &v, long long int n) {
  v.resize(n);
  for (long long int i = 0; i < n; i++) cin >> v[i];
}
bool inline isVowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
long long int n;
vector<long long int> a;
bool pp(long long int u, long long int c1, long long int c2, long long int c3) {
  for (int curn1 = (0); curn1 <= (c1); curn1++) {
    for (int curn2 = (0); curn2 <= (c2); curn2++) {
      if (2 * curn2 + curn1 > u) continue;
      if ((u - curn1 - 2 * curn2) % 3 != 0) continue;
      if ((u - curn1 - 2 * curn2) / 3 <= c3) return true;
    }
  }
  return false;
}
bool possible(long long int c1, long long int c2, long long int c3) {
  for (auto u : a)
    if (!pp(u, c1, c2, c3)) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(8) << fixed;
  long long int txtc;
  cin >> txtc;
  for (int tcase = 1; tcase <= txtc; tcase++) {
    cin >> n;
    in(a, n);
    long long int m = *max_element(a.begin(), a.end());
    ;
    long long int ans = 1e18;
    const long long int maxn = 2;
    for (int coins1 = (0); coins1 <= (3); coins1++) {
      for (int coins2 = (0); coins2 <= (3); coins2++) {
        long long int coins3 = max(0ll, (m - coins1 - 2 * coins2) / 3);
        if ((3 * coins3 + 2 * coins2 + coins1) < m) continue;
        if (possible(coins1, coins2, coins3)) {
          ans = min(ans, coins2 + coins1 + coins3);
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
