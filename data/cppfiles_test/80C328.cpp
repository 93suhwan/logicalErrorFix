#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(T v) {
  cout << ((int)(v).size()) << endl;
  for (auto x : v) cout << x << ' ';
  cout << endl;
};
template <class T>
void print1(T v) {
  cout << ((int)(v).size()) << endl;
  for (auto x : v) cout << x + 1 << ' ';
  cout << endl;
};
template <class T>
void printpair(T v) {
  cout << ((int)(v).size()) << endl;
  for (auto x : v) cout << '(' << v.first << ' ' << v.second << ')' << ' ';
  cout << endl;
};
template <class T1, class T2>
ostream& operator<<(ostream& o, pair<T1, T2> x) {
  return o << x.first << ' ' << x.second;
}
template <class T1, class T2>
istream& operator>>(istream& o, pair<T1, T2>& x) {
  return o >> x.first >> x.second;
}
template <class T1, class T2>
pair<T1, T2> operator+(pair<T1, T2> a, pair<T1, T2> b) {
  a.first += b.first;
  a.second += b.second;
  return a;
}
template <class T1, class T2>
pair<T1, T2> operator-(pair<T1, T2> a, pair<T1, T2> b) {
  a.first -= b.first;
  a.second -= b.second;
  return a;
}
template <class T1, class T2>
void operator+=(pair<T1, T2>& a, pair<T1, T2> b) {
  a.first += b.first;
  a.second += b.second;
}
template <class T1, class T2>
void operator-=(pair<T1, T2>& a, pair<T1, T2> b) {
  a.first -= b.first;
  a.second -= b.second;
}
template <class T>
vector<T> operator+(vector<T> a, vector<T> b) {
  a.insert(a.end(), b.begin(), b.end());
  return a;
}
const int mod = 1000000000 + 7;
void solve();
signed main() {
  {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  };
  int tc = 1;
  cin >> tc;
  for (int i = 0; i < (tc); i++) {
    solve();
  }
}
string s;
void solve() {
  int n, left_pos = -1, right_pos = -1;
  cin >> n;
  cin >> s;
  if (n % 2 == 0) {
    for (int i = 0; i < (n / 2); i++) {
      if (s[i] == '0') {
        left_pos = i;
        break;
      }
    }
    if (left_pos != -1) {
      cout << left_pos + 1 << ' ' << n << ' ' << left_pos + 2 << ' ' << n
           << endl;
      return;
    }
    for (int i = n / 2; i < n; i++) {
      if (s[i] == '0') {
        right_pos = i;
        break;
      }
    }
    if (right_pos != -1) {
      cout << 1 << ' ' << right_pos + 1 << ' ' << 1 << ' ' << right_pos << endl;
      return;
    }
    cout << 1 << ' ' << n - 1 << " " << 2 << " " << n << endl;
  } else {
    for (int i = 0; i < (n / 2 + 1); i++) {
      if (s[i] == '0') {
        left_pos = i;
        break;
      }
    }
    if (left_pos != -1) {
      cout << left_pos + 1 << ' ' << n << ' ' << left_pos + 2 << ' ' << n
           << endl;
      return;
    }
    for (int i = n / 2; i < n; i++) {
      if (s[i] == '0') {
        right_pos = i;
        break;
      }
    }
    if (right_pos != -1) {
      cout << 1 << ' ' << right_pos + 1 << ' ' << 1 << ' ' << right_pos << endl;
      return;
    }
    cout << 1 << ' ' << n - 1 << " " << 2 << " " << n << endl;
  }
}
