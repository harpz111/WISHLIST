#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;


main() {
int choice;
cout << "WISHLIST\n\nWelcome.\n1: Register\n2: Login\n\nYour choice: "; cin >> choice;
if (choice == 1){
    string username, password;
    cout << "Create a username: "; cin >> username;
    cout << "Create a password: "; cin >> password;

    ofstream createdfile;
    createdfile.open("C:\\Users\\hamza\\Documents\\Code\\Logindetails\\" + username + ".txt");
    createdfile << username << "\n" << password;
    createdfile.close(); 
    main();
} else if (choice == 2){
    string user, pass, username, password;
    cout << "Username: "; cin >> username;
    cout << "Password: "; cin >> password;

    ifstream read("C:\\Users\\hamza\\Documents\\Code\\Logindetails\\" + username + ".txt");
    getline(read, user);
    getline(read, pass);
    if (user == username && password == pass) {
        cout << "Welcome to your wishlist accout. What would you like to do?\n";
        //Start of wishlist
        int choicein;
        start:
        cout << "1: Make a wishlist\n2: View wishlists\n3: Exit\n\nChoice: "; cin >> choicein;
        cin.ignore();
        if (choicein == 1) {
            string name, thing;
            vector<string> list;
            cout << "Name your wishlist. Make sure to add spaces with _, otherwise the wishlist will not save...\n"; 
            getline(cin, name);
            
            cout << "Add some things to this list! Enter NOTHING in all caps to stop adding to the list, and to create the list.\n";
     
            while (thing != "NOTHING") {               
                cout << "Thing: "; getline(cin,thing);
               if (thing != "NOTHING") {
                list.push_back(thing); 

               }  else if (thing == "NOTHING"){
                  ofstream wishlist;
                  wishlist.open("C:\\Users\\hamza\\Documents\\Code\\Wishlists\\" + name + ".txt");
                    for (int b=0; b < list.size(); b++) {
                    wishlist << list[b] << "\n";
                    } 
                }
                
        }
        goto start;
        //End of wishlist
    } else if (choice == 2){
   //view

        string folder_path = "C:\\Users\\hamza\\Documents\\Code\\Wishlists";
         for (const auto& entry : fs::directory_iterator(folder_path)) {
        if (entry.path().extension() == ".txt") {
            cout << entry.path().stem().string() << "\n";
        }
    }
    system("PAUSE");
    cout << "Select a list.";

//view end
    }
    
    
    else {
        cout << "Invalid.\n";
        main();
    }

} else {
    cout << "Input valid choice!\n";
    main();
}



}
}