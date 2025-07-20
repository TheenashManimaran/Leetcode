class Solution {


    public List<List<String>> partition(String s) {
        
        List<List<String>> ans = new ArrayList<>();
        List<String> ds = new ArrayList<>();

        func(0,s,ans,ds);
        return ans;
    }

    public void func(int ind, String s, List<List<String>> ans, List<String> ds){

        if(ind == s.length()){
            ans.add(new ArrayList<>(ds));
            return;
        }

        for(int i=ind;i<s.length();i++){

            if(isPalindrome(ind,i,s)){

                ds.add(s.substring(ind,i+1));
                func(i+1,s,ans,ds);
                ds.remove(ds.size() - 1);
            }
        }
    }

    public boolean isPalindrome(int start, int end, String s){
        while(start<end){
            if(s.charAt(start++) !=  s.charAt(end--)) return false;
        }
        return true;
    }
}