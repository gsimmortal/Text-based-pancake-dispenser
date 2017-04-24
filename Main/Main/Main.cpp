#include <iostream>
#include <vector>					
#include <math.h>								//Used for rounding credit to pounds and pence for display
#include <iomanip>								//For displaying numbers in display function
#include <string>								//Used for storing descriptions of current pancake
#include <random>								//Used for random number generation class
//=================================================================================================================================================
//=================================================================================================================================================
//                       _____                      _               _____  _                                    
//                      |  __ \                    | |             |  __ \(_)                                   
//                      | |__) |_ _ _ __   ___ __ _| | _____       | |  | |_ ___ _ __   ___ _ __  ___  ___ _ __ 
//                      |  ___/ _` | '_ \ / __/ _` | |/ / _ \      | |  | | / __| '_ \ / _ \ '_ \/ __|/ _ \ '__|
//                      | |  | (_| | | | | (_| (_| |   <  __/      | |__| | \__ \ |_) |  __/ | | \__ \  __/ |   
//                      |_|   \__,_|_| |_|\___\__,_|_|\_\___|      |_____/|_|___/ .__/ \___|_| |_|___/\___|_|   
//                                                                              | |                             
//                                                                              |_|              
//=================================================================================================================================================
//=================================================================================================================================================
using namespace std;
//===================================================== Prototypes (and forward declarations) =====================================================
class State;									//Forward declared these classes so that previous classes do not re-declare them
class PCake_Dispenser;							
class Pancake;									
class Pancake_Decorator;						

void PInterface(int, int, int, int);			//Custom class that displays text based menus and parts of menus so that I dont have to
int RandomNumber(int, int);						//Custom class that takes two ints and returns an between them inclusivly
int getCost(Pancake*);							//Prototype for a pancake interface that returns the cost of the pancake pointed to by the input
string getDescription(Pancake*);				//Prototype for pancake interface that returns the description of the pancake pointed to by the
												//    input
//=============================================================== State Pattern Setup ============================================================= 

enum state { Out_Of_Mix, No_Credit, Has_Credit, Has_Credit2, Dispenses_PCake};					//States for the pancake dispenser
enum stateParameter { No_Of_Mix, Credit, Cost_Of_PCake, Save_Point};							//State pattern parameters for pancake dispenser

//============================================================= Decorator Pattern Setup ===========================================================
														
