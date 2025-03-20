#include <iostream>
#include <limits>
#include <string>
const int inventoryItem = 20; //use name of constant when you wanna use the 20 

class RetialItem
{

  private:
  //literally just call the names said in the worssheet but make sure to use caps when the word changes
  std::string description=" ";
  int unitsOnHand=0;
  double price=0.0;
  int reorderQuantity=0;
//these are in your private class!!!

  public:
// this is your default constructor because there are no arguments
//these are in your public class!!!
  RetialItem()
  {
    description = "";
    unitsOnHand = 0;
    price = 0.0;
    reorderQuantity = 0;  //intilizing the variable as teh rpofessor said
  }    
// this is your non defualt constructor because there are arguments
  RetialItem(std::string description, int unitsOnHand, double price, int reorderQuantity)
    {
      this -> description = description; //using the shadowing technique so that I can use the same names!!!
      this -> unitsOnHand = unitsOnHand;
      this -> price = price;
      this -> reorderQuantity = reorderQuantity; //using the shadowing we learned
    }
//accesors are your gets rememberrr
  std::string getDescription()const{return description;} //getting all the functions so that I can use them in my functions below main! you need the const here!
  int getUnitsOnHand()const{return unitsOnHand;}
  double getPrice()const{return price;}
  int getReorderQuantity()const{return reorderQuantity;} //remember to put the const in front of the function
//mutators are the sets rememberrr
  void setDescription(std::string d){description=d;} //getting all me sets! remember that you dont need the "const" here!
  void setUnitsOnHand(int u){unitsOnHand =u;}
  void setPrice(double p){price=p;}
  void setReorderQuantity(int r){reorderQuantity=r;} //initiliazing the variables

}; //end of class RetailItem

void addItem(RetialItem inventory[], int &itemCounter);
void displayInventory(const RetialItem inventory[], int itemCounter);
void displayReorderItems(const RetialItem inventory[], int itemCounter);
bool checkInventory(const RetialItem inventory[], int itemCounter, std::string itemNameThatIsBeingLookedFor);
void updateItem( RetialItem inventory[] ); //might need to change?? still waiting for the professor to tell me what can be updated. so far I got the desc right!!

void displayInventory(const RetialItem inventory[], int itemCounter, std::string updatedName, float updatedPrice, int updatedReorderQuantity, int newUnitsOnHand);

//DONT FORGET TO PASTE ABOVE MAIN 
//if you dont it obvi wont run!

int main() 
{
  std::string addedItems[20]; //I dont think I really need this one here so I commented it out
  RetialItem inventory[inventoryItem]; //must create a name of the array and place the const in the brackets instead of a number sinxe i initilized it to 20
  int choice;
  int itemCounter =0;
//remember how to use do while loops they are very helpful!
  do 
    {
      std::cout<<"\nMenu:\n 0. Quit\n 1. Add an item to inventory\n 2. Display all items in inventory\n 3. Check to see if an item is in inventory\n 4. Display only those items that need to be re-ordered\n 5. Update an item in inventory: ";
        std::cin >> choice; //lit  just askign them their choice

      switch (choice) //using the switch instead of a buncha while loops
        //tech can use the while loops but I noticed it was much easier with switch, in the car partner prgram I will change it to a swtich so its easier!
        {
          //lit just providing each case with the conditions if they chooce whatver number it will go thru wat i want it to do for me
          case 0:
          std::cout<<"\nGoodbye"; //giving them a nice message for using my program
          break;

          case 1:
          addItem( inventory,  itemCounter); //lit my add function
          break;

          case 2:
             displayInventory( inventory,  itemCounter); //lit my`
          break;

          case 3:
            { //this one had a little more to it because I had to ask them for somthing before probifnd the function 
                std::string itemNameThatIsBeingLookedFor;
                std::cout << "\nPlease enter the name of the item you are looking for: ";
                std::cin >> itemNameThatIsBeingLookedFor; //lit just asking for what they want 
//using the if bc idk if they typed in the correct item name
                if (checkInventory(inventory, itemCounter, itemNameThatIsBeingLookedFor))
                {
                    std::cout << "Item is in inventory.\n";
                }
                else
                {
                    std::cout << "Item is not in inventory.\n";
                }
            }
            break; //if it isnt in iventory it will just say that it isnt in inventory simple.

             //checkInventory( inventory,  itemCounter,);

          break;

          case 4:
             displayReorderItems(inventory,  itemCounter); //lit my display function
            
            

          break;

          case 5:
             updateItem(inventory); //lit my update item function

          break;

          default:
          std::cout<<"\nInvalid. Please choose an option from the menu";
          //if they didnt choose 0-5 it will just say invalid and ask them to choose again
          
        } //end switch
      
      
    } while (choice != 0); //end of do while, bc they didnt choose 0 it will keep going
  

  return 0;
} //end main 

