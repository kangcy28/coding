const int maxn = 100005;
int sum[maxn << 2];
int lazy[maxn << 2];

void pushdown(int rt, int m) {
	if(lazy[rt]) {
		lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
		sum[rt << 1] = (m - (m >> 1)) * lazy[rt];
		sum[rt << 1 | 1] = (m >> 1) * lazy[rt];
		lazy[rt] = 0;
	}
}
void build(int l, int r, int rt) {
	lazy[rt] = 0;
	sum[rt] = r - l + 1;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
}
void update(int L, int R, int c, int l, int r, int rt) {
	if(L <= l && r <= R) {
		sum[rt] = c * (r - l + 1);
		lazy[rt] = c;
		return;
	}
	pushdown(rt, r - l + 1);
	int mid = (l + r) >> 1;
	if(L <= mid) update(L, R, c, l, mid, rt << 1);
	if(R >= mid + 1) update(L, R, c, mid + 1, r, rt << 1 | 1);
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
