#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
bool isPowOfTwo(int x) { return x && (!(x & (x - 1))); }
bool cmp1(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first < b.first);
}
bool cmp2(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
long long min3(long long a, long long b, long long c) {
  return min(a, min(b, c));
}
long long min4(long long a, long long b, long long c, long long d) {
  return min(a, min(b, min(b, c)));
}
long long max3(long long a, long long b, long long c) {
  return max(a, max(b, c));
}
long long max4(long long a, long long b, long long c, long long d) {
  return max(a, max(b, max(b, c)));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
      s += "()";
    }
    for (int i = 0; i < n; i++) {
      cout << s << endl;
      swap(s[i + 1], s[s.length() - i - 2]);
    }
  }
  return 0;
}
