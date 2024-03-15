#include "Modul1/231511085.h"
#include "Modul4/231511091.h"

int main()
{
    user loggedUser = loginDosen();
    cout << loggedUser.nama << endl;
    string cipher = CaesarCipherEnkrip(loggedUser.nama);
    cout << cipher;
}