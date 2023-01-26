#include <bits/stdc++.h>
using namespace std;
const int nax = (int)1e4;
int arr[nax];
int sum = 0;
int n;
bool F(int x) {
  x = n - x;
  if (sum % x != 0) return false;
  const int val = sum / x;
  int curr = 0;
  for (int i = 0; i < n; ++i) {
    curr += arr[i];
    if (curr == val) {
      curr = 0;
    } else if (curr > val)
      return false;
  }
  return curr == 0;
}
void solve() {
  scanf("%d", &n);
  sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    sum += arr[i];
  }
  for (int i = 0; i < n; ++i) {
    if (F(i)) {
      printf("%d\n", i);
      return;
    }
  }
  puts("-1");
}
int main() {
  int tt;
  scanf("%d", &tt);
  for (int i = 0; i < tt; ++i) {
    solve();
  }
}
