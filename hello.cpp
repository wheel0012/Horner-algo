#include <iostream>
#include <string>
class Tools
{
    public:
    Tools()
    {

    }
    template<typename T>
    T Split(T str)
    {
        for(int i = 0; i< (sizeof(str)/sizeof(char)); i++)
        {
            std::cout<<"yo"<<i<<std::endl;
        }
        //str[0]
    }
};
int main()
{
    Tools tools; 
    char *str = (char *)malloc(sizeof(char) * 200);
    std::cin >> str;
    fflush(stdin);
    std::cout << "hello, world!" << std::endl;
    tools.Split(str);
    getchar();
    return 0;
}
