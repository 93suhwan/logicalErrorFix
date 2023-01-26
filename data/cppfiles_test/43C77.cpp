#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
inline void upd1(T1& a, const T2& b) {
  a = a < b ? a : b;
}
template <class T1, class T2>
inline void upd2(T1& a, const T2& b) {
  a = b < a ? a : b;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
struct Ano {
  operator long long() {
    long long x = 0, y = 0, c = getchar();
    while (c < 48) {
      y = c == 45;
      c = getchar();
    }
    while (c > 47) {
      x = x * 10 + c - 48;
      c = getchar();
    }
    return y ? -x : x;
  }
} buf;
constexpr int N = 6e5 + 5;
int n;
struct vec {
  bool c, w;
  vec() {}
  vec(bool c, bool w) : c(c), w(w) {}
};
vec operator+(vec a, vec b) { return vec(a.c | b.c, a.w ^ b.w); }
struct node;
typedef node* ptr;
struct node {
  ptr i, j, p;
  bool r, c;
  vec v, s;
  node();
  ptr up() {
    s = i->s + v + j->s;
    return this;
  }
  void down() {
    if (r) i->r ^= 1, j->r ^= 1, swap(i, j), r = 0;
    if (c) i->cov(), j->cov(), c = 0;
  }
  void cov();
} e[N];
node::node() { i = j = p = e; }
void node::cov() {
  if (this == e) return;
  c = 1;
  if (this - e > n)
    s.c = v.c = 1;
  else
    s.c = i != e || j != e;
}
bool root(ptr o) { return o != o->p->i && o != o->p->j; }
void turn(ptr o) {
  ptr s = o->p, t = s->p;
  if (!root(s)) (s == t->i ? t->i : t->j) = o;
  s->p = o, o->p = t;
  if (o == s->i)
    s->i = o->j, o->j->p = s, o->j = s->up();
  else
    s->j = o->i, o->i->p = s, o->i = s->up();
}
void push(ptr o) {
  if (!root(o)) push(o->p);
  o->down();
}
ptr splay(ptr o) {
  push(o);
  while (!root(o)) {
    if (!root(o->p)) turn(o == o->p->i ^ o->p == o->p->p->i ? o : o->p);
    turn(o);
  }
  return o->up();
}
ptr exp(ptr o) {
  ptr s = e;
  while (o != e) splay(o)->j = s, s = o->up(), o = o->p;
  return s;
}
int main() {
  n = buf;
  int m = n;
  for (int q = buf; q; --q) {
    int u = buf, v = buf, w = buf;
    exp(e + u)->r = 1;
    ptr o = exp(e + v);
    while (o->i != e) {
      o = o->i, o->down();
    }
    bool a = 1;
    if (splay(o) != e + u) {
      e[++m].v = vec(0, w);
      splay(e + u)->p = e + m;
      e[m].p = e + v;
    } else {
      if (!o->s.c && o->s.w ^ w) {
        o->cov();
      } else {
        a = 0;
      }
    }
    puts(a ? "YES" : "NO");
  }
}
