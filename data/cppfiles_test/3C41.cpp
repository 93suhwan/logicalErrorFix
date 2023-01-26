#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const long long INFll = 4e18;
const long long INFi = 1e9 + 63;
const double pi = acos(-1);
const int maxn = 6e5;
const int maxd = 16;
const long long mod = 998244353;
const int sqrtN = 300;
int caseNo = 1;
void E() {}
template <class A, class... B>
void E(A $, B... _) {
  cerr << ' ' << $;
  E(_...);
}
bool valid(string s) {
  if (((int)(s).size()) == 1) return true;
  bool isSmthOnPref = false;
  for (int i = 0; i < ((int)(s).size()); i++) {
    if (s[i] == '0' && !isSmthOnPref) return false;
    if (s[i] != '0') isSmthOnPref = true;
  }
  return true;
}
bool div25(string s) {
  long long val = std::stoll(s);
  return !(val % 25);
}
int tryAll(string s, char X, int ptr) {
  if (ptr == -1) {
    if (valid(s) && div25(s))
      return 1;
    else
      return 0;
  }
  if (ptr == ((int)(s).size()) - 3) {
    char last = s[((int)(s).size()) - 1];
    char predLast = s[((int)(s).size()) - 2];
    int num = (predLast - '0') * 10 + (last - '0');
    if (num % 25) return 0;
  }
  if (s[ptr] == 'X') {
    s[ptr] = X;
    return tryAll(s, X, ptr - 1);
  }
  if (s[ptr] >= '0' && s[ptr] <= '9') {
    return tryAll(s, X, ptr - 1);
  }
  assert(s[ptr] == '_');
  int res = 0;
  for (char ch = '0'; ch <= '9'; ch++) {
    s[ptr] = ch;
    res += tryAll(s, X, ptr - 1);
  }
  return res;
}
int tryAll(string s) {
  bool containsX = false;
  for (auto& it : s) {
    if (it == 'X') containsX = true;
  }
  if (!containsX) {
    return tryAll(s, '\0', ((int)(s).size()) - 1);
  }
  int res = 0;
  for (char ch = '0'; ch <= '9'; ch++) {
    res += tryAll(s, ch, ((int)(s).size()) - 1);
  }
  return res;
}
void solve() {
  string s;
  cin >> s;
  int n = ((int)(s).size());
  int res = tryAll(s);
  cout << res;
}
int main(int argc, char** argv) {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  int t = 1;
  clock_t start = clock();
  for (int i = 0; i < t; i++) solve();
  return 0;
}
