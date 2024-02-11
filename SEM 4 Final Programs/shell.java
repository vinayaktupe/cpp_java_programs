import java.io.*;
class shell{
    void disp(int arr[]){
        int size=arr.length;
        for(int i=0;i<size;++i){
            System.out.println(arr[i]);
        }
    }
    void sort(int arr[]){
        int i,j,temp,gap,n;
        n=arr.length;
        for(gap=n/2;gap>0;gap/=2){
            for(i=gap;i<n;++i){
                temp=arr[i];
                for(j=i;j>=gap && arr[j-gap]>temp;j-=gap){
                    arr[j]=arr[j-gap]; 
                }
                arr[j]=temp;
            }
        }
        
        System.out.println("Sorted List:");
        disp(arr);
    }
    public static void main(String ...args){
        int ary[]={16,19,12,45,10,5};
        shell s=new shell();
        System.out.println("Unsorted List:");
        s.disp(ary);
        s.sort(ary);
    }
}