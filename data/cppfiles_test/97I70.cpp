#include<bits/stdc++.h>
using namespace std;
#define lson (i<<1)
#define rson (i<<1|1)
#define repeat(i, s, n) for(int i = s; i <= n; ++i)
#define foreach(i,items) for(auto &i: items)
#define downrep(i, n, s) for(int i = n; i >= s; --i)
#define lowbit(x) (x&-x)
#define bzero(x) memset(x, 0, sizeof(x))
#define gcd(a,b) __gcd(a,b)

#define brkline puts("")
#define spaceout putchar(' ')
#define all(a) a.begin(),a.end()
#define pb  push_back

template<typename S, typename T>
bool chminx(S &a, const T &b){
    return a < b ? 1 : a=b, 0;
}

template<typename S, typename T>
bool chmaxx(S &a, const T &b){
    return a > b ? 1 : a=b, 0;
}

template<typename T>
void read_int(T &res) {
    int flag = 1;
    char ch;
    while(isspace(ch = getchar()));
    res = 0;
    if(ch == '-')  flag = -1;
    else if(ch >= '0' && ch <= '9')  res = ch - '0';
    while((ch=getchar()) >= '0' && ch <= '9')
        res = res * 10 + ch - '0';
    res *= flag;
}

template <typename T,typename... Args>
void read_ints(T &t,Args &...args){read_int(t);read_int(args...);}



template<typename T>
void int_out(T a) {
    if(a < 0) {
        putchar('-');
        a = -a;
    }
    if(a > 9)
        int_out(a / 10);
    putchar(a % 10 + '0');
}

typedef long long LL;

const int INF = 0x3f3f3f3f;
const double tol = 1e-8;
const int N = 200001;
const int SQ = sqrt(N);


int dp[N][SQ + 2], tmp[SQ + 2], sz[N];
// 开两个dp数组会超内存
int ks[N], vs[N], res[N];
vector<int> tree[N];

void get_dp1(int x, int fa){
    foreach(y, tree[x]) {
        if(y == fa) continue;
        get_dp1(y, x);
        repeat(k, 0, SQ) {
            dp[x][k] += max(dp[y][k] - k, 1);
        }
    }
}

void get_dp2(int x, int fa) {
    sz[x] = 1;
    foreach(y, tree[x]) {
        if(y == fa) continue;
        get_dp2(y, x);

        bzero(tmp);
        repeat(i, 0, min(sz[x], SQ)){
            chmaxx(tmp[i], dp[x][i] + 1);

            repeat(j, 0, sz[y]){
                if(i + j + 1 > SQ) break;
                chmaxx(tmp[i + j + 1], dp[x][i] + dp[x][j]);
            }
        }
        sz[x] += sz[y];
//        memcpy(dp[x], tmp, (min(sz[x], SQ) + 1) * sizeof *tmp);
        for(int i=0;i<=min(sz[x],SQ); ++i) dp[x][i]=tmp[i];
    }
}

int main(){

    int n;
    read_int(n);
    repeat(i, 1, n - 1) {
        int u, v;
        read_ints(u, v);
        tree[u].pb(v);
        tree[v].pb(u);
    }
    bzero(dp);
    get_dp1(1, 0);

    int q;
    read_int(q);
    bzero(res);
    repeat(i, 1, q) {
        read_ints(vs[i], ks[i]);
        if(ks[i] <= SQ) res[i] = dp[vs[i]][ks[i]];
    }

    bzero(dp);
    get_dp2(1, 0);
    repeat(i, 1, q) {
        int v = vs[i], k = ks[i];
        if(k > SQ) {
            repeat(j, 0, SQ) chmaxx(res[i], dp[v][j] - k * j);
        }
    }

    repeat(i, 1, q){
        int_out(res[i]);
        brkline;
    }

    return 0;
}
