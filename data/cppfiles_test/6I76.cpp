/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 200000;

const int MOD = (int) 1e9 + 7;

int pwr (const int &a, const int &b)
{
    if(b == 0)
        return 1;
    if(b & 1)
        return (ll) a * pwr(a, (b ^ 1)) % MOD;
    int aux = pwr(a, (b >> 1));
    return (ll) aux * aux % MOD;
}

int f[N_MAX + 2];

vector <int> divs[N_MAX + 2];

int n;

int a[N_MAX + 2];
int cnt[N_MAX + 2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 1; i <= N_MAX; i++)
        f[i] = i;
    for(int d = 1; d <= N_MAX; d++)
        for(int i = d; i <= N_MAX; i += d)
        {
            if(i != d)
            {
                f[i] -= f[d];
                if(f[i] < 0)
                    f[i] += MOD;
            }
            divs[i].push_back(d);
        }

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    int answer = 0;
    for(int d = 1; d <= n; d++)
    {
        int sum = 0;
        if(n / d <= 100)
        {
            for(int i = d; i <= n; i += d)
                for(int j = d; j <= n; j += d)
                {
                    sum += __gcd(a[i], a[j]);
                    if(sum >= MOD)
                        sum -= MOD;
                }
        }
        else
        {
            for(int i = d; i <= n; i += d)
                for(int g : divs[a[i]])
                    cnt[g]++;

            for(int i = d; i <= n; i += d)
                for(int g : divs[a[i]])
                {
                    sum = (sum + (ll) f[g] * cnt[g]) % MOD;
                    cnt[g] = 0;
                }
        }

        answer = (answer + (ll) sum * f[d]) % MOD;
    }

    cout << answer << "\n";

    return 0;
}
