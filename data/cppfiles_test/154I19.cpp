#include <bits/stdc++.h>
using namespace std;
bool debug_cerr = 1;
void dbg_out() {
  if (!debug_cerr) {
  } else
    cerr << endl;
}
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  if (!debug_cerr) {
  } else
    cerr << H << ",";
  dbg_out(T...);
}
template <class A, class B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
  return os << '(' << p.first << "," << p.second << ')';
}
template <typename T>
ostream& operator<<(ostream& stream, const vector<T>& obj) {
  stream << "[";
  for (auto x : obj) stream << x << ",";
  stream << "]" << ((obj.size() > 3) ? "\n" : "");
  return stream;
}
template <typename T, size_t N>
ostream& operator<<(ostream& stream, const array<T, N>& obj) {
  stream << "[";
  for (auto x : obj) stream << x << ",";
  stream << "]" << ((N > 3) ? "\n" : "");
  return stream;
}
template <typename T>
void printarr(T arr[], int n) {
  if (!debug_cerr) {
  } else
    cerr << "Array ";
  for (int i = 0; i < n; i++) {
    if (!debug_cerr) {
    } else
      cerr << arr[i] << " ";
  }
  if (!debug_cerr) {
  } else
    cerr << endl;
}
template <typename T>
void printarr(T arr) {
  if (!debug_cerr) {
  } else
    cerr << ">>";
  for (auto it = arr.begin(); it != arr.end(); it++) {
    if (!debug_cerr) {
    } else
      cerr << *it << " ";
  }
  if (!debug_cerr) {
  } else
    cerr << endl;
}
const long long mod = 1000000007;
int main() {
  long long test, ti, i, j, k, n, m, q;
  cin >> test;
  for (ti = 1; ti <= test; ti++) {
    vector<long long> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    bool suc = false;
    if (v[2] == v[0] + v[1]) {
      suc = true;
    } else if (v[2] == v[1] && v[0] % 2 == 0) {
      suc = true;
    }
    cout << (suc ? "YES" : "NO") << "\n";
  }
  return 0;
}
