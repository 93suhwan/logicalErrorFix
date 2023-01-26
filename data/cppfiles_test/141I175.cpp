#include <bits/stdc++.h>
using namespace std;
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
void intext() {}
bool isPrime(int n) {
  if (n == 1) return false;
  if (n == 2) return true;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  intext();
  long long t = 1;
  cin >> t;
  while (t--) {
    string a, s;
    cin >> a >> s;
    string ans = "";
    bool flag = 1;
    long long ptr = s.size() - 1;
    for (long long i = a.size() - 1; i >= 0; i--) {
      if (ptr < 0) {
        flag = 0;
        break;
      }
      if ((s[ptr] - '0') >= (a[i] - '0')) {
        ans.push_back((s[ptr] - a[i]) + '0');
        ptr--;
      } else if (ptr > 0 &&
                 (((s[ptr] - '0') + 10 * (s[ptr - 1] - '0')) - (a[i] - '0') <=
                  9)) {
        ans.push_back(((s[ptr] - '0') + 10 * (s[ptr - 1] - '0')) -
                      (a[i] - '0') + '0');
        ;
        ptr--;
        ptr--;
      } else {
        flag = 0;
        break;
      }
    }
    if (ptr >= 0) {
      while (ptr >= 0) {
        ans.push_back(s[ptr]);
        ptr--;
      }
    }
    if (flag) {
      reverse(ans.begin(), ans.end());
      cout << stoi(ans) << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
