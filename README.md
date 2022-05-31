# Intergalaktyczna gra turowa
--------------------------------

# Krótki opis

Intergalaktyczna gra turowa to gra polegająca na pokonaniu wszystkich przeciwników i odnalezieniu przedmiotu, którego poszukiwanie zlecono na początku fabuły rozgrywki. Interakcja z użytkownikiem przebiega w terminalu, a sam użytkownik do dyspozycji ma jedynie klawiaturę numeryczną. Jego zadaniem jest wybieranie odpowiednich opcji by skutecznie przejść grę do końca, nie będąc zabitym przez żadnego wroga.

Fabuła gry, podobnie jak wszystkie komendy, napisana jest po angielsku, ze względu na dobry nawyk programistyczny.

# Konstrukcja programu

Program został zrealizowany przy pomocy programowania obiektowego (OOP). Podsatową klasą jest **Person**, która jest klasą bazową, po której dziedziczą:


- **Player**, który tworzy obiekt gracza, kontrolowanego przez użytkownika
- **Enemy**, który tworzy obiekty wroga, atakujące gracza
- **Boss**, który dodatkowo dziedziczy po klasie **Enemy** a tworzy obiekt bossa, którego trzeba pokonać pod koniec każdego poziomu.

## **Person**

Klasa **Person** przechowuje jedynie atrybut odpowiadający za punkty zdrowia, który można pozyskać lub ustawić metodami publicznymi.

    class Person
    {
        protected:
            const int health;
    };


## **Player**


Klasa **Player** dodatkowo ma atrybuty:

        int max_health;
        int weapon_damage;
        int shield;

które nadają graczowi kolejno maksymalną ilość punktów życia (która jest niezmienialna), punkty ataku oraz punkty obrony.
Punkty ataku odpowiadają za ilość punktów życia zabranych przeciwnikowi, a punkty obrony za ilość punktów życia nadanych graczowi, kiedy
użytkownik postanowi użyć metody `heal`.
Poza getterami i setterami, klasa player ma również wcześniej wspomnianą metodę `heal`, która polega na podniesieniu jego punktów życia
(z upewnieniem się, że nie przekroczy ona wartości max_health) oraz `attack_kind`, która zostanie omówiona przy klasie **Gameplay**.

## **Enemy**

    class Enemy: public Person
    {
        protected:
            std::string name;
            int eweapon_damage;
            int ekind;
            //which value represents the planet:
            //1: PIPR-2
            //2: ALIN-ANA
            //3: POEL-4.5P
            //4: PROI-25
    };

Klasa **Enemy** poza atrybutem otrzymanym z klasy **Person**, posiada atrybut nazwy, punktów ataku oraz rodzaju. W grze rodzaj odpowiada aktualnemu poziomowi gry, które nazwy swoje mają od planet, na których wg fabuły w danej chwili znaduje się gracz. Rodzaj wroga wykorzystywany jest potem w wielu funkcjach i metodach klasy **Gameplay**.

Klasa oczywiście posiada gettery i settery.

Dodatkowo, klasa ma metodę *dodge()*, zwracającą wartość logiczną oraz *deal_dmg()* zwracającą liczbę całkowitą.

    bool dodge()
    {
        srand(time(0));
        int chance = rand() % 10;
        if(chance == 1)
            return true;
        return false;
    }

Metoda *dodge()* losuje, z 10% szansą, czy wróg może uniknąc atak gracza.

    int deal_dmg()
    {
        srand(time(0));
        int dmg = rand() % 11;
        return abs(eweapon_damage - dmg);
    }

Metoda *deal_dmg()* losuje z jaką ilością punktów ataku wróg zaatakuje przeciwnika.




Dodatkowo napisane zostały klasy mające inne role:

- **Item**, który tworzy obiekty przedmiotów dodającej specjalne właściwości graczowi (np. zwiększające jego punkty obrony)
- **Chest**, który tworzy obiekt skrzyni będącej kontenerem obiektów klasy **Item**
- **Gameplay**, który jest klasą realizującą wszystkie akcje w grze, między innymi *bitwę*, bądź *otwieranie skrzyni*.


## **Item** 


