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
int row[] = {-1, 0, 1, 0};
int col[] = {0, 1, 0, -1};
int mod = 1e9 + 7;
int mod1 = 998244353;
const long long int ninf = -1 * 1e18;
const long long int pinf = 1e18;
void solveTestCase() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int ansX = 1, ansY = 1;
  int x = 0, nx = 0, y = 0, ny = 0;
  int cntx = 0, cnty = 0;
  for (int i = 0; i < int(s.size()); i++) {
    if (s[i] == 'R')
      cntx++;
    else if (s[i] == 'L')
      cntx--;
    else if (s[i] == 'U')
      cnty++;
    else
      cnty--;
    if (cnty < 0) ny = max(ny, abs(cnty));
    if (cnty > 0) y = max(y, cnty);
    if (cntx < 0) nx = max(nx, abs(cntx));
    if (cntx > 0) x = max(x, cntx);
    if ((x + nx + 1) <= m && (y + ny + 1) <= n) {
      ansX = y + 1;
      ansY = nx + 1;
    } else
      break;
  }
  cout << ansX << " " << ansY << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(9);
  cout << fixed;
  int testcases;
  cin >> testcases;
  while (testcases--) solveTestCase();
  return 0;
}
