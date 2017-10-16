#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;
void final(const double outPut[], int graduation,int zhangshu)
{
    int count, index,temp;
    count = 0;

    std::stringstream ss;
    std::string str;
    ss<<zhangshu;
    ss>>str;
    string head="frames";
    string extension=".PGM";
    string fullname=head+str+extension;
    cout<<fullname;
    ofstream SaveFile(fullname);


    SaveFile<<"P2\n"<<graduation<<" "<<graduation<<"\n"<<"255\n";
    for (index=0;index<(graduation*graduation);index++)
    {
        temp=(outPut[index]+1)*127.5+0.5;
        SaveFile <<temp<< "  ";
        count++;
        if (count == (graduation))
        {
            SaveFile << "\n";
            count = 0;
        }
    }
}
void Second(int graduation,double z, int zhangshu)
{
    double tempX,tempY,x,y,outPut [(graduation)*(graduation)];
    int index,count;
    count=0;
    tempX=10.0/(graduation-1);
    tempY=17.0/(graduation-1);
    y=5.0;
    x=-4.0;
    for (index=0;index<graduation*graduation;index++)
    {
        outPut[index] = (0.5 * sin(x) + 0.5 * cos(y))*cos(z);
        count++;
        x=x+tempX;
        if (count==graduation)
        {
            y=y-tempY;
            x=-4;
            count=0;
        }
    }
    final(outPut,graduation,zhangshu);
}
int main()
{
    int graduation,frames,count;
    double z,tempZ;
    std::cout<<"(1/2 sin(x) + 1/2 cos(y))*cos(z)\n";
    std::cout<<"Number of graduations per axis: ";
    std::cin>>graduation;
    std::cout<<"Number of frames to creat\n";
    std::cin>>frames;

    z=0;
    tempZ=6.28318530718/(frames-1);
    for (count=1;count<=frames;count++)
    {
        z=z+tempZ;
        Second(graduation,z,count);
    }
    main();
    return (0);
}