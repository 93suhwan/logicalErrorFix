#include <bits/stdc++.h>
using namespace std;
const int n7 = 1012345, m7 = n7;
struct dino {
  int x, y;
} e[m7];
struct mist {
  int fa, son[2];
  int laz, id, lazid;
  bool val, tot, fp;
} tre[n7];
int n, m;
long long ans;
int rd() {
  int shu = 0;
  bool fu = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') fu = 1;
    ch = getchar();
  }
  while (isdigit(ch)) shu = (shu << 1) + (shu << 3) + ch - '0', ch = getchar();
  return fu ? -shu : shu;
}
void updat(int o) {
  tre[o].tot = (tre[tre[o].son[0]].tot | tre[tre[o].son[1]].tot);
  if (o > n)
    tre[o].tot |=
        (tre[tre[o].son[0]].val | tre[tre[o].son[1]].val | tre[o].val);
}
void pudown(int o) {
  if (tre[o].laz == 1) {
    tre[tre[o].son[0]].val = tre[tre[o].son[1]].val = 1;
    tre[tre[o].son[0]].tot = tre[tre[o].son[1]].tot = 1;
    tre[tre[o].son[0]].laz = tre[tre[o].son[1]].laz = 1;
  }
  if (tre[o].laz == -1) {
    tre[tre[o].son[0]].val = tre[tre[o].son[1]].val = 0;
    tre[tre[o].son[0]].tot = tre[tre[o].son[1]].tot = 0;
    tre[tre[o].son[0]].laz = tre[tre[o].son[1]].laz = -1;
  }
  tre[o].laz = 0;
  if (tre[o].lazid > 0) {
    tre[tre[o].son[0]].id = tre[tre[o].son[1]].id = tre[o].lazid;
    tre[tre[o].son[0]].lazid = tre[tre[o].son[1]].lazid = tre[o].lazid;
  }
  if (tre[o].lazid == -1) {
    tre[tre[o].son[0]].id = tre[tre[o].son[1]].id = 0;
    tre[tre[o].son[0]].lazid = tre[tre[o].son[1]].lazid = -1;
  }
  tre[o].lazid = 0;
  if (tre[o].fp) {
    tre[tre[o].son[0]].fp ^= 1, tre[tre[o].son[1]].fp ^= 1;
    swap(tre[o].son[0], tre[o].son[1]);
    tre[o].fp = 0;
  }
  tre[0] = (mist){0, {0, 0}, 0, 0, 0, 0, 0, 0};
}
bool Dwhi(int o) { return tre[tre[o].fa].son[1] == o; }
bool izrot(int o) {
  return tre[tre[o].fa].son[0] == o || tre[tre[o].fa].son[1] == o;
}
void rota(int o) {
  int y = tre[o].fa, z = tre[y].fa, whi = Dwhi(o);
  int fawhi = (izrot(y) ? Dwhi(y) : -1), v = tre[o].son[!whi];
  tre[v].fa = y, tre[y].son[whi] = v;
  tre[y].fa = o, tre[o].son[!whi] = y;
  tre[o].fa = z;
  if (~fawhi) tre[z].son[fawhi] = o;
  updat(y), updat(o);
}
void puall(int o) {
  if (izrot(o)) puall(tre[o].fa);
  pudown(o);
}
void splay(int o) {
  puall(o);
  while (izrot(o)) {
    int y = tre[o].fa;
    if (izrot(y)) {
      Dwhi(o) == Dwhi(y) ? rota(y) : rota(o);
    }
    rota(o);
  }
}
void aces(int o) {
  int las = 0;
  while (o) {
    splay(o), tre[o].son[1] = las, updat(o);
    las = o, o = tre[o].fa;
  }
}
void Mroot(int o) { aces(o), splay(o), tre[o].fp ^= 1; }
int Froot(int o) {
  aces(o), splay(o);
  while (tre[o].son[0]) pudown(o), o = tre[o].son[0];
  splay(o);
  return o;
}
void split(int o1, int o2) { Mroot(o1), aces(o2), splay(o2); }
void link(int o1, int o2) {
  if (Froot(o1) == Froot(o2)) return;
  Mroot(o1), tre[o1].fa = o2;
}
bool cancut(int o1, int o2) {
  if (Froot(o1) ^ Froot(o2)) return 0;
  split(o1, o2);
  if (tre[o1].fa ^ o2 || tre[o1].son[0] || tre[o1].son[1]) return 0;
  return 1;
}
void cut(int o1, int o2) {
  pudown(o1), pudown(o2);
  if (cancut(o1, o2)) tre[o1].fa = tre[o2].son[0] = 0, updat(o2);
}
bool check(int o1, int o2) {
  if (Froot(o1) ^ Froot(o2)) return 1;
  split(o1, o2);
  if (!tre[o2].tot) return 1;
  return 0;
}
int main() {
  n = rd(), m = rd();
  for (int i = 1; i <= m; ++i) e[i] = (dino){rd(), rd()};
  for (int l = 1, r = 0; r <= m; ++r) {
    ans = ans + r - l + 1;
    if (r == m) break;
    while (!check(e[r + 1].x, e[r + 1].y)) {
      if (!cancut(e[l].x, l + n)) {
        split(e[l].x, e[l].y);
        tre[e[l].y].val = tre[e[l].y].tot = 0, tre[e[l].y].laz = -1,
        tre[e[l].y].lazid = 0;
      } else {
        int z = tre[l + n].id;
        if (z) {
          split(e[z].x, e[z].y);
          tre[e[z].y].val = tre[e[z].y].tot = 0, tre[e[z].y].laz = -1;
          tre[e[z].y].id = 0, tre[e[z].y].lazid = -1;
        }
        cut(e[l].x, l + n), cut(l + n, e[l].y);
        if (z) {
          link(e[z].x, z + n), link(z + n, e[z].y);
        }
      }
      l++;
    }
    if (Froot(e[r + 1].x) == Froot(e[r + 1].y)) {
      split(e[r + 1].x, e[r + 1].y);
      tre[e[r + 1].y].val = 1, tre[e[r + 1].y].laz = 1;
      tre[e[r + 1].y].id = tre[e[r + 1].y].lazid = r + 1;
    } else {
      link(e[r + 1].x, r + 1 + n), link(r + 1 + n, e[r + 1].y);
    }
  }
  printf("%lld", ans);
  return 0;
}
