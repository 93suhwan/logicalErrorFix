#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
void setIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}
void setIO(string s) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const int N = 2e5 + 10;
int n;
long long a[N];
string s;
int main() {
  setIO();
  cin >> n;
  for (int i = (0); i < (n); i++) cin >> a[i];
  cin >> s;
  char lst = s[0];
  int x = 0;
  for (int i = (1); i < (n); i++) {
    char cc = s[i];
    if (cc != lst) {
      x++;
    }
    lst = cc;
  }
  long long l = n - 2 - x, r = n - x, left = 0, right = 0;
  if (s[0] == 'L') {
    left += a[l + 1];
    cout << a[l + 1] << " " << 'L' << '\n';
  } else {
    right += a[l + 1];
    cout << a[l + 1] << " " << 'R' << '\n';
  }
  for (int i = (1); i < (n); i++) {
    if (s[i] == 'L') {
      if (r < n && right > left) {
        cout << a[r] << " " << 'L' << '\n';
        left += a[r];
        r++;
      } else if (l >= 0) {
        cout << a[l] << " ";
        if (right + a[l] < left) {
          cout << 'R' << '\n';
          right += a[l];
        } else {
          cout << 'L' << '\n';
          left += a[l];
        }
        l--;
      }
    } else if (s[i] == 'R') {
      if (r < n && left > right) {
        cout << a[r] << " " << 'R' << '\n';
        right += a[r];
        r++;
      } else if (l >= 0) {
        cout << a[l] << " ";
        if (left + a[l] < right) {
          cout << 'L' << '\n';
          left += a[l];
        } else {
          cout << 'R' << '\n';
          right += a[l];
        }
        l--;
      }
    }
  }
}
