#include<stdio.h>


int binarysearch (int *arr , int size , int elem){
int found=0;
int first=0;
int last=size;
while(first<=last&& !found){
int mid =( first+last)/2;
if(arr[mid]==elem){
found=1;
printf("index is %d \n",mid);
}
else if(arr[mid]<elem){
first=mid+1;}
else{
last=mid-1;}
}

if(found!=1){
found =-1;}

return found;

}

int main(){
int arr[6]={9,6,3,5,7,8};
int size = sizeof(arr)/sizeof(int);
int result = binarysearch(arr,size,8);
printf("%d",result);
return 0;
}
 
