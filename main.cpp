#include<string>

/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
    - if your functions return something other than 'void', add a comment explaining what is being returned.  see the example code below.
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a [-Wpadded] warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips); //3) returns the number of miles traveled
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage); //3) returns the total amount charged.
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};


/*
Thing 1) Rock Band
5 properties:
    1) number of players
    2) number of rehersal time per week
    3) number of live show time per week
    4) amount of money made per live show
    5) amount of money spent for rehersal in studio
3 things it can do:
    1) schedule the tour plan
    2) do live show
    3) make money
*/
struct RockBand
{
    int numberOfPlayers = 3;
    int numberOfRehersalTimePerWeek = 2;
    int numberOfLiveShowTimePerWeek = 1;
    int amountOfMoneyMadePerLiveShow = 300;
    int amountOfMoneySpentForRehersalInStudio = 50;

    void scheduleTheTourPlan(bool ifTheShowIsCancelled = true);
    void doLiveShow(int showTimeAmount = 120, int songNumbers = 25);

    //returns how much money the band is making
    float makeMoney(bool isThisShowHasTicket = true);
};

/*
Thing 2) YouTuber
5 properties:
    1) hour amount on script
    2) hour amount on shooting
    3) hour amount on editing
    4) view amount per video
    5) money amount made from per 1000 view
3 things it can do:
    1) make video
    2) increase follower
    3) make money
*/
struct YouTuber
{
    float hourAmountOnScript = 4;
    float hourAmountOnShooting = 3;
    float hourAmountOnEditing = 3;
    int viewAmountPerVideo = 7000;
    float moneyAmountPerVideo = 10;

    void makeVideo(std::string videoTopic, RockBand ACDC, float timeLong = 8.0f);
    void increaseFollower(bool subNotify = true);
    void makeMoney(bool monetization = true);
};


/*
Thing 3) Song Writer
5 properties:
    1) number of words in lyrics
    2) number of instruments used while producing
    3) number of BPM
    4) second amount of the song
    5) number of people who listened
3 things it can do:
    1) reach to the audience
    2) increase follower
    3) nail record label's contract
*/
struct SongWriter
{
    int numberOfWordsInLyrics = 300;
    int numberOfInstrumentsUsedWhileProducing = 6;
    int secondAmountOfTheSong = 150;
    int numberOfPeopleWhoListened = 5000;

    void reachToTheAudience(int platformAmount, YouTuber recordLabelA);
    void increaseFollower(bool needToPay = true);
    void nailRecordLabelsContract(bool labelInterests = true, int amountOfLabelsReachedOut = 10);
};

/*
Thing 4) School
5 properties:
    1) number of students
    2) amount of grades
    3) number of teachers
    4) number of subjects
    5) number of classes
3 things it can do:
    1) educate people
    2) offer jobs for society
    3) supply well-educated labors for society
*/
struct School
{
    int numberOfStudents = 1000;
    int amountOfGrades = 3;
    int numberOfTeachers = 5;
    int numberOfSubjects = 8;
    int numberOfClasses = 300;

    void educatePeople(bool openSchool = true);
    void offerJobsForSociety(SongWriter popSongWriterA, int jobAmount = 100);
    void supplyWellEducatedLaborsForSociety(bool openGraduation = true);
};


/*
Thing 5) Neck
5 properties:
    1) fret number (int)
    2) fret shape (std::string)
    3) 12th fret thickness in mm (int)
    4) fingerboard wood type (std::string)
    5) fret indicator inlay type (std::string)
3 things it can do:
    1) supply finger rest
    2) help indexing notes
    3) hold strings in position
*/
struct Neck
{
    int fretNumber = 22;
    std::string fretShape = "jumbo";
    int twelvethFretThickness = 30;
    std::string fingerboardWoodType = "maple";
    std::string fretIndicatorInlayType = "shell dot";

    void supplyFingerRest(int neckBoltPosition);
    void helpIndexingNotes(SongWriter classicalWriterA, bool fretInlay = true);
    void holdStringsInPosition(std::string nutType = "cow bone");
};

/*
Thing 6) Body
5 properties:
    1) body shape (std::string)
    2) number of pickups (int)
    3) number of pots (int)
    4) wood type (std::string)
    5) thickness in mm (int)
3 things it can do:
    1) hold parts together
    2) improve the vibration
    3) make guitar look cool
*/
struct Body
{
    std::string bodyShape = "strat";
    int numberOfPickups = 3;
    int numberOfPots = 3;
    std::string woodType= "alder";
    int thicknessInMM = 40;

    void holdPartsTogether(std::string boltType = "bolt on");
    void improveTheVibration(float resonateFrequency = 50);
    void makeGuitarLookCool (SongWriter rockWriterA, bool colourfulFinish = true);
};

/*
Thing 7) Bridge
5 properties:
    1) number of string slot (int)
    2) material type (std::string)
    3) color (std::string)
    4) whammy bar type (std::string)
    5) number of body screw hole (int)
3 things it can do:
    1) hold strings still
    2) make pitch dive
    3) match the body color
*/
struct Bridge
{
    int numberOfStringSlot = 6;
    std::string materialType = "stainless steel";
    std::string color = "nickel";
    std::string whammyBarType = "floyd rose";
    int numberOfBodyScrewHole = 2;

    void holdStringsStill(bool stringInTune = true);
    void makePitchDive(float stringTensionInKg = 1);

    //returns if the bridge matches guitar body's color
    bool matchTheBodyColor(SongWriter rockWriterA);
};

