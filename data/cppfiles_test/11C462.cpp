#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const ll mod = 1e9 + 7;
char gl;
bool comp(string a, string b) {
  ll cnt1 = 0, cnt2 = 0;
  ll n = a.length(), m = b.length();
  for (auto i : a) {
    if (i == gl) {
      cnt1++;
    }
  }
  cnt1 = cnt1 - (n - cnt1);
  for (auto i : b) {
    if (i == gl) {
      cnt2++;
    }
  }
  cnt2 = cnt2 - (m - cnt2);
  if (cnt1 != cnt2) {
    return cnt1 > cnt2;
  }
  return a.length() < b.length();
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<string> v(n);
    map<char, ll> m;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      for (auto j : v[i]) {
        m[j]++;
      }
    }
    ll ans = 0;
    for (char c = 'a'; c <= 'e'; c++) {
      gl = c;
      sort(v.begin(), v.end(), comp);
      ll cur = 0;
      ll cnt = 0;
      ll rem = 0;
      ll ovr = 0;
      for (int i = 0; i < v.size(); i++) {
        ll cnt = 0;
        for (auto j : v[i]) {
          if (j == gl) {
            cnt++;
          }
        }
        rem += v[i].length() - cnt;
        ovr += cnt;
        if (ovr > rem) {
          cur++;
        } else {
          break;
        }
      }
      ans = max(ans, cur);
    }
    cout << ans << '\n';
  }
  return 0;
}
