#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> order_set;


const int mxN = 1e6+5;
const int mod = 1e9+7;
const int mxlogN = 20;
const int mxK = 65;

int a[mxN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cout << "? ";
        for(int i = 1; i < n; i++) cout << n << " ";
        cout << i << "\n";
        cout.flush();
        int k; cin >> k;
        if(k)
        {
            a[n-1] = n+1-i;
            break;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(i == a[n-1]) continue;
        int x = n+1-i;
        int y = n+1-a[n-1];
        cout << "? ";
        for(int i = 1; i < n; i++) cout << x << " ";
        cout << y << "\n";
        cout.flush();
        int pos; cin >> pos;
        a[pos-1] = i;
    }
    cout << "! ";
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
    cout.flush();
}
