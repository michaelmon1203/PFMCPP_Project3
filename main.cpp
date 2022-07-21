 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */


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
    float amountOfMoneyMadePerLiveShow = 300.0f;
    float amountOfMoneySpentForRehersalInStudio = 50.0f;

    struct BandManager
    {
        bool friendWillingToHelpForFree = false;
        bool fullTimeManagement = false;
        bool offlineManagement = false;
        float regularSalaryPerMonth = 0;
        float percentageShareOfIncome = 30.0f;
        
        void bookRehersalRoom(float bandBudgetPerHour = 50);
        void scheduleTheTourPlan(bool ifTheShowIsCancelled = true);
        void doMarketing(int posterPrintAmount = 100);
    };

    void doRehersal(bool allBandMemberAttended);
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
    std::string artistName = "Johnny Cash";
    int numberOfWordsInLyrics = 300;
    int numberOfInstrumentsUsedWhileProducing = 6;
    int secondAmountOfTheSong = 150;
    int numberOfPeopleWhoListened = 5000;

    void reachToTheAudience(int platformAmount, YouTuber songReviewerA);
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