/*
Thing 8) String
5 properties:
    1) wound type (std::string)
    2) 1st string gauge in inch (float)
    3) 6th string gauge in inch (float)
    4) brand (std::string)
    5) coat type (std::string)
3 things it can do:
    1) vibrate
    2) get rust
    3) get broken
*/
struct String
{
    std::string woundType = "round wound";
    float firstStringGaugeInInch = 0.090f;
    float sixthStringGaugeInInch = 0.042f;
    std::string brand = "Elixir";
    std::string coatType = "ultra-thin";

    struct StringType
    {
        bool firstStringWound = false;
        bool secondStringWound = false;
        bool thirdStringWound = true;
        bool fourthStringWound = true;
        bool fifthStringWound = true;
        bool sixthStringWound = true;

        //returns how many wound strings do we have
        int checkWoundString(int woundStringAmount = 0);

        //returns the proper string pack name
        std::string chooseStringPack(int roundWoundStringNum = 3, int flatWoundStringNum = 4);

        //returns how much would the proper string pack cost
        float calculateStringPackBudget(float averageCostOfStringPack = 6);
        
    };

    void vibrate(Body strat, float frequency = 440, std::string pitchNotation = "A4");
    void getRust(bool colorChange = false);
    void getBroken(int brokenStringAmount = 0);
};

/*
Thing 9) Pickup
5 properties:
    1) coil type (std::string)
    2) string distance in mm (int)
    3) magnet material type (std::string)
    4) cover color (std::string)
    5) string number (int)
3 things it can do:
    1) pickup string vibration
    2) change the guitar tone
    3) match the body color
*/
struct Pickup
{
    std::string coilType = "single coil";
    int stringDistanceInMm = 8;
    std::string magnetMaterialType = "alnico 5";
    std::string coverColor = "ivory";
    int stringNumber = 6;

    void pickupStringVibration(bool pluckString = false);
    void changeTheGuitarTone(int pickupSwitchPosition = 5);

    //returns if pickup cover color matches the body color
    bool matchTheBodyColor(SongWriter rockWriterA);
};

/*
Thing 10) Electric Guitar
5 properties:
    1) Neck
    2) Body
    3) Bridge
    4) String
    5) Pickup
3 things it can do:
    1) sell money
    2) play rock music
    3) collect dust
*/
struct ElectricGuitar
{
    struct Neck
    {
        int fretNumber = 22;
        std::string fretShape = "jumbo";
        int twelvethFretThickness = 30;
        std::string fingerboardWoodType = "maple";
        std::string fretIndicatorInlayType = "shell dot";

        void supplyFingerRest(int neckBoltPosition);
        void helpIndexingNotes(SongWriter classicalWriterA, bool fretInlay = true);
        void holdStringsInPosition(std::string nutType = "cow bone");
    };

    struct Body
    {
        std::string bodyShape = "strat";
        int numberOfPickups = 3;
        int numberOfPots = 3;
        std::string woodType= "alder";
        int thicknessInMM = 40;
    
        void holdPartsTogether(std::string boltType = "bolt on");
        void improveTheVibration(float resonateFrequency = 50);
        void makeGuitarLookCool (SongWriter rockWriterA, bool colourfulFinish = true);
    };

    struct Bridge
    {
        int numberOfStringSlot = 6;
        std::string materialType = "stainless steel";
        std::string color = "nickel";
        std::string whammyBarType = "floyd rose";
        int numberOfBodyScrewHole = 2;

         void holdStringsStill(bool stringInTune = true);
        void makePitchDive(float stringTensionInKg = 1);

        //returns if the bridge matches guitar body's color
        bool matchTheBodyColor(SongWriter rockWriterA);
    };

    struct String
    {
        std::string woundType = "round wound";
        float firstStringGaugeInInch = 0.090f;
        float sixthStringGaugeInInch = 0.042f;
        std::string brand = "Elixir";
        std::string coatType = "ultra-thin";

        struct StringType
        {
            bool firstStringWound = false;
            bool secondStringWound = false;
            bool thirdStringWound = true;
            bool fourthStringWound = true;
            bool fifthStringWound = true;
            bool sixthStringWound = true;

            //returns how many wound strings do we have
            int checkWoundString(int woundStringAmount = 0);

            //returns the proper string pack name
            std::string chooseStringPack(int roundWoundStringNum = 3, int flatWoundStringNum = 4);

            //returns how much would the proper string pack cost
            float calculateStringPackBudget(float averageCostOfStringPack = 6);
        };
        
        void vibrate(Body strat, float frequency = 440, std::string pitchNotation = "A4");
        void getRust(bool colorChange = false);
        void getBroken(int brokenStringAmount = 0);
};

    struct Pickup
    {
        std::string coilType = "single coil";
        int stringDistanceInMm = 8;
        std::string magnetMaterialType = "alnico 5";
        std::string coverColor = "ivory";
        int stringNumber = 6;

        void pickupStringVibration(bool pluckString = false);
        void changeTheGuitarTone(int pickupSwitchPosition = 5);

        //returns if pickup cover color matches the body color
        bool matchTheBodyColor(SongWriter rockWriterA);
    };

    Neck roseWood22Frets;
    Body alderStrat;
    Bridge floydRose6Strings;
    String stockRoundWound090;
    Pickup stockSingleCoil;

    //returns how much money will get from selling this guitar
    float sellMoney(float totallValue = 0, float askingPrice = 0, float buyerBudget = 0);
    void playRockMusic(SongWriter rockWriterA, std::string songName = "Hell's Bell");
    
    //returns if the guitar is currently collecting dust
    bool collectDust(int useTimesInRecentWeek = 0);
};


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
