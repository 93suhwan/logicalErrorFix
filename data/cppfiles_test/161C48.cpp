#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
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
vector<long long> sieve(int n) {
  int* arr = new int[n + 1]();
  vector<long long> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
set<pair<int, int>> s;
vector<pair<pair<int, int>, int>> ans;
void solve(int ttc) {
  int n;
  cin >> n;
  s.clear();
  ans.clear();
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    s.insert(make_pair(l, r));
  }
  for (auto it : s) {
    int l = it.first;
    int r = it.second;
    if (l == r) {
      ans.push_back(make_pair(make_pair(l, r), l));
      continue;
    }
    for (int i = l; i <= r; i++) {
      pair<int, int> range1, range2;
      bool f1, f2;
      if (l <= i - 1) {
        range1 = make_pair(l, i - 1);
        f1 = false;
      } else {
        f1 = true;
      }
      if (i + 1 <= r) {
        range2 = make_pair(i + 1, r);
        f2 = false;
      } else {
        f2 = true;
      }
      if (s.find(range1) != s.end()) {
        f1 = true;
      }
      if (s.find(range2) != s.end()) {
        f2 = true;
      }
      if (f1 and f2) {
        ans.push_back(make_pair(make_pair(l, r), i));
      }
    }
  }
  for (auto it : ans) {
    cout << it.first.first << " " << it.first.second << ' ' << it.second
         << "\n";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int ttc = 1;
  cin >> ttc;
  for (int i = 1; i <= ttc; i++) {
    solve(i);
  }
  return 0;
}
