#include "Aviary.h"

Aviary::Aviary()
{
    arr = nullptr;
    size = 0;
    maxamountincage = 5;
}

Aviary::Aviary(int maxamountincage)
{
    arr = nullptr;
    size = 0;
    this->maxamountincage = maxamountincage;
}

Aviary::~Aviary()
{
    if (arr != nullptr)
    {
        int i = 0;
        while (i < size)
        {
            arr[i++]->~Animal();
        }
    }
    delete arr;
}

int Aviary::getSize() const&
{
    return size;
}

void Aviary::addAnimal(Animal* an)
{
    if (size == maxamountincage)
    {
        throw new MaxCapacityException();
    }
    else
    {   
        // ак сделать проверку на хищника?
        if (arr != nullptr)
        {   
            //                           к за€цам                          волк  ||                         к волкам                           за€ц
            if ((arr[0]->getIsPredator() == false && an->getIsPredator() == true) || (arr[0]->getIsPredator() == true && an->getIsPredator() == false))
            {
                throw new PredatorException();
            }
            //ƒќЅј¬»Ћ ѕ–ќ¬≈– ”=================================================================================================================================
            else if (arr[0]->getIsPredator() == true && (an->getIsPredator() == true && an->type() == "Bird" && ((Bird*)an)->getIsFlying() == false))
            {//                           волк  ||                       пингвин, был бы орЄл - было бы всЄ равно, т.к. летает
                throw new PredatorException();
            }
            else if ((arr[0]->getIsPredator() == true && arr[0]->type() == "Bird" && ((Bird*)an)->getIsFlying() == false) && (an->getIsPredator() == true && an->type() == "Beast"))
            {
                throw new PredatorException();
            }
            //ƒќЅј¬»Ћ ѕ–ќ¬≈– ”=================================================================================================================================
            else
            {
                // Ёто значит, что вольер пустой и можно заселить хоть кого первым
                Animal** tmp = new Animal * [++size];
                if (arr != nullptr)
                {
                    memcpy(tmp, arr, sizeof(arr) * (size - 1));
                    delete[] arr;
                }
                tmp[size - 1] = an;
                arr = tmp;
                cout << "\nThe animal has been successfully placed in aviary!\n\n";
            }
        }
        else 
        {
            // Ёто значит, что вольер пустой и можно заселить хоть кого первым
            Animal** tmp = new Animal * [++size];
            if (arr != nullptr)
            {
                memcpy(tmp, arr, sizeof(arr) * (size - 1));
                delete[] arr;
            }
            tmp[size - 1] = an;
            arr = tmp;
            cout << "\nThe animal has been successfully placed in aviary!\n\n";
        }
    }
}

void Aviary::removeAnimal(string name)
{
    if (size == 0) cout << "\nThe Aviary neither closed nor empty.\n\n";
    else
    {
        int id = findAnimalByName(name);
        if (id == -1) cout << "\nAccomodation wasn't found. Check input data.\n\n";
        else
        {
            Animal** tmp = new Animal * [--size];
            int i = 0;
            while (i < size)
            {
                if (i < id) tmp[i] = arr[i];
                else if (i >= id) tmp[i] = arr[i + 1];
                i++;
            }
            arr[id]->~Animal();
            if (arr != nullptr) delete[] arr;
            arr = tmp;
            cout << "\nThe animal with identification number on system [" << id + 1 << "] has been succesfully removed from aviary and ready be transported!\n\n";
        }
    }
}

