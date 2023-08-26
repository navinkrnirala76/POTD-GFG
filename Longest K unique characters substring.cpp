 int i=0;
    int res=-1;
    unordered_map<char,int>mp;
    for(int j=0;j<s.length();j++){
        mp[s[j]]++;
        while(mp.size()>k){
            mp[s[i]]--;
            if(mp[s[i]]==0){
                mp.erase(s[i]);
            }
            i++;
        }
        if(mp.size()==k){
            res=max(res,j-i+1);
        }
    }
    return res;
    
