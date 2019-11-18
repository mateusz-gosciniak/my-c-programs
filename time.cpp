#include <iostream>
#include <sys/time.h>  /// funkcje pomiaru czasu

using namespace std;

/// klasa pomiaru czasu
class pomiar_czasu{
  private:
    struct timeval
        startuj_pomiar, zakoncz_pomiar;

    long czas, sekundy, mikrosekundy;

  public:
    void start()
        { gettimeofday(&startuj_pomiar, NULL); }

    void koniec()
        { gettimeofday(&zakoncz_pomiar, NULL); }

    long wynik_pomiaru()
    {
        sekundy = zakoncz_pomiar.tv_sec  - startuj_pomiar.tv_sec;
        mikrosekundy = zakoncz_pomiar.tv_usec - startuj_pomiar.tv_usec;
        czas = sekundy*1000 + mikrosekundy/1000 + 0.5; /// wynik w jednostce milisekund
        return czas;
    }
};

int main()
{
    pomiar_czasu czas;

    czas.start();
    {
        /// kod do pomiaru czasu
        for(int i=0;i<100000000;i++) {}
    }
    czas.koniec();

    cout << "czas: " << czas.wynik_pomiaru() << " milisekund" << endl;

    return 0;
}

