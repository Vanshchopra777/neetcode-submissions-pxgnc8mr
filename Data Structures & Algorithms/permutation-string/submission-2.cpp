class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n1=s1.length();
        int n2=s2.length();

        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        for(auto it:s1){
            freq1[it-'a']++;
        }

        int i=0;
        for(int j=0;j<n2;j++){
            freq2[s2[j]-'a']++;

            if(j-i+1>n1){
                freq2[s2[i]-'a']--;
                i++;
            }
            if(freq1==freq2)return true;

        }
        return false;

        
    }
};
