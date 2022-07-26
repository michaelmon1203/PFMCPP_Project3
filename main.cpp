#include<math.h>

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
struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;
    int time;

    struct Foot
    {
        int footSize = 290;
        int footNum = 0;

        void stepFoward();
        int stepSize();
    };

    Foot leftFoot;
    Foot rightFoot;

    void run(int howFast, bool startWithLeftFoot);
};

void Person::Foot::stepFoward()
{
    footNum += 1;
}

int Person::Foot::stepSize()
{
    int distancePerFoot = footNum * footSize;
    return distancePerFoot;
}

void Person::run(int howFast, bool startWithLeftFoot)
{
    if(startWithLeftFoot == true)
    {
        leftFoot.stepFoward();
        rightFoot.stepFoward();
    }
    else
    {
        rightFoot.stepFoward();
        leftFoot.stepFoward();
    }
    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();
    howFast = distanceTraveled / time;
}


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


struct RockBand
{
    int numberOfPlayers = 3;
    int numberOfRehersalTimePerWeek = 0;
    int numberOfLiveShowTimePerWeek = 0;
    float amountOfMoneyMadePerLiveShow = 300.0f;
    float amountOfMoneySpentPerRehersal = 50.0f;
    float moneyMade;

    struct BandManager
    {
        bool friendWillingToHelpForFree = false;
        bool fullTimeManagement = false;
        bool offlineManagement = false;
        float regularSalaryPerMonth = 0;
        bool ifTheShowIsCancelled = true;
        int bookRehersalTime = 0;
        
        void bookRehersalRoom(float bandBudgetPerHour = 50);
        bool scheduleTheTourPlan(bool barOpen = false);
        void doMarketing(int posterPrintAmount = 100);
    };

    void doRehersal(bool allBandMemberAttended);
    void doLiveShow(int showTimeAmount = 120, int songNumbers = 25);
    float makeMoney(bool isThisShowHasTicket = true);
};

bool RockBand::BandManager::scheduleTheTourPlan(bool barOpen)
{
    if(barOpen)
    {
        bookRehersalTime -=1;
    }
    else
    {
        ifTheShowIsCancelled = true;
    }
    return ifTheShowIsCancelled;
}

void RockBand::BandManager::bookRehersalRoom(float bandBudgetPerHour)
{
    if(bandBudgetPerHour > 0 && ifTheShowIsCancelled == false)
    {
        bookRehersalTime += 1;
    }
}

void RockBand::BandManager::doMarketing(int posterPrintAmount)
{
    if(ifTheShowIsCancelled)
    {
        posterPrintAmount = 0;   
    }
    else
    {
        posterPrintAmount = 300;   
    }
}

void RockBand::doRehersal(bool allBandMemberAttended)
{
    if(allBandMemberAttended)
    {
        numberOfRehersalTimePerWeek +=1;
    }
}

void RockBand::doLiveShow(int showTimeAmount, int songNumbers)
{
    songNumbers = showTimeAmount / 4;
}

float RockBand::makeMoney(bool isThisShowHasTicket)
{
    if(isThisShowHasTicket)
    {
        moneyMade = amountOfMoneyMadePerLiveShow * numberOfLiveShowTimePerWeek - amountOfMoneySpentPerRehersal * numberOfRehersalTimePerWeek;
    }
    return moneyMade;
}


struct YouTuber
{
    float hourAmountOnScript = 4;
    float hourAmountOnShooting = 3;
    float hourAmountOnEditing = 3;
    int viewAmountPerVideo = 7000;
    float moneyAmountPerVideo = 10;
    int videoNum = 1;
    float moneyMade = 0.0f;

    void makeVideo(std::string videoTopic, RockBand ACDC, float timeLong = 8.0f);
    void increaseFollower(bool subNotify = true);
    float makeMoney(bool monetization = true);
};

void YouTuber::makeVideo(std::string videoTopic, RockBand ACDC, float timeLong)
{ 
    timeLong = ACDC.numberOfPlayers * 2;
    videoTopic = "ACDC";
}

