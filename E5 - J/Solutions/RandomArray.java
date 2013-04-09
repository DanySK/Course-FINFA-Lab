import java.util.*;

class RandomArray {

  static int[] f(int n) {
    int[] r = new int[n];
    for(int i = 0; i<n; i++) {
      r[i] = (int)(Math.random() * 1000);
    }
    return r;
  }

  public static void main(String[] a) {
    int n = 10;
    if(a.length > 0) {
      int arg = Integer.parseInt(a[0]);
      if(arg >= 0) {
	n = arg;
      }
    }
    System.out.println("Here is your fresh random array! " + Arrays.toString(f(n)));
  }
  
}
