#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EXP = exp(1.0);
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long lowbit(long long x) { return x & (-x); }
stack<int> st;
int arr[maxn];
bool check(int brk, int a, int b) {
  int tot = a + b;
  if (tot & 1) {
    int tmpa = (tot + 1) / 2;
    int tmpb = (tot) / 2;
    for (int i = 0; i <= brk; i++) {
      tmpa = (tot + 1) / 2;
      tmpb = (tot) / 2;
      int brka = i, brkb = brk - i;
      if (brka > tmpb || brkb > tmpa) continue;
      tmpa = tmpa + i - brkb;
      tmpb = tmpb + brkb - i;
      if (tmpa < 0 || tmpb < 0) continue;
      if (a == tmpa && b == tmpb) {
        return true;
      }
    }
    for (int i = 0; i <= brk; i++) {
      tmpa = tot / 2;
      tmpb = (tot + 1) / 2;
      int brka = i, brkb = brk - i;
      if (brkb > tmpa || brka > tmpb) continue;
      tmpa = tmpa + i - brkb;
      tmpb = tmpb + brkb - i;
      if (tmpa < 0 || tmpb < 0) continue;
      if (a == tmpa && b == tmpb) {
        return true;
      }
    }
  } else {
    for (int i = 0; i <= brk; i++) {
      int tmpa = (tot) / 2;
      int tmpb = (tot) / 2;
      int brka = i, brkb = brk - i;
      if (brka > tmpb || brkb > tmpa) continue;
      tmpa = tmpa + i - brkb;
      tmpb = tmpb + brkb - i;
      if (tmpa < 0 || tmpb < 0) continue;
      if (a == tmpa && b == tmpb) return true;
    }
  }
  return false;
}
void solve1() {
  int a, b;
  cin >> a >> b;
  int tot = a + b;
  int idx = 0;
  for (int i = 0; i <= tot; i++) {
    if (check(i, a, b)) arr[idx++] = i;
  }
  cout << idx << endl;
  for (int i = 0; i < idx; i++) cout << arr[i] << " ";
  cout << endl;
}
void solve2() {
  int a, b;
  cin >> a >> b;
  int tot = a + b;
  int d = abs(a - b) / 2;
  if (tot & 1) {
    int idx = 0;
    for (int i = d; i <= tot - d; i++) {
      arr[idx++] = i;
    }
    cout << idx << endl;
    for (int i = 0; i < idx; i++) cout << arr[i] << " ";
    cout << endl;
  } else {
    int idx = 0;
    for (int i = d; i <= tot - d; i += 2) arr[idx++] = i;
    cout << idx << endl;
    for (int i = 0; i < idx; i++) cout << arr[i] << " ";
    cout << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve2();
  }
  return 0;
}
