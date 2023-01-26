/*
*  enjoy coding, good luck, good grades
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200010;

struct node {
    ll v;
} tr[N * 4];
ll a[N];

void build(int x, int l, int r) {
    if (l == r) tr[x].v = a[l] - a[l - 1];
    else {
        int mid = (l + r) >> 1;
        build(x << 1, l, mid);
        build(x << 1 | 1, mid + 1, r);
        tr[x].v = __gcd(tr[x << 1].v, tr[x << 1 | 1].v);
    }
}

ll query(int x, int l, int r, int lx, int rx) {
    if (l >= lx && r <= rx) return tr[x].v;
    int mid = (l + r) >> 1;
    if (rx <= mid) return query(x << 1, l, mid, lx, rx);
    else if (lx > mid) return query(x << 1 | 1, mid + 1, r, lx, rx);
    else return __gcd(query(x << 1, l, mid, lx, rx), query(x << 1 | 1, mid + 1, r, lx, rx));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        build(1, 1, n);
        int res = 1;
        for (int i = 1, r = 1; i <= n; i++) {
            r = max(r, i + 1);
            while (r < n && query(1, 1, n, i + 1, r) > 1) ++r;
            if (query(1, 1, n, i + 1, r) > 1) res = max(res, r - i + 1);
        }
        cout << res << '\n';
    }
    return 0;
}
