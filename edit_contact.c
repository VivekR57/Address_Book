// Function to edit an existing contact in the address book.
// The user can modify the contact's name, mobile number, or email.
// Validations ensure proper input format and prevent duplicate entries.
#include "contact.h"
void editContact(AddressBook *addressBook)
{
    int option;
    char name[100];
    char mobile[25];
    char newname[100];
    char mail[20];
    char newmail[20];
    int found = 0;
    int contactFound = 0;
    printf("Enter the option to edit:\n1.Name:\n2.Mobile no:\n3.Email id:\n");
    scanf("%d", &option);
    getchar();
    switch (option)
    {
    case 1: // Editing the contact's name
        printf("Enter the Name to Edit:\n");
        scanf(" %[^\n]", name);
        // Validate the provided name (alphabetic characters only)
        int validname = 1;
        int length1 = strlen(name);
        for (int i = 0; i < length1; i++)
        {
            if (!isalpha(name[i]) && name[i] != ' ')
            {
                validname = 0;
                break;
            }
        }
        if (!validname)
        {
            printf("Invalid name.Please enter alphabetic characters only\n");
            return; // Exit if the name is invalid
        }
        // Check if the name exists in the address book
        int count = 0;
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].name, name) == 0)
            {
                count++;
            }
        }
        if (count == 0)
        {
            printf("\nContact with the name '%s' not found.\n", name);
            return; // Exit if no contact with the given name is found
        }
        else if (count == 1)
        {
            // Edit the name if only one contact with the given name is found
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(addressBook->contacts[i].name, name) == 0)
                {
                    printf("Enter the New Name:\n");
                    scanf(" %[^\n]", newname);
                    // Validate the new name (alphabetic characters only)
                    int validname = 1;
                    int length = strlen(newname);
                    for (int j = 0; j < length; j++)
                    {
                        if (!isalpha(newname[j]) && newname[j] != ' ')
                        {
                            validname = 0;
                            break;
                        }
                    }

                    if (!validname)
                    {
                        printf("Invalid name. Please enter alphabetic characters only.\n");
                        return; // Exit if the new name is invalid
                    }
                    // Update the contact's name
                    strcpy(addressBook->contacts[i].name, newname);
                    printf("Contact updated successfully.\n");
                    found = 1;
                    break;
                }
            }
        }
        else
        {
            // multiple contacts having the same name
            printf("Multiple contacts with the name '%s' found. Please enter the mobile number to confirm:\n", name);
            scanf("%s", mobile);
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(addressBook->contacts[i].name, name) == 0 && strcmp(addressBook->contacts[i].phone, mobile) == 0)
                {
                    printf("Enter the new name:\n");
                    scanf(" %[^\n]", newname);
                    // Validate the new name (alphabetic characters only)
                    int validname = 1;
                    int length = strlen(newname);
                    for (int j = 0; j < length; j++)
                    {
                        if (!isalpha(newname[j]) && newname[j] != ' ')
                        {
                            validname = 0;
                            break;
                        }
                    }
                    if (!validname)
                    {
                        printf("Invalid name. Please enter alphabetic characters only.\n");
                         // Exit if the new name is invalid
                    }
                    // Update the contact's name
                    strcpy(addressBook->contacts[i].name, newname);
                    printf("Contact with mobile number '%s' updated successfully.\n", mobile);
                    contactFound = 1;
                    break;
                }
            }
            if (!contactFound)
            {
                printf("No contact with name '%s' and mobile number '%s' found.\n", name, mobile);
            }
        }

        break;
    case 2: // Editing the contact's mobile number
        printf("Enter the Mobile No to edit:\n");
        scanf(" %[^\n]", mobile);

        // Validate the provided mobile number (10 digits only)
        int valid = 1;
        int length = strlen(mobile);
        if (length != 10)
        {
            valid = 0;// Invalid if length is not 10
        }
        else
        {
            for (int i = 0; i < length; i++)
            {
                if (!isdigit(mobile[i]))
                {
                    valid = 0;
                    break; // Exit if the mobile number is invalid
                }
            }
        }
        if (!valid)
        {
            printf("Invalid mobile number. Must be a 10-digit number.\n");
            break;
        }
        // Check if the mobile number exists in the address book
        int numberfound = 0;
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].phone, mobile) == 0)
            {
                numberfound = 1;
                break;
            }
        }

        if (!numberfound)
        {
            printf("Contact With the mobile number '%s' not found\n", mobile);
            break; // Exit if the mobile number is not found
        }
        // Prompt for the new mobile number
        char newmobile[15];
        printf("Enter the new mobile number to edit:\n");
        scanf(" %[^\n]", newmobile);
        // Validate the new mobile number (10 digits only)
        valid = 1;
        length = strlen(newmobile);
        if (length != 10)
        {
            valid = 0;
        }
        else
        {
            for (int i = 0; i < length; i++)
            {
                if (!isdigit(mobile[i]))// Check if each character is a digit
                {
                    valid = 0;
                    break;
                }
            }
        }
        if (!valid)
        {
            printf("Invalid mobile number. Must be a 10-digit number.\n");
            break; // Exit if the new mobile number is invalid
        }

        // Check if the new mobile number already exists
        int newnumber = 0;
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].phone, newmobile) == 0)
            {
                newnumber = 1;
                break;
            }
        }
        if (newnumber)
        {
            printf("The new mobile number '%s' is already there", newmobile);
            break; // Exit if the new mobile number already exists
        }
        // Update the contact's mobile number
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].phone, mobile) == 0)
            {
                strcpy(addressBook->contacts[i].phone, newmobile);
                printf("Mobile number updated successfully");
                break;
            }
        }
        break;

    case 3: // Editing the contact's email address
        printf("Enter the Email To edit:\n");
        scanf(" %[^\n]", mail);

        // Check if the email exists in the address book
        int found = 0;
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].email, mail) == 0)
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            printf("Email is not found '%s'\n", mail);
            break; // Exit if the email is not found
        }

        printf("Enter the new Email address:\n");
        scanf(" %[^\n]", newmail);
        // Validate the new email address
        char *ptr = strstr(newmail, "@");
        valid = 0;
        if (ptr != NULL)
        {
            // Check that there is an alphabetic character after '@' and ends with ".com"
           char*ptr1=strstr(ptr,".com");
           if (ptr1 != NULL && *(ptr1 + 4) == '\0' && ptr[1] != '\0' && isalpha(ptr[1]))
            {
                int duplicate = 0;
                // Check if the new email already exists
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (strcmp(addressBook->contacts[i].email, newmail) == 0)
                    {
                        duplicate = 1;
                        break;
                    }
                }
                if (duplicate)
                {
                    printf("The Email '%s' is already there\n", newmail);
                    valid = 0;
                }
                else
                {
                    // Update the contact's email address
                    for (int i = 0; i < addressBook->contactCount; i++)
                    {
                        if (strcmp(addressBook->contacts[i].email, mail) == 0)
                        {
                            strcpy(addressBook->contacts[i].email, newmail);
                            printf("Email updated successfully");
                            found = 1;
                            break;
                        }
                    }
                }
            }
            else
            {
                printf("Invalid email. The character after '@' must be an alphabetic character.\n");
                valid = 0;
            }
        }
        if (!valid)
        {
            break; // Exit if the email is invalid
        }
        break;

    default:
        break;
    }
}