//
//  E1.java
//

class E1 {

	/**
	 * Realizzare in modo iterativo la funzione ric sotto riportata che
	 * controlla se l'array in input contiene una frase della grammatica {12}3,
	 * ossia una sequenza anche vuota di coppie 12, seguita da un 3. Come
	 * riferimento, si consideri che la funzione deve soddisfare il test sotto
	 * riportato.
	 * 
	 **/

	public static boolean ric(int[] a) {
		if (a.length % 2 == 0 || a[a.length - 1] != 3) {
			return false;
		}
		int i = 0;
		for (; i < a.length / 2 && a[2 * i] == 1 && a[2 * i + 1] == 2; i = i + 1);
		return (i == a.length / 2);
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
