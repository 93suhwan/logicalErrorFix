#include <bits/stdc++.h>
using namespace std;
void setIO(string name = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (int((name).size())) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long mcm(long long a, long long b) { return (a * b) / gcd(a, b); }
bool prime(long long n, long long i) {
  if (i > sqrt(n)) return true;
  if (n % i == 0)
    return false;
  else
    return prime(n, i + 1);
}
struct compii {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == a.second) return a.second < b.second;
    return a.first > b.first;
  }
};
bool comp(int a, int b) { return a > b; }
namespace operators {
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& x) {
  in >> x.first >> x.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> x) {
  out << x.first << " " << x.second;
  return out;
}
template <typename T1>
istream& operator>>(istream& in, vector<T1>& x) {
  for (auto& i : x) in >> i;
  return in;
}
template <typename T1>
ostream& operator<<(ostream& out, vector<T1>& x) {
  for (auto& i : x) out << i << " ";
  return out;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, vector<pair<T1, T2>>& x) {
  for (auto& i : x) out << i.first << " " << i.second;
  return out;
}
template <typename T1, typename T2>
istream& operator>>(istream& in, vector<pair<T1, T2>>& x) {
  for (auto& i : x) in >> i.first >> i.second;
  return in;
}
}  // namespace operators
using namespace operators;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
const int mod = 1e9 + 7;
const long long inf = 1e18;
void solve() {
  string second;
  cin >> second;
  bool ok = 0;
  for (auto& x : second) {
    if (x == 'a') ok = 1;
  }
  if (!ok) {
    cout << second << endl;
    return;
  }
  if (second[0] == 'b') second[0] = 'a';
  if (second[int((second).size()) - 1] == 'b')
    second[int((second).size()) - 1] = 'a';
  cout << second << endl;
}
int main() {
  setIO("");
  int t = 1;
  cin >> t;
  while (t-- > 0) solve();
  return 0;
}