Klasa **Item**, poza tym że przechowuje atrybuty *nazwa* oraz *wartość*, ma również atrybut *rodzaj*, który określa do czego przyporządkowana jest wartość przedmiotu. Na przykład, kiedy przedmiot jest rodzaju 2 i zostanie podniesiony przez użytkownika, gracz otrzymuje dodatkową liczbę punktów obrony odpowiadającą wartości *value*.

    class Item
    {
        private:
            std::string iname;
            int ivalue;
            int ikind;
            // which value represents which kind:
            // 0: health
            // 1: weapon_damage
            // 2: shield
    };

Poza tym, klasa ma również przeciążone operatory potrzebne w klasie **Gameplay** oraz metodę *print*, która wyświetla w terminalu parametry przedmiotu, np.
    (Blade, 10)
co oznacza, że przedmiot o nazwie *blade* ma wartość 10. 

## **Chest**

Klasa **Chest** tworzy obiekt, który jest kontenerem określonej ilości przedmiotów. Można je z niego usunąć metodą *pop_item()*, która przy okazji zwraca też ten przedmiot. Poniżej pokazano domyślną zawartość kontenera. Znajduje się ona w konstruktorze klasy.

    Chest():item_number(10)
    {
        // 0: health
        // 1: wd
        // 2: sh
        items = new Item[10];
        items[0] = Item("Astro Toy Box", -5, 1);
        items[1] = Item("Spear of 1000 moons", 20, 1);
        items[2] = Item("Photon spear", -10, 1);
        items[3] = Item("Healing tears of Holy Mother", 30, 0);
        items[4] = Item("4-dimensional Spikes", -5, 1);
        items[5] = Item("Sharp Lightbringer", 15, 1);
        items[6] = Item("Space Cola", 10, 2);
        items[7] = Item("Quantum Guardian Protection", 15, 2);
        items[8] = Item("Black Hole Elixir", 10, 0);
        items[9] = Item("Tears of a dying star", 15, 0);
    }

Jak widać, niektóre wartości przedmiotów mają parametr ujemny, który jest równoważny punktom życia zabranym graczowi.

## **Gameplay**

Klasa **Gameplay** to najważniejsza klasa realizująca wszystkie akcje w grze oraz zapewniająca interakcję z użytkownikiem. Klasa nie posiada żadnych atrybutów, stworzona została jedynie dla porządkowości kodu, aby widoczne było, które metody odpowiadają za akcję w grze.

Klasa ma 5 metod:

    class Gameplay
    {
        private:
        public:
            Gameplay(){}
            void disp_battle(Player& player, Enemy& enemy, int& round);
            void battle(Player &player, Enemy &enemy);
            void boss_battle(Player &player, Boss &boss);
            void disp_chest(Player& player, Chest& chest);
            void draw_battle(Player &player, int const& ek);
    };

Dodatkowo w pliku, poza klasą, znajdują się funkcje:

    void disp_border();
    Enemy generate_enemy(int const& ek);
    std::string draw_rand_name(int const& ek);

### *battle(Player& player, Enemy& enemy)*

Metoda informuje użytkownika o nadchodzącej walce i wywołuje metodę *disp_battle(...)*, która na wejście otrzymuje obiekt *player*, *enemy* oraz numer rundy walki, która w tej metodzie zwiększana jest o 1 po wykonaniu akcji przez użytkownika.

Użytkownik wybiera, czy chce zaatakować przeciwnika, czy chce się obronić. W przypadku ataku przeciwnika, gracz wybiera *atak specjalny*, który zadaje wrogowi większe obrażenia, jeśli jest on akurat na niego podatny. W kodzie rozwiązane zostało to w taki sposób, że specjalny atak na wroga odpowiada jego rodzajowi, czyli tak naprawdę z jakiego poziomu pochodzi. Ale użytkownik tego nie wie (być może w trakcie gry to rozgryzie).

W czasie ataku wróg również zadaje graczowi obrażenia, których wartość wylosowana została w metodzie *enemy.deal_dmg()*

