// This file contains functions for managing an address book, including initializing the contact list,  
// loading contacts from a file, saving contacts to a file, and exiting the program.
#include "contact.h"
/**
 * Function: saveAndExit
 * Description: Saves the contacts to a file and exits the program.
 * Input: AddressBook pointer containing contact details.
 * Output: Saves contacts to a file and terminates the program.
 */
void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS);              // Exit the program
}

/**
 * Function: saveContactsToFile
 * Description: Saves all contacts from the address book to a file.
 * Input: AddressBook pointer containing the contact list.
 * Output: Writes contacts to "contacts.txt" for persistence.
 */
void saveContactsToFile(AddressBook *addressBook)
{
    FILE *fptr = fopen("contacts.txt", "w+"); // Open file for writing
    if (fptr == NULL)                         // Check if file opened successfully
    {
        printf("Failed to open file for writing.\n");
        return;
    }
    fprintf(fptr, "%d\n", addressBook->contactCount); // Write number of contacts

    // Write each contact's details to the file
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fptr, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }
    fclose(fptr); // Close the file
    printf("File closed successfully. Contacts saved.\n");
}
