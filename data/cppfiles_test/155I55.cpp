#include <bits/stdc++.h>
using namespace std;
class node {
 public:
  int data;
  node *right;
  node *left;
  int height;
};
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (auto &i : a) cin >> i;
    string s;
    cin >> s;
    int cnt = 0;
    for (auto i : s) cnt += (i == '1');
    sort(a, a + n);
    stack<int> big, small;
    for (int i = n - 1; i >= 0; i--, cnt--) {
      if (cnt > 0)
        big.push(a[i]);
      else
        small.push(a[i]);
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        a[i] = small.top();
        small.pop();
      } else {
        a[i] = big.top();
        big.pop();
      }
      cout << a[i] << " ";
    }
    cout << '\n';
  }
}
