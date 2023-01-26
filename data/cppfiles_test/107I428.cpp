#include <iostream>
using namespace std;

void swap(int *a,int *b)
{
    int dummy{};
    dummy=*a;
    *a=*b;
    *b=dummy;
}

int main()
{
    int t{};
    cin>>t;
    while(t--)
    {
        int n{},a{},b{};
        cin>>n>>a>>b;
        int arr[n+1]{};
        for(int i=1;i<=n;i++)
            arr[i]=i;
        if(a+b+2>n || a-b>1 || a-b<-1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(a==0 && b==0)
        {
            for(int i=1;i<=n;i++)
                cout<<arr[i]<<' ';
            cout<<endl;
            continue;
        }
        if(a>=b)
        {
            for(int i=n;i>n-a-b-1;i-=2)
            {
                swap(&arr[i],&arr[i-1]);
            }
        }
        else
        {
            for(int i=1;i<a+b+2;i+=2)
            {
                swap(&arr[i],&arr[i+1]);
            }
        }
        for(int i=1;i<=n;i++)
            cout<<arr[i]<<' ';
        cout<<endl;
        int count{};
        // for(int i=2;i<=n-1;i++)
        // {
        //     if(arr[i]>arr[i+1] && arr[i]>arr[i-1])
        //         count++;
        // }
        // cout<<count<<endl;
    }
}