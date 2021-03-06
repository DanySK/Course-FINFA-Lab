import java.util.*;

class PushZeroes {

  static int[] f(int[] a) {
    System.out.print(Arrays.toString(a) + " --> ");
    int ones = 0;
    for(int i=0; i<a.length; i++){
      if(a[i] == 1) {
	ones++;
      }
    }
    int[] res = new int[a.length+ones];
    int zeroes = 0;
    for(int i = 0; i < a.length; i++) {
      res[i+zeroes] = a[i];
      if(a[i] == 1){
	zeroes++;
	res[i+zeroes] = 0;
      }
    }
    System.out.println(Arrays.toString(res));
    return res;
  }

  static boolean test() {
    return Arrays.equals(f(new int[]{}), new int[]{}) && 
      Arrays.equals(f(new int[]{1}), new int[]{1,0}) &&
      Arrays.equals(f(new int[]{1,1,1}), new int[]{1,0,1,0,1,0}) &&
      Arrays.equals(f(new int[]{0,1,2,3}), new int[]{0,1,0,2,3}) &&
      Arrays.equals(f(new int[]{2,3,4,5}), new int[]{2,3,4,5}) &&
      Arrays.equals(f(new int[]{2,2,1,2,2,1}), new int[]{2,2,1,0,2,2,1,0});
  }

  public static void main(String[] a) {
    System.out.println("Running test... ");
    boolean testResult = test();
    System.out.println("done. Result is "+testResult);
  }
  
}