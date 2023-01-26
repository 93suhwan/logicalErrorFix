#include <bits/stdc++.h>
using namespace std;
long long k, n, Mo = 1000000007;
char s[10];
int path[100], top = 0;
bool ban[6][6]{{1, 1, 0, 0, 0, 0}, {1, 1, 0, 0, 0, 0}, {0, 0, 1, 1, 0, 0},
               {0, 0, 1, 1, 0, 0}, {0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 1, 1}};
struct Tree {
  Tree *child[2]{0, 0};
  int co = -1;
} Root;
void Insert(Tree *t, int p, int co) {
  if (p == 0)
    t->co = co;
  else {
    if (t->child[path[p]] == NULL) t->child[path[p]] = new Tree();
    Insert(t->child[path[p]], p - 1, co);
  }
}
long long GetAns(int x) {
  if (x == 1) return 1;
  long long y = GetAns(x - 1);
  return 4 * y % Mo * 4 % Mo * y % Mo;
}
vector<long long> GetAns(Tree *p, int dep) {
  vector<long long> L(6, 0), R(6, 0), Re(6, 0);
  if (dep == 1) return Re[p->co] = 1, Re;
  if (p->child[0] == NULL)
    L = vector<long long>(6, GetAns(dep - 1));
  else
    L = GetAns(p->child[0], dep - 1);
  if (p->child[1] == NULL)
    R = vector<long long>(6, GetAns(dep - 1));
  else
    R = GetAns(p->child[1], dep - 1);
  for (int i = 0; i <= 5; ++i)
    if (p->co == -1 || i == p->co)
      for (int l = 0; l <= 5; ++l)
        for (int r = 0; r <= 5; ++r)
          if (!ban[i][l] && !ban[i][r]) Re[i] = (Re[i] + L[l] * R[r]) % Mo;
  return Re;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> k >> n;
  for (long long i = 1, v, co; i <= n; ++i) {
    cin >> v >> s;
    switch (s[0]) {
      case 'w':
        co = 0;
        break;
      case 'y':
        co = 1;
        break;
      case 'g':
        co = 2;
        break;
      case 'b':
        co = 3;
        break;
      case 'r':
        co = 4;
        break;
      case 'o':
        co = 5;
        break;
    }
    top = 0;
    while (v != 1) {
      if (v & 1)
        path[++top] = 1;
      else
        path[++top] = 0;
      v >>= 1;
    }
    Insert(&Root, top, co);
  }
  auto vec = GetAns(&Root, k);
  long long ans = 0;
  for (auto vp : vec) ans += vp;
  cout << ans % Mo << endl;
  return 0;
}
