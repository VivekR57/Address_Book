// Function to search for a contact in the address book based on name, phone number, or email
#include "contact.h"
void searchContact(AddressBook *addressBook)
{
    int searchChoice;
    char searchName[50];
    char searchmobile[11];
    char searchemail[20];
    int found = 0;     // Flag to indicate if a contact was found
    int namematch = 0; // Flag to indicate if there was a name match
    int count = 0;     // Counter for the number of matches found
    printf("Select search option:\n");
    printf("1. Search by Name\n");
    printf("2. Search by Mobile Number\n");
    printf("3. Search by Email\n");
    printf("Enter your choice: ");
    scanf("%d", &searchChoice);

    switch (searchChoice)
    {
    case 1:
        printf("Enter the name of the contact to search: ");
        scanf(" %[^\n]", searchName);
        getchar();
        // Search for contacts with the specified name
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].name, searchName) == 0)
            {
                namematch = 1; // Indicate a name match was found
                count++;
            }
        }
        if (!namematch)
        {
            printf("\nContact with the name '%s' not found.\n", searchName);
            break;
        }
        // If exactly one match is found, display contact details
        if (count == 1)
        {
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(addressBook->contacts[i].name, searchName) == 0)
                {
                    printf("\nContact found:\n");
                    printf("Name: %s\n", addressBook->contacts[i].name);
                    printf("Mobile No: %s\n", addressBook->contacts[i].phone);
                    printf("Mail id: %s\n", addressBook->contacts[i].email);
                    found = 1; // Indicate that a contact was found
                    break;
                }
            }
        }
        // If more than one match is found, display a list of matching contacts
        else if (count > 1)
        {
            printf("Multiple  same name found. Please enter the mobile number to confirm:\n");
            scanf("%s", searchmobile);

            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(addressBook->contacts[i].name, searchName) == 0 && strcmp(addressBook->contacts[i].phone, searchmobile) == 0)
                {
                    printf("\nContact found:\n");
                    printf("Name: %s\n", addressBook->contacts[i].name);
                    printf("Mobile No: %s\n", addressBook->contacts[i].phone);
                    printf("Mail id: %s\n", addressBook->contacts[i].email);
                    found = 1; // Indicate that contacts were found
                    break;
                }
            }

            if (!found)
            {
                printf("\nContact with the mobile number '%s' not found.\n", searchmobile);
                break;
            }
        }
        break;
    case 2:        // Search for a contact with the specified mobile number
        found = 0; // Reset found flag
        printf("Enter the mobile number to search:\n");
        scanf(" %[^\n]", searchmobile);

        int validmobile = 1;
        if (strlen(searchmobile) != 10) // Validate mobile number to be exactly 10 digits
        {
            validmobile = 0;
        }

        for (int i = 0; i < 10; i++)
        {
            if (!isdigit(searchmobile[i]))
            {
                validmobile = 0;
                break;
            }
        }
        if (!validmobile)
        {
            printf("Invalid mobile number.It should be exactly 10 digits.\n");
            break;
        }
        // Search for a contact with the specified mobile number
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].phone, searchmobile) == 0)
            {
                printf("\nContact found:\n");
                printf("Name: %s\n", addressBook->contacts[i].name);
                printf("Mobile No: %s\n", addressBook->contacts[i].phone);
                printf("Mail id: %s\n", addressBook->contacts[i].email);
                found = 1; // Indicate that a contact was found
                break;
            }
        }
        if (!found)
        {
            printf("\nContact with the mobile no  '%s' not found.\n", searchmobile);
        }
        break;
    case 3:        // Search by Email
        found = 0; // Reset found flag
        printf("Enter the mail to search:\n");
        scanf(" %[^\n]", searchemail);
        // Search for a contact with the specified email
        char *ptr = strstr(searchemail, "@"); // Validate email format
        int valid = 1;
        if (ptr != NULL)
        {
            if (isalpha(*(ptr + 1)) && strstr(ptr + 1, ".com"))
            {
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strcmp(addressBook->contacts[i].email, searchemail) == 0)
                    {
                        printf("\nContact found:\n");
                        printf("Name: %s\n", addressBook->contacts[i].name);
                        printf("Mobile No: %s\n", addressBook->contacts[i].phone);
                        printf("Mail id: %s\n", addressBook->contacts[i].email);
                        found = 1; // Indicate that a contact was found
                        break;
                    }
                }
                if (!found)
                {
                    printf("\nContact with the mail id  '%s' not found.\n", searchemail);
                }
            }
            else
            {
                printf("Invalid email format. It must contain an '@' symbol and a valid domain.\n");
                valid = 0;
            }
        }
        else
        {
            printf("Invalid email format. It must contain an '@' symbol and a valid domain.\n");
            valid = 0;
        }
        if (!valid)
        {
            break;
        }
        break;

    default:
        printf("Invalid option to search\n");
        break;
    }
}