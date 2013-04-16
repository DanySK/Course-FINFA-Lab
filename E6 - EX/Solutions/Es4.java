class Es4 {

	/**
	 * Realizzare la funzione onlyPos sotto riportata che crea e ritorna un
	 * NUOVO array i cui elementi sono, in ordine, gli elementi di a maggiori di
	 * 0. Come riferimento si consideri la funzionalità di test sotto riportata.
	 **/

	public static int[] onlyPos(int[] a) {
		int pos = 0;
		for (int i = 0; i < a.length; i++) {
			if (a[i] > 0) {
				pos += 1;
			}
		}
		int[] b = new int[pos];
		int j = 0;
		for (int i = 0; i < a.length; i++) {
			if (a[i] > 0) {
				b[j] = a[i];
				j++;
			}
		}
		return b;
	}

	public static boolean testOnlyPos() {
		return arrayEquals(onlyPos(new int[] {}), new int[] {})
				&& arrayEquals(onlyPos(new int[] { 1, 2, 3 }), new int[] { 1, 2, 3 })
				&& arrayEquals(onlyPos(new int[] { -2, -5, 0 }), new int[] {})
				&& arrayEquals(onlyPos(new int[] { -2, 1, -3, 2 }), new int[] {1, 2 });
	}

	public static void main(String[] s) {
		System.out.println("" + testOnlyPos());
	}

	public static String arrayToString(int[] a) {
		String s = "(";
		for (int i = 0; i < a.length; i++) {
			s = s + a[i];
			if (i != a.length - 1) {
				s = s + ",";
			}
		}
		return s + ")";
	}

	public static boolean arrayEquals(int[] a, int[] b) {
		if (a.length != b.length) {
			return false;
		}
		for (int i = 0; i < a.length; i++) {
			if (a[i] != b[i]) {
				return false;
			}
		}
		return true;
	}
}
