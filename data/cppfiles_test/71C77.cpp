#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int maxl = 9;
int a[maxl + 1], b[maxl + 1];
int len, k;
void prepare(int x) {
  vector<int> p;
  while (x > 0) {
    p.push_back(x % 10);
    x /= 10;
  }
  len = p.size();
  reverse(p.begin(), p.end());
  for (int i = 1; i <= len; i++) {
    a[i] = p[i - 1];
  }
}
bool reach = false;
int cntBit(int n) {
  int cnt = 0;
  while (n) {
    n &= (n - 1);
    cnt++;
  }
  return cnt;
}
void print() {
  for (int i = 1; i <= len; i++) {
    cout << b[i];
  }
  cout << '\n';
}
void dp(int pos, int flag, int mask) {
  if (reach) {
    return;
  }
  if (cntBit(mask) > k) {
    return;
  }
  if (pos > len) {
    print();
    reach = true;
    return;
  }
  int mini;
  if (flag == 0) {
    mini = 0;
  } else {
    mini = a[pos];
  }
  for (int i = mini; i <= 9; i++) {
    b[pos] = i;
    if (i == mini) {
      int newMask = mask | (1 << i);
      dp(pos + 1, flag, newMask);
    } else {
      int newMask = mask | (1 << i);
      dp(pos + 1, 0, newMask);
    }
  }
}
int main() {
  if (fopen(""
            ".INP",
            "r")) {
    freopen(
        ""
        ".INP",
        "r", stdin);
  }
  int t;
  cin >> t;
  for (int co = 0; co < t; co++) {
    reach = false;
    int x;
    cin >> x;
    cin >> k;
    if (x == 1e9) {
      if (k == 1) {
        cout << 1111111111;
      } else {
        cout << x;
      }
      cout << '\n';
      continue;
    }
    prepare(x);
    dp(1, 1, 0);
  }
}
