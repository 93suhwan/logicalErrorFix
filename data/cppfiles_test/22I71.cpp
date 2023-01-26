#include <bits/stdc++.h>
using namespace std;

struct FastIO { FastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); } } fastio;

const int MN = 2e5 + 5;
const int MM = sqrt(MN) + 5;

int n, m;
int s[MN], x[MN], y[MN];

int thre;

// x[k] + y[k] <= thre
int sum1[MM][MM];
void add1(int s, int x, int y) {
  int l = x + y;
  for (int i = x; i < l; i++) {
    sum1[l][(s + i) % l]++;
  }
}

void del1(int s, int x, int y) { 
  int l = x + y;
  for (int i = x; i < l; i++) {
    sum1[l][(s + i) % l]--;
  }
}

// x[k] + y[k] > thre
int mark[MN];
int sum2 = 0;
void add2(int s, int x, int y) {
  for (int i = s + x; i <= m; i += x + y) {
    mark[i]++;
    mark[i + y]--;
  }
}

void del2(int s, int x, int y, int now) {
  for (int i = s + x; i <= m; i += x + y) {
    mark[i]--;
    mark[i + y]++;
    if (i < now && now <= i + y) {
      sum2--;
    }
  }
}

int cnt(int d) {
  int ans = sum2;
  for (int i = 1; i <= thre; i++) {
    ans += sum1[i][d % i];
  }
  return ans;
}

int main() {
  cin >> n >> m;
  thre = sqrt(m);
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }


  int op, k;
  for (int i = 0; i < m; i++) {
    cin >> op >> k;
    if (op == 1) {
      s[k] = i;
      if (x[k] + y[k] <= thre) add1(s[k], x[k], y[k]);
      else add2(s[k], x[k], y[k]);
    } else {
      if (x[k] + y[k] <= thre) del1(s[k], x[k], y[k]);
      else del2(s[k], x[k], y[k], i);
    }
    sum2 += mark[i];
    cout << cnt(i) << '\n';
  }
  return 0;
}
