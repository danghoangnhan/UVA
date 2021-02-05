import java.util.*;
import java.math.BigInteger;
 class UVA10814 {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int number =in.nextInt();
        for(int i=0;i<number;i++){
            //String s=in.nextLine();
           // String str[]=s.split("\\ |\\/");
           // BigInteger a = new BigInteger(str[0]);
          //  BigInteger b = new BigInteger(str[1]);
            BigInteger a =in.nextBigInteger();
            char c=in.next().charAt(0);
           BigInteger b =in.nextBigInteger();
           int compare = a.compareTo(b);
           BigInteger max=b,min=a;
           if(compare==1){
               max=a;
               min=b;
           }
            BigInteger num=gcd(max,min);
            System.out.println(a.divide(num)+" / "+b.divide(num));
        }
    }

    public static BigInteger gcd(BigInteger x,BigInteger y){
        BigInteger r = x.remainder(y);
        BigInteger zero= new BigInteger("0");
        if(r.equals(zero)){
            return y;
        }
        return gcd(y,r);
    }
}
