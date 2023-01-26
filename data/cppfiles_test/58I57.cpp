#include <bits/stdc++.h>
using namespace std;
typedef struct node {
  int k, f;
  struct node *next, *head;
} node;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long i, j, k, l, m, n, t, x, y, z;
  long long a[200010], b[200010], inv[400010], jie[400010], ijie[400010];
  node *p, *q, *c[2010], *head, *s;
  inv[1] = 1;
  jie[0] = jie[1] = j = 1;
  ijie[0] = ijie[1] = k = 1;
  for (i = 2; i <= 400000; i++) {
    inv[i] = inv[998244353 % i] * (998244353 - 998244353 / i) % 998244353;
    j = j * i % 998244353;
    jie[i] = j;
    k = k * inv[i] % 998244353;
    ijie[i] = k;
  }
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> n >> m;
    z = m;
    l = 1;
    for (j = 0; j < m; j++) {
      cin >> k >> x;
      while (l < k) {
        a[l] = l;
        l++;
      }
      a[l++] = x;
    }
    while (l <= n) {
      a[l] = l;
      l++;
    }
    k = sqrt(n);
    c[0] = head = p = (node *)malloc(sizeof(node));
    p->f = 0;
    for (j = 1; j <= n; j++) {
      q = (node *)malloc(sizeof(node));
      if (a[j] == j) {
        q->k = j;
        q->f = 0;
        q->head = p;
        p->next = q;
        p = q;
      } else {
        q->k = j;
        q->f = 1;
        l = (a[j] - 1) / k;
        s = c[l];
        for (x = 0; x < (a[j] - 1) % k; x++) {
          s = s->next;
        }
        if (s->f == 1) z--;
        q->head = s;
        q->next = s->next;
        s->next = q;
        q->next->head = q;
        for (x = l + 1; x <= (j - 1) / k; x++) {
          c[x] = c[x]->head;
        }
      }
      if (j % k == 0) c[j / k] = p;
    }
    cout << (ijie[n] * ijie[n - z] % 998244353) * jie[n + n - z] % 998244353
         << endl;
  }
  return 0;
}
