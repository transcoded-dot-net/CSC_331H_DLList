#include "Doubly_Linked_List.cpp"

/***************************************************************/

/***************************************************************/

// printMenu displays a menu of choices and returns the user's choice

int printMenu();

// InsertList inserts an item into the list parameter

void insertListItem ( Doubly_Linked_List<int> & );

// deleteList deletes an item from the list parameter

void deleteListItem ( Doubly_Linked_List<int> & );

// searchItem searches for an item in the list parameter

void searchListItem ( Doubly_Linked_List<int> &  );

//************************** main program ************************/

int main()
{
    Doubly_Linked_List<int> l;
    int choice;

    cout<<"\nOperations allowed on the unsorted list of integers are below."
        <<"\nPlease enter the number of your choice and press return.\n\n";

    choice = printMenu();

    while ( choice != 7 )
    {

        switch ( choice )
        {

            case 1 : insertListItem( l );
                break;

            case 2 : deleteListItem ( l );
                break;

            case 3 : l.print_list();
                break;

            case 4 : l.print_list_backwards();
                break;

            case 5 : searchListItem ( l );
                break;

            case 6 : cout<<"\nThe list contains "<<l.get_length()
                         << " items\n\n";
                break;

            default :cout<<"\nNumber is not correct. Please look at "
                         <<"choices and reenter\n\n";
                break;
        }

        choice = printMenu();
    }

    Doubly_Linked_List<int> l2;

    l2 = l;

    cout<<"\nPrinting a new list with the same values as the old list \n";

    l2.print_list();

    cout<<"\nProgram terminated\n\n";

    return 0;
}

//********************functions implementation ********************//

int printMenu ()
{
    int c;

    cout<<"\n1: Add an item to the list.";
    cout<<"\n2: Delete an item from the list.";
    cout<<"\n3: Print the list.";
    cout<<"\n4. Print list from back to front";
    cout<<"\n5: Search the list for a given item";
    cout<<"\n6: Return the number of items in the list";
    cout<<"\n7: Quit.\n\n";
    cin>>c;

    return c;
}

void insertListItem ( Doubly_Linked_List<int> &l )
{
    int num;


    cout<<"\nEnter the number to insert : ";
    cin>>num;
    l.insert_item(num);
    cout<<"\nThe number has been inserted\n\n";


}

void deleteListItem ( Doubly_Linked_List<int> &l )
{

    int num;

    cout<<"\nEnter the number to delete : ";
    cin>>num;

    l.delete_item(num);


}

void searchListItem ( Doubly_Linked_List<int>& l )
{

    int num;

    cout<<"\nEnter the number to search for : ";
    cin>>num;

    if ( l.search_item (num))

        cout<<"\nThe number is in the list\n\n";

    else  cout<<"\nThe number is NOT in the list\n\n";

}