class Commodity															//Part of a basic decorator pattern that can be extended or implemented
{																		//    in any project
public:
	virtual float cost(void)											//Cost (virtual to allow re-definition)
	{
		return 0;														//Default return value if one isnt given is 0
	}
	virtual ~Commodity(void)											//Destructor (virtual to allow destructor calling via Commodity pointer/s)
	{
	}
};
class Commodity_Decorator : public Commodity							//The second part of a basic decorator pattern that can be extended or 
{																		//    in any project
public:
	Commodity* commodity;												//Pointer to a commodity
	~Commodity_Decorator(void)											//Destructor that over-rides original virtual destructor
	{
		delete commodity;												//Deletes the commodity held at the location of the local pointer held 
	}																	//    in this commodity decorator class
	virtual void addToCommodity(Commodity* currentCommodity)			//Virtual add function that takes a pointer to a commodity
	{
		commodity = currentCommodity;									//Saves the memory address of the commodity pointed to by the input
	}																	//    of this function to the local 'commodity pointer'
};
class Pancake :public Commodity					//Pancake is a public commodity which has virtual cost functions and virtual destructor already
{												
public:
	virtual string description(void)			//I extend the commodity with a virtual description function that allows me to later
	{											//    return the pancakes description to make sure I am dispensing the correct pancake desc.
		return " ";								//Default return value if one isnt given is ' ' (space)
	}
};
class Pancake_Decorator :public Pancake			//This entire class is a copy of the default decorator pattern class however it is modified
{												//    to use more relevant variable names and point to a Pancake not a Commodity
public:
	Pancake* pancake;													//Pointer to a pancake
	~Pancake_Decorator(void)											//Destructor that over-rides original virtual destructor
	{
		delete pancake;													//Deletes the pancake held at the location of the local pointer held 
	}																	//    in this pancake decorator class
	virtual void addToPancake(Pancake* currentPancake)					//Virtual add function that takes a pointer to a pancake
	{
		pancake = currentPancake;										//Saves the memory address of the pancake pointed to by the input of
	}																	//    of this function to the local 'pancake pointer'
};
//============================================================= Commodities (base product) ========================================================
class Plain_F :public Pancake					//Plain class that is a public Pancake with its own specific cost and description
{
	float cost()								//Cost that over-rides the pancake class' cost with the cost for this specific pancake
	{
		return 150;								//Shows the cost for this specific type of pancake
	}
	string description()						//Description that over-rides the pancake class' description with a specific one for this
	{											//    pancake
		return "+Plain Base ";					//Shows the description for this specific type of pancake
	}
};												//I HAVE COLLAPSED ALL CLASSES THAT ARE IDENTICAL TO THIS ONE IN TERMS OF IMPLEMENTATION
#pragma region More Pancakes
class Vanilla_Cream :public Pancake
{
	float cost()
	{
		return 180;
	}
	string description()
	{
		return "+Vanilla Base ";
	}
};
class Chocolate_F :public Pancake
{
	float cost()
	{
		return 180;
	}
	string description()
	{
		return "+Chocolate Base ";
	}
};
class Fudge :public Pancake
{
	float cost()
	{
		return 180;
	}
	string description()
	{
		return "+Fudge Base ";
	}
};
class Chocolate_Fudge :public Pancake
{
	float cost()
	{
		return 180;
	}
	string description()
	{
		return "+Choc_Fudge Base ";
	}
};
class Strawberry :public Pancake
{
	float cost()
	{
		return 180;
	}
	string description()
	{
		return "+Strawberry Base ";
	}
};
class Raspberry :public Pancake
{
	float cost()
	{
		return 180;
	}
	string description()
	{
		return "+Raspberry Base ";
	}
};
class Blueberry :public Pancake
{
	float cost()
	{
		return 180;
	}
	string description()
	{
		return "+Blueberry Base ";
	}
};
class Wild_Berry_F :public Pancake
{
	float cost()
	{
		return 180;
	}
	string description()
	{
		return "+Wild_Berry Base ";
	}
};
class Cherry :public Pancake
{
	float cost()
	{
		return 180;
	}
	string description()
	{
		return "+Cherry Base ";
	}
};
class Peanut_Butter :public Pancake
{
	float cost()
	{
		return 180;
	}
	string description()
	{
		return "+Pnt_Butter Base ";
	}
};
class Cookies_and_Cream :public Pancake
{
	float cost()
	{
		return 2.0;
	}
	string description()
	{
		return "+C&Cream Base ";
	}
};
class Cookie_Dough :public Pancake
{
	float cost()
	{
		return 2.0;
	}
	string description()
	{
		return "+Cookie_Dough Base ";
	}
};
#pragma endregion
//============================================================== Decorators (extras) ==============================================================
class Plain_T :public Pancake_Decorator			//Plain class that is a public Pancake decorator with its own cost and description
{
	float cost()								//Cost that over-rides the pancake decorator class' cost variable for this specific decorator 
	{
		return (0 + pancake->cost());			//Modifies the cost of the pancake at the memory location held in the pancake decorator main
	}											//    class and adds the cost for this specific decorator/topping
	string description()						//Description that over-rides the decorator class' description variable
	{
		return (pancake->description() + "+No Toppings ");	//Modifies the description of the pancake at the memory location held in the pancake
	}														//    decorator main class and extends it by adding the description for this topping
};												//I HAVE COLLAPSED ALL CLASSES THAT ARE IDENTICAL TO THIS ONE IN TERMS OF IMPLEMENTATION
#pragma region More Decorators
class Frosted :public Pancake_Decorator
{
	float cost()
	{
		return (30 + pancake->cost());
	}
	string description()
	{
		return (pancake->description() + "+Frost ");
	}
};
class Chocolate_T :public Pancake_Decorator
{
	float cost()
	{
		return (30 + pancake->cost());
	}
	string description()
	{
		return (pancake->description() + "+Chocolate ");
	}
};
class Chocolate_Chip :public Pancake_Decorator
{
	float cost()
	{
		return (30 + pancake->cost());
	}
	string description()
	{
		return (pancake->description() + "+Choc Chip ");
	}
};
class Smarties :public Pancake_Decorator
{
	float cost()
	{
		return (30 + pancake->cost());
	}
	string description()
	{
		return (pancake->description() + "+Smarties ");
	}
};
class Wild_Berry_T :public Pancake_Decorator
{
	float cost()
	{
		return (30 + pancake->cost());
	}
	string description()
	{
		return (pancake->description() + "+Wild Berry ");
	}
};
class Wildlicious :public Pancake_Decorator
{
	float cost()
	{
		return (50 + pancake->cost());
	}
	string description()
	{
		return (pancake->description() + "+Wildilicious ");
	}
};
class H_and_T :public Pancake_Decorator
{
	float cost()
	{
		return (50 + pancake->cost());
	}
	string description()
	{
		return (pancake->description() + "+100s and thousands ");
	}
};
class Jelly_Beans :public Pancake_Decorator
{
	float cost()
	{
		return (50 + pancake->cost());
	}
	string description()
	{
		return (pancake->description() + "+Jelly Beans ");
	}
};
class Brown_Sugar :public Pancake_Decorator
{
	float cost()
	{
		return (30 + pancake->cost());
	}
	string description()
	{
		return (pancake->description() + "+Brown Sugar ");
	}
};
#pragma endregion
//=============================================================== pancake interfaces ==============================================================
int getCost(Pancake* thisPancake)								//Get cost function to further seperate classes from PANCAKE DEPENDANCE
{
	if (thisPancake != NULL)return (thisPancake->cost());		//If the memory address pointed to is not empty/NULL then return cost ->
	else return 0;														//Otherwise return a value of 0, to not break if there is no pancake
}
string getDescription(Pancake* thisPancake)								//Get description function to seperate classes further from pancakes
{
	if (thisPancake != NULL)return (thisPancake->description());		//If the memory address pointed to is not null return description ->
	else return " ";															//Otherwise return " " (space)
}

class Transition																//Class for holding transitions between states 							
{
public:
	virtual void insertMoney(int) {}											//Insert money transition
	virtual void makeSelectionFill(Pancake*){}									//Customised makeselection function that takes a Pancake pointer
	virtual void makeSelectionTopper(Pancake_Decorator*){}						//Customised makeselection function that takes a decorator pointer
	virtual void moneyRejected(void){}											//Money rejected transition
	virtual void addMix(int number){}											//Add mix transition
	virtual void dispense(void){}												//Dispense transition

};
class StateContext																//Class for handling the getting and setting of states and
{																				//    state parameters
protected:
	State* currentState;														//Pointer to the memory address where the current state is stored
	Pancake* currentPancake = new Plain_F;										//Pointer to the memory address of a current sale of pancake
	Pancake_Decorator* currentDecorator;										//Pointer to the current decorator being applied to the pancake
	vector<State*> availableStates;												//Vector that holds all available state classes 
	vector<int> stateParameters;												//Vector that holds all available stateparameters of type int

public:
	~StateContext()																//StateContect default deconstructor
	{
		for (int i = 0; i < availableStates.size(); i++)						//For every available state-->
		{
			delete availableStates[i];											//Delete that available state
		}
	}
	virtual void setState(state newState)										//Virtual State function that takes a state as a parameter
	{
		this->currentState = availableStates[newState];							//Sets the current state to the state passed into the function
		switch (newState)														//On transition in to these states display these screens
		{
		case Out_Of_Mix:
			PInterface(this->stateParameters[Credit], this->stateParameters[No_Of_Mix], getCost(currentPancake), 14);//Insert Mix Screen
			break;
		case No_Credit:
			PInterface(this->stateParameters[Credit], this->stateParameters[No_Of_Mix], getCost(currentPancake), 11);//Insert Money Screen
			break;
		case Has_Credit:
			PInterface(this->stateParameters[Credit], this->stateParameters[No_Of_Mix], getCost(currentPancake), 9);//Front End Interface
			break;
		case Has_Credit2:
			PInterface(this->stateParameters[Credit], this->stateParameters[No_Of_Mix], getCost(currentPancake), 13);//Topper selection interface
			break;
		case Dispenses_PCake:
			PInterface(this->stateParameters[Credit], this->stateParameters[No_Of_Mix], getCost(currentPancake), 15);//dispensed below screen
			break;
		}
	}
	void setStateParam(stateParameter StateParam, int value)					//Set State Parameter function that takes a state parameter
	{																			//    and an int as parameters
		this->stateParameters[StateParam] = value;								//Sets the state parameter input to the int input
	}
	int getStateParam(stateParameter StateParam)								//Get State Parameter function that takes a state parameter
	{																			//    and returns an int
		return this->stateParameters[StateParam];								//Returns the int value of the state parameter input 
	}

	void setPancake(Pancake* thisPancake)										//Set current pancake function that takes a pancake pointer
	{																	 
		this->currentPancake = thisPancake;										//Stores the pointer input into the locally held pancake pointer
	}
	Pancake* getPancake(void)													//Get pancake function that returns the pointer to the current
	{																			//    sale pancake
		return this->currentPancake;											//Returns the pointer to the current sales' pancake
	}
	void decoratePancake(Pancake_Decorator* thisDecorator)						//Decorate pancake constructor that takes a decorator pointer
	{
		this->currentDecorator = thisDecorator;									//Stores the pointer input into the locally held decorator one
		currentDecorator->addToPancake(currentPancake);							//Adds the decorator to the current sale pancake
		currentPancake = currentDecorator;										//Copies the current pancake pointer to the current decorator
	}
	void clearPancake(void)														//Clears pancake function
	{
		currentPancake = NULL;													//Clears the memory address of the current sales' pancake
		currentDecorator = NULL;												//Cleasrs the memory address of the current sales' decorator
	}
};
class State : public Transition
{
protected:

	StateContext* currentContext;

public:
	State(StateContext* Context)
	{
		currentContext = Context;
	}

};
class OutOfMix : public State											//Out of mix state
{
public:
	OutOfMix(StateContext* Context) : State(Context){}					//On creation sets the current state context to outofmix
	void insertMoney(int money)											//If money is inserted in this state:
	{
																		//Do nothing do not want to be able to add mix in insert mix screen
	}
	void makeSelectionFill(Pancake* currentSale)				//If a selection is made in this state:
	{
																//Do nothing do not want to be able to make selection in insert mix screen
	}
	void makeSelectionTopper(Pancake_Decorator* currentSale)	//If a topper selection is made in this state:
	{
																//Do nothing do not want to be able to make selection in insert mix screen
	}
	void moneyRejected(void)									//If money is rejected in this state:
	{
																//Do nothing do not want to be able to eject money in insert mix screen
	}
	void addMix(int number)										//If mix is added in this state:
	{
			this->currentContext->setStateParam(No_Of_Mix, (number + this->currentContext->getStateParam(No_Of_Mix)));
			if (this->currentContext->getStateParam(Save_Point) == 1)
			{
				this->currentContext->setState(Has_Credit);		//THESE LINES MAKE SURE THE MAXIMUM AMOUNT OF MIX IS NOT EXCEEDED
			}
			else this->currentContext->setState(Has_Credit2);
	}
	void dispense(void)											//If dispense is chosen in this state
	{
																//do nothing do not want to be able todispense in insert mix screen
	}
};
class NoCredit : public State									//Out of credit state
{
public:

	NoCredit(StateContext* Context) : State(Context){}			//On creation sets the current state context to outofcredit

	void insertMoney(int money)									//If money is inserted in this state:
	{
		this->currentContext->setStateParam(Credit, (money + this->currentContext->getStateParam(Credit)));
		if (this->currentContext->getStateParam(Save_Point) == 1)
		{
			this->currentContext->setState(Has_Credit);			//THESE LINES ADD CREDIT THEN RETURN TO THE PREVIOUS SCREEN HELD IN SAVEPOINT
		}
		else this->currentContext->setState(Has_Credit2);
	}
	void makeSelectionFill(Pancake* currentSale)				//If a selection is made in this state:
	{
																		//do nothing do not want to be able to add mix in insert credit screen
	}

	void makeSelectionTopper(Pancake_Decorator* currentSale)			//If a topper selection is made in this state:
	{
																		//do nothing do not want to be able to decorate in no credit screen
	}
	void moneyRejected(void)											//If money is rejected in this state:
	{
																		//do nothing do not want to be able to add mix in insert credit screen
	}
	void addMix(int number)												//If mix is added in this state:
	{
																		//do nothing do not want to be able to add mix in insert credit screen
	}	
	void dispense(void)													//If dispense is chosen in this state:
	{
																		//do nothing do not want to be able to add mix in insert credit screen
	}
};
class HasCredit : public State											//Has credit state
{
public:

