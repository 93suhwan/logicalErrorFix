#include <bits/stdc++.h>
using namespace std;
int qtd[4 * 300300];
long long lazy[4 * 300300];
int on[4 * 300300];
int v[300300];
long long ans[300300];
void update(int ini, int fim, int p, int pos) {
  if (ini > pos) return;
  if (fim < pos) return;
  if (ini == fim) {
    qtd[p]++;
    return;
  }
  int mid = (ini + fim) / 2;
  update(ini, mid, 2 * p, pos);
  update(mid + 1, fim, 2 * p + 1, pos);
  qtd[p] = qtd[2 * p] + qtd[2 * p + 1];
}
long long query(int ini, int fim, int p, int x) {
  if (ini / x == fim / x) return (long long)(ini / x) * qtd[p];
  int mid = (ini + fim) / 2;
  return query(ini, mid, 2 * p, x) + query(mid + 1, fim, 2 * p + 1, x);
}
void refresh(int ini, int fim, int p) {
  if (ini < fim) {
    lazy[2 * p] += lazy[p];
    lazy[2 * p + 1] += lazy[p];
    lazy[p] = 0;
  }
}
void update_2(int ini, int fim, int p, int y) {
  refresh(ini, fim, p);
  if (ini / y == fim / y) {
    lazy[p] += y * (ini / y);
    refresh(ini, fim, p);
    return;
  }
  int mid = (ini + fim) / 2;
  update_2(ini, mid, 2 * p, y);
  update_2(mid + 1, fim, 2 * p + 1, y);
}
long long turn_on(int ini, int fim, int p, int pos) {
  refresh(ini, fim, p);
  if (ini > pos || fim < pos) return 0;
  if (ini == fim) {
    if (on[p] == 0) lazy[p] = 0;
    on[p] = 1;
    return lazy[p];
  }
  int mid = (ini + fim) / 2;
  return turn_on(ini, mid, 2 * p, pos) + turn_on(mid + 1, fim, 2 * p + 1, pos);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", v + i);
    ans[i] = query(0, 300300 - 1, 1, v[i]);
    update(0, 300300 - 1, 1, v[i]);
  }
  for (int i = n - 1; i >= 0; i--) {
    update_2(0, 300300 - 1, 1, v[i]);
    turn_on(0, 300300 - 1, 1, v[i]);
  }
  long long s = 0;
  long long ss = 0;
  for (int i = 0; i < n; i++) {
    ("%lld - %lld + %lld - %lld = ", s, (long long)v[i] * ans[i],
     (long long)i * v[i], turn_on(0, 300300 - 1, 1, v[i]));
    ss += s - (long long)v[i] * ans[i] + (long long)i * v[i] -
          turn_on(0, 300300 - 1, 1, v[i]);
    printf("%lld\n", ss);
    s += v[i];
  }
  printf("\n");
}
