
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;


#define LETS_GET_SCHWIFTY ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
#define ff              first
#define ss              second
#define int             long long
#define ll              long long
#define pb              push_back
#define pii             pair<int,int>
#define vi              vector<int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)      __builtin_ctzll(x)
#define mod             998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define vpii            vector<pair<int,int> >
#define all(x)          x.begin(),x.end()
#define matrixprint(arr,a,b,c,d) for(int i=a;i<=c;i++){for(int j=b;j<=d;j++){cout<<arr[i][j]<<" ";}cout<<"\n";}
#define show(arr,x,y)   for(int i=x;i<=y;i++){cout<<arr[i]<<" ";}cout<<"\n"
#define sz(x)           (int)x.size()
#define db(x)           cout<<x<<"\n";

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

//insert,find_by_order,order_of_key,lower_bound,upper_bound;

#define TRACE
#ifdef TRACE
#define deb(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define deb(...)
#endif

  
//////////////////////////////code//////////////////////////////

const int N = 200;
int n , m;
int dx[4] = {-1 , 1 , 0 , 0};
int dy[4] = {0 , 0 , -1 , 1};

int ok(int x,int y, vector<vector<char> >&arr)
{
        int cnt = 0;

        for(int i = 0;i < 4 ; i++)
        {
                int nx = dx[i] + x , ny = dy[i] + y;

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && (arr[nx][ny] == '.' || arr[nx][ny] == 'L'))
                    cnt++;
        }

        return cnt <= 2;
}

void solve()
{


    cin >> n >> m;
    vector<vector<char > >arr(n + 1 , vector<char>(m + 1));
    queue<pii>q;

    vector<vi> dis(n + 1 , vi(m + 1 , -1));

    for(int i = 0;i < n; i++)
        for(int j = 0;j < m; j++)
        {
            cin >> arr[i][j];

            if(arr[i][j] == 'L')
            {
                q.push({i , j});
                dis[i][j] = 0;
            }
        }


    while(!q.empty())
    {
            auto it = q.front();
            int x = it.ff , y = it.ss;
            q.pop();

            for(int i = 0;i < 4;  i++)
            {
                    int nx = dx[i] + x , ny = dy[i] + y;

                    if(nx >= 0 && nx < n && ny >=0 && ny < m && dis[nx][ny] == -1 && arr[nx][ny] != '#' && ok(nx , ny , arr))
                    {
                            dis[nx][ny] = 1 + dis[x][y];
                            q.push({nx , ny});
                    }
            }
    }


    for(int i = 0;i < n; i++)
    {


        for(int j = 0;j < m; j++)
        {
                if(arr[i][j] == '.')
                {
                        if(dis[i][j] > -1)
                            cout << '+';
                        else
                            cout << '.';
                }
                else
                    cout << arr[i][j];
        }

        cout << "\n";

    }


}

int32_t main()
{   

    LETS_GET_SCHWIFTY;

     #ifndef ONLINE_JUDGE
     freopen("INP.txt", "r", stdin);
     freopen("out.txt", "w", stdout);
     #endif  


    int t = 1;
   cin >> t;

    while (t--)
        solve();

}

// check out for following mistakes-
// if using pb operation on vector and then trying to access index..check if sizeof that vec could remain 0 only
// is using prime sieve make sure it fits
// when using factorial template or combinatorics make sure that you edit fillfac fun values and array values

