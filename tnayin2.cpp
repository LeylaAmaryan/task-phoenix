#include <iostream>
#include <vector>
#include <string>

// Forward declaration of the implementation class
class LibraryManagementSystemImpl;

// Declaration of the LibraryManagementSystem class
class LibraryManagementSystem {
public:
    LibraryManagementSystem();
    ~LibraryManagementSystem();
    
    // Methods to interact with the library
    void addBook(const std::string& title, const std::string& author);
    void removeBook(const std::string& title);
    std::vector<std::string> queryByTitle(const std::string& title) const;
    std::vector<std::string> queryByAuthor(const std::string& author) const;
    
private:
    // Pointer to the implementation class
    LibraryManagementSystemImpl* impl;
};

// Implementation class declaration
class LibraryManagementSystemImpl {
public:
    void addBook(const std::string& title, const std::string& author) {
        // Implementation for adding a book
        books.push_back(std::make_pair(title, author));
    }
    
    void removeBook(const std::string& title) {
        // Implementation for removing a book
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->first == title) {
                books.erase(it);
                break;
            }
        }
    }
    
    std::vector<std::string> queryByTitle(const std::string& title) const {
        // Implementation for querying books by title
        std::vector<std::string> result;
        for (const auto& book : books) {
            if (book.first == title) {
                result.push_back(book.second);
            }
        }
        return result;
    }
    
    std::vector<std::string> queryByAuthor(const std::string& author) const {
        // Implementation for querying books by author
        std::vector<std::string> result;
        for (const auto& book : books) {
            if (book.second == author) {
                result.push_back(book.first);
            }
        }
        return result;
    }
    
private:
    std::vector<std::pair<std::string, std::string>> books;
};

// LibraryManagementSystem constructor
LibraryManagementSystem::LibraryManagementSystem() : impl(new LibraryManagementSystemImpl()) {}

// LibraryManagementSystem destructor
LibraryManagementSystem::~LibraryManagementSystem() {
    delete impl;
}

// Method to add a book
void LibraryManagementSystem::addBook(const std::string& title, const std::string& author) {
    impl->addBook(title, author);
}

// Method to remove a book
void LibraryManagementSystem::removeBook(const std::string& title) {
    impl->removeBook(title);
}

// Method to query books by title
std::vector<std::string> LibraryManagementSystem::queryByTitle(const std::string& title) const {
    return impl->queryByTitle(title);
}

// Method to query books by author
std::vector<std::string> LibraryManagementSystem::queryByAuthor(const std::string& author) const {
    return impl->queryByAuthor(author);
}

int main() {
    LibraryManagementSystem library;
    
    library.addBook("The Great Gatsby", "F. Scott Fitzgerald");
    library.addBook("To Kill a Mockingbird", "Harper Lee");
    library.addBook("1984", "George Orwell");
    
    std::cout << "Books by George Orwell:\n";
    for (const auto& book : library.queryByAuthor("George Orwell")) {
        std::cout << book << std::endl;
    }
    
    return 0;
}
