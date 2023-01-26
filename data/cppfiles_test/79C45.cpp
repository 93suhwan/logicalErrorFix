#include <bits/stdc++.h>
using namespace std;
int MD(int x) {
  if (x < 0) return x + 1000000007;
  if (x >= 1000000007) return x - 1000000007;
  return x;
}
long long MDL(long long x) {
  return (x % 1000000007LL + 1000000007LL) % 1000000007LL;
}
long long modpow(long long a, long long b, long long m) {
  if (!b) return 1LL;
  if (b & 1LL) return a * modpow(a, b - 1, m) % m;
  long long r = modpow(a, b >> 1, m);
  return r * r % m;
}
long long invmod(long long a, long long m) { return modpow(a, m - 2, m); }
vector<char> getString() {
  char ch = (char)getchar();
  vector<char> ret;
  while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
         (ch >= '0' && ch <= '9')) {
    ret.push_back(ch);
    ch = (char)getchar();
  }
  return ret;
}
int n, t = 1;
int A[3 * 100007];
int B[3 * 100007];
int d[6 * 100007];
int ant[6 * 100007];
int WALL = 300005;
set<int> naoVisitados;
vector<int> rem;
vector<int> resp;
int main() {
  while (t--) {
    resp.clear();
    scanf("%d", &n);
    d[0] = 1000000;
    d[0 + WALL] = 1000000;
    for (int i = 1; i <= n; i++) {
      scanf("%d", A + i);
      d[i] = 1000000;
      d[i + WALL] = 1000000;
      naoVisitados.insert(i);
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", B + i);
    }
    int s = n;
    d[s] = 0;
    deque<int> q;
    q.push_front(s);
    while (!q.empty()) {
      int v = q.front();
      q.pop_front();
      if (v > WALL) {
        int ve = v - WALL;
        int nxt = ve + B[ve];
        if (d[v] < d[nxt]) {
          d[nxt] = d[v];
          ant[nxt] = v;
          q.push_front(nxt);
        }
      } else {
        if (v - A[v] <= 0) {
          d[0] = d[v] + 1;
          ant[0] = v;
          break;
        }
        auto it1 = naoVisitados.lower_bound(v - A[v]);
        auto it2 = naoVisitados.lower_bound(v + 1);
        while (it1 != it2) {
          int x = *it1;
          if (d[v] + 1 < d[x + WALL]) {
            d[x + WALL] = d[v] + 1;
            q.push_back(x + WALL);
            ant[x + WALL] = v;
          }
          rem.push_back(x);
          it1 = next(it1);
        }
        for (int x : rem) {
          naoVisitados.erase(x);
        }
        rem.clear();
      }
    }
    if (d[0] == 1000000) {
      printf("-1\n");
      return 0;
    }
    int x = 0;
    resp.push_back(0);
    while (x != n) {
      if (x >= WALL) resp.push_back(x - WALL);
      x = ant[x];
    }
    reverse(resp.begin(), resp.end());
    printf("%d\n", ((int)(resp).size()));
    for (int x : resp) {
      printf("%d ", x);
    }
    printf("\n");
  }
}
