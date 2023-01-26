#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int mod1 = 1e7 + 7;
const int N = 2e5 + 10;
int a[N];
int b[N];
long long cnt;
struct P {
  int num;
  int index;
} p[N];
int cmp(P a, P b) { return a.num < b.num; }
long long n, m;
map<int, int> mp;
string s;
int g[N][5];
int main() {
  int t, k;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) cin >> g[i][j];
    }
    int id = 0;
    for (int i = 1; i < n; i++) {
      int cou = 0;
      for (int j = 0; j < 5; j++) {
        cou += g[i][j] < g[id][j] ? 1 : 0;
      }
      if (cou >= 3) id = i;
    }
    for (int i = 0; i < n; i++) {
      int cou = 0;
      for (int j = 0; j < 5; j++) {
        cou += g[i][j] < g[id][j] ? 1 : 0;
      }
      if (cou >= 3) id = -2;
    }
    cout << id + 1 << endl;
  }
}
