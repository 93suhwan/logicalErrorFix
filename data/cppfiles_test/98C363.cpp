#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &i : v) is >> i;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &p) {
  for (T x : p) os << x << " ";
  os << '\n';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &p) {
  os << "{ ";
  for (T x : p) os << x << " ";
  os << "}" << '\n';
  return os;
}
template <typename Tk, typename Tv>
ostream &operator<<(ostream &os, const map<Tk, Tv> &p) {
  os << "{ ";
  for (pair<Tk, Tv> x : p) os << x << " ";
  os << "}" << '\n';
  return os;
}
template <typename Tk, typename Tv>
ostream &operator<<(ostream &os, const pair<Tk, Tv> &p) {
  os << "{" << p.first << ',' << p.second << "}";
  return os;
}
string str;
bool bal(long long int i, long long int j) {
  long long int a, b;
  a = b = 0;
  for (long long int k = i; k <= j; k++) str[k] == 'a' ? a++ : b++;
  return (a == b);
}
void solve() {
  long long int n;
  cin >> n;
  cin >> str;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = i + 1; j < n; j++) {
      if (i < j and bal(i, j)) {
        cout << i + 1 << " " << j + 1 << '\n';
        return;
      }
    }
  }
  cout << "-1 -1\n";
}
int32_t main() {
  auto start = high_resolution_clock::now();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int tc;
  cin >> tc;
  for (long long int t = 1; t <= tc; t++) {
    solve();
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
}
