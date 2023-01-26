#include <bits/stdc++.h>
#include <iostream>
# define M_PI 3.14159265358979323846
using namespace std;
typedef long long ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> order_set;


const int mxN = 1e6+5;
const int mod = 1e9+7;
const int mxlogN = 20;
const int mxK = 20;

int n, k;

struct point
{
    int x, y;
    void scan()
    {
        cin >> x >> y;
    }
    double abs()
    {
        return sqrt(x*x+y*y);
    }
};

point ar[mxN];
const double eps = 1e-9;

bool ok(double r)
{
    vector<pair<double, int>> arr;
    for(int i = 0; i < n; i++)
    {
        double d = ar[i].abs();
        if(2*r < d) continue;
        double delta = acos(d/(2*r));
        double rad = atan2(ar[i].y, ar[i].x);
        if(rad < 0) rad = 2*M_PI+rad;
        if(rad-delta < 0)
        {
            arr.push_back({2*M_PI+(rad-delta), +1});
            arr.push_back({0, +1});
        }
        else
        {
            arr.push_back({rad-delta, +1});
        }
        if(rad+delta > 2*M_PI)
        {
            arr.push_back({rad+delta-2*M_PI, -1});
            arr.push_back({0, +1});
        }
        else
        {
            arr.push_back({rad+delta, -1});
        }
    }
    sort(arr.begin(), arr.end());
    int cur = 0;
    int ans = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        cur += arr[i].second;
        ans = max(ans, cur);
    }
    return ans >= k;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++) ar[i].scan();
    double l = 0, r = 2e5;
    for(int i = 0; i < 100; i++)
    {
        double m = (l+r)*0.5;
        if(ok(m)) r = m;
        else l = m;
    }
    printf("%.9f", r);
}
