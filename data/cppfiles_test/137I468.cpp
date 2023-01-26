#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
std::string DecimalToAny(int64_t number, int64_t target) {
  std::string ans = "";
  int64_t num = number;
  for (int i = 0; i < 10; ++i) {
    if (num % target >= 10) {
      ans.push_back('A' + num % target - 10);
    } else {
      ans.push_back('0' + num % target);
    }
    num = num / target;
    if (num == 0) {
      std::reverse(ans.begin(), ans.end());
      return ans;
    }
  }
}
std::string to_binary_string(ll n) {
  std::string buffer;
  buffer.reserve(std::numeric_limits<ll>::digits);
  do {
    buffer += char('0' + n % 2);
    n = n / 2;
  } while (n > 0);
  return std::string(buffer.crbegin(), buffer.crend());
}
void solve() {
  ll x, y;
  cin >> x >> y;
  string first = to_binary_string(x), second = to_binary_string(y);
  ll finn = second.find(first);
  if (finn != std::string::npos) {
    for (int i = 0; i < finn; ++i) {
      if (second[i] != '1') {
        cout << "NO\n";
        return;
      }
    }
    for (int i = finn + first.size(); i < second.size(); ++i) {
      if (second[i] != '1') {
        cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
    return;
  }
  reverse(first.begin(), first.end());
  finn = second.find(first);
  if (finn != std::string::npos) {
    bool f = true;
    for (int i = 0; i < finn; ++i) {
      if (second[i] != '1') {
        f = false;
      }
    }
    for (int i = finn + first.size(); i < second.size(); ++i) {
      if (second[i] != '1') {
        f = false;
      }
    }
    if (f) {
      cout << "YES\n";
      return;
    }
  }
  while (first[0] == '0') {
    first.erase(0, 1);
  }
  finn = second.find(first);
  if (finn != std::string::npos) {
    bool f = true;
    for (int i = 0; i < finn; ++i) {
      if (second[i] != '1') {
        f = false;
      }
    }
    for (int i = finn + first.size(); i < second.size(); ++i) {
      if (second[i] != '1') {
        f = false;
      }
    }
    if (f) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
  return;
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll tatarinov = 1;
  while (tatarinov--) {
    solve();
  }
  return 0;
}
