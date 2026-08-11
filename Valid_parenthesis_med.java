import java.util.Stack;
class Solution {
    public boolean checkValidString(String s) {
        Stack<Integer> leftstack=new Stack<>();
        Stack<Integer> starstack=new Stack<>();
        for(int i=0;i<s.length();i++){
            char c=s.charAt(i);
            if(c=='('){
                leftstack.push(i);
            }
            else if(c=='*'){
                starstack.push(i);
            }
            else{
                if(!leftstack.isEmpty()){
                    leftstack.pop();
                }
                else if(!starstack.isEmpty()){
                    starstack.pop();
                }
                else{
                    return false;
                }
            }

        }
        while(!leftstack.isEmpty()&&!starstack.isEmpty()){
            if(leftstack.pop()>starstack.pop()){
                return false;
            }
        }
        return leftstack.isEmpty();
    }
}
