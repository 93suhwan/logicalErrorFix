#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

int t,n,a[MAXN];

int cnt[30];
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false), cin.tie(0);
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1; i<=n; i++)
            cin>>a[i];
        
        memset(cnt, 0, sizeof(cnt));
        int m = 0;
        for (int i = 1; i <= 21; i++) {
            int mask = 1<<i;
            for (int j = 1; j <= n; j++) {
                if (a[j]&mask)
                    cnt[i]++;
            }

            m = __gcd(m, cnt[i]);
        }

        // 全是0
        if (m == 0) {
            for (int i = 1; i <= n; i++) cout << i << ' ';
            cout << endl;
            continue;
        } else {
            // 输出m的约数
            set<int> s;
            for (int i = 1; i*i <= m; i++) 
                if (m%i==0) {
                    s.insert(i);
                    s.insert(m/i);
                }
            
            for (auto it : s)
                cout << it << ' ';
            cout << endl;
        }        
    }
    return 0;
}