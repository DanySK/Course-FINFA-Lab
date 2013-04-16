class Es2 {

	// riconoscitore in forma ricorsiva grammatica {0}{2}^n{3}^n
	public static boolean ric(int[] a) {
		return false;
	}

	public static boolean test() {
		return ric(new int[] {})
				&& ric(new int[] { 0, 0, 0 })
				&& ric(new int[] { 0, 0, 0, 2, 2, 3, 3 })
				&& ric(new int[] { 2, 2, 2, 3, 3, 3 })
				&& ric(new int[] { 2, 3 })
				&& !ric(new int[] { 2, 2, 2, 3, 3 })
				&& !ric(new int[] { 1, 0 })
				&& !ric(new int[] { 2, 2, 3, 3, 3 })
				&& !ric(new int[] { 0, 0, 0, 2, 2, 0, 3, 3 });
	}

	public static void main(String[] s) {
		System.out.println("" + test());
	}
}
