//package test;
import java.math.BigInteger;
import java.util.*;
 class 10862 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		BigInteger[] series = new BigInteger[2005];
		 BigInteger limit = BigInteger.valueOf(2005);
		 series[1] = BigInteger.valueOf(1);
		 series[2] = BigInteger.valueOf(3);
		 for(int i=3;i<=2000;i++) {
			 series[i]=series[i-1].multiply(BigInteger.valueOf(2)).add((series[i-1].subtract(series[i-2])));
		 }
		 
		 while(true) {
			 int sample = in.nextInt();
			 if(sample==0)
				 break; 
			 System.out.println(series[sample]);		 
	}	
	}

}
