#include <bits/stdc++.h>
using namespace std;
long long get_time() {
  return chrono::duration_cast<chrono::nanoseconds>(
             chrono::steady_clock::now().time_since_epoch())
      .count();
}
template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
  bool done_something = false;
  stringstream res;
  res << "[";
  for (; begin_iter != end_iter and counter; ++begin_iter) {
    done_something = true;
    counter--;
    res << *begin_iter << ", ";
  }
  string str = res.str();
  if (done_something) {
    str.pop_back();
    str.pop_back();
  }
  str += "]";
  return str;
}
template <typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T>& p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    out << v[i];
    if (i != (int)v.size() - 1) out << ", ";
  }
  out << "]";
  return out;
}
template <class TH>
void _dbg(const char* name, TH val) {
  clog << name << ": " << val << endl;
}
template <class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
  while (*names != ',') clog << *names++;
  clog << ": " << curr_val << ", ";
  _dbg(names + 1, vals...);
}
const int MAXN = 100100;
int ppp[MAXN];
int phi[MAXN];
vector<int> divisors[MAXN];
const long long mod = 1e9 + 7;
int cnt[MAXN];
long long solve(const vector<int>& a) {
  vector<int> used;
  for (int x : a) {
    for (int d : divisors[x]) {
      cnt[d] += 1;
      used.push_back(d);
    }
  }
  long long res = 0;
  for (int d : used) {
    if (cnt[d] == 0) continue;
    long long c = cnt[d];
    res += (phi[d] * c * c) % mod;
    cnt[d] = 0;
  }
  return res % mod;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int p = 2; p < MAXN; p++) {
    if (ppp[p]) continue;
    for (int d = p; d < MAXN; d += p) ppp[d] = p;
  }
  for (int n = 1; n < MAXN; n++) {
    int m = n;
    phi[n] = 1;
    while (m != 1) {
      int p = ppp[m];
      m /= p;
      phi[n] *= p - 1;
      while (m % p == 0) m /= p, phi[n] *= p;
    }
  }
  for (int d = 1; d < MAXN; d++) {
    for (int n = d; n < MAXN; n += d) divisors[n].push_back(d);
  }
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long res = 0;
  for (int d = 1; d < MAXN; d++) {
    vector<int> vec;
    for (int i = d; i <= n; i += d) vec.push_back(a[i]);
    res += phi[d] * solve(vec) % mod;
  }
  cout << res % mod << "\n";
}
