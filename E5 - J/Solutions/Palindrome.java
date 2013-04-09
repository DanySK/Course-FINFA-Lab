import java.util.*;

class Palindrome {

  static int[] f(int n) {
    if(n < 0) {
      n = 0;
    }
    int[] res = new int[n*2 + 1];
    res[n] = 0;
    for(int i = 1; i <= n; i++) {
	res[n-i] = i;
	res[n+i] = i;
    }
    return res;
  }

  static int[] fr(int n) {
    if(n < 0) {
      n = 0;
    }
    int[] res = new int[n*2 + 1];
    res[n] = 0;
    return fr(n, 1, res);
  }

  static int[] fr(int n, int i, int[] res) {
    if(i <= n) {
	res[n-i] = i;
	res[n+i] = i;
	return fr(n, i+1, res);
    }
    return res;
  }

  static boolean test() {
    return Arrays.equals(f(0), new int[]{0}) && 
      Arrays.equals(f(-100), new int[]{0}) &&
      Arrays.equals(f(1), new int[]{1,0,1}) &&
      Arrays.equals(f(2), new int[]{2,1,0,1,2}) &&
      Arrays.equals(f(5), new int[]{5,4,3,2,1,0,1,2,3,4,5});
  }

  static boolean test_recursive() {
    return Arrays.equals(fr(0), new int[]{0}) && 
      Arrays.equals(fr(-100), new int[]{0}) &&
      Arrays.equals(fr(1), new int[]{1,0,1}) &&
      Arrays.equals(fr(2), new int[]{2,1,0,1,2}) &&
      Arrays.equals(fr(5), new int[]{5,4,3,2,1,0,1,2,3,4,5});
  }

  public static void main(String[] a) {
    System.out.print("Running test... ");
    boolean testResult = test();
    System.out.println("done. Result is "+testResult);
    System.out.print("Running test for the recursive... ");
    testResult = test_recursive();
    System.out.println("done. Result is "+testResult);
    if(a.length > 0) {
      System.out.println("Computing array with n="+a[0]+": ");
      System.out.println(Arrays.toString(f(Integer.parseInt(a[0]))));
    }
  }
  
}
