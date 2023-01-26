#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int  n, m, q;
    cin >> n >> m >> q;
    vector a(n, vector<int>(m, 1));
    vector c(n, vector(m, vector(2, 0)));
    ll sum=n*m;
    auto pull=[&](int i, int j) {
        sum-=c[i][j][0]+c[i][j][1];
        c[i][j].assign(2, 0);
        if (i+1<n) c[i][j][0]+=c[i+1][j][1]+a[i+1][j];
        if (j+1<m) c[i][j][1]+=c[i][j+1][0]+a[i][j+1];
        sum+=c[i][j][0]+c[i][j][1];
    };
    for (int i=n-1; i>=0; i--) {
        for (int j=m-1; j>=0; j--) {
            if (i==n-1 && j==m-1) continue;
            pull(i, j);
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        auto update=[&](int x, int y, int dx, int dy) {
            x+=dx, y+=dy;
            while (x>=0 && y>=0) {
                if (!a[x][y]) break;
                pull(x, y);
                x+=dx, y+=dy;
                swap(dx, dy);
            }
        };
        if (a[x][y]) {
            int ori=c[x][y][0]+c[x][y][1];
            sum-=ori+1;
            c[x][y][0]=c[x][y][1]=0;
        } else {
            sum++;
            pull(x, y);
        }
        a[x][y]^=1;
        update(x, y, 0, -1);
        update(x, y, -1, 0);
        cout << sum << '\n';
    }
}
