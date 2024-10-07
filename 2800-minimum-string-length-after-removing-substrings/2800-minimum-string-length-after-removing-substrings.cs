public class Solution {
    public int MinLength(string s) {
        Stack myStack = new Stack();
        int index = 0;

        while(index < s.Length) 
        {
            myStack.Push(s[index]);
            while((char)myStack.Peek() == 'B' || (char)myStack.Peek() == 'D')
            {
                char temp = (char)myStack.Pop();
                bool removed = false;
                if(myStack.Count != 0)
                {
                    
                    char secondTemp = (char)myStack.Peek();
                    //Console.WriteLine($"{temp} {secondTemp}");
                    if(secondTemp == 'A' && temp == 'B')
                    {
                        myStack.Pop();
                        removed = true;
                    }
                    if(secondTemp == 'C' && temp == 'D')
                    {
                        myStack.Pop();
                        removed = true;
                    }
                }

                if(removed == false)
                {
                    myStack.Push(temp);
                    break;
                }
                if(myStack.Count == 0)
                break;
            }
            index++;
        }
        return myStack.Count;
    }
}