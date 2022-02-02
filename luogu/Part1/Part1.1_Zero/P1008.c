// https://www.luogu.com.cn/problem/P1008
#include <stdio.h>

int main()
{
    int x1, x2, x3;
    int y1, y2, y3;
    int z1, z2, z3;
    int n1, n2, n3;
    for (x1 = 1; x1 <= 3; x1++)
    {
        for (x2 = 1; x2 <= 9; x2++)
        {
            if (x2 == x1)
                continue;
            for (x3 = 1; x3 <= 9; x3++)
            {
                if (x3 == x1 || x3 == x2)
                    continue;
                n1 = 100 * x1 + 10 * x2 + x3;
                n2 = 2 * n1;
                n3 = 3 * n1;
                if (n3 > 987)
                    break;

                y1 = n2 / 100;
                y2 = (n2 - 100 * y1) / 10;
                y3 = n2 - 100 * y1 - 10 * y2;

                z1 = n3 / 100;
                z2 = (n3 - 100 * z1) / 10;
                z3 = n3 - 100 * z1 - 10 * z2;

                if (y1 != 0 && y2 != 0 && y3 != 0 
                && y1 != x1 && y2 != x1 && y3 != x1 
                && y1 != x2 && y2 != x2 && y3 != x2 
                && y1 != x3 && y2 != x3 && y3 != x3 
                && z1 != 0 && z2 != 0 && z3 != 0 
                && z1 != x1 && z2 != x1 && z3 != x1 
                && z1 != x2 && z2 != x2 && z3 != x2 
                && z1 != x3 && z2 != x3 && z3 != x3
                && z1 != y1 && z2 != y1 && z3 != y1 
                && z1 != y2 && z2 != y2 && z3 != y2 
                && z1 != y3 && z2 != y3 && z3 != y3)
                    printf("%d %d %d\n", n1, n2, n3);
            }
            if (n3 > 987)
                break;
        }
    }
    return 0;
}