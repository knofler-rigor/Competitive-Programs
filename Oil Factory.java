import java.util.Scanner;
public class OilFactory {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
	
		int numContainers = scan.nextInt();
		int[] cont = new int[numContainers];
		for(int i=0;i<numContainers; i++) {
			cont[i] = scan.nextInt();
		}
		
		for(int i=0;i<numContainers-1;i++) {
			for(int j=i+1;j<numContainers;j++) {
				if(cont[i]>cont[j]) {
					int temp = cont[i];
					cont[i] = cont[j];
					cont[j] = temp;
				}
			}
		}
		int mid = numContainers/2; 
		int n = numContainers-1; 
		
		for(int i=0; i<mid; i++) {
			System.out.println(cont[n]+" "+cont[i]); 
			n--;
		}
		
		if(numContainers%2 != 0) {
			System.out.println(cont[mid]+" 0");
		}
	}
}
