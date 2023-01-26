// Daniel Grzegorzewski
// while (clock()<=69*CLOCKS_PER_SEC)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

#define MP make_pair
#define PB push_back
#define ST first
#define ND second

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//X.find_by_order(k); - zwraca iterator na k-ty element (numeracja od zerowego)
//X.order_of_key(k); - zwraca liczbę elementów ostro mniejszych niż k

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef long long LL;

void init_ios() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}

auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
 
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
mt19937_64 rng(SEED);

const int N = 503;

int n, m, col[N*N];
char a[N][N];
VI child[N*N];
bool vis[N*N];

void dfs(int v, int co) {
  vis[v] = true;
  col[v] = co;
  for (int x: child[v])
    if (!vis[x])
      dfs(x, 5-co);
}

int main() {
  init_ios();
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> a[i][j];
  bool ok = true;
  for (int i = 1; i < n-1; ++i)
    for (int j = 1; j < m-1; ++j) {
      if (a[i][j] != 'X')
        continue;
      VI ids;
      for (int p = -1; p <= 1; ++p)
        for (int q = -1; q <= 1; ++q)
          if (p*p + q*q == 1 && a[i+p][j+q] == '.')
            ids.PB(m*(i+p)+j+q);
      if (ids.size()%2 == 1)
        ok = false;
      random_shuffle(ids.begin(), ids.end());
      if (ids.size() >= 2) {
        child[ids[0]].PB(ids[1]);
        child[ids[1]].PB(ids[0]);
      }
      if (ids.size() == 4) {
        child[ids[2]].PB(ids[3]);
        child[ids[3]].PB(ids[2]);
      }
    }
  if (!ok) {
    cout<<"NO\n";
    return 0;
  }
  cout<<"YES\n";
  for (int i = 0; i < n*m; ++i)
    if (!vis[i] && child[i].size())
      dfs(i, 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '.' && child[m*i+j].size() == 0)
        col[m*i+j] = 1;
      if (a[i][j] == 'X') {
        for (int p = -1; p <= 1; ++p)
          for (int q = -1; q <= 1; ++q)
            if (p*p+q*q == 1 && a[i+p][j+q] != 'X')
              col[m*i+j] += col[m*(i+p)+j+q];
      }
      cout<<col[m*i+j]<<" ";
    }
    cout<<"\n";
  }
}