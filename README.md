# 📒 Address Book Project

The **Address Book** project is a **C-based** console application that allows users to manage personal contacts efficiently. The application provides features for **creating**, **searching**, **editing**, **deleting**, and **listing** contacts with **data persistence** through file I/O operations. It emphasizes **data validation**, **error handling**, and **modular design**, ensuring a robust and user-friendly experience.

---

## 🛠 Project Features

- **Create Contact:** Add new contacts with validated **name**, **phone number**, and **email address**.
- **Search Contact:** Locate contacts by **name**, **phone number**, or **email address**.
- **Edit Contact:** Update existing contact information with full validation.
- **Delete Contact:** Remove contacts safely, handling multiple matches if needed.
- **List Contacts:** Display all saved contacts in a formatted manner.
- **Data Persistence:** Automatically **save** and **load** contacts from a file (**contacts.txt**).
- **Validation:** Ensures **name**, **phone**, and **email** follow the correct formats.
- **Duplicate Handling:** Prevents adding contacts with the same **phone number** or **email address**.
- **Error Messages:** Provides clear feedback when input validation fails.

---

## 🧰 Technology Stack

- **Programming Language:** C
- **File I/O:** Persistent storage in **contacts.txt** using **CSV** format.
- **Data Validation:** Validation for name, phone, and email inputs.
- **Modular Design:** Separate modules for **CRUD** operations.
- **Memory Management:** Uses static arrays for contact storage.

---

## 🔄 Project Workflow

1. **Application Startup:**
   - Initializes the address book.
   - Attempts to **load existing contacts** from **contacts.txt**.
   - Displays the **main menu** to the user.

2. **Menu Interaction:**
   - Offers options to **create**, **search**, **edit**, **delete**, **list**, **save**, and **exit**.
   - **Validation** and **error handling** ensure smooth user interaction.

3. **Contact Management:**
   - **Create Contact:** Validates input and checks for duplicates.
   - **Search Contact:** Provides search by **name**, **phone**, or **email**.
   - **Edit Contact:** Updates information with additional validation.
   - **Delete Contact:** Removes contacts, adjusting the contact array.
   - **List Contacts:** Shows all contacts or informs if the list is empty.

4. **Data Persistence:**
   - Saves all contacts to **contacts.txt** in **CSV** format.
   - Automatically loads contacts when the program starts.

---

## 📂 File Structure

- `contact.h` - Header file with **structure definitions** and **function prototypes**.
- `contact.c` - Initializes the address book and loads contacts from the file.
- `create_contact.c` - Implements **contact creation** with input validation.
- `search_contact.c` - Manages **search operations** by different criteria.
- `edit_contact.c` - Provides **editing functionality** with validation.
- `delete_contact.c` - Safely **removes contacts** from the address book.
- `list_contact.c` - Displays all saved contacts in a user-friendly format.
- `save_contact.c` - Handles **file I/O operations** to persist contact data.
- `populate.c` - Adds **dummy data** for testing purposes.
- `main.c` - **Menu-driven interface** and central program logic.

---

## 🚀 Future Enhancements

- **Categorization:** Allow organizing contacts into **groups** (e.g., Family, Work).
- **Additional Fields:** Include **addresses**, **birthdays**, and **social media handles**.
- **Image Support:** Add functionality to store **profile pictures**.
- **Database Integration:** Replace file-based storage with a **database** like **SQLite**.
- **Graphical UI:** Develop a **GUI** using frameworks like **GTK** or **Qt**.
- **Search Optimization:** Implement **indexing** for faster search operations.
- **Cloud Sync:** Enable synchronization with **cloud services** for backup and restore.
- **Mobile Integration:** Create a **mobile app** with **API** support.

---

## 📧 Contact

For any questions, feel free to reach out:

- **Vivek**
- Email: [gopivivek57@gmail.com](mailto:gopivivek57@gmail.com)
- LinkedIn: [Vivek](https://www.linkedin.com/in/vivek57/)
