#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
const int N = 1e6 + 5;
int a[N], bucket[N], cnt[N];
int bucket_size;
struct query {
    int l, r, i;
} q[N];
int ans = 0;

void add(int index) {
	std::cerr << ">>> Entering add(index=" << index << ")" << std::endl;
    cnt[a[index]]++;
    if (cnt[a[index]] == 1)
        ans++;
		std::cerr << "<<< Exiting add(index=" << index << ")" << std::endl;
}
void remove(int index) {
	std::cerr << ">>> Entering remove(index=" << index << ")" << std::endl;
    cnt[a[index]]--;
    if (cnt[a[index]] == 0)
        ans--;
		std::cerr << "<<< Exiting remove(index=" << index << ")" << std::endl;
}

bool mycmp(query x, query y) {
	std::cerr << ">>> Entering mycmp(x=" << x << ",y=" << y << ")" << std::endl;
    if (x.l / bucket_size != y.l / bucket_size)
	std::cerr << "<<< Exiting mycmp(x=" << x << ",y=" << y << ")" << std::endl;
        return x.l / bucket_size < y.l / bucket_size;
    return x.r < y.r;
}

int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    int n, t, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    bucket_size = ceil(sqrt(n));
    scanf("%d", &t);
	std::cerr << "main(): bucket_size → " << bucket_size << std::endl;
    for (i = 0; i < t; i++) {
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].l--;
        q[i].r--;
        q[i].i = i;
    }
    sort(q, q + t, mycmp);
    int left = 0, right = 0;
    for (i = 0; i < t; i++) {
        int L = q[i].l, R = q[i].r;
        while (left < L) {
            remove(left);
            left++;
        }
        while (left > L) {
            add(left - 1);
            left--;
        }
        while (right <= R) {
            add(right);
            right++;
        }
        while (right > R + 1) {
            remove(right - 1);
            right--;
        }
        bucket[q[i].i] = ans;
    }
    for (i = 0; i < t; i++) printf("%d\n", bucket[i]);
	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
