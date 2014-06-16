import java.math.*;
import java.util.*;

class MINNUM
{
	public static void main(String[] args)
	{
		BigInteger bi1, bi2,bi3,bi4;
		bi2=new BigInteger("9");
		Scanner io=new Scanner(System.in);
		String str;
		str=io.next();
		while(!str.equals("-1"))
		{
			bi1=new BigInteger(str);
			bi4=bi1.divide(bi2);
			bi3=bi1.mod(bi2);
			if(!bi3.equals(new BigInteger("0")))
				bi4=bi4.add(new BigInteger("1"));
			System.out.println(bi4);
			str=io.next();
		}
	  }
}
