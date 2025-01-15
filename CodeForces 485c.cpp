#include <cstdio>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        long long l, r, k, p = 1;
        scanf("%lld%lld", &l, &r);
        while (l <= r)
        {
            k = l | p;
            if (k > r)
                break;
            l = k;
            p = p << 1;
        }
        printf("%lld\n", l);
    }
    return 0;
}