void Aviary::editAnimalsInfo(string name) const&
{
    int id = findAnimalByName(name);

    if (id == -1) cout << "\nAnimal wasn't found. Check input data.\n\n";
    else
    {
        int menu = 0;
        string s1 = "", s2 = "";
        float fvalue = 0;
        bool bvalue1 = false, bvalue2 = false;

        if (arr[id]->type() == "Beast")
        {
            /*string name, bool ispredator, string habitat, bool isdomestic*/
            do
            {
                cout << "\n\tMENU TO CHANGE INFORMATION:";
                cout << "\n1) Name.";
                cout << "\n2) Predator.";
                cout << "\n3) Habitat.";
                cout << "\n4) Domestic.";
                cout << "\n5) All info.";
                cout << "\n0) Turn back to main menu.\nChoice: ";

                cin >> menu;
                switch (menu)
                {
                case 1:
                    cout << "\nInput name: ";
                    cin.ignore();
                    getline(cin, s1);
                    arr[id]->setName(s1);
                    cout << "\nName set succesfully!\n\n";
                    break;

                case 2:
                    cout << "\nInput [1] for true or [0] for false: ";
                    cin >> bvalue1;
                    arr[id]->setIsPredator(bvalue1);
                    cout << "\nPredator information set succesfully!\n\n";
                    break;

                case 3:
                    cout << "\nInput habitat: ";
                    cin.ignore();
                    getline(cin, s1);
                    ((Beast*)arr[id])->setHabitat(s1);
                    cout << "\nHabitat set succesfully!\n\n";
                    break;

                case 4:
                    cout << "\nInput [1] for true or [0] for false: ";
                    cin >> bvalue2;
                    ((Beast*)arr[id])->setIsDomestic(bvalue2);
                    cout << "\nDomestic information set succesfully!\n\n";
                    break;


                case 5:
                    cout << "\nInput name: ";
                    cin.ignore();
                    getline(cin, s1);
                    arr[id]->setName(s1);

                    cout << "\nInput [1] for true or [0] for false: ";
                    cin >> bvalue1;
                    arr[id]->setIsPredator(bvalue1);

                    cout << "\nInput habitat: ";
                    cin.ignore();
                    getline(cin, s1);
                    ((Beast*)arr[id])->setHabitat(s1);
                    cout << "\nHabitat set succesfully!\n\n";

                    cout << "\nInput [1] for true or [0] for false: ";
                    cin >> bvalue2;
                    ((Beast*)arr[id])->setIsDomestic(bvalue2);

                    cout << "\nAll information set succesfully!\n\n"; break;
                    break;

                default: if (menu > 5 && menu != 0 || menu < 0) cout << "\nWrong menu item selected.\n\n"; break;
                }

            } while (menu != 0);
        }
        else if (arr[id]->type() == "Bird")
        {
            /*	string name, bool ispredator, float speed, bool isflying */
            do
            {
                cout << "\n\tMENU TO CHANGE INFORMATION:";
                cout << "\n1. Name.";
                cout << "\n2. Predator.";
                cout << "\n3. Speed.";
                cout << "\n4. Flying.";
                cout << "\n5. All of this.";
                cout << "\n0. Turn back to main menu.\nChoice: ";

                cin >> menu;
                switch (menu)
                {
                case 1:
                    cout << "\nInput name: ";
                    cin.ignore();
                    getline(cin, s1);
                    arr[id]->setName(s1);
                    cout << "\nName set succesfully!\n\n";
                    break;

                case 2:
                    cout << "\nInput [1] for true or [0] for false: ";
                    cin >> bvalue1;
                    arr[id]->setIsPredator(bvalue1);
                    cout << "\nPredator information set succesfully!\n\n";
                    break;

                case 3:
                    cout << "\nInput speed: ";
                    cin >> fvalue;
                    ((Bird*)arr[id])->setSpeed(fvalue);
                    cout << "\nHabitat set succesfully!\n\n";
                    break;

                case 4:
                    cout << "\nInput [1] for true or [0] for false: ";
                    cin >> bvalue2;
                    ((Bird*)arr[id])->setFlying(bvalue2);
                    cout << "\nFlying bird information set succesfully!\n\n";
                    break;

                case 5:
                    cout << "\nInput name: ";
                    cin.ignore();
                    getline(cin, s1);
                    arr[id]->setName(s1);

                    cout << "\nInput [1] for true or [0] for false: ";
                    cin >> bvalue1;
                    arr[id]->setIsPredator(bvalue1);

                    cout << "\nInput speed: ";
                    cin >> fvalue;
                    ((Bird*)arr[id])->setSpeed(fvalue);

                    cout << "\nInput [1] for true or [0] for false: ";
                    cin >> bvalue2;
                    ((Bird*)arr[id])->setFlying(bvalue2);

                    cout << "\nAll information set succesfully!\n\n";
                    break;

                default: if (menu > 5 && menu != 0 || menu < 0) cout << "\nWrong menu item selected.\n\n"; break;
                }
            } while (menu != 0);
        }
        else if (arr[id]->type() == "Fish")
        {
            /*
            string name, bool ispredator, bool isdeepseafish
            */
            do
            {
                cout << "\n\tMENU TO CHANGE INFORMATION:";
                cout << "\n1. Name.";
                cout << "\n2. Predator.";
                cout << "\n3. Deep sea fish.";
                cout << "\n4. All of this.\nChoice: ";

                cin >> menu;
                switch (menu)
                {
                case 1:
                    cout << "\nInput name: ";
                    cin.ignore();
                    getline(cin, s1);
                    arr[id]->setName(s1);
                    cout << "\nName set succesfully!\n\n";
                    break;

                case 2:
                    cout << "\nInput [1] for true or [0] for false: ";
                    cin >> bvalue1;
                    arr[id]->setIsPredator(bvalue1);
                    cout << "\nPrice set succesfully!\n\n";
                    break;

                case 3:
                    cout << "\nInput [1] for true or [0] for false: ";
                    cin >> bvalue2;
                    ((Fish*)arr[id])->setIsDeepSeaFish(bvalue2);
                    cout << "\nDeep sea fish information set succesfully!\n\n";
                    break;

                case 4:
                    cout << "\nInput name: ";
                    cin.ignore();
                    getline(cin, s1);
                    arr[id]->setName(s1);

                    cout << "\nInput [1] for true or [0] for false: ";
                    cin >> bvalue1;
                    arr[id]->setIsPredator(bvalue1);

                    cout << "\nInput [1] for true or [0] for false: ";
                    cin >> bvalue2;
                    ((Fish*)arr[id])->setIsDeepSeaFish(bvalue2);

                    cout << "\nAll information set succesfully!\n\n";
                    break;

                default: if (menu > 4 && menu != 0 || menu < 0) cout << "\nWrong menu item selected.\n\n"; break;
                }
            } while (menu != 0);
        }
    }
}

