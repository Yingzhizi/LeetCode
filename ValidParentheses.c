// Given a string containing just the characters '(', ')', '{', '}', '[' and ']'
// determine if the input string is valid.

// Example 1:
// Input: "()"
// Output: true

// Example 2:
// Input: "()[]{}"
// Output: true

// Example 3:
// Input: "(]"
// Output: false

// Example 4:
// Input: "([)]"
// Output: false

// Example 5:
// Input: "{[]}"
// Output: true

bool isValid(char* s) {
    int length = strlen(s);
    //if the length is odd, then it's not valid
    if (length % 2) return false;

    //create a stack with size = length/2
    int limit = length / 2;
    char *stack = malloc(limit*sizeof(char));

    int i;
    int index = 0;
    for(i = 0; i < length; i++) {
        char curr = s[i];
        //if {, [, (, push to stack
        if (curr == '{' || curr == '[' || curr == '(') {
            if (index == limit) return false;
            stack[index] = curr;
            index++;
        } else {
            if (index == 0) return false;
            //if reach '}', ']', ')', check weather it match top of the stack
            //if match, pop the top
            if((curr == '}' && stack[index - 1] == '{') || (curr == ']' && stack[index - 1] == '[') || (curr == ')' && stack[index - 1] == '(')) {
                index--;
            } else {
                return false;
            }
        }
    }
    if (index != 0) {
        return false;
    }
    return true;
}
