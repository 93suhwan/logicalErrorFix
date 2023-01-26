#include <bits/stdc++.h>
#define int long long
using pii=std::pair<int,int>;
using namespace std;

const int maxn = 2e5 + 5;

int t, n, a[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for(int cases = 0; cases < t; cases++)
    {
        cin >> n;
        int cnt[30] = {0}, all_zero = 1;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            all_zero &= (a[i] == 0);
            for(int j = 0; j < 30; j++)
                if(a[i] & (1ll << j))
                    cnt[j]++;
        }
        if(all_zero)
        {
            for(int i = 1; i <= n; i++)
                cout << i << " ";
            cout << "\n";
            continue;
        }
        int ans = n;
        for(int j = 0; j < 30; j++)
        {
            ans = __gcd(ans, cnt[j]);
            ans = __gcd(ans, (n - cnt[j]));
        }
        for(int i = 1; i <= ans; i++)
            if(ans % i == 0)
                cout << i << " ";
        cout << "\n";
    }
    return 0;
}