void addItem(RetialItem inventory[], int &itemCounter) //this one needed the & in front of it bc the itemcounters number changes with each item added. tbh i didnt know this until replit yelled at me and told me about it so I will be more careful from now. 
  {
      if (itemCounter < inventoryItem)
      {
        std::string d;
        int u;
        double p;
        int r; 
        //bring in your set variables!
        
        std::cout << "\nEnter the name of the item: ";
        std::cin >> d;

        std::cout << "\nEnter the number of units on hand: ";
        std::cin >> u;

        std::cout << "\nEnter the price of the item: ";
        std::cin >> p;

        std::cout<<"\nEnter the reorder quantity: ";
        std::cin>>r;
        //lit just asked them the questions so pretty easy
        
        inventory[itemCounter] = RetialItem(d, u, p, r); //this basically       will store the items in your array! Without it, nothing will be stored and therefore nothing will be displayed. The teacher susan peterson told me about this so I will be even MORE careful from now. 

        itemCounter++; //adding one to the item counter since they cant be more than 20
      } //end if
      else
      {
        std::cout<<"\nThe inventory is full"; //if the inventory is full, you cant add anymore items!
      } //end else
  } //end add items

void displayInventory(const RetialItem inventory[], int itemCounter)
{
  std::cout<<"\nItems in the Inventory: \n";

  for (int i=0; i<itemCounter; i++) //just using a for loop to display the items in the inventory becuase if its less or equal to 20 they can display it
    {
      std::cout<<"\nItem "<<i+1<<":\n"; //using the i+1 because the array starts at 0
      std::cout<<"\nDescription: "<<inventory[i].getDescription(); //your "getting" the decription the user typed in. Use i when the number in array isnt given/decided since its user input
      std::cout<<"\nUnits on hand: "<<inventory[i].getUnitsOnHand();
      std::cout<<"\nPrice: "<<inventory[i].getPrice();
      std::cout<<"\nReorder Quantity: "<<inventory[i].getReorderQuantity();
    } //end for
  
} //end displayInventory
//okay here I needed a bool FUNCTION and not just as a bool name=whatever because I needed the function to return a true or false. Similar to what we did in the car partner practise. 
bool checkInventory(const RetialItem inventory[], int itemCounter, std::string itemNameThatIsBeingLookedFor)
{
    for (int i=0; i<itemCounter; i++) 
      {
        if(inventory[i].getDescription() == itemNameThatIsBeingLookedFor)
        {
          return true;
        }
      }
    return false; //if the item descpription doesnt match the desc the user typed it it will return a false
  //using this bool function makes it easier since its a true or false kinda thing. remember to use bool when you want to "start" or "turn something on" like in the car partner program we did
} //end check inventory

void displayReorderItems(const RetialItem inventory[], int itemCounter)
{
  std::cout<<"\nItems that need to be re-ordered: \n";
//same thing as my other display tbh
  for (int i=0; i<itemCounter; i++)
  {
    if (inventory[i].getUnitsOnHand() < inventory[i].getReorderQuantity())
    { //if the reorder quantity is greater than the units on hand, then it will display the items that need to be re-ordered. If it isnt that its fine! anyway I decided this made more sense because if I did it the other way around then the getunitson hand would be greater then the reorder quantity so they wouldtnt need anything 
      std::cout<<"\nItem "<<i+1<<":\n"; //using the i+1 because the array starts at 0 
      std::cout<<"\nDescription: "<<inventory[i].getDescription(); //your "getting" the decription the user typed in. Use i when the number in array isnt given/decided since its user input
      std::cout<<"\nUnits on hand: "<<inventory[i].getUnitsOnHand();
      std::cout<<"\nPrice: "<<inventory[i].getPrice();
      std::cout<<"\nReorder Quantity: "<<inventory[i].getReorderQuantity();
    } //end if

    //kinda similar to the other display function I made
      
  } //end for
} //end my display reorder items

void updateItem( RetialItem inventory[] ) //might need to change?? still waiting for the professor to tell me what can be updated. so far I got the desc right!!
{
  std::string itemWantedToUpdate;
  int newUnitsOnHand;
  std::cout<<"\nWhich item would you like to update? ";
  std::cin >> itemWantedToUpdate;

  for (int i=0; i<inventoryItem; i++)
    {
      if (inventory[i].getDescription() == itemWantedToUpdate)
      {
        std::cout<<"\nEnter the new units on hand: ";
        std::cin >> newUnitsOnHand;

        inventory[i].setUnitsOnHand(newUnitsOnHand);
        
        std::string updatedName="";
        float updatedPrice =0.0;
        int updatedReorderQuantity=0;
        //int updatedUnitsOnHand=0;

        std::cout<<"\nEnter the new description name: ";
        std::cin>> updatedName;
        inventory[i].setDescription(updatedName);

        std::cout<<"\nEnter the new price: ";
        std::cin>> updatedPrice;
        inventory[i].setPrice(updatedPrice);

        std::cout<<"\nEnter the new reorder quantity: ";
        std::cin>> updatedReorderQuantity;
        inventory[i].setReorderQuantity(updatedReorderQuantity);
        // std::cout<<"\nEnter the new units on hand quantity: ";
        // std::cin>> updatedUnitsOnHand;
        break;
      }
      else 
      {
        std::cout<<"\n There is no item by that name.";
        break;
      }
    break;
    }
  
  //turning in
  
}


