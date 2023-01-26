#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define watch(x) cout << (#x) << " is " << (x) << '\n'
#define dashline() cout << "=============\n"
#else
#define watch(x)
#define dashline()
#endif
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int arr[200011];

int main()
{
    cin.tie(nullptr); cout.tie(nullptr);
    ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif

    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int i,j;
        set<int> st;
        for(i=1;i<=n;i++)
        {
            cin>>arr[i];
            st.insert(arr[i]);
        }
        sort(arr+1,arr+n+1,greater<>());
        
        for(i=2;i<=n/2+1;i++)
        {
            int a=arr[1], b=arr[i];
            while( st.find(a%b) != st.end() )
            {
                int c=a%b;
                a=b;
                b=c;
            }
            cout<<a<<' '<<b<<'\n';
        }
        dashline();
    }

    return 0;
}