	HasCredit(StateContext* Context) : State(Context){}					//On creation sets the current state context to outofcredit
	void insertMoney(int money)											//If money is inserted in this state:
	{
		this->currentContext->setState(No_Credit);						//Modified so that this just changes dispenser state
	}
	void makeSelectionFill(Pancake* currentSale)						//If a selection is made in this state:
	{
		this->currentContext->setPancake(currentSale);
		this->currentContext->setStateParam(Save_Point, 2);				//THESE LINES STORE THE SELECTED PANCAKE AND CHANGE THE SAVE POINT
		this->currentContext->setState(Has_Credit2);
	}
	void makeSelectionTopper(Pancake_Decorator* currentSale)			//When a topper selection is made in this state:
	{
																		//do nothing do not want to be able to decorate in has credit screen
	}
	void moneyRejected(void)											//If money is rejected in this state:
	{
		this->currentContext->setStateParam(Credit, 0);
		this->currentContext->setState(No_Credit);						//THESE LINES CLEAR THE DISPENSER AND SET IT TO THE NO CREDIT STATE
		this->currentContext->clearPancake();
	}
	void addMix(void)													//When mix is added in this state:
	{
		this->currentContext->setState(Out_Of_Mix);						//Modified so this just changes dispenser state
	}
	void dispense(void)													//If dispense is chosen in this state:
	{
																		//do nothing do not want to be able to dispense in has credit screen
	}
};
class HasCredit2 : public State											//Second has credit class used for adding toppings
{
public:
	HasCredit2(StateContext* Context) : State(Context){}				//On creation sets the current state context to outofcredit
	void insertMoney(int money)											//If money is inserted in this state:
	{
		this->currentContext->setState(No_Credit);						//modified so that this just changes dispenser state
	}
	void makeSelectionFill(Pancake* currentSale)						//If a selection is mad in this state:
	{
																//do nothing do not want to be able to make selection in has credit2 screen
	}
	void makeSelectionTopper(Pancake_Decorator* currentSale)			//If a topping selection is made in this state:
	{
		this->currentContext->decoratePancake(currentSale);
		this->currentContext->setState(Has_Credit2);					//go back to this state so that it renews display
	}
	void moneyRejected(void)											//If money is rejected in this state:
	{
		this->currentContext->setStateParam(Credit, 0);
		this->currentContext->setState(No_Credit);						//THESE LINES CLEAR THE DISPENSER AND SET IT TO THE NO CREDIT STATE
		this->currentContext->setStateParam(Save_Point, 1);				//    THEY ALSO CLEAR THE SAVE POINT
		this->currentContext->clearPancake();
	}
	void addMix(void)													//If mix is added in this state:
	{
		this->currentContext->setState(Out_Of_Mix);				//modified so that this just changes dispenser state depending on mix level
	}
	void dispense(void)											//If dispense is chosen in this state:
	{
		this->currentContext->setState(Dispenses_PCake);		//Set stae to dispense pancake so that one is dispensed after validation
	}
};
class DispensesPCake : public State								//Dispensing of pancake state
{
public:
	DispensesPCake(StateContext* Context) : State(Context){}		//On creation sets the current state context to outofcredit
	void insertMoney(int money)										//If money is inserted in this state:
	{
																	//do nothing do not want to be able to insert credit in dispensing screen
	}
	void makeSelectionFill(Pancake* currentSale)					//If a selection is made in this state:
	{
																	//do nothing do not want to be able to make selection in dispensing screen
	}
	void makeSelectionTopper(Pancake_Decorator* currentSale)		//If a topping selection is made in this state:
	{
																	//do nothing do not want to be able to make selection in insert mix screen
	}
	void moneyRejected(void)										//If money is rejected in this state:
	{
																	//do nothing do not want to be able to reject money in dispensing screen
	}
	void addMix(int number)											//If mix is added in this state:
	{
																	//do nothing do not want to be able to add mix in dispensing screen
	}
	void dispense(void)												//If dispense is selected in this state:
	{
		this->currentContext->setStateParam(Cost_Of_PCake, (getCost(this->currentContext->getPancake())));	//Sets the cost of the pancake

		if (this->currentContext->getStateParam(Credit) >= this->currentContext->getStateParam(Cost_Of_PCake))	//Money check
		{
			this->currentContext->setStateParam(Credit, this->currentContext->getStateParam(Credit) - this->currentContext->getStateParam(Cost_Of_PCake));
			this->currentContext->setStateParam(No_Of_Mix, this->currentContext->getStateParam(No_Of_Mix) - 1); //Take money and mix
			//====================================== CHANCE TO WIN A SECOND PANCAKE =================================
			int doesWin = RandomNumber(1, 10);//returns an int between 1 and 10
			if (doesWin == 1)																					//1/10 (10% chance)
			{
				PInterface(this->currentContext->getStateParam(Credit), this->currentContext->getStateParam(No_Of_Mix), getCost(this->currentContext->getPancake()), 15);		//dispensed below screen
				PInterface(this->currentContext->getStateParam(Credit), this->currentContext->getStateParam(No_Of_Mix),getCost(this->currentContext->getPancake()), 16);		//has won banner
				this->currentContext->setStateParam(No_Of_Mix, this->currentContext->getStateParam(No_Of_Mix) - 1);
			}																									//If you win take second mix
			else
			{
				PInterface(this->currentContext->getStateParam(Credit), this->currentContext->getStateParam(No_Of_Mix), getCost(this->currentContext->getPancake()), 15);		//dispensed below screen
				PInterface(this->currentContext->getStateParam(Credit), this->currentContext->getStateParam(No_Of_Mix), getCost(this->currentContext->getPancake()), 17);		//has lost banner
			}																									//If you loose display loose
			cout << setfill(' ') << setw(68)<< left << getDescription(this->currentContext->getPancake()) << right << endl;
			PInterface(this->currentContext->getStateParam(Credit), this->currentContext->getStateParam(No_Of_Mix), getCost(this->currentContext->getPancake()), 8);		//double bar callout

			this->currentContext->clearPancake();									//THESE FOLLOWING LINES CLEAR THE CURRENT SALES PANCAKE
			system("pause");														//AND RETURN YOU TO THE APPROPRIATE STATE DEPENDING ON
																					//MONEY, MIX LEFT, AND THEN RESET THE SAVE POINT
			if (this->currentContext->getStateParam(Credit) > 0)
			{
				this->currentContext->setStateParam(Save_Point, 1);
				this->currentContext->setState(Has_Credit);
			}
			else
			{
				this->currentContext->setStateParam(Save_Point, 1);
				this->currentContext->setState(No_Credit);
			}
			if (this->currentContext->getStateParam(No_Of_Mix) == 0)
			{
				this->currentContext->setState(Out_Of_Mix);
			}
		}
		else
		{
			this->currentContext->setState(Has_Credit2);							//THIS ELSE STATEMENT RETURNS YOU TO THE PREVIOUS SAVE POINT
			cout << "Error! Not enough money" << endl;								//IF YOU DIDNT HAVE ENOUGH MONEY
		}
	}
};
class PCake_Dispenser : public StateContext, Transition {				//THIS CLASS ENCAPSULATES ALL THE STATES, TRANSITIONS AND FUNCTIONS
public:																	//OF THE STATE PATTERN
	PCake_Dispenser(int Mix_count) //constructor
	{
		this->availableStates.push_back(new OutOfMix(this));
		this->availableStates.push_back(new NoCredit(this));
		this->availableStates.push_back(new HasCredit(this));
		this->availableStates.push_back(new HasCredit2(this));
		this->availableStates.push_back(new DispensesPCake(this));
		this->stateParameters.push_back(0); // No of Mix
		this->stateParameters.push_back(0); // Available Credit
		this->stateParameters.push_back(50); //Cost of Pancake
		this->stateParameters.push_back(1); //save state 1 = filler 2 = topper
		this->setState(Out_Of_Mix);
		if (Mix_count > 0)
		{
			this->addMix(Mix_count);
		}
	}
	void insertMoney(int money)
	{
		this->currentState->insertMoney(money);
	}
	void makeSelectionFill(Pancake* currentSale)
	{
		this->currentState->makeSelectionFill(currentSale);
	}
	void makeSelectionTopper(Pancake_Decorator* currentSale)
	{
		this->currentState->makeSelectionTopper(currentSale);
	}
	void moneyRejected(void)
	{
		this->currentState->moneyRejected();
	}
	void addMix(int mix_count)
	{
		this->currentState->addMix(mix_count);
	}
	void dispense(void)
	{
		this->currentState->dispense();
	}
};



