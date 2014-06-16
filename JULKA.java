import java.math.*;
import java.util.*;

class JULKA
{
	public static void main(String[] args)
	{
		BigInteger bi1, bi2, bi3,bi4;
		bi4=new BigInteger("2");
		Scanner io=new Scanner(System.in);
		String temp;
		int test=10;
		while(test-->0)
		{
			temp=io.next();
			bi1=new BigInteger(temp);
			temp=io.next();
			bi2=new BigInteger(temp);
			bi3=bi1.subtract(bi2);
			bi3=bi3.divide(bi4);
			bi1=bi3.add(bi2);
			System.out.println(bi1);
			System.out.println(bi3);
		}
	  }
}
