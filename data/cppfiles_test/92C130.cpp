#include <bits/stdc++.h>
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  std::cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
std::pair<int, int> operator+(std::pair<int, int> a, std::pair<int, int> b) {
  return {a.first + b.first, a.second + b.second};
}
std::pair<long long, long long> operator+(std::pair<long long, long long> a,
                                          std::pair<long long, long long> b) {
  return {a.first + b.first, a.second + b.second};
}
std::ostream& operator<<(std::ostream& out, std::pair<int, int> a) {
  out << a.first << " " << a.second << "\n";
  return out;
}
std::ostream& operator<<(std::ostream& out, std::pair<long long, long long> a) {
  out << a.first << " " << a.second << "\n";
  return out;
}
std::istream& operator>>(std::istream& in, std::pair<int, int>& a) {
  in >> a.first >> a.second;
  return in;
}
std::istream& operator>>(std::istream& in, std::pair<long long, long long>& a) {
  in >> a.first >> a.second;
  return in;
}
long long bpow(long long x, long long v) {
  if (v == 0) return 1 % 1000000007;
  if (v % 2 == 1) return (x * bpow(x, v - 1)) % 1000000007;
  long long r = bpow(x, v / 2);
  return (r * r) % 1000000007;
}
using namespace std;
void solve() {
  string str, s;
  cin >> str;
  vector<int> v;
  for (int i = 0; i < str.size();) {
    char ch = str[i];
    int c = 0;
    while (i < str.size() && str[i] == ch) {
      c++;
      i++;
    }
    s += ch;
    v.push_back(c);
  }
  if (s[0] == s[s.size() - 1])
    cout << str << "\n";
  else {
    if (str[0] == 'a')
      str[0] = 'b';
    else
      str[0] = 'a';
    cout << str << "\n";
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
