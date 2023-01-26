#include <bits/stdc++.h>
using namespace std;
int t;
const int maxn = 1e5 + 8;
char s[maxn];
int n;
void find(char s[]) {
  int mid = n >> 1;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      if (i <= mid) {
        cout << i << " " << n << " " << i + 1 << " " << n << endl;
      } else {
        cout << 1 << " " << i << " " << 1 << " " << i - 1 << endl;
      }
      return;
    }
  }
  cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s + 1;
    find(s);
  }
  return 0;
}
