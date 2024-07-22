class Solution {
public:
    int fib(int n) {
        if(n==0)
        return 0;
        if(n==1 ||n==2)
        return 1;

        int arr[]={1,1};

        for(int i=3;i<=n;++i)
        {
            int temp=arr[1];
            arr[1]=arr[0]+arr[1];
            arr[0]=temp;
        }

        return arr[1];
        
    }
};