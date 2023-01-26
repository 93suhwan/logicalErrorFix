#include <bits/stdc++.h>
using std::abs;
using std::array;
using std::cerr;
using std::cin;
using std::cout;
using std::generate;
using std::get;
using std::make_pair;
using std::make_tuple;
using std::map;
using std::max;
using std::max_element;
using std::min;
using std::min_element;
using std::pair;
using std::queue;
using std::reverse;
using std::set;
using std::sort;
using std::string;
using std::swap;
using std::tuple;
using std::unique;
using std::vector;
template <typename T>
T input() {
  T res;
  cin >> res;
  {};
  return res;
}
template <typename IT>
void input_seq(IT b, IT e) {
  std::generate(b, e,
                input<typename std::remove_reference<decltype(*b)>::type>);
}
const int mod = 998244353;
string toString(__int128_t num) {
  if (not num) return "0";
  string res;
  while (num) {
    res += char('0' + num % 10);
    num /= 10;
  }
  std::reverse(res.begin(), res.end());
  return res;
}
void solve(vector<int> variables, int base, __int128_t& ans) {
  int cur, until;
  vector<int> rem1, rem2;
  std::function<void(int)> brute = [&](int pos) {
    if (pos == until) {
      rem1.push_back(cur);
      return;
    }
    auto oldcur = cur;
    for (int t = 0; t < 10; ++t) {
      brute(pos + 1);
      cur += variables[pos];
      if (cur >= mod) cur -= mod;
    }
    cur = oldcur;
  };
  cur = base;
  until = int((variables).size()) / 2;
  brute(0);
  rem2 = std::move(rem1);
  cur = 0;
  until = int((variables).size());
  brute(int((variables).size()) / 2);
  sort(rem1.begin(), rem1.end());
  sort(rem2.begin(), rem2.end());
  int64_t totalrsum = 0;
  for (int b : rem2) totalrsum += b;
  int j = int((rem2).size()) - 1;
  for (int a : rem1) {
    while (j >= 0 and a + rem2[j] >= mod) --j;
    ans += a * int64_t(int((rem2).size())) + totalrsum -
           (int((rem2).size()) - 1 - j) * int64_t(mod);
  }
}
int64_t pw10[17];
int64_t count_with_prefix(const string& s, int64_t n, const string& n_str) {
  int64_t ans = 0;
  int64_t s_val = 0;
  for (char ch : s) s_val = 10 * s_val + ch - '0';
  for (int len = int((s).size()); len <= int((n_str).size()); ++len) {
    if (len < int((n_str).size()))
      ans += pw10[len - int((s).size())];
    else {
      int t = strncmp(s.c_str(), n_str.c_str(), int((s).size()));
      if (t < 0)
        ans += pw10[len - int((s).size())];
      else if (t == 0) {
        ans += (n + 1) - s_val * pw10[int((n_str).size()) - int((s).size())];
      }
    }
  }
  return ans;
}
int main() {
  std::iostream::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int64_t n = input<int64_t>();
  string n_str;
  for (int64_t t = n; t; t /= 10) n_str += char('0' + t % 10);
  std::reverse(n_str.begin(), n_str.end());
  pw10[0] = 1;
  for (int i = 1; i < 17; ++i) pw10[i] = 10 * pw10[i - 1];
  __int128_t ans = 0;
  for (int len = 1; len <= int((n_str).size()); ++len) {
    int64_t cur = 0;
    string curst;
    for (int firstdiff = 0; firstdiff < int((n_str).size()) and firstdiff < len;
         ++firstdiff) {
      if (firstdiff) {
        cur = 10 * cur + (n_str[firstdiff - 1] - '0');
        curst += n_str[firstdiff - 1];
      }
      for (int lastdig = 0; lastdig <= 9; ++lastdig) {
        if (firstdiff == 0 and lastdig == 0) continue;
        if (lastdig == n_str[firstdiff] - '0') continue;
        if (len == int((n_str).size()) and lastdig > n_str[firstdiff] - '0')
          continue;
        auto curp = 10 * cur + lastdig;
        auto curstp = curst + char('0' + lastdig);
        int64_t base = 0;
        string tmp = "";
        for (int pos = 0; pos < int((curstp).size()); ++pos) {
          for (char dig = (pos == 0 ? '1' : '0'); dig < curstp[pos]; ++dig)
            base += count_with_prefix(tmp + dig, n, n_str);
          tmp += curstp[pos];
        }
        base += len - 1;
        vector<int> variables;
        for (int pos = int((curstp).size()); pos < len; ++pos) {
          variables.push_back(count_with_prefix(tmp + '0', n, n_str) % mod);
          tmp += '0';
        }
        base += 1;
        base -= curp * pw10[len - int((curstp).size())];
        for (int t = 0; t < int((variables).size()); ++t)
          variables[int((variables).size()) - 1 - t] -= pw10[t] % mod;
        base %= mod;
        if (base < 0) base += mod;
        for (int& val : variables) {
          val %= mod;
          if (val < 0) val += mod;
        }
        solve(variables, base, ans);
      }
    }
  }
  int64_t cur = 0;
  string curst;
  for (int len = 1; len <= int((n_str).size()); ++len) {
    curst += n_str[len - 1];
    cur = 10 * cur + (n_str[len - 1] - '0');
    int64_t val = 1;
    string tmp = "";
    for (int pos = 0; pos < int((curst).size()); ++pos) {
      for (char dig = (pos == 0 ? '1' : '0'); dig < curst[pos]; ++dig)
        val += count_with_prefix(tmp + dig, n, n_str);
      tmp += curst[pos];
    }
    val += len - 1;
    val -= cur;
    val %= mod;
    if (val < 0) val += mod;
    ans += val;
  }
  ans %= (1000 * 1000 * 1000 + 7);
  cout << toString(ans) << "\n";
  return 0;
}
