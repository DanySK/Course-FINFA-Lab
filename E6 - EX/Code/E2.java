public class E2 {

	/*
	 * Realizzare la funzione ric dell'esercizio precedente in modo ricorsivo, e
	 * tale che soddisfi il medesimo test.
	 */

	public static boolean ric(int[] a) {
		// Costruire anche altre funzioni se servono!
		return true;
	}

	public static boolean test() {
		return ric(new int[] { 3 })
				&& ric(new int[] { 1, 2, 3 })
				&& ric(new int[] { 1, 2, 1, 2, 1, 2, 3 })
				&& ric(new int[] { 1, 2, 1, 2, 3 })
				&& ric(new int[] { 1, 2, 1, 2, 1, 2, 1, 2, 3 })
				&& !ric(new int[] {})
				&& !ric(new int[] { 1, 2, 1, 2, 1, 2, 1, 2 })
				&& !ric(new int[] { 1 })
				&& !ric(new int[] { 1, 2, 1, 2, 1 })
				&& !ric(new int[] { 2 })
				&& !ric(new int[] { 1, 2, 1, 2, 2 })
				&& !ric(new int[] { 1, 2, 1, 2, 1, 2, 3, 1 })
				&& !ric(new int[] { 1, 2, 1, 2, 1, 2, 3, 2 })
				&& !ric(new int[] { 1, 2, 1, 2, 1, 2, 3, 3 })
				&& !ric(new int[] { 1, 2, 1, 2, 3, 1, 2 })
				&& !ric(new int[] { 1, 2, 1, 2, 1, 3 });
	}

	public static void main(String[] s) {
		System.out.println("" + test());
	}

	static String arrayToString(int[] a) {
		String s = "";
		for (int i = 0; i < a.length; i++) {
			s += a[i] + ";";
		}
		return s;
	}

	static boolean arrayEquals(int[] a, int[] b) {
		if (a.length != b.length)
			return false;
		for (int i = 0; i < a.length; i++) {
			if (a[i] != b[i]) {
				return false;
			}
		}
		return true;
	}

}
