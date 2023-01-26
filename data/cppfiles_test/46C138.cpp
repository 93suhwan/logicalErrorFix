#include <bits/stdc++.h>
const long long ansmod = 1e9 + 7;
using namespace std;
long long int power(long long int x, long long int y, long long int push) {
  long long int res = 1;
  x = x % ansmod;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % ansmod;
    y = y >> 1;
    x = (x * x) % ansmod;
  }
  return res;
}
long long int modinv(int a, int mod) { return power(a, ansmod - 2, ansmod); }
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
class Solution {
 public:
  void solve() {
    long long int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) {
      cin >> x;
    }
    vector<int> final;
    int max = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (arr[i] > max) {
        final.push_back(arr[i]);
        max = arr[i];
      }
    }
    cout << final.size() - 1;
    cout << endl;
  }
};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    Solution ob;
    ob.solve();
  }
  return 0;
}
