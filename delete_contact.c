// Function to delete a contact from the Address Book.
// Allows deletion by name. If multiple contacts have the same name, 
// deletion is confirmed using a phone number.
#include "contact.h"
void deleteContact(AddressBook *addressBook)
{
    int option;
    char name[50];
    char mobile[15];
    int found = 0;
    int count = 0;
    printf("Enter the Options To Delete:\n1.Name:\n");
    scanf("%d", &option);
    getchar();

    switch (option)
    {
    case 1: // Case to delete a contact by name
        printf("Enter the name to delete:\n");
        scanf(" %[^\n]", name);
        // Count the number of contacts with the given name
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].name, name) == 0)
            {
                count++;
            }
        }
        // If no contact with the given name is found
        if (count == 0)
        {
            printf("Contact with the name '%s' not found.\n", name);
            return; // Exit if no contact is found
        }
        // If exactly one contact with the given name is found
        if (count == 1)
        {
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(addressBook->contacts[i].name, name) == 0)
                {
                    // Shift all contacts after the one to be deleted one position left
                    for (int j = i; j < addressBook->contactCount; j++)
                    {
                        addressBook->contacts[j] = addressBook->contacts[j + 1];
                    }
                    addressBook->contactCount--; // Decrement the contact count
                    printf("Contact with the name '%s' has been deleted.\n", name);
                    found = 1; // Mark that a contact has been found and deleted
                    break;     // Exit the loop after deletion
                }
            }
        }
        // If multiple contacts with the same name are found
        else if (count > 1)
        {
            printf("Multiple contacts with the same name found. Please enter the mobile number to confirm:\n");
            scanf("%s", mobile);
            // Find the contact with the matching name and mobile number
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(addressBook->contacts[i].name, name) == 0 && strcmp(addressBook->contacts[i].phone, mobile) == 0)
                {
                    // Shift all contacts after the one to be deleted one position left
                    for (int j = i; j < addressBook->contactCount; j++)
                    {
                        addressBook->contacts[j] = addressBook->contacts[j + 1];
                    }
                    addressBook->contactCount--; // Decrement the contact count
                    printf("Contact with the name '%s' and mobile '%s' has been deleted.\n", name, mobile);
                    found = 1; // Mark that a contact has been found and deleted
                    break;     // Exit the loop after deletion
                }
            } // If no contact with the specified mobile number is found
            if (!found)
            {
                printf("Contact with the mobile number '%s' not found.\n", mobile);
            }
        }

        break;
    default:
        printf("Invalid option");
        break;
    }
}