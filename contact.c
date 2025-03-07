// Function to initialize the address book by setting the contact count to zero 
// and loading contacts from a file if available.
#include "contact.h" 
// Initializes the address book
void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;     
    loadContactsFromFile(addressBook); // Load contacts from file during initialization
}
// Function to load contacts from a file into the address book. 
// If the file does not exist, it prints an error message.
void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fptr = fopen("contacts.txt", "r"); // Open file for reading
    if (fptr == NULL)                        
    {
        printf("File does not exist"); // Print error message if file does not exist
        return;
    }
    
    int count;
    fscanf(fptr, "%d\n", &count);     // Read number of contacts from file
    addressBook->contactCount = count; 

    for (int i = 0; i < count; i++)
    {
        // Read contact details from file
        fscanf(fptr, "%[^,],%[^,],%[^\n]\n",
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
    }
    
    fclose(fptr); // Close the file after reading all contacts
}
