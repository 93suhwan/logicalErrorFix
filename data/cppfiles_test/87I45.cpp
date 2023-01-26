#include<bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,m;
        cin>>n>>m;
        int A[m];int B[m]={0};
        int total=0;
        for(int q=0;q<m;q++)
        {
            cin>>A[q];
            A[q]=A[q]-1;

        }

        for(int q=0;q<m;q++)
        {
            B[A[q]]+=1;
            for(int w=0;w<m;w++)
            {
                total+=B[w];
            }
        }
        cout<<total<<endl;
    }
}
int32_t main()
{

   solve();
    return 0;
}
