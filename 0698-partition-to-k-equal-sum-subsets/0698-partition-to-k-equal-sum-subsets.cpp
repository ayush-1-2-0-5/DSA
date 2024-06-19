class Solution {
public:
    bool dp(int k,int mask,int remaining,int n,vector<int>& nums,int target,unordered_map<int,bool>& lookup){
        if(k==0) return true;
        int key=mask*20+k;
        
        if(lookup.find(key)==lookup.end()){
            bool ans=false;
            for(int i=0;i<n;i++){
                if(!(mask&(1<<i))){
                    if(nums[i]==remaining){
                        if(dp(k-1,mask|(1<<i),target,n,nums,target,lookup)){
                            ans=true;
                            break;
                        }
                    } else if(nums[i]<remaining){
                        if(dp(k,mask|(1<<i),remaining-nums[i],n,nums,target,lookup)){
                            ans=true;
                            break;
                        }
                    }
                }
            }
            
            lookup[key]=ans;             
        }
        
        return lookup[key];
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int num: nums) sum+=num;
        if(sum%k!=0) return false;
        int target=sum/k;
        unordered_map<int,bool> lookup;
        return dp(k,0,target,n,nums,target,lookup);
    }
};