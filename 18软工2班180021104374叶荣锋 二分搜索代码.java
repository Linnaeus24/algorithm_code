public class r {
	public static  void main(String[] args) {
		int[] arr = {1,3,5,7,9,11};
		int key = 4;
		
		int position = commonBinarySearch(arr, key);
        if(position == -1){
			System.out.println("查找的是"+key+",序列中没有该数！");
		}
        else
        {
        	System.out.println("查找的是"+key+",找到位置为："+position);
        }
        System.out.println("没有找到");//最后仍然没有找到，则返回-1

	}
public static int commonBinarySearch(int[] arr,int key){
	int low = 0;
	int high = arr.length - 1;
	int middle = 0;			//定义middle
		
	if(key < arr[low] || key > arr[high] || low > high){
		return -1;				
	}
		
	while(low <= high){
		middle = (low + high) / 2;
		if(arr[middle] > key){
				//比关键字大则关键字在左区域
			high = middle - 1;
		}else if(arr[middle] < key){
				//比关键字小则关键字在右区域
			low = middle + 1;
		}else{
			return middle;
		}
	}
		
	return -1;		//最后仍然没有找到，则返回-1
	}
}
