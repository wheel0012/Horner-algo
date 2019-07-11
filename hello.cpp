#include <iostream>
#include <string.h>
class Tools
{
    public:
    Tools()
    {

    }
    void Split(char* str)
    {
        std::cout<<strlen(str)<<std::endl;
        for(int i = 0; i< strlen(str); i++)
        {
            std::cout<<str[i]<<std::endl;
        }
        std::cout<<"\n"<<std::endl;
        //str[0]
    }
};
int main()
{
    Tools tools; 
    char *str = (char *)malloc(sizeof(char) * 200);
    std::cin.getline(str, sizeof(*str));
    fflush(stdin);
    //std::cout << "hello, world!" << std::endl;
    tools.Split(str);
    getchar();
    return 0;
}