void YouTuber::increaseFollower(bool subNotify)
{
    if(subNotify)
    {
        int follower;
        follower = (int) round(viewAmountPerVideo * 0.01);
    }
}

float YouTuber::makeMoney(bool monetization)
{
    if(monetization)
    {
        moneyMade = moneyAmountPerVideo * videoNum;
    }
    return moneyMade;
}


struct SongWriter
{
    std::string artistName = "Johnny Cash";
    int numberOfWordsInLyrics = 300;
    int numberOfInstrumentsUsedWhileProducing = 6;
    int secondAmountOfTheSong = 150;
    int numberOfPeopleWhoListened = 5000;
    int recordLabelsContract = 0;

    void reachToTheAudience(int platformAmount, YouTuber songReviewerA);
    void increaseFollower(bool needToPay = true);
    void nailRecordLabelsContract(bool labelInterests = true, int amountOfLabelsReachedOut = 10);
};

void SongWriter::reachToTheAudience(int platformAmount, YouTuber songReviewerA)
{
    RockBand rockWriter;
    platformAmount = 3;
    numberOfPeopleWhoListened = numberOfPeopleWhoListened / platformAmount;
    songReviewerA.videoNum += 1;
}

void SongWriter::increaseFollower(bool needToPay)
{
    if(needToPay)
    {
        numberOfPeopleWhoListened = (int) round(numberOfPeopleWhoListened * 0.3);
    }
}

void SongWriter::nailRecordLabelsContract(bool labelInterests, int amountOfLabelsReachedOut)
{
    if(labelInterests && amountOfLabelsReachedOut > 0)
    {
        recordLabelsContract += 1;
    }
}


struct School
{
    int graduationPerYear = 0;
    int numberOfStudentsPerGrade = 1000;
    int numberOfGrades = 3;
    int numberOfTeachers = 5;
    int numberOfSubjects = 8;
    int numberOfClasses = 300;

    void educatePeople(bool openSchool, int numberOfStudents);
    void offerJobsForSociety(int jobAmount = 100);
    void supplyWellEducatedLaborsForSociety(bool openGraduation = true);
};

void School::educatePeople(bool openSchool, int numberOfStudents)
{
    if(openSchool)
    {
        numberOfStudents = numberOfStudentsPerGrade * numberOfGrades;
    }
}

void School::offerJobsForSociety(int jobAmount)
{
    jobAmount += numberOfTeachers;
}

void School::supplyWellEducatedLaborsForSociety(bool openGraduation)
{
    if(openGraduation)
    {
        graduationPerYear = numberOfStudentsPerGrade;
    }
}


struct Neck
{
    int fretNumber = 22;
    std::string fretShape = "jumbo";
    int twelvethFretThickness = 30;
    std::string fingerboardWoodType = "maple";
    std::string fretIndicatorInlayType = "shell dot";

    void supplyFingerRest(int neckBoltPosition);
    void helpIndexingNotes(bool fretInlay = true);
    void holdStringsInPosition(float nutDepth = 0);
};

void Neck::supplyFingerRest(int neckBoltPosition)
{
    neckBoltPosition = fretNumber - 7;
}

void Neck::helpIndexingNotes(bool fretInlay)
{
    if(fretInlay)
    {
        twelvethFretThickness += 5;
    }
}

void Neck::holdStringsInPosition(float nutDepth)
{
    nutDepth = 3.5f;
}


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

void Body::holdPartsTogether(std::string boltType)
{
    if (boltType == "bolt on")
    {
        thicknessInMM += 10;
    }
}

void Body::improveTheVibration(float resonateFrequency)
{
    if(woodType == "alder")
    {
        resonateFrequency = resonateFrequency * 1.5f;
    }
}

void Body::makeGuitarLookCool(SongWriter rockWriterA, bool colourfulFinish)
{
    if(colourfulFinish)
    {
        rockWriterA.increaseFollower();
    }
}


