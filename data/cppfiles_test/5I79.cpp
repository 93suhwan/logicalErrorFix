#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
long long int arr1[500005];
long long int size1[500005];
vector<pair<int, int>> vec[100005];
// // ll height[500005];
int k;
bool vis[1 << 25];
// ll parent[500005];
// int dp[1500005];
// //  ans[500005];
// int color[500005];
// int white[500005];
// int black[500005];
// int ans[500005];
// vector<int> ans[500005];
// int mod = 1e9 + 7;
// ll fastexpo(ll a, ll b)
// {
//     ll ans = 1;
//     while (b)
//     {
//         if (b & 1)
//             ans = (ans * a) % mod;
//         b = b / 2;
//         a = (a * a) % mod;
//     }
//     return ans % mod;
// }
//vector<pair<long long int, long long int>> vec;
long long int find1(long long int node)
{
    while (node != arr1[node])
    {
        arr1[node] = arr1[arr1[node]];
        node = arr1[node];
    }
    return node;
}

// // void uni(long long int x, long long int y)

// // {
// //     long long int node1 = find1(x), node2 = find1(y);

// //     if (size1[node1] > size1[node2])
// //     {
// //         size1[node1] += size1[node2];
// //         arr1[node2] = node1;
// //     }
// //     else
// //     {
// //         size1[node2] += size1[node1];
// //         arr1[node1] = node2;
// //     }
// // }
// // vector<int> topology;
// // bool acy[500005];
// // bool f = 0;
// // int check = 0;
// // // int num = 0;
// // int counter = 0;
int Gcd[1000005];
int parent[1000005];
int height[1000005];
vector<pair<int, int>> vec1[1000005];
int ans = 0;
// void dfs(int node)
// {
//     vis[node] = 1;
//     for (int i = 0; i < vec[node].size(); i++)
//     {
//         if (!vis[vec[node][i].first])
//         {
//             height[vec[node][i]] = height[node] + 1;
//             parent[vec[node][i]] = node;
//             dfs(vec[node][i]);
//             // dp[node] += dp[vec[node][i]];
//         }
//     }

//     // return num;
// }
// // void dfs1(int node)
// // {
// //     vis[node] = 1;
// //     for (int i = 0; i < vec[node].size(); i++)
// //     {
// //         if (!vis[vec[node][i]])
// //         {
// //             ans[vec[node][i]] = max(ans[parent[vec[node][i]]], white[vec[node][i]] - black[vec[node][i]]);
// //             dfs(vec[node][i]);
// //         }
// //     }
// // }

// // bool comp(pair<int, pair<int, int>> &x, pair<int, pair<int, int>> &y)
// // {
// //     if (x.first > y.first)
// //         return true;
// //     if (x.first == y.first)
// //     {
// //         if (x.second.first < y.second.first)
// //         {
// //             return true;
// //         }
// //     }
// //     return false;
// // }
int divi[20000005];
bool vis1[20000005];
int pre_sum[20000005];
vector<int> prime;
void run()
{
    int j = 1;
    for (int i = 2; i < 20000001; i++)
    {
        if (!vis1[i])
            while (i * j < 20000001)
            {
                vis1[i * j] = 1;
                divi[i * j] = i;
                j++;
            }
        j = 1;
    }
    for (int i = 2; i < 1000001; i++)
    {
        // cout << i << " " << divi[i] << "\n";
        if (i == divi[i])
        {
            prime.push_back(i);
            pre_sum[i] = 1;
        }
    }
}
// void Factorial()
// {
//     ll fact[1001];
//     fact[0] = 1;
//     ll dp[1001][1001] = {0};
//     for (int i = 0; i < 1001; i++)
//     {
//         for (int j = 0; j < 1001; j++)
//         {
//             dp[i][j] = 0;
//         }
//     }
//     dp[0][0] = 1;
//     for (ll i = 0; i < 101; i++)
//     {
//         dp[i][0] = 1;
//         for (ll j = 1; j < i; j++)
//         {
//             dp[i][j] = (((dp[i][j - 1] * (i - j + 1)) % mod) * (fastexpo(j, mod - 2))) % mod;
//             // cout << i << " " << j << " " << dp[i][j] << endl;
//         }
//         dp[i][i] = 1;
//     }
//     for (ll i = 1; i < 1001; i++)
//     {
//         fact[i] = (fact[i - 1] * (ll)i) % mod;
//         // cout << fact[i] << endl;
//     }
// }

