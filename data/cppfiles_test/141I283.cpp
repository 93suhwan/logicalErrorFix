#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VL = vector<LL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
void dout() { cerr << endl; }
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
  cerr << H << ' ';
  dout(T...);
}
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
LL rand(LL l, LL r) { return uniform_int_distribution<LL>(l, r)(rnd); }
pair<bool, string> rec(string a, string sum) {
  if (a.empty() && sum.empty()) return {true, ""};
  if (a.empty()) return {true, sum};
  if (a.back() <= sum.back()) {
    string aa = a;
    aa.pop_back();
    string sums = sum;
    sums.pop_back();
    auto [ok, ans] = rec(aa, sums);
    if (ok) {
      ans += (sum.back() - a.back() + '0');
      return {true, ans};
    }
    if ((int)sum.size() > (int)a.size()) {
      int dig = (sum[(int)sum.size() - 2] - '0') * 10 + sum.back() - '0';
      int res = dig - (a.back() - '0');
      if (res < 10) {
        sums.pop_back();
        auto [ok1, ans1] = rec(aa, sums);
        if (ok1) {
          ans += to_string(res);
          return {true, ans};
        }
      }
    }
    return {false, ""};
  } else if ((int)sum.size() > (int)a.size()) {
    int dig =
        (sum[(int)sum.size() - 2] - '0') * 10 + sum[(int)sum.size() - 1] - '0';
    int res = dig - (a[(int)a.size() - 1] - '0');
    if (res > 9) return {false, ""};
    string aa = a;
    aa.pop_back();
    string sums = sum;
    sums.pop_back();
    sums.pop_back();
    auto [ok, ans] = rec(aa, sums);
    if (!ok) return {false, ""};
    return {true, ans + to_string(res)};
  }
  return {false, ""};
}
void solve() {
  LL a, s;
  cin >> a >> s;
  auto [ok, ans] = rec(to_string(a), to_string(s));
  cout << (ok ? stoll(ans.c_str()) : -1) << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
