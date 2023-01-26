#include <bits/stdc++.h>
using namespace std;
int p;
string place(int x, int y) {
  printf("%d %d\n", x, p = y);
  string s;
  cin >> s;
  return s;
}
bool patrol(int i) {
  for (int j = p == 1 ? 2 : 1; j <= 8; j++) {
    string s = place(i, j);
    if (s == "Done") return 1;
    if (s[0] == 'D') return 0;
    if (s[0] == 'U') return patrol(i);
  }
}
void mein() {
  for (int i = p = 1; i <= 8; i++)
    if (place(i, p) == "Done" || patrol(i)) return;
}
int main() {
  int T;
  for (scanf("%d", &T); T--;) mein();
}
