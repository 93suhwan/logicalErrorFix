#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#define lch (rt << 1)
#define rch (rt << 1 | 1)
#define int long long
const int N = 2e5 + 5;
//=========================
inline int read()
{
    int k = 0, f = 1 ;
    char c = getchar() ;
    while(!isdigit(c)){if(c == '-') f = -1 ;c = getchar() ;}
    while(isdigit(c)) k = (k << 1) + (k << 3) + c - 48 ,c = getchar() ;
    return k * f ;
}
//==========================

int n, a[N], b[N], t[N << 2];

void pushup(int rt) { t[rt] = __gcd(t[lch], t[rch]); }

void build(int rt, int l, int r) 
{
    if (l == r) { t[rt] = b[l]; return ; }
    int mid = l + r >> 1;
    build(lch, l, mid); build(rch, mid + 1, r);
    pushup(rt);
}

int query(int rt, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr) return t[rt];
    int mid = l + r >> 1;
    if (ql > mid) return query(rch, mid + 1, r, ql, qr);
    if (qr <= mid) return query(lch, l, mid, ql, qr);
    return __gcd(query(rch, mid + 1, r, ql, qr), query(lch, l, mid, ql, qr));
}


signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = read();
    while (T--) {
        n = read();
        for (int i = 1; i <= n; i++) { a[i] = read(); b[i - 1] = abs(a[i] - a[i - 1]); }
        if (n == 1) { puts("1"); continue; }
        build(1, 1, n - 1);
        int l = 0, ans = 0;
        for (int r = 1; r < n; r++) {
            while (l <= r && query(1, 1, n - 1, l, r) == 1) l++;
            ans = max(ans, 1LL * (r - l + 2));
        }
        cout << ans << endl;
        
    }
    return 0;
}