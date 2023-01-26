#include <bits/stdc++.h>
using namespace std;

#define lli long long
#define loop(i, l, r) for (lli i = l; l < r ? i < r : i > r; l < r ? i += 1 : i -= 1)
#define itr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define it(i, a) for (auto i : a)
#define endl "\n"
#define inputarray(arr, start, size) \
    loop(i, start, size) { cin >> arr[i]; }
#define printarray(arr, start, size)                \
    loop(i, start, size) { cout << arr[i] << " "; } \
    cout << endl;
#define mod 1000000007
#define inf 1e18
#define sp(x, y) fixed << setprecision(y) << x << endl;
#define pii pair<lli, lli>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define debug(x) cout << #x << "=" << x << endl

void file_IO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main()
{
    file_IO();
    lli t = 1;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;
        string s1, s2;
        cin >> s1;
        cin >> s2;
        lli ct = 0;
        if (n == 1)
        {
            if (s1[0] == '0' && s2[0] == '1')
                cout << "1" << endl;
            else
                cout << "0" << endl;
            continue;
        }
        loop(i, 0, n)
        {
            if (s1[i] == '0' && s2[i] == '1')
            {
                ct++;
                s2[i] == '0';
            }
        }
        if (s1[0] == '1' and s2[1] == '1')
        {
            ct++;
            s1[0] = '0';
            s2[1] = '0';
        }
        loop(i, 1, n - 1)
        {
            if (s1[i] != '0')
            {
                if (s2[i - 1] == '1')
                {
                    ct++;
                    s2[i - 1] = '0';
                }
                else if (s2[i + 1] == '1')
                {
                    ct++;
                    s2[i + 1] = '0';
                }
            }
        }
        if (s1[n - 1] == '1' and s2[n - 2] == '1')
        {
            ct++;
            s1[n - 1] = '0';
            s2[n - 2] = '0';
        }
        cout << ct << endl;
    }
    return 0;
}