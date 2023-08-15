class Solution {
public:
    void helper(vector<string> &ans, string str,  int lp, int rp, int n) {
        if(lp == rp && lp == n && rp == n) {
            // cout<<lp<<" "<<rp<<endl;
            // cout<<str<<endl;
            ans.push_back(str);
            return;
        }
        //cout<<n<<" "<<lp<<endl;
        if(lp < n) {
            str += "(";
            cout<<"LP: "<<str<<endl;
            helper(ans, str, lp+1, rp, n);
            str.pop_back();
        }
        if(rp < lp) {
            str += ")";
            cout<<"RP: "<<str<<endl;
            helper(ans, str, lp, rp+1, n);
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int cnt = 0;
        string str = "";
        helper(ans, str, 0, 0, n);
        return ans;
    }
};