#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
const int CONSTANT = 3e5 + 1;
bool compare(pair<int, int> &a, pair<int, int> &b) { return a.first < b.first; }
long long int gcd(long long int a, long long int b) {
  if (a < b) swap(a, b);
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    bool flag = false;
    for (int i = 0; i < n; i++) {
      if (s1[i] == '1' && s2[i] == '1') {
        flag = true;
        break;
      }
    }
    if (flag)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}
