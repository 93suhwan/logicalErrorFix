#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:666000000")
using namespace std;
const int INF = (1 << 30) - 1;
const long double EPS = 1e-9;
void ML(const bool v) {
  if (v) return;
  int* ass;
  for (;;) {
    ass = new int[2500000];
    for (int i = 0; i < 2500000; i++) ass[i] = rand();
  }
}
void TL(const bool v) {
  if (v) return;
  for (;;) cout << rand() % (rand() % 1000 + 1) << endl;
}
void PE(const bool v) {
  if (v) return;
  for (int i = 0; i < 10000; i++) printf("%c", rand() % 256);
  exit(0);
}
void go(vector<int>& a, int pos) {
  for (int i = 0; i < (int)(a.size()); i++)
    if (i != pos) a[i] ^= 1;
}
void calc(int& c0, int& c1, vector<int>& a) {
  c0 = c1 = 0;
  for (int i = 0; i < (int)(a.size()); i++)
    if (0 == a[i])
      c0++;
    else if (1 == a[i])
      c1++;
}
int n;
string s, t;
vector<int> a, b;
bool LoAd() {
  if (!(1 == scanf("%d", &n))) return false;
  cin >> s >> t;
  n = (int)s.size();
  return true;
}
void SoLvE() {
  a.resize(s.size());
  b.resize(t.size());
  for (int i = 0; i < (int)(s.size()); i++) a[i] = s[i] - '0';
  for (int i = 0; i < (int)(t.size()); i++) b[i] = t[i] - '0';
  int c0a, c1a, c0b, c1b;
  calc(c0a, c1a, a);
  calc(c0b, c1b, b);
  int res = n * n;
  if (c1b != c1a && c1b != (c0a + 1)) {
    puts("-1");
    return;
  }
  if (c1b == c1a) {
    int t = 0;
    for (int i = 0; i < (int)(n); i++)
      if (a[i] != b[i]) t++;
    res = min(res, t);
  }
  if (c1b == (c0a + 1)) {
    int t = 0;
    for (int i = 0; i < (int)(n); i++)
      if (a[i] == b[i]) t++;
    res = min(res, t);
  }
  cout << res << endl;
}
int main() {
  srand((int)time(NULL));
  int nt;
  (1 == scanf("%d", &nt));
  for (int i = 0; i < (int)(nt); i++) {
    LoAd();
    SoLvE();
  }
  return 0;
}
