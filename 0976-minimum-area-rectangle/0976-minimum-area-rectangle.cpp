class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int,int>> s;

        int n = points.size();
        for(int i=0;i<n;i++){
            s.insert({points[i][0],points[i][1]});
        }
        for(auto p: s){
            cout<<p.first<<" "<<p.second<<endl;
        }

        int minArea = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                int x1 = points[i][0] , y1 = points[i][1];
                int x2 = points[j][0] , y2 = points[j][1];
                // different points (x1,x2 and y1,y2 all are different which forms diagonal)
                if(x1 != x2 && y1 != y2){

                    // if other two points are present
                    if(s.count({x1,y2}) && s.count({x2,y1})){
                        int area = abs(x1 - x2) * abs(y1 - y2);
                        minArea = min(minArea, area);
                    }
                }
            }
        }
        return (minArea != INT_MAX)? minArea : 0;
    }
};