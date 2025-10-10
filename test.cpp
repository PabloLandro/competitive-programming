#include <iostream>
#include <unistd.h>   // for gethostname


using namespace std;

int main() {
    char hostname[30];

    if (gethostname(hostname, sizeof(hostname)) == 0) {
        cout << hostname << endl;
    } else {
        perror("gethostname");
        return 1;
    }

    return 0;
}