class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length()==0)
        {
            return 0;
        }

        int curlen=0;
        int maxlen=0;
        //init char array
        int position[256];
        for (int i = 0; i < 256; ++i)
        {
            position[i]=-1;
        }
        for (int i = 0; i < s.length(); ++i)
        {
           
            int prevIndex=position[s[i]];
            if (prevIndex<0||i-prevIndex>curlen)
            {
                ++curlen;
            }else{
                if (curlen>maxlen)
                {
                    maxlen=curlen;
                }
                curlen=i-prevIndex;

            }
            position[s[i]]=i;
        }
        if (curlen>maxlen)
        {
            maxlen=curlen;
        }
        return maxlen;
        
    }
};