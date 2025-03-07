// Function to create a new contact and add it to the address book
// Ensures that name, phone number, and email follow the required format and are unique
#include "contact.h"
void createContact(AddressBook *addressBook)
{
    int flag = 1;
    while (flag)
    {
        printf("Enter the name:\n");
        scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name);
        int length = strlen(addressBook->contacts[addressBook->contactCount].name);
        int validname = 1;
        // Validate the name to contain only alphabetic characters and spaces
        for (int i = 0; i < length; i++)
        {
            if (!isalpha(addressBook->contacts[addressBook->contactCount].name[i]) && addressBook->contacts[addressBook->contactCount].name[i] != ' ')
            {
                validname = 0; // Set flag to invalid if any character is not alphabetic or space
                break;         // Exit loop if invalid character is found
            }
        }
        if (!validname)
        {
            printf("Invalid name Please enter alphabetic characters only.\n");
        }
        else
        {
            flag = 0; // Exit loop if name is valid
        }
    }
    flag = 1; // Reset flag for phone number input validation
    while (flag)
    {
        printf("Enter the phone number:\n");
        scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].phone);
        int length = strlen(addressBook->contacts[addressBook->contactCount].phone);
        flag = 0;
        // Validate phone number to be exactly 10 digits
        if (length != 10)
        {
            printf("Invalid phone number. Please enter a valid 10-digit number.\n");
            flag = 1; // Retry if phone number is invalid
            continue;
        }
        for (int i = 0; i < length; i++)
        {
            if (!isdigit(addressBook->contacts[addressBook->contactCount].phone[i]))
            {
                // Print error message if phone number contains non-digit characters
                printf("Invalid phone number. Only digits are allowed.\n");
                flag = 1; // Retry if phone number contains non-digit characters
                break;
            }
        }
        // Check for duplicate phone numbers
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(addressBook->contacts[i].phone, addressBook->contacts[addressBook->contactCount].phone) == 0)
            {
                printf("The phone number is already there..please enter a different number");
                flag = 1; // Retry if phone number already exists
                break;    // Exit loop if duplicate phone number is found
            }
        }
    }
    flag = 1; // Reset flag for email input validation
    while (flag)
    {
        printf("Enter the E-mail :\n");
        scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].email);
        char *ptr = strstr(addressBook->contacts[addressBook->contactCount].email, "@");
        // Validate email format
        if (ptr != NULL)
        {
            if (isalpha(*(ptr + 1))) // Check if the character after '@' is alphabetic
            {
                if (strstr(ptr + 1, ".com")) // Check if email contains ".com"
                {
                    int duplicate = 0; // Flag to indicate if the email is a duplicate
                    // Check for duplicate email addresses
                    for (int i = 0; i < addressBook->contactCount; i++)
                    {
                        if (strcmp(addressBook->contacts[i].email, addressBook->contacts[addressBook->contactCount].email) == 0)
                        {
                            duplicate = 1; // Set flag to indicate a duplicate email
                            break;
                        }
                    }
                    if (duplicate)
                    {
                        printf("The email is already there. Please enter a different email.\n");
                    }
                    else
                    {
                        flag = 0; // Exit loop if email is valid and unique
                    }
                }
            }
            else
            {
                printf("Invalid E-mail. The character after '@' must be an alphabetic character.\n");
            }
        }

        else
        {
            printf("Invalid E-mail. Enter again.\n");
        }
    }
    addressBook->contactCount++; // Increment contact count after adding a new contact
}