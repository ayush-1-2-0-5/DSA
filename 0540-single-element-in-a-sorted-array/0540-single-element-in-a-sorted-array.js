/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNonDuplicate = function(nums) {
    var ans=0;
    for(let i=0;i<nums.length;++i)
    {
       ans=ans^nums[i];
    }
  return ans;
};