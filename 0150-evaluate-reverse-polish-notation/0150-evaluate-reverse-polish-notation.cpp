class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;

        int i=0;

        while(i < n){

            if(tokens[i] == "+"){
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                int ans = num1 + num2;
                st.push(ans);
            }
            else if(tokens[i] == "-"){
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                int ans = num1 - num2;
                st.push(ans);
            }
            else if(tokens[i] == "*"){
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                int ans = num1 * num2;
                st.push(ans);
            }
            else if(tokens[i] == "/"){
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                int ans = num1 / num2;
                st.push(ans);
            }
            else{
                int num = stoi(tokens[i]);
                st.push(num);
            }
            i++;
        }

        return st.top();
    }
};