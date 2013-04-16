class Es2{

	// riconoscitore in forma ricorsiva grammatica {0}{2}^n{3}^n
	public static boolean ric(int[] a) {
		return ric(a, 0);
	}

	public static boolean ric(int[] a, int i) {
		if (i == a.length) {
			return true;
		}
		if (i < a.length && a[i] == 0) {
			return ric(a, i + 1);
		}
		if (i < a.length && a[i] == 2) {
			return ric(a, i, 0);
		}
		return false;
	}

	public static boolean ric(int[] a, int i, int n) {
		if (i < a.length && a[i] == 2) {
			return ric(a, i + 1, n + 1);
		}
		if (i < a.length && a[i] == 3) {
			return ric1(a, i, n);
		}
		return false;
	}

	public static boolean ric1(int[] a, int i, int n) {
		if (i < a.length && a[i] == 3) {
			return ric1(a, i + 1, n - 1);
		}
		if (n == 0 && i == a.length) {
			return true;
		}
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
