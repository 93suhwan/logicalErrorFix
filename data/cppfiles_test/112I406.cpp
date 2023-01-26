#include <bits/stdc++.h>
using namespace std;
long long getGcd(long long a, long long b) {
  if (a == 0) return b;
  return getGcd(b % a, a);
}
long long getLcm(long long a, long long b) { return (a / getGcd(a, b)) * b; }
void rec(vector<string>& ans, string curr, int op, int n) {
  if (ans.size() >= n) return;
  if (curr.size() == 2 * n) {
    ans.push_back(curr);
    return;
  }
  if (op == n) {
    rec(ans, curr + ")", op, n);
    return;
  } else {
    int cl = curr.size() - op;
    rec(ans, curr + "(", op + 1, n);
    if (op > cl) {
      rec(ans, curr + ")", op, n);
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    vector<int> a(3, 0);
    int m;
    cin >> a[0] >> a[1] >> a[2] >> m;
    sort(a.begin(), a.end());
    int maxans = a[0] + a[1] + a[2] - 3;
    int minans = abs(a[0] - (a[2] - a[1])) - 1;
    if (m >= minans && m <= maxans) {
      cout << "YES\n";
    } else
      cout << "NO\n";
  }
}
