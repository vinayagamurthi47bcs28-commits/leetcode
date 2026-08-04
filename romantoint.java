class Solution {
    public int romanToInt(String s) {
       int total=0;
       int n=s.length();
       for(int i=0;i<n;i++){
        int currentvalue=getvalue(s.charAt(i));
        if(i+1<n && currentvalue<getvalue(s.charAt(i+1))){
            total-=currentvalue;
        }
        else{
            total+=currentvalue;
        }
       }
       return total; 
    }
    private int getvalue(char c){
        switch(c){
            case'I':return 1;
            case'V':return 5;
            case'X':return 10;
            case'L':return 50;
            case'C':return 100;
            case'D':return 500;
            case'M':return 1000;
            default:return 0;
        }


    }
}