//================================================== MAIN LOOP ===================================================================================
// KEEPS TRACK OF WHERE YOU ARE IN THE DISPENSER WITHOUT GIVING THE USER ANY ACCESS TO THE STATES IN THE DISPENSER
void main()
{
	bool running = true;
	int trackMyState = 0; // 0 = No Mix, 1 = No Credit , 2 = Has Credit, 3 = has Credit2 , 4 = Dispensing
	int trackSaveState = 1; // 1 = was selecting filler , 2 = was selecting topper
	PCake_Dispenser* myDispenser = new PCake_Dispenser(0);
	Pancake* myPancake;
	Pancake_Decorator* myDecorator;
	int tmpInput;

	while (running)
	{
		switch (trackMyState)					//switch case for displaying different screens
		{
		case 0://validation for input of addmix state (no mix)
#pragma region NO_MIX
			tmpInput = 0;//clear tmpInput of previously stored user input

			//cin.clear();
			//cin.ignore(1000, '\n');
			cin >> tmpInput;
			while (tmpInput <= 0 || tmpInput > 25)
			{
				cin >> tmpInput;							//user input to make selection on screen
			}
			if (tmpInput > 0 && (tmpInput + myDispenser->getStateParam(No_Of_Mix) <= 25))
			{
				myDispenser->addMix(tmpInput);
			}
			if (trackSaveState == 1)trackMyState = 2;
			else trackMyState = 3;

			tmpInput = 0;//clear tmpInput of previously stored user input
			break;
#pragma endregion
		case 1://validation for input of money state (no credit)
#pragma region NO_CREDIT
			tmpInput = 0;//clear tmpInput of previously stored user input

			//cin.clear();
			//cin.ignore(1000, '\n');
			cin >> tmpInput;
			while (tmpInput <= 0 || tmpInput > 2000)
			{
				cin >> tmpInput;							//user input to make selection on screen
			}
			myDispenser->insertMoney(tmpInput);
			if (trackSaveState == 1)trackMyState = 2;
			else trackMyState = 3;

			tmpInput = 0;//clear tmpInput of previously stored user input
#pragma endregion
			break;

		case 2://validation for input of choose filler state (has credit)
#pragma region HAS_CREDIT
			tmpInput = 0; //clear tmpInput of previously stored user input

			//cin.clear();
			//cin.ignore(1000, '\n');
			cin >> tmpInput;
			while (tmpInput <= 0 || tmpInput > 22)//valid input range
			{
				cin >> tmpInput;
			}

			switch (tmpInput)
			{
			case 1:
				myPancake = new Plain_F();
				myDispenser->makeSelectionFill(myPancake);
				trackMyState = 3;
				break;
			case 2:
				myPancake = new Vanilla_Cream();
				myDispenser->makeSelectionFill(myPancake);
				trackMyState = 3;
				break;
			case 3:
				myPancake = new Chocolate_F();
				myDispenser->makeSelectionFill(myPancake);
				trackMyState = 3;
				break;
			case 4:
				myPancake = new Fudge();
				myDispenser->makeSelectionFill(myPancake);
				trackMyState = 3;
				break;
			case 5:
				myPancake = new Chocolate_Fudge();
				myDispenser->makeSelectionFill(myPancake);
				trackMyState = 3;
				break;
			case 6:
				myPancake = new Strawberry();
				myDispenser->makeSelectionFill(myPancake);
				trackMyState = 3;
				break;
			case 7:
				myPancake = new Raspberry();
				myDispenser->makeSelectionFill(myPancake);
				trackMyState = 3;
				break;
			case 8:
				myPancake = new Blueberry();
				myDispenser->makeSelectionFill(myPancake);
				trackMyState = 3;
				break;
			case 9:
				myPancake = new Wild_Berry_F();
				myDispenser->makeSelectionFill(myPancake);
				trackMyState = 3;
				break;
			case 10:
				myPancake = new Cherry();
				myDispenser->makeSelectionFill(myPancake);
				trackMyState = 3;
				break;
			case 11:
				myPancake = new Peanut_Butter();
				myDispenser->makeSelectionFill(myPancake);
				trackMyState = 3;
				break;
			case 12:
				myPancake = new Cookie_Dough();
				myDispenser->makeSelectionFill(myPancake);
				trackMyState = 3;
				break;
			case 13:
				myPancake = new Cookies_and_Cream();
				myDispenser->makeSelectionFill(myPancake);
				trackMyState = 3;
				break;
			case 14://return money
				myDispenser->moneyRejected();
				trackMyState = 1;
				break;
			case 20://input money
				myDispenser->insertMoney(0);
				trackMyState = 1;
				break;
			case 21://input mix
				myDispenser->addMix(0);
				trackMyState = 0;
				break;
			case 22://shutdown
				running = false;
				break;
			}

			tmpInput = 0;//clear tmpInput of previously stored user input
#pragma endregion
			break;

		case 3://validation for input of choose topping state (has credit2)
#pragma region HAS_CREDIT2
			tmpInput = 0; //clear tmpInput of previously stored user input
			trackSaveState = 2;

			//cin.clear();
			//cin.ignore(1000, '\n');
			cin >> tmpInput;
			while (tmpInput <= 0 || tmpInput > 22)//valid input range
			{
				cin >> tmpInput;
			}
			
			switch (tmpInput)
			{
			case 1:
				myDecorator = new Brown_Sugar();
				myDispenser->makeSelectionTopper(myDecorator);
				break;
			case 2:
				myDecorator = new Frosted();
				myDispenser->makeSelectionTopper(myDecorator);
				break;
			case 3:
				myDecorator = new Chocolate_T();
				myDispenser->makeSelectionTopper(myDecorator);
				break;
			case 4:
				myDecorator = new Chocolate_Chip();
				myDispenser->makeSelectionTopper(myDecorator);
				break;
			case 5:
				myDecorator = new Smarties();
				myDispenser->makeSelectionTopper(myDecorator);
				break;
			case 6:
				myDecorator = new Wild_Berry_T();
				myDispenser->makeSelectionTopper(myDecorator);
				break;
			case 7:
				myDecorator = new Wildlicious();
				myDispenser->makeSelectionTopper(myDecorator);
				break;
			case 8:
				myDecorator = new H_and_T();
				myDispenser->makeSelectionTopper(myDecorator);
				break;
			case 9:
				myDecorator = new Jelly_Beans();
				myDispenser->makeSelectionTopper(myDecorator);
				break;
			case 10://done //remeber fix ui
				myDispenser->dispense();
				trackMyState = 4;
				break;
			case 11://return
				myDispenser->moneyRejected();
				trackSaveState = 1;
				trackMyState = 1;
				break;
			case 20://input money
				myDispenser->insertMoney(0);
				trackMyState = 1;
				break;
			case 21://input mix
				myDispenser->addMix(0);
				trackMyState = 0;
				break;
			case 22://shutdown
				running = false;
				break;
			}

			tmpInput = 0;//clear tmpInput of previously stored user input
#pragma endregion
			break;

		case 4://validation for dispense state (same as dispense state itself to simulate outcome)
#pragma region DISPENSES_PCAKE
			myDispenser->dispense();
			if (myDispenser->getStateParam(Credit) >= myDispenser->getStateParam(Cost_Of_PCake))//succesfull dispense
			{
				if (myDispenser->getStateParam(Credit) > 0)
				{
					trackSaveState = 1;
					trackMyState = 2; //back to has credit validation
				}
				else
				{
					trackSaveState = 1;
					trackMyState = 1; //back to no credit validation
				}
				if (myDispenser->getStateParam(No_Of_Mix) == 0)
				{
					trackMyState = 0;
				}
			}
			else
			{
				trackMyState = 3; //back to has credit 2 validation (keeps save state 2)
			}
#pragma endregion
			break;

		}
	}

	delete myDispenser;
	system("pause");
}



