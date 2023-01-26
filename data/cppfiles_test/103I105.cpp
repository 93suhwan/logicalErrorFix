#include <bits/stdc++.h>
#define rep(i, a, b) for (register int i(a); i <= b; ++i)
#define per(i, a, b) for (register int i(a); i >= b; --i)
#define FILE(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define mem(a, x) memset(a, x, sizeof a)
#define pb push_back
#define umap unordered_map
#define pqueue priority_queue
#define mp make_pair
#define PI acos(-1)
//#define int long long

using namespace std;
typedef long long ll;
int n, m, dis[2005][2005];
struct node {
    int x, y;
} to[2005][2005], lst[2005][2005], t[4000005];
char a[2005][2005];
int ansx, ansy, ans, sx, sy, tot;
bool vis[2005][2005];

template <typename _T>
void rd(_T &x) {
    int f = 1; x = 0;
    char s = getchar();
    while (s > '9' || s < '0') {if (s == '-') f = -1; s = getchar();}
    while (s >= '0' && s <= '9') x = (x<<3)+(x<<1)+(s^48), s = getchar();
    x *= f;
}

void dfs(int x, int y) {
    t[++tot] = (node){x, y};
    if (x < 1 || x > n || y < 1 || y > m || vis[x][y]) return ;
    // printf("%d %d\n", x, y);
    vis[x][y] = 1;
    dfs(to[x][y].x, to[x][y].y);
    dis[x][y] = dis[to[x][y].x][to[x][y].y]+1;
    return ;
}

void slv() {
    rd(n), rd(m);
    rep(i, 1, n) rep(j, 1, m) dis[i][j] = to[i][j].x = to[i][j].y = vis[i][j] = 0;
    rep(i, 1, n) {
        scanf("%s", a[i]+1);
        rep(j, 1, m) {
            int x = i, y = j;
            if (a[i][j] == 'L') --y;
            else if (a[i][j] == 'R') ++y;
            else if (a[i][j] == 'U') --x;
            else ++x;
            to[i][j] = (node){x, y};
        }
    }
    ans = 0;
    rep(i, 1, n) rep(j, 1, m) {
        if (vis[i][j]) continue;
        tot = 0;
        dfs(i, j);
        node tmp = (node){t[tot].x, t[tot].y};
        rep(k, 1, tot) if (tmp.x == t[k].x && tmp.y == t[k].y) {
            rep(l, k, tot-1) dis[t[l].x][t[l].y] = tot-k;
            break;
        }
    }
    rep(i, 1, n) rep(j, 1, m) if (ans < dis[i][j]) ans = dis[i][j], ansx = i, ansy = j;
    printf("%d %d %d\n", ansx, ansy, ans);
    return ;
}

int main() {
    int _;
    for (rd(_); _; _--) slv();
    return 0;
}
