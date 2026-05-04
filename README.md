Sistem de Gestiune Componente Hardware
Proiect realizat în C++ pentru gestionarea unui inventar de componente informatice, permițând configurarea și analiza performanței unui sistem PC.

Descriere Tehnică
Programul utilizează concepte avansate de Programare Orientată pe Obiecte pentru a modela interacțiunea dintre diferite piese hardware:

Ierarhie de clase: Clasa de bază abstractă Hardware și clasele derivate Procesor, PlacaVideo și MemorieRAM.

Managementul memoriei: Utilizarea std::shared_ptr pentru a asigura eliberarea automată a resurselor și evitarea scurgerilor de memorie.

Polimorfism: Calcularea performanței totale și afișarea datelor prin metode virtuale suprascrise.

Deep Copy: Implementarea metodei clone() pentru copierea corectă a obiectelor în vectori polimorfici.

Validare: Utilizarea excepțiilor custom pentru a preveni introducerea datelor eronate (prețuri negative sau parametri tehnici invalizi).

Structura Codului
Hardware.h/cpp: Definirea interfeței și a membrilor comuni.

Procesor.h/cpp, PlacaVideo.h/cpp, MemorieRAM.h/cpp: Implementările specifice fiecărui tip de hardware.

SistemPC.h/cpp: Clasa manager care utilizează un container de tip vector pentru stocarea componentelor.

HardwareExceptions.h/cpp: Ierarhia de erori derivată din std::exception.

Compilare și Execuție
Proiectul poate fi compilat folosind orice compilator compatibil C++11 sau mai nou.

Comandă compilare:
g++ *.cpp -o program

Comandă rulare:
./program

Surse de inspirație
Logica proiectului și implementarea conceptelor de bază au avut ca sursă de inspirație materialele de curs, seminariile de profil și platforme de documentare precum w3schools.