//INTERFACE CALLOUTS TO STOP ME HAVING TO RE-TYPE THEM A MILLION TIMES
void PInterface(int money,int mix,int cost, int interfaceOption)
{
	int tmpMoney = 0;
	int tmpPennies = 0;
	int tmpPounds = 0;
	int tmpMix = 0;
	int tmpMixPegs = 0;
	string pegHolder = "";
	int tmpCost = 0;
	int tmpCostPennies = 0;
	int tmpCostPounds = 0;
	char poundSymbol = 156;
	switch (interfaceOption)
	{
	case 0://Header Callout
		cout << "============= Super Pancake Dispenser Of Awesomeness =========R3.0==" << endl;
		break;
	case 1://Clear Page
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		break;
	case 2://Horizontal Bar Callout
		cout << "====================================================================" << endl;
		break;
	case 3://Machine Status Bar Callout
		//"== £ "0000":"0000" ===="
		tmpMoney = money;
		tmpPennies = tmpMoney % 100;
		tmpPounds = floor(tmpMoney / 100);
		tmpMix = mix;
		tmpMixPegs = floor(tmpMix / 2.5);//splits the 25 capacity into 10 bars
		tmpCost = cost;
		tmpCostPennies = tmpCost % 100;
		tmpCostPounds = floor(tmpCost / 100);
		cout << "== " << poundSymbol << " " << setfill('0') << setw(3) << tmpPounds << ":" << setfill('0') << setw(2) << tmpPennies << " ========= COST: ";
		cout << poundSymbol << " " << setfill('0') << setw(2) << tmpCostPounds << ":" << setfill('0') << setw(2) << tmpCostPennies << " =========== MIX: [";
		for (int i = 0; i < tmpMixPegs; i++)pegHolder += "#";
		cout << setfill(' ') << setw(10) << left << pegHolder << right << "] ==" << endl;
		break;
	case 4://Fill-Up Prompt
		cout << "=============        TECHNICIAN: PLEASE ADD MIX        =============" << endl;
		break;
	case 5://How-To Screen
		cout << "================ 20 = Add Money ====== 21 = Add Mix ================" << endl;
		break;
	case 6://Filler Option Screen
		cout << "== Pancake Filler Options: =========================================" << endl;
		PInterface(money, mix, cost, 2);//Horizontal Bar
		PInterface(money, mix, cost, 7);//Menu Filler Bar
		cout << "== 1.  PLAIN\t\t= 2.  VANILLA\t\t= 3.  CHOCOLATE\t  ==" << endl;
		cout << "==\t" << poundSymbol << "1.50\t\t=\t" << poundSymbol << "1.80\t\t=\t" << poundSymbol << "1.80\t  ==" << endl;
		cout << "== 4.  FUDGE\t\t= 5.  CHOC FUDGE\t= 6.  STRAWBERRY  ==" << endl;
		cout << "==\t" << poundSymbol << "1.80\t\t=\t" << poundSymbol << "1.80\t\t=\t" << poundSymbol << "1.80\t  ==" << endl;
		cout << "== 7.  RASPBERRY\t= 8.  BLUEBERRY\t\t= 9.  WILD BERRY  ==" << endl;
		cout << "==\t" << poundSymbol << "1.80\t\t=\t" << poundSymbol << "1.80\t\t=\t" << poundSymbol << "1.80\t  ==" << endl;
		cout << "== 10. CHERRY\t\t= 11. PNT.BUTTER\t=\t\t  ==" << endl;
		cout << "==\t" << poundSymbol << "1.80\t\t=\t" << poundSymbol << "1.80\t\t=\t\t  ==" << endl;
		cout << "== 12. COOKIE DOUGH\t= 13. COOKIES & CREAM\t= 14. RETURN\t  ==" << endl;
		cout << "==\t" << poundSymbol << "2.00\t\t=\t" << poundSymbol << "2.00\t\t=\t\t  ==" << endl;
		break;
	case 7://Menu Filler Bar
		cout << "==\t\t\t=\t\t\t=\t\t  ==" << endl;
		break;
	case 8://Double Bar Callout
		PInterface(money, mix, cost, 2);//Horizontal Bar
		PInterface(money, mix, cost, 2);//Horizontal Bar
		break;
	case 9://Front End
		PInterface(money, mix, cost, 1);//Clear Page
		PInterface(money, mix, cost, 0);//Header text
		PInterface(money, mix, cost, 2);//Horizontal Bar
		PInterface(money, mix, cost, 3);//Machine Status Bar
		PInterface(money, mix, cost, 2);//Horizontal Bar
		PInterface(money, mix, cost, 6);//Filler Option Bars
		PInterface(money, mix, cost, 7);//Menu Filler Bar
		PInterface(money, mix, cost, 8);//Double Horizontal Bar
		PInterface(money, mix, cost, 5);//How To Bar
		PInterface(money, mix, cost, 8);//Double Horizontal Bar
		break;
	case 10://Fill Up Screen
		PInterface(money, mix, cost, 1);//Clear screen
		PInterface(money, mix, cost, 0);//Header text
		PInterface(money, mix, cost, 4);//Fillup text
		cout << "Add Mix(Max 25): " << endl;
		break;
	case 11://Insert Credit Screen
		PInterface(money, mix, cost, 1);//Clear Page
		PInterface(money, mix, cost, 0);//Header text
		PInterface(money, mix, cost, 2);//Horizontal Bar
		PInterface(money, mix, cost, 3);//Machine Status Bar
		PInterface(money, mix, cost, 8);//Double Horizontal Bar
		PInterface(money, mix, cost, 8);//Double Horizontal Bar
		cout << "==                   _                      _                     ==" << endl;
		cout << "==                  |_| ___  ___  ___  ___ | |_                   ==" << endl;
		cout << "==                  | ||   ||_ -|| -_||  _||  _|                  ==" << endl;
		cout << "==                  |_||_|_||___||___||_|  |_|                    ==" << endl;
		cout << "==                                                                ==" << endl;
		cout << "==                                    _  _  _                     ==" << endl;
		cout << "==                   ___  ___  ___  _| ||_|| |_                   ==" << endl;
		cout << "==                  |  _||  _|| -_|| . || ||  _|                  ==" << endl;
		cout << "==                  |___||_|  |___||___||_||_|                    ==" << endl;
		cout << "==                                                       1p - " << poundSymbol << "20 ==" << endl;
		PInterface(money, mix, cost, 8);//Double Horizontal Bar
		PInterface(money, mix, cost, 8);//Double Horizontal Bar
		PInterface(money, mix, cost, 8);//Double Horizontal Bar
		break;
	case 12://Topper Option Screen
		cout << "== Pancake Topper Options: =========================================" << endl;
		PInterface(money, mix, cost, 2);//Horizontal Bar
		PInterface(money, mix, cost, 7);//Menu Filler Bar
		cout << "== 1.  BROWN SUGAR\t\t= 2.  FROSTED\t\t= 3.  CHOCOLATE\t  ==" << endl;
		cout << "==\t" << poundSymbol << "0.30\t\t=\t" << poundSymbol << "0.30\t\t=\t" << poundSymbol << "0.30\t  ==" << endl;
		cout << "== 4.  CHOC CHIP\t= 5.  SMARTIES\t\t= 6.  WILD BERRY  ==" << endl;
		cout << "==\t" << poundSymbol << "0.30\t\t=\t" << poundSymbol << "0.30\t\t=\t" << poundSymbol << "0.50\t  ==" << endl;
		cout << "== 7.  WILDILICIOUS\t= 8.  100s & 1000s\t= 9.  JELLY BEANS ==" << endl;
		cout << "==\t" << poundSymbol << "0.50\t\t=\t" << poundSymbol << "0.50\t\t=\t" << poundSymbol << "\t  ==" << endl;
		PInterface(money, mix, cost, 7);//Menu Filler Bar
		PInterface(money, mix, cost, 7);//Menu Filler Bar
		PInterface(money, mix, cost, 7);//Menu Filler Bar
		cout << "== 10. DONE\t\t=\t\t\t= 11. RETURN\t  ==" << endl;
		break;
	case 13://Choose Toppers Screen
		PInterface(money, mix, cost, 1);//Clear Page
		PInterface(money, mix, cost, 0);//Header text
		PInterface(money, mix, cost, 2);//Horizontal Bar
		PInterface(money, mix, cost, 3);//Machine Status Bar
		PInterface(money, mix, cost, 2);//Horizontal Bar
		PInterface(money, mix, cost, 12);//Topper Option Bars
		PInterface(money, mix, cost, 7);//Menu Filler Bar
		PInterface(money, mix, cost, 8);//Double Horizontal Bar
		PInterface(money, mix, cost, 5);//How To Bar
		PInterface(money, mix, cost, 8);//Double Horizontal Bar
		break;
	case 14:
		PInterface(money, mix, cost, 1);//Clear Page
		PInterface(money, mix, cost, 0);//Header text
		PInterface(money, mix, cost, 2);//Horizontal Bar
		PInterface(money, mix, cost, 3);//Machine Status Bar
		PInterface(money, mix, cost, 8);//Double Horizontal Bar
		PInterface(money, mix, cost, 8);//Double Horizontal Bar
		cout << "==                   _                      _                     ==" << endl;
		cout << "==                  |_| ___  ___  ___  ___ | |_                   ==" << endl;
		cout << "==                  | ||   ||_ -|| -_||  _||  _|                  ==" << endl;
		cout << "==                  |_||_|_||___||___||_|  |_|                    ==" << endl;
		cout << "==                                                                ==" << endl;
		cout << "==                               _                                ==" << endl;
		cout << "==                        _____ |_| _ _                           ==" << endl;
		cout << "==                       |     || ||_'_|                          ==" << endl;
		cout << "==                       |_|_|_||_||_,_|                          ==" << endl;
		cout << "==                                                        1 - " << poundSymbol << "20 ==" << endl;
		PInterface(money, mix, cost, 8);//Double Horizontal Bar
		PInterface(money, mix, cost, 8);//Double Horizontal Bar
		PInterface(money, mix, cost, 8);//Double Horizontal Bar
		break;
	case 15://dispensed below ribbon
		PInterface(money, mix, cost, 1);//Clear Page
		PInterface(money, mix, cost, 0);//Header text
		PInterface(money, mix, cost, 2);//Horizontal Bar
		PInterface(money, mix, cost, 3);//Machine Status Bar
		PInterface(money, mix, cost, 2);//Horizontal Bar
		cout << "==             _  _                                  _            ==" << endl;
		cout << "==           _| ||_| ___  ___  ___  ___  ___  ___  _| |           ==" << endl;
		cout << "==          | . || ||_ -|| . || -_||   ||_ -|| -_|| . |           ==" << endl;
		cout << "==          |___||_||___||  _||___||_|_||___||___||___|           ==" << endl;
		cout << "==                   _   |_|   _                                  ==" << endl;
		cout << "==                  | |_  ___ | | ___  _ _ _                      ==" << endl;
		cout << "==                  | . || -_|| || . || | | |                     ==" << endl;
		cout << "==                  |___||___||_||___||_____|                     ==" << endl;
		cout << "==                                                                ==" << endl;
		break;
	case 16://you did win this time ribbon
		cout << "==  _|_                                                      _|_  ==" << endl;
		cout << "==   |                                              _         |   ==" << endl;
		cout << "==      _ _ _  ___  ___    ___  ___  ___  ___  ___ | |_  ___      ==" << endl;
		cout << "==     | | | || . ||   |  | . || .'||   ||  _|| .'|| '_|| -_|     ==" << endl;
		cout << "==     |_____||___||_|_|  |  _||__,||_|_||___||__,||_,_||___|     ==" << endl;
		cout << "==                        |_|                                     ==" << endl;
		break;
	case 17://you didnt win this time ribbon
		cout << "==  _|_                                                      _|_  ==" << endl;
		cout << "==   |                       _                                |   ==" << endl;
		cout << "==               ___  ___   | |_  ___  ___  _ _  ___              ==" << endl;
		cout << "==              |   || . |  | . || . ||   || | ||_ -|             ==" << endl;
		cout << "==              |_|_||___|  |___||___||_|_||___||___|             ==" << endl;
		cout << "==                                                                ==" << endl;
		break;
	case 18://not enough credit for pancake ribbon
		cout << "==                     _                          _               ==" << endl;
		cout << "==             ___ ___| |_    ___ ___ ___ _ _ ___| |_             ==" << endl;
		cout << "==            |   | . |  _|  | -_|   | . | | | . |   |            ==" << endl;
		cout << "==            |_|_|___|_|    |___|_|_|___|___|_  |_|_|            ==" << endl;
		cout << "==                                 _ _ _     |___|                ==" << endl;
		cout << "==                   ___ ___ ___ _| |_| |_                        ==" << endl;
		cout << "==                  |  _|  _| -_| . | |  _|                       ==" << endl;
		cout << "==                  |___|_| |___|___|_|_|                         ==" << endl;
		break;
	}
}

int RandomNumber(int min, int max)
{
	random_device rd;
	mt19937 mt(rd());

	//create random number with given min and max
	uniform_int_distribution<int>iRand(min, max);

	int returnVal = iRand(rd);

	return returnVal;
}

