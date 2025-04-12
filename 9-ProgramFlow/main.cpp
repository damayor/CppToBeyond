// Section 9
// Challenge
/*    
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.
    
    Your program should display a menu options to the user as follows:
    
    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:
    
The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space. 
For example, [ 1 2 3 4 5 ]
      
If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list 
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/
#include <iostream>
#include <vector>
#include <climits> 

using namespace std;

int main() {
        
    char option;
    vector<int> numbers;
        
    cout << "P - Print numbers  " << endl;
    cout << "A - Add a number " << endl;
    cout << "M - Display mean of the numbers " << endl;
    cout << "S - Display the smallest number " << endl;
    cout << "L - Display the largest number " << endl;
    cout << "Q - Quit " << endl;
        
    for(;;) {
      
      
    
        cout << "Enter your choice: [P, A, M, S, L, Q]" << endl ;
    
     
        cin >> option;
        cout << "the selected option is " << option << endl; 
     
     
        if( option == 'P' || option == 'p')
        {
          
            
            if(numbers.size() == 0) 
            {
                cout << "[] - the list is empty" << endl ;
            }
            else 
            {
                cout << "The numbers list is" << endl;
                cout << '[';
             
                for (auto n: numbers) {
                    cout << n <<" " ;
                }
                cout << ']' << endl;
            }
        }
        
        else if( option == 'A' || option == 'a')
        {
            int input;
            cout << "Type a new number to add: "<< endl ;
            
            cin >> input;
            numbers.push_back(input);
        }
        else if( option == 'M' || option == 'm')
        {
            int sum = 0;
    
            for (auto n: numbers) {
                
                sum += n;
            }
            
            float medium = (float)sum / numbers.size();
            cout << "The medium is " << medium << endl ;
    
        }
        else if( option == 'S' || option == 's')
        {
            int min = INT_MAX;
            for (auto n: numbers) {
                
                if(n < min)
                {
                    min = n;
                }
            }
            cout << "The smallest number is " << min << endl ;
    
        }
        else if( option == 'L' || option == 'l')
        {
            int max = 0;
    
            for (auto n: numbers) {
                
                if(n > max)
                {
                    max = n;
                }
            }
            cout << "The largest number is " << max << endl ;
    
        }
        else if( option == 'Q' || option == 'q')
        {
           
            cout << "Exit the program " << endl ;
            break;
            
        }
        else
        {
            cout << "Unknown selection, please try again" << endl ;
        }
    }
        
    
    cout << "Hello world" << endl;
    return 0;
}

