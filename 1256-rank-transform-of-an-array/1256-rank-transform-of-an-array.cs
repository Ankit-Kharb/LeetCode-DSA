public class CustomNumber
{
    public int value;
    public int index;
    public CustomNumber(int value, int index)
    {
        this.value = value;
        this.index = index;
    }
}

public class Solution {

    public int[] ArrayRankTransform(int[] arr) {
        int size = arr.Length;
        int[] result = new int[size];
        List<CustomNumber> list = new List<CustomNumber>();

       for(int i = 0; i < size; i++) 
       {
            list.Add(new CustomNumber(arr[i], i));
       }

       list.Sort((x,y)=> x.value<y.value ? -1 : 1);
       int rank = 0;
       for(int i=0;i<size;i++)
       {
            if(i>0 && list[i-1].value == list[i].value)
            {
                arr[list[i].index] = rank;
            }
            else
            {
                rank++;
                arr[list[i].index] = rank;
            }
       }
       return arr;
    }
}