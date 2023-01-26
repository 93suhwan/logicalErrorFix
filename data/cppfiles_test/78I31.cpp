#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
const int maxn = 2e5 + 10;

int n, a[maxn];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    int nod = 0;
    for (int bit = 0; bit <= 30; bit ++)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i ++)
        {
            if ((a[i] & (1 << bit)) > 0)
                cnt ++;
        }

        nod = __gcd(nod, cnt);
    }

    vector < int > v;
    for (int j = 1; j <= sqrt(nod); j ++)
    {
        if (nod % j == 0)
        {
            v.push_back(j);
            if (j * j != nod)
            v.push_back(nod / j);
        }
    }

    sort(v.begin(), v.end());
    if (nod == 0)
    {
        for (int i = 1; i <= n; i ++)
            v.push_back(i);
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i ++)
        cout << v[i] << " ";
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t --)
        solve();
    return 0;
}
