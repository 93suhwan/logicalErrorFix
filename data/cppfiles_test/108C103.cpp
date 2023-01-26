#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:666000000")
using namespace std;
const int INF = (1 << 30) - 1;
const long double EPS = 1e-9;
void ML(const bool v) {
  if (v) return;
  int *ass;
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
int n;
vector<int> a, b;
bool LoAd() {
  if (!(1 == scanf("%d", &n))) return false;
  a.resize(n);
  b.resize(n);
  for (int i = 0; i < (int)(n); i++) (1 == scanf("%d", &a[i]));
  for (int i = 0; i < (int)(n); i++) (1 == scanf("%d", &b[i]));
  return true;
}
vector<pair<int, int> > pa, pb;
vector<int> posa;
vector<int> posb;
vector<int> win;
int na, nb;
void goa(int lt);
void gob(int lt);
void goa(int lt) {
  int np = n;
  for (int i = lt; i < na; i++) {
    int pid = pa[i].second;
    if (win[pid]) continue;
    win[pid] = true;
    np = min(np, posb[pid]);
  }
  na = lt;
  if (np != n) {
    gob(np);
  }
}
void gob(int lt) {
  int np = n;
  for (int i = lt; i < nb; i++) {
    int pid = pb[i].second;
    if (win[pid]) continue;
    win[pid] = true;
    np = min(np, posa[pid]);
  }
  nb = lt;
  if (np != n) {
    goa(np);
  }
}
void SoLvE() {
  pa.clear();
  pb.clear();
  for (int i = 0; i < (int)(n); i++) {
    pa.push_back(make_pair(a[i], i));
    pb.push_back(make_pair(b[i], i));
  }
  sort(pb.begin(), pb.end());
  sort(pa.begin(), pa.end());
  win.assign(n, 0);
  win[pb.back().second] = 1;
  win[pa.back().second] = 1;
  posa.resize(n);
  posb.resize(n);
  for (int i = 0; i < (int)(n); i++) {
    posa[pa[i].second] = i;
    posb[pb[i].second] = i;
  }
  na = n;
  nb = n;
  goa(posa[pb.back().second]);
  gob(posb[pa.back().second]);
  for (int i = 0; i < n; i++) printf("%d", win[i]);
  puts("");
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
