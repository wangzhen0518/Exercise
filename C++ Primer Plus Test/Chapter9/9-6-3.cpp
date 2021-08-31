#include <iostream>

struct chaff
{
    char dross[20];
    int slag;
};

int main()
{
    using std::cout;
    using std::endl;
    chaff *cf = new chaff[2]{{"wangzhen", 20}, {"chenyulan", 30}};
    int n = 2;
    for (int i = 0; i < n; i++)
        cout << i + 1 << ": " << endl
             << "dross: " << cf[i].dross << endl
             << "slag: " << cf[i].slag << endl;

    return 0;
}
