#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXLEN = 50;
char s[MAXLEN + 1];
int slen;
bool solve() {
  int nb = 0;
  for (int i = (0); i < (slen); ++i)
    if (s[i] == 'B') ++nb;
  return 2 * nb == slen;
}
void run() {
  scanf("%s", s);
  slen = strlen(s);
  printf("%s\n", solve() ? "YES" : "NO");
}
int main() {
  int ncase;
  scanf("%d", &ncase);
  for (int i = (1); i <= (ncase); ++i) run();
  return 0;
}
