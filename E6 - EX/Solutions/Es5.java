public class Es5 {

	/**
	 * Realizzare la funzione create sotto riportata che crea e ritorna un NUOVO
	 * array lungo size, i cui elementi a partire da 1 rappresentano una
	 * sequenza con incremento 1 di numeri interi in duplice copia se dispari,
	 * in copia unica se pari. Come riferimento si consideri la funzionalità di
	 * test sotto riportata.
	 **/

	public static int[] create(int size) {
		int[] a = new int[size];
		if (size == 0) {
			return a;
		}
		a[0] = 1;
		for (int i = 1; i < a.length; i++) {
			if (i % 3 == 1) {
				a[i] = a[i - 1];
			} else {
				a[i] = a[i - 1] + 1;
			}
		}
		return a;
	}

	public static boolean test() {
		return arrayEquals(create(0), new int[] {})
				&& arrayEquals(create(1), new int[] { 1 })
				&& arrayEquals(create(3), new int[] { 1, 1, 2 })
				&& arrayEquals(create(5), new int[] { 1, 1, 2, 3, 3 })
				&& arrayEquals(create(10), new int[] { 1, 1, 2, 3, 3, 4, 5, 5, 6, 7 })
				&& arrayEquals(create(11), new int[] { 1, 1, 2, 3, 3, 4, 5, 5, 6, 7, 7 });

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
