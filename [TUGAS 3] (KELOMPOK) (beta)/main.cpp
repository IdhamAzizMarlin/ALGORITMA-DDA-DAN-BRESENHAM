   #include <stdio.h>
#include <iostream>
#include <dda.h>
#include <bresenham.h>

using namespace std;

int main() {
//dda tes2;
bresenham tes;
//tes2.hitungDDA(8,8,20,17);
tes.hitungBresenham(8,8,20,17);

for (int i = 0; i <= tes.step; i++) {
/*cout << tes2.arrayYBulat[i] << ',';*/
cout << tes.pk[i] << ',';
}

system("PAUSE");
return 0;
}