struct Bridge
{
    int numberOfStringSlot = 6;
    std::string materialType = "stainless steel";
    std::string color = "nickel";
    std::string whammyBarType = "floyd rose";
    int numberOfBodyScrewHole = 2;
    bool intonationAdjustable = true;

    void holdStringsStill(bool stringInTune = true);
    void makePitchDive(float stringTensionInKg = 1);
    void matchTheBodyColor(SongWriter rockWriterA);
};

void Bridge::holdStringsStill(bool stringInTune)
{
    if(intonationAdjustable)
    {
        stringInTune = true;
    }
    else
    {
        stringInTune = false;
    }
}

void Bridge::makePitchDive(float stringTensionInKg)
{
    if(whammyBarType == "floyd rose")
    {
        stringTensionInKg = stringTensionInKg * 0.3f;
    }
}

void Bridge::matchTheBodyColor(SongWriter rockWriterA)
{
    rockWriterA.increaseFollower();
}


struct String
{
    std::string woundType = "round wound";
    float firstStringGaugeInInch = 0.090f;
    float sixthStringGaugeInInch = 0.042f;
    std::string brand = "Elixir";
    std::string coatType = "ultra-thin";

    void vibrate(float frequency = 440, std::string pitchNotation = "A4");
    bool getRust(bool colorChange = false, float playHour = 0, bool rusted = false);
    bool getBroken(int brokenStringAmount = 0, bool broken = false);
};

void String::vibrate(float frequency, std::string pitchNotation)
{
    if(pitchNotation == "A4")
    {
        frequency = 400;
    }
}

bool String::getRust(bool colorChange, float playHour, bool rusted)
{
    if(playHour > 200 && brand == "Elixir" && colorChange == true)
    {
        rusted = true;
    }
    return rusted;
}

bool String::getBroken(int brokenStringAmount, bool broken)
{
    if(brokenStringAmount > 0)
    {
        broken = true;
    }
    return broken;
}


struct Pickup
{
    std::string coilType = "single coil";
    int stringDistanceInMm = 8;
    std::string magnetMaterialType = "alnico 5";
    std::string coverColor = "ivory";
    int stringNumber = 6;

    void pickupStringVibration( String fifthString, bool pluckString = false);
    bool changeTheGuitarTone(int pickupSwitchPosition = 5, bool toneChanged = false);
    void matchTheBodyColor(SongWriter rockWriterA);
};

void Pickup::pickupStringVibration(String fifthString, bool pluckString)
{
    if(pluckString)
    {
        fifthString.vibrate();
    }
}

bool Pickup::changeTheGuitarTone(int pickupSwitchPosition, bool toneChanged)
{
    if(pickupSwitchPosition != 5)
    {
        toneChanged = true;
    }
    else
    {
        toneChanged = false;
    }
    return toneChanged;
}

void Pickup::matchTheBodyColor(SongWriter rockWriterA)
{
    rockWriterA.increaseFollower();
}


struct ElectricGuitar
{
    Neck roseWood22Frets;
    Body alderStrat;
    Bridge floydRose6Strings;
    String stockRoundWound090;
    Pickup stockSingleCoil;

    float sellMoney(float totallValue = 0, float askingPrice = 0, float buyerBudget = 0);
    void playRockMusic(SongWriter rockWriterA, std::string songName = "Hell's Bell");
    bool usageCheck(int useTimesInRecentWeek = 0, bool collectDust = false);
};

float ElectricGuitar::sellMoney(float totalValue, float askingPrice, float buyerBudget)
{
    if(buyerBudget > askingPrice)
    {
        totalValue = buyerBudget;
    }
    return totalValue;
}

void ElectricGuitar::playRockMusic(SongWriter rockWriterA, std::string songName)
{
    if(songName == "Hell's Bell")
    {
        rockWriterA.increaseFollower();
    }
}

bool ElectricGuitar::usageCheck(int useTimesInRecentWeek, bool collectDust)
{
    if(useTimesInRecentWeek == 0)
    {
        collectDust = true;
    }
    else
    {
        collectDust = false;
    }
    return collectDust;
}
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
