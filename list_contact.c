// Function to display all saved contacts in the address book.  
// If no contacts are available, it informs the user.

#include "contact.h"

void listContacts(AddressBook *addressBook)
{
    if (addressBook->contactCount == 0)
    {
        printf("No contacts available.\n");
        return;
    }

    // Loop through all contacts and display their details
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("Name: %s\nMobile No: %s\nEmail: %s\n\n",
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
    }
}
