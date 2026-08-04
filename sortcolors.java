class Solution {
    public void sortColors(int[] nums) {
        int c0=0;
        int c1=0;
        int c2=0;
        for(int num:nums){
            if(num==0){
                c0++;
            }
            else if(num==1){
                c1++;
            }
            else if(num==2){
                c2++;
            }
        }
        int i=0;
        while(c0!=0){
            nums[i++]=0;
            c0--;
        }
        while(c1!=0){
            nums[i++]=1;
            c1--;
        }
        while(c2!=0){
            nums[i++]=2;
            c2--;
        }
    }
}
