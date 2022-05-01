#include <iostream>
#include <fstream>

using namespace std;
using namespace std;
int main(int argc, char *argv[])
{
    ofstream f;
    f.open("here_is_my_working_folder.txt");
    if (f.fail()){
        cout<<"file failed to open"<<endl;
        exit(-1);
    }
    f<<"This is my working folder. "<<endl;
    f<<"this file was created by where_is_my_working_folder project."<<endl;
    f.close();
    cout << "--------------- success ------------------" << endl;
    return 0;
}