// // int dp[10000005];
// // int ans[10000005];
// // bool special[10000005];
// // int intersection(int a, int b, int c, int d)
// // {
// // int x=max(0,min())
// // }
ll countDivisibles(ll A, ll B, ll M)
{

    // Add 1 explicitly as A is divisible by M
    if (A % M == 0)
        return (B / M) - (A / M) + 1;

    // A is not divisible by M
    return (B / M) - (A / M);
}
// // ll Divisor(ll a, ll l, ll r, ll mo)
// // {
// //     l -= mo, r -= mo;
// //     // cout << l << " " << r << " "
// //     //  << "\n";
// //     if (r * l == 0)
// //     {
// //         if (r == 0)
// //         {
// //             return (r / a) - (l / a) + 1;
// //         }
// //         // return
// //     }

// //     return (r / a) - (l / a) + !(bool(l % a)) + bool(l * r < 0);
// // }

// // vector<int> Matrix(int **a, int k)
// // {
// //     vector<int> ans;
// // }
// // ll hashing[10000005];
// vector<int> divisors[100005], ans[100005];
// // int mp[10000005] = {0}, mp1[10000005] = {0};
// bool func(ll &n, ll mid)
// {
//     ll sum = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         sum += min(((ll)(mid / i)), (ll)n);
//     }
//     ll val = ((n * n) / 2) + 1;
//     // cout << sum << " " << val << endl;
//     if (sum < val)
//     {
//         return false;
//     }
//     return true;
// }
// int mod = 1e9 + 7;

int segmenttree[2000005];
void build(int arr[], int index, int left, int right)
{
    if (left == right)
    {
        segmenttree[index] = arr[left];
    }
    else
    {
        int mid = (left + right) / 2;
        build(arr, 2 * index + 1, left, mid);
        build(arr, 2 * index + 2, mid + 1, right);
        segmenttree[index] = min(segmenttree[index * 2 + 1], segmenttree[index * 2 + 2]);
    }
}
int Action(int index, int left, int right, int qleft, int qright)
{
    if (qleft > qright)
    {
        return 0;
    }
    if (left == qleft && right == qright)
    {
        return segmenttree[index];
    }
    int mid = (left + right) / 2;
    return Action(2 * index + 1, left, mid, qleft, min(mid, right)) + Action(2 * index + 2, mid + 1, right, max(left, mid + 1), qright);
}
void update(int index, int val, int left, int right)
{
}
bool check_collinear(int x1, int y1, int x2, int y2, int x3, int y3)
{
    // int a = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    int dis1 = abs(x1 - x2) + abs(y1 - y2);
    int dis2 = abs(x1 - x3) + abs(y1 - y3);
    int dis3 = abs(x3 - x2) + abs(y3 - y2);

    // cout << dis1 << " " << dis2 << " " << dis3 << endl;
    if ((dis1 == dis2 + dis3) || (dis2 == dis3 + dis1) || (dis3 == dis1 + dis2))
        return true;
    else
        return false;
}
int check(string str, char c)
{
    int val = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c)
        {
            val++;
        }
    }
    return val;
}
bool comp(pair<int, int> a, pair<int, int> b)
{
    if (b.second - b.first < a.second - a.first)
    {
        return true;
    }
    else
    {
        if (b.second - b.first == a.second - a.first)
        {
            if (b.second > a.second)
            {
                return true;
            }
        }
    }
    return false;
}
int func(int x)
{
    if (x <= 0)
        return 1;
    return func(x - 1) + 2 * (x - 1);
}
int main()
{
    // run();
    // freopen("square.in", "r", stdin);
    // freopen("square.out", "w", stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // for (int i = 1; i < 1000001; i++)
    // {
    //     for (int j = i; j < 1000001; j += i)
    //     {
    //         divisors[j].push_back(i);
    //     }
    // }
    // run();
    // int counter[200002][5] = {0};
    // int t;
    // cin >> t;
    // while (t--)
    // {
    // }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string str1, str2;
        cin >> str1 >> str2;
        int ans = 0;
        bool vis[n] = {0};
        for (int i = 0; i < n; i++)
        {
            if (str2[i] == '1')
            {
                if (str1[i] == '0')
                {
                    ans++;
                }
                else
                {
                    if (i == 0)
                    {
                        if (str1[i + 1] == '1' && vis[i + 1] == 0)
                        {
                            ans++;
                            vis[i + 1] = 0;
                        }
                    }
                    else
                    {
                        if (i == n - 1)
                        {
                            if (str1[i - 1] == '1' && vis[i - 1] == 0)
                            {
                                ans++;
                                vis[i - 1] = 1;
                            }
                        }
                        else
                        {
                            if (str1[i - 1] == '1' && vis[i - 1] == 0)
                            {
                                ans++;
                                vis[i - 1] = 1;
                            }
                            else
                            {
                                if (str1[i + 1] == '1' && vis[i + 1] == 0)
                                {
                                    ans++;
                                    vis[i + 1] = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}