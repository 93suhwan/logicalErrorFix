#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define fo(i, n) for (ll i = 0; i < (ll)n; ++i)
#define fos(j, i, n) for (ll j = i; j < (ll)n; ++j)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define ror(i, n) for (ll i = (ll)n - 1; i >= 0; --i)
#define ve vector
typedef ve<ll> vi;
typedef ve<vi> vvi;
typedef pair<ll, ll> ii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> vec(n, 0);
        vector<int> temp(n, 0);
        for (auto &v : vec)
        {
            cin >> v;
        }
        for (int i = 0; i < n; i++)
        {
            temp[i] = vec[i];
        }
        sort(temp.begin(), temp.end());
        if (!(vec == temp))
        {
            cout << "YES" << endl;
        }
        else if(n==1){
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}