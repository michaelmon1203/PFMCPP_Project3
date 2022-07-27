/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.





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
    int follower;

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
        follower = viewAmountPerVideo * 100 / 10000;
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
        numberOfPeopleWhoListened = numberOfPeopleWhoListened * 3 / 10;
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
    bool stringInTune = true;

    bool holdStringsStill();
    void makePitchDive(float stringTensionInKg = 1);
    void matchTheBodyColor(SongWriter rockWriterA);
};

bool Bridge::holdStringsStill()
{
    if(intonationAdjustable)
    {
        stringInTune = true;
    }
    else
    {
        stringInTune = false;
    }
    return stringInTune;
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
    bool toneChanged = false;

    void pickupStringVibration( String fifthString, bool pluckString = false);
    bool changeTheGuitarTone(int pickupSwitchPosition = 5);
    void matchTheBodyColor(SongWriter rockWriterA);
};

void Pickup::pickupStringVibration(String fifthString, bool pluckString)
{
    if(pluckString)
    {
        fifthString.vibrate();
    }
}

bool Pickup::changeTheGuitarTone(int pickupSwitchPosition)
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
    bool collectDust = false;

    float sellMoney(float totallValue = 0, float askingPrice = 0, float buyerBudget = 0);
    void playRockMusic(SongWriter rockWriterA, std::string songName = "Hell's Bell");
    bool usageCheck(int useTimesInRecentWeek = 0);
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

bool ElectricGuitar::usageCheck(int useTimesInRecentWeek)
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
    Example::main();
    
    std::cout << "good to go!" << std::endl;
}
