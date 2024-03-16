#include "231511085/231511085.h"
#include "231511088/231511088.h"

int main()
{
    user loggedUser = loginDosen();
    string choice = dashboard(loggedUser);
    if (choice == "Logout")
    {
        loggedUser = loginDosen();
    }
}