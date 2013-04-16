public class E3 {

	/*
	 * Realizzare la funzione create sotto riportata che dato l'array a in
	 * ingresso, crea e ritorna un NUOVO array lungo quanto a, e che ricopia
	 * esattamente gli elementi di a finché questi sono in ordine strettamente
	 * crescente, poi lascia il resto al valore rest. Come riferimento si
	 * consideri la funzionalità di test sotto riportata.
	 */

	public static int[] create(int[] a, int rest) {
		/*
		 * Per verificare qual è il valore dell'indice (e quindi essere
		 * coscienti di quale valore dell'array si sta di volta in volta
		 * leggendo o assegnando, si può usare all'interno del for l'istruzione:
		 * System.out.println("index = " +i);
		 */
		return new int[] {};
	}

	public static boolean test() {
		return arrayEquals(create(new int[] {}, -1), new int[] {})
				&& arrayEquals(create(new int[] { 1 }, -1), new int[] { 1 })
				&& arrayEquals(create(new int[] { 1, 7, 10, 15 }, -1), new int[] { 1, 7, 10, 15 })
				&& arrayEquals(create(new int[] { 1, 7, 10, 8, 4 }, -1), new int[] { 1, 7, 10, -1, -1 })
				&& arrayEquals(create(new int[] { 1, 7, 10, 8, 4 }, 0), new int[] { 1, 7, 10, 0, 0 })
				&& arrayEquals(create(new int[] { 1, 7, 4, 6, 3 }, 0), new int[] { 1, 7, 0, 0, 0 })
				&& arrayEquals(create(new int[] { 1, 7, 4, 6, 12 }, 0), new int[] { 1, 7, 0, 0, 0 })
				&& arrayEquals(create(new int[] { 10, 9, 8, 7 }, -1), new int[] { 10, -1, -1, -1 })
				&& arrayEquals(create(new int[] { 1, 7, 10, 10, 4 }, 0), new int[] { 1, 7, 10, 0, 0 });

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
