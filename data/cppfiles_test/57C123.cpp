#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 2021;
int n;
int a[MAXN];
vector<int> ans;
int cur[MAXN];
void move(int len) {
  assert(len % 2 == 1);
  ans.push_back(len);
  reverse(cur, cur + len);
}
bool solve() {
  assert(n % 2 == 1);
  for (int i = (0); i < (n); ++i)
    if ((a[i] % 2) != (i % 2)) return false;
  ans.clear();
  for (int i = (0); i < (n); ++i) cur[i] = a[i];
  for (int x = n - 1; x >= 2; x -= 2) {
    int xpos = -1;
    for (int i = (0); i < (n); ++i)
      if (cur[i] == x) xpos = i;
    assert(xpos != -1 && xpos % 2 == 0);
    if (xpos != 0) move(xpos + 1), xpos = 0;
    int y = x - 1;
    int ypos = -1;
    for (int i = (0); i < (n); ++i)
      if (cur[i] == y) ypos = i;
    assert(ypos != -1 && ypos % 2 == 1);
    if (ypos != 1) move(ypos), xpos = ypos - 1;
    if (xpos != 0) {
      move(ypos + 2), ypos = 1, xpos = 2;
      move(3), xpos = 0, ypos = 1;
    }
    move(x + 1);
  }
  return true;
}
void run() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) scanf("%d", &a[i]), --a[i];
  if (!solve()) {
    printf("%d\n", -1);
    return;
  }
  printf("%d\n", ((int)(ans).size()));
  for (int i = (0); i < (((int)(ans).size())); ++i) {
    if (i != 0) printf(" ");
    printf("%d", ans[i]);
  }
  puts("");
}
int main() {
  int ncase;
  scanf("%d", &ncase);
  for (int i = (1); i <= (ncase); ++i) run();
  return 0;
}
