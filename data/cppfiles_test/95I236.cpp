#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using ll = long long;
int tens(int n) {
  int ans = 1;
  for (int i = 0; i < n; i++) {
    ans *= 10;
  }
  return ans;
}
void f(int s, int n) {
  int pos[10] = {
      0,
  };
  int idx = 0;
  bool chk = false;
  while (s > 0) {
    pos[idx] = s % 10;
    s /= 10;
    idx++;
  }
  s = 0;
  idx -= 1;
  for (int i = idx; i > 0; i--) {
    s += pos[i];
    s *= 10;
  }
  s += pos[0];
  while (n > 1) {
    if (s - tens(idx) >= n - 1) {
      n--;
      cout << tens(idx) << ' ';
      s -= tens(idx);
    } else if (s - tens(idx) <= 0) {
      idx--;
    } else {
      chk = true;
      for (int i = 0; i < n - 1; i++) {
        cout << 1 << ' ';
        s -= 1;
      }
      cout << s << '\n';
      break;
    }
  }
  if (!chk) {
    cout << s << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, s;
    cin >> s >> n;
    f(s, n);
  }
  return 0;
}
