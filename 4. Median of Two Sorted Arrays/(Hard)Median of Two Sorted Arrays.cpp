

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int totalSize = nums1Size+nums2Size;
    int n1 = 0 , n2 = 0;
    int total[totalSize];
    while(n1<nums1Size && n2<nums2Size){//先把一個陣列放進去
        if(nums1[n1]<nums2[n2]){
            n1++;
            total[n1+n2-1] = nums1[n1-1];
        }
        else{
            n2++;
            total[n1+n2-1] = nums2[n2-1];  
        }
    }
    //把剩下的再放進去
    if(n1<nums1Size){
        for(n1 ; n1 < nums1Size ; n1++){
            total[n1+n2] = nums1[n1];
        }
    }
    if(n2<nums2Size){
        for(n2 ; n2 < nums2Size ; n2++){
            total[n1+n2] = nums2[n2];
        }
    }
    if(totalSize%2==0)//偶數
        return (double)(total[totalSize/2-1] + total[totalSize/2])/2;
    else//奇數
        return (double)total[totalSize/2];
}

