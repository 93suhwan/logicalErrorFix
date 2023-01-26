#include <bits/stdc++.h>
using namespace std;
int MOD = 998244353;
int OO = 1e8;
const int N = 3e5 + 10, M = N << 1;
int n, m, k, T;
int a, b, c;
int arr[N];
void Test() {
  cin >> n;
  if (n <= 4) {
    for (int i = 0; i < n; ++i) cout << char('a' + i);
    cout << "\n";
    return;
  }
  for (int i = 2;; i += 2) {
    if (i + (i - 1) + 1 == n) {
      string lt = string(i, 'z');
      string rt = string(i - 1, 'z');
      cout << lt << 'a' << rt << "\n";
      return;
    }
    if (i + (i - 1) + 2 == n) {
      string lt = string(i, 'z');
      string rt = string(i - 1, 'z');
      cout << lt << 'a' << rt << 'b' << "\n";
      return;
    }
    if (i + (i + 1) + 1 == n) {
      string lt = string(i, 'z');
      string rt = string(i + 1, 'z');
      cout << lt << 'a' << rt << "\n";
      return;
    }
    if (i + (i + 1) + 2 == n) {
      string lt = string(i, 'z');
      string rt = string(i + 1, 'z');
      cout << lt << 'a' << rt << 'b' << "\n";
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL);
  cin >> T;
  while (T--) {
    Test();
  }
  return 0;
}
