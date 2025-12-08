class Solution {
public:
    int countTriples(int n) {
        
        int count = 0;
        for(int i = 3; i<n;i++){
            for(int j=3;j<n;j++){
                for(int k = 5;k<=n;k++){
                    if((i * i) + (j*j) == (k*k)) {
                        count+=1;
                        //cout<<i<<" "<<j<<" "<<k<<endl;
                    }
                    
                }
            }
        }

        return count;
    }
};