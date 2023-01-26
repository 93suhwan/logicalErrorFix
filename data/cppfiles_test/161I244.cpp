#include <bits/stdc++.h>
using namespace std;
int t, n;
struct x {
  int o1, o2, o3;
} mem[1100];
int used[1100];
queue<x> q;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    memset(used, 0, sizeof(used));
    for (int i = 1; i < n + 1; i++) {
      cin >> mem[i].o1 >> mem[i].o2;
      used[mem[i].o1]++;
      used[mem[i].o2]++;
      mem[i].o3 = 0;
      if (mem[i].o1 == 1 && mem[i].o2 == n) q.push(mem[i]);
    }
    while (!q.empty()) {
      x u = q.front();
      q.pop();
      int sum = 0x3f3f3f3f;
      int o;
      for (int i = u.o1; i < u.o2 + 1; i++) {
        if (sum > used[i]) {
          sum = used[i];
          o = i;
        }
      }
      cout << u.o1 << " " << u.o2 << " " << o << "\n";
      if (u.o1 < o) q.push({u.o1, o - 1, 0});
      if (u.o2 > o) q.push({o + 1, u.o2, 0});
      used[u.o1]--;
      used[u.o2]--;
    }
  }
  return 0;
}
