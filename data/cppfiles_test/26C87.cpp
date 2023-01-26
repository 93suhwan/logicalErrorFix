#include <bits/stdc++.h>
using std::min;
char s[20];
int win(int x) {
  int left[2] = {5, 5};
  int score[2] = {0, 0};
  for (int i = 1; i <= 10; i++) {
    if (s[i] == '1' || (s[i] == '?' && x == (i & 1))) score[i & 1]++;
    left[i & 1]--;
    if (score[1] > score[0] + left[0] || score[0] > score[1] + left[1])
      return i;
  }
  return 10;
}
void solve() {
  scanf("%s", &s[1]);
  printf("%d\n", min(win(0), win(1)));
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
