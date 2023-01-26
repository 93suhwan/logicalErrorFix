#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p) {
  return (istream >> p.first >> p.second);
}
template <typename T>
istream &operator>>(istream &istream, vector<T> &v) {
  for (auto &it : v) {
    cin >> it;
  }
  return istream;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) {
  return (ostream << p.first << " " << p.second);
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
  for (auto &it : c) {
    cout << it << " ";
  }
  return ostream;
}
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
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
template <typename T>
void swap(T *a, T *b) {
  T temp = *a;
  *a = *b;
  *b = temp;
}
bool isprime(long n) {
  if (n < 2) return false;
  if (n == 2 || n == 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long i = 6L; i <= sqrt(n); i += 6) {
    if (n % (i - 1) == 0 || n % (i + 1) == 0) return false;
  }
  return true;
}
vector<bool> seive(int n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i) is_prime[j] = false;
    }
  }
  return is_prime;
}
bool is_squre(long long n) {
  if ((sqrt(n) * sqrt(n) * 1ll) == n)
    return true;
  else
    return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    string s[n - 2];
    cin >> s[0];
    string ans = "";
    ans += s[0][0];
    bool flag = false;
    for (int i = 1; i < n - 2; i++) {
      cin >> s[i];
      if (s[i][0] == s[i - 1][1])
        ans += s[i][0];
      else {
        ans += s[i - 1][1];
        ans += s[i][0];
        flag = true;
      }
    }
    ans += s[n - 3][1];
    if (flag)
      cout << ans << "\n";
    else
      cout << ans << "a"
           << "\n";
  }
  return 0;
}
