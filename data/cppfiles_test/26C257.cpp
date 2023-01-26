#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T>
void _print(deque<T> v);
template <class T>
void _print(priority_queue<T> v);
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
template <class T, class V>
void _print(unordered_map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(deque<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(priority_queue<T> v) {
  cerr << "[ ";
  while (!v.empty()) {
    _print(v.top());
    v.pop();
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(priority_queue<T, vector<T>, greater<T>> v) {
  cerr << "[ ";
  while (!v.empty()) {
    _print(v.top());
    v.pop();
    cerr << " ";
  }
  cerr << "]";
}
bool testcase = 1;
int casenumber = 1;
bool cases = 0;
const char sp = ' ';
const char nl = '\n';
void getans() {
  long long n;
  cin >> n;
  long long nn = n;
  n *= 2;
  n--;
  long long ans = 1;
  while (n > 0) {
    ans *= n;
    ans %= mod;
    n--;
  }
  ans %= mod;
  ans *= (nn);
  ans %= mod;
  cout << ans << nl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T = 1;
  if (testcase) {
    cin >> T;
  }
  while (T--) {
    if (cases) {
      cout << "Case #" << casenumber << ": ";
      casenumber++;
    }
    getans();
  }
  return 0;
}