Druga opcja pozwala na obronę, lecz szansa, że gracz się uzdrowi, zależy od jego obecnych punktów obrony:

    srand(time(0));
    int chance = rand() % (100 + player.get_sh());
    if(chance > 60)
    {
        player.heal(50);

        cout<<"You healed yourself"<<endl;
    }
    else
    {
        player.take_damage(enemy.deal_dmg());

        cout<<"Enemy hit you for "<<enemy.deal_dmg()<<endl;
    }

Jeśli graczowi los się nie powiedzie, zostanie on zaatakowny przez wroga.
Metoda jest aktywna, dopóki gracz lub przeciwnik nie został zabity.

### *boss_battle(Player &player, Boss &boss)*

Metoda *boss_battle(...)* działa bardzo podobnie, z taką różnicą, że na wejście metody *battle()* podaje gracza i bossa.

Dodatkowo, po pokonaniu bossa, gracz podnosi przedmiot, który boss miał w swoim posiadaniu.

    if(!boss.is_alive())
        {
            cout << "You defeated the Boss\nIn return you get ";
            bitem.print();
        }
        else
            cout << "You were defeated by the boss" << endl;
        if(bitem.get_ikind() == 0)
            player.heal(bitem.get_ivalue());
        else if(bitem.get_ikind() == 1)
            player.pick_up(bitem.get_ivalue());
        else
            player.set_sh(player.get_sh() + bitem.get_ivalue());

### *disp_chest(Player& player, Chest& chest)*

Zadaniem metody *disp_chest(...)* jest wyświetlenie przedmiotu wylosowanego ze skrzyni (obiekt klasy **Chest**), a następnie nadania graczowi jego odpowiednich wartości. Wykorzystane przy tym zostały rodzaje przedmiotów (atrybut klasy **Item**). Przed podniesienem przedmiotów, gracz jest pytany, czy wyraża na to zgodę. Gracz musi być czujny, ponieważ przedmiot, który znajduje się w skrzyni, może mu zaszkodzić i odjąć punkty życia.


    if(opt[0] == 'Y' || opt[0] == 'y')
            {
                usleep(3 * microsecond);
                if(item.get_ikind() == 0)
                {
                    player.heal(item.get_ivalue());
                    cout << '\n' << item.get_iname()<< " healed you for "<<item.get_ivalue()<<endl;
                }
                else if(item.get_ikind() == 1)
                {
                    player.pick_up(item.get_ivalue());
                    cout << '\n' << item.get_iname()<< " increased your damage by "<<item.get_ivalue()<<" points"<<endl;
                }
                else
                {
                    player.set_sh(player.get_sh() + item.get_ivalue());
                    cout << '\n' <<item.get_iname()<< " increased your shield by "<<item.get_ivalue()<<" points"<<endl;
                }

Na sam koniec wyświetlone zostają nowe parametry gracza.

W pliku odpowiadającym za rozgrywkę i fabułę po wyjściu z metody, sprawdzane jest, czy gracz nadal żyje (jego punkty życia są większe od 0). Wynia to z tego, że przemiotu mogą mu również zadawać obrażenia.

### *draw_battle(Player &player, int const& ek)*

Zadaniem tej metody jest wywołanie funkji *battle(...)*, uprzednio tworząc wroga przy pomocy funkcji *generate_enemy(ek)* (ona z kolei korzysta z funkcji *draw_rand_name(int const& ek)*, w celu nadania wrogowi nazwy). Szansa, że walka zostanie wywołana jest równa 20%.

    if (rand() % 5 == 0)
        {
            Enemy rand_enemy = generate_enemy(ek);
            cout << "You were unexpectedly attacted by an unknown enemy" << endl;
            battle(player, rand_enemy);
        }

Ta metoda poukrywana została w różnych miejscach w funkcji *plot()* w pliku `main_game.cpp`, w móc zaskakiwać użytkownika na różnych etapach gry.




# Interfejs

Poniżej przedstawiono krótki opis interfejsu

![](/do_dok/interfejs.png)

Komunikacja z użytkownikiem przebiega poprzez interfejs w terminalu, który napisany został w pliku *Gameplay.cpp*

# Autorzy
- Rybojad Adam
- Szczygielski Filip
- Wewiór Mikołaj
