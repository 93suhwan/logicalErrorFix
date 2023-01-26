#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
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
long long n = 0;
const long long mod = 1e9 + 7;
long long tt = 0;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long x, long long y, long long m) {
  if (y == 0) return 1;
  if (y == 1) return x;
  long long cur = power(x, y / 2, m);
  cur = (cur % m * cur % m);
  if ((y & 1)) cur = (cur % m * x % m) % m;
  return cur;
}
long long modinv(long long x, long long m) { return power(x, m - 2, m) % m; }
void pre_solve() {}
void sol(long long tc) {
  stack<pair<char, bool> > st;
  string s, t;
  cin >> s >> t;
  long long j = 0;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] != t[j]) {
      if (st.size() == 0)
        continue;
      else if (st.top().second && st.size() == 1 && st.top().first == s[i])
        continue;
      else if (st.top().second)
        st.push(make_pair(s[i], 0));
      else
        st.pop();
    } else {
      if (st.size() && st.top().second == 0)
        st.pop();
      else
        st.push(make_pair(s[i], 1)), j++;
    }
    if (j == t.size()) {
      if (((long long)s.size() - i - 1) & 1) {
        cout << "NO\n";
        return;
      }
      break;
    }
  }
  string k;
  while (st.size()) {
    if (st.top().second == 0) {
      cout << "NO\n";
      return;
    }
    k.push_back(st.top().first);
    st.pop();
  }
  reverse(k.begin(), k.end());
  ;
  ;
  if (k == t)
    cout << "YES\n";
  else
    cout << "NO\n";
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    tt++;
    sol(tc);
  }
  return 0;
}
