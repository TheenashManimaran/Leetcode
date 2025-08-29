class Solution {
public:
// ..........monotonic stack...............
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mapp;

        stack<int> st;
        for(int i = nums2.size() - 1; i>= 0 ;i--){
            if(st.empty()){
                mapp[nums2[i]] = -1;
                st.push(nums2[i]);
            } 
            else{
                while(!st.empty()){
                    if(nums2[i] < st.top()) {
                        mapp[nums2[i]] = st.top();
                        st.push(nums2[i]);
                        break;
                    }
                    else{
                        st.pop();
                    }
                }
                if(st.empty()){
                    mapp[nums2[i]] = -1;
                    st.push(nums2[i]);

                }
            }
        }

        for(auto &i : nums1){
            i = mapp[i];
        }

        return nums1;
    }
};