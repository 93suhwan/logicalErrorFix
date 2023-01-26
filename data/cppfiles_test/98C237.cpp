#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
bool prime(int x) {
  if (x == 1)
    return false;
  else if (x == 2 || x == 3)
    return true;
  for (int i = 2; i <= sqrt(x); i++)
    if (x % i == 0) return false;
  return true;
}
void show_binary(int n) {
  for (int i = 0; i < 20; ++i) {
    cout << !!(n & (1 << i));
  }
  cout << "\n";
}
int nxt() {
  int x;
  cin >> x;
  return x;
}
bool check(vector<int> &a, int n) {
  for (int i = 0; i < n; i++)
    if (a[i] == 0) return false;
  return true;
}
int find_(string &s1, char x) {
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] == x) return i;
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s1, s2;
    cin >> s1 >> s2;
    long long ans = 0;
    for (int i = 1; i < s2.size(); i++) {
      int pos1 = find_(s1, s2[i]);
      int pos2 = find_(s1, s2[i - 1]);
      ans += abs(pos1 - pos2);
    }
    cout << ans << endl;
  }
  return 0;
}
