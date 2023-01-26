#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 200000;
int n;
int a[MAXN];
char s[MAXN + 1];
pair<int, char> ans[MAXN];
bool solve() {
  sort(a, a + n);
  int nflip = 1;
  for (int i = (0); i < (n - 1); ++i)
    if (s[i] != s[i + 1]) ++nflip;
  int atsmall = n - nflip - 1, atbig = n - nflip;
  long long pos = 0;
  for (int i = (0); i < (n); ++i) {
    if (pos <= 0 && s[i] == 'R') {
      assert(atbig < n);
      int cur = a[atbig++];
      ans[i] = make_pair(cur, 'R');
      pos += cur;
      assert(pos > 0);
    } else if (pos >= 0 && s[i] == 'L') {
      assert(atbig < n);
      int cur = a[atbig++];
      ans[i] = make_pair(cur, 'L');
      pos -= cur;
      assert(pos < 0);
    } else if (pos > 0) {
      assert(atsmall >= 0);
      int cur = a[atsmall--];
      assert(atbig >= n || pos <= a[atbig] - cur - 1 || pos >= cur + 1);
      if (atbig >= n || pos <= a[atbig] - cur - 1) {
        ans[i] = make_pair(cur, 'R');
        pos += cur;
      } else {
        ans[i] = make_pair(cur, 'L');
        pos -= cur;
      }
      assert(pos > 0);
    } else {
      assert(atsmall >= 0);
      int cur = a[atsmall--];
      assert(atbig >= n || -pos <= a[atbig] - cur - 1 || -pos >= cur + 1);
      if (atbig >= n || -pos <= a[atbig] - cur - 1) {
        ans[i] = make_pair(cur, 'L');
        pos -= cur;
      } else {
        ans[i] = make_pair(cur, 'R');
        pos += cur;
      }
      assert(pos < 0);
    }
  }
  return true;
}
void run() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) scanf("%d", &a[i]);
  scanf("%s", s);
  if (!solve()) {
    printf("-1\n");
    return;
  }
  for (int i = (0); i < (n); ++i)
    printf("%d %c\n", ans[i].first, ans[i].second);
}
void stress() {
  for (int rep = (0); rep < (100000); ++rep) {
    n = rnd() % 100 + 1;
    for (int i = (0); i < (n); ++i) a[i] = rnd() % 1000 + 1000;
    sort(a, a + n);
    for (int i = (0); i < (n); ++i) a[i] += i;
    for (int i = (0); i < (n); ++i) s[i] = rnd() % 2 == 0 ? 'L' : 'R';
    s[n] = '\0';
    solve();
    printf(".");
  }
}
int main() {
  run();
  return 0;
}
