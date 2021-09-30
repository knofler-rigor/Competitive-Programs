import java.util.Scanner;

class Parser{
    Boolean isBalanced(String input) 
    {
        while(input.length()!=(input=input.replaceAll("\\(\\)|\\[\\]|\\{\\}","")).length());
        return input.isEmpty();
        

    }
    
}
class Solution {
    
    public static void main(String[] args) {
        Parser parser = new Parser();
        
        Scanner in = new Scanner(System.in);

        while (in.hasNext()) {
            System.out.println(parser.isBalanced(in.next()));
        }
        
        in.close();
    }
}
