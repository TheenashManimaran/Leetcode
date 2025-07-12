class Solution {

    void func(int ind, int t, List<Integer> ds, List<List<Integer>> ans, int nums[]){
        if(ind == nums.length){
            if(t == 0){
                ans.add(new ArrayList<>(ds));
            }
            return;
        }

        if(t >= nums[ind]){
            ds.add(nums[ind]);
            func(ind,t-nums[ind],ds,ans,nums);
            ds.remove(ds.size() - 1);
        }
        func(ind + 1, t, ds, ans, nums);
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> ds = new ArrayList<>();

        func(0,target,ds,ans,candidates);
        return ans;
    }
}