// It's better to do something rather than complaining 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define modi 1000000007
#define test int abc; cin>>abc; while(abc--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define yes "YES\n"
#define no "NO\n"
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define all(a) a.begin(),a.end()
#define endl "\n"
#define ld long double
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
inline void debugMode() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
}


void solve()
{
    int n; 
    cin>>n; 
    string s; 
    cin>>s; 
    char mat[n][n];
    init(mat,'?');

    vector<int> ans;

    for(int i=0;i<n;i++)
    {
        int count=1;
        int flag=0;
        if(s[i]=='1')
        {
            flag=1;
        }
        else
        {
            flag=2;
        }
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]=='+')
            {
                count=2;
            }
            if(mat[i][j]!='?')
            continue;

            if(i==j)
            {
                mat[i][j]='X';
                continue;
            }
            if(flag==1)
            {
                mat[i][j]='=';
                mat[j][i]='=';
            }
            else
            {
                if(s[j]=='1')
                {
                    mat[i][j]='=';
                    mat[j][i]='=';
                }
                else
                {
                    if(flag==2)
                    {
                        mat[i][j]='+'; 
                        mat[j][i]='-';
                        flag=0;
                        count=2;
                    }
                    else
                    {
                        mat[i][j]='-'; 
                        mat[i][j]='+';
                    }
                }
            }
        }
        ans.push_back(count);
    }

    for(int i=0;i<n;i++)
    {
        if(ans[i]!=(s[i]-'0'))
        {
            cout<<no;
            return;
        }
    }
    cout<<yes;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<mat[i][j];
        }
        cout<<endl;
    }
}
 
int32_t main(){
    debugMode();
    test
    solve();
    return 0;
}