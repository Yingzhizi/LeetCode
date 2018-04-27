// Input: ["flower","flow","flight"]
// Output: "fl"
char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize==0) return "";
    if(strsSize==1) return strs[0];
    //always compare with the strs[0]
    //but need to reset strs
    for(int i=1; i<strsSize; i++){
        for(int j=0; strs[0][j]!= '\0'; j++){
            if(strs[i][j] != strs[0][j]){
                strs[0][j] = '\0';
                if(j==0) {
                    return "";
                }
                break;
            }
        }
    }
    return strs[0];
}
