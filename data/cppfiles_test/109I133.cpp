#include <bits/stdc++.h>
using namespace std;
long long a;
long long count;
bool check = true;
template <class val>
char so(val a) {
  if (a == 'a')
    a = 'b';
  else if (a == 'b')
    a = 'c';
  else
    a = 'a';
  return a;
}
template <class val>
inline long long gcd(val a, val b) {
  return gcd(b, a % b);
}
template <class val>
inline long long lcm(val a, val b) {
  return a / gcd(a, b) * b;
}
long long f[int(1e7)];
map<long long, long long> mp;
void solve() {
  long long a, b, c, n;
  string s;
  cin >> n;
  cin.ignore();
  cin >> s;
  long long sum = 0;
  for (int i = 0; i < s.size(); i++) {
    sum += (s[i] - '0' + 1);
    if (s[i] == s[s.size() - 1]) sum--;
  }
  cout << sum << "\n";
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long a, b, c, g, da, db;
  long long arr[26] = {0, 0};
  vector<char> left, right;
  set<string> st;
  cin >> a;
  while (a--) {
    solve();
  }
}