void Aviary::editAnimalsInfoByID(int id) const&
{
    string tmp = "";
    tmp = arr[id]->getName();
    editAnimalsInfo(tmp);
}

void Aviary::showAviary() const&
{
    if (size == 0) cout << "\nThe shop neither closed nor empty.\n\n";
    else
    {
        int i = 0;
        while (i < size)
        {
            cout << "\n\tAnimal #" << i + 1 << endl;
            arr[i++]->show();
        }
    }
}

int Aviary::findAnimalByName(string name) const&
{
    int i = 0;
    while (i < size)
    {
        if (arr[i]->getName() == name)
        {
            return i;
            break;
        }
        i++;
    }
    return -1;
}

void Aviary::showCurrentType(string type) const&
{
    int i = 0, check = 0;
    while (i < size)
    {
        if (arr[i]->type() == type)
        {
            cout << "\n\tAnimal type {" << type << "}:";
            arr[i]->show();
            check++;
        }
        i++;
    }
    if (check == 0) cout << "\nError. The type wasn't found.\n\n";
    else cout << "\nFound " << check << " animals.\n\n";
}

void Aviary::showAnimalByName(string name) const&
{
    int id = findAnimalByName(name);

    if (id == -1) cout << "\nAnimal wasn't found. Check input data.\n\n";
    else arr[id]->show();
}

void Aviary::sort(bool(*cmp)(const Animal*, const Animal*)) const&
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (cmp(arr[j + 1], arr[j]))
            {
                swap(arr[j + 1], arr[j]);
            }
        }
    }
    cout << "\nAviary sorted.\n\n";
}