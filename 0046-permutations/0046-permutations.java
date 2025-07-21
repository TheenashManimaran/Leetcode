class Solution {

    void func(int[] nums, List<Integer> ds, List<List<Integer>> ans, int map[], int n){
        int flag = 1;
        for(int i=0;i<n;i++){
            if(map[i] == 0){
                flag = 0;
                break;
            }
        }
        if(flag == 1) {
            ans.add(new ArrayList<>(ds));

            // System.out.println("1");
            // for(Integer i : ds){
            //     System.out.print(i + " ");
            // }System.out.println();
            
            return;
        }

        for(int i=0;i<n;i++){
            if(map[i] == 0){
                ds.add(nums[i]);
                map[i] = 1;
                func(nums, ds, ans, map, n);
                ds.remove(ds.size() - 1);
                map[i] = 0;

            }
        }
    }


    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> ds = new ArrayList<>();

        int n = nums.length;
        int[] map = new int[n];
        for(int i=0;i<n;i++){
            map[i] = 0;
        }

        func(nums, ds, ans, map, n);
        return ans;
    }
}