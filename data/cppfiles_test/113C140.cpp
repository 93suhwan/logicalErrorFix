#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  if (a % b) return gcd(b, a % b);
  return b;
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
vector<string> tokenizer(string str, char ch) {
  std::istringstream var((str));
  vector<string> v;
  string t;
  while (getline((var), t, (ch))) {
    v.push_back(t);
  }
  return v;
}
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << "\n";
  err(++it, args...);
}
void solve() {
  string s1, s2;
  long long int p1, p2;
  cin >> s1 >> p1 >> s2 >> p2;
  if (s1.size() + p1 > s2.size() + p2) {
    cout << ">\n";
  } else if (s1.size() + p1 < s2.size() + p2) {
    cout << "<\n";
  } else {
    if (s1.size() < s2.size()) {
      while (s1.size() != s2.size()) s1 += "0";
    } else {
      while (s1.size() != s2.size()) s2 += "0";
    }
    if (s1 > s2) {
      cout << ">\n";
    } else if (s1 < s2) {
      cout << "<\n";
    } else {
      cout << "=\n";
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
