class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.size()==0) return 0;

        //case for open beacess 
        //n0. of times we require extra during closing braces
        stack<char>st;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(s[i]);

            else{
                if(!st.empty()){
                    st.pop();
                    continue;
                }
                else {
                    count++;
                    continue;
                }
            }
        }
        if(!st.empty()) count+=st.size();

        return count;
    }
};