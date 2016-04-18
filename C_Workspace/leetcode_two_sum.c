/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i,j;
    int *output;
    output = (int*)malloc(sizeof(int)*2);
    for (i = 0; i < numsSize; i++){
        for (j = i+1; j < numsSize; j++){
            if (nums[i] + nums[j] == target){
                printf("index1 = %d , index2 = %d",i+1,j+1);
                output[0] = i+1;
                output[1] = j+1;
                return output;
            }
            
        }
    } 
    
    return 0;
}