#include <iostream>
#include <vector>
#include <memory>
#include "procesor.h"
#include "placavideo.h"
#include "memorieram.h"
#include "sistempc.h"
#include "exceptii.h"

int main() 
{
    try 
    {
        std::cout << "Testare Validare Date\n";
        Procesor p1("Core i7", "Intel", -500, 65, "LGA1700", 8, 3.6);
    } 
    catch (const ExceptieHardware& e) 
    {
        std::cerr << "Capturat excepție: " << e.what() << "\n\n";
    }

    SistemPC sistemulMeu("Gaming Beast 2026");

    try 
    {
        auto cpu = std::make_shared<Procesor>("Ryzen 9", "AMD", 2500, 105, "AM5", 12, 4.2);
        auto gpu = std::make_shared<PlacaVideo>("RTX 5090", "NVIDIA", 9000, 450, 24, true);
        auto ram = std::make_shared<MemorieRAM>("Vengeance", "Corsair", 800, 15, 32, 6000, "DDR5");

        sistemulMeu.adaugaPiesa(cpu);
        sistemulMeu.adaugaPiesa(gpu);
        sistemulMeu.adaugaPiesa(ram);
    } 
    catch (const ExceptieHardware& e) 
    {
        std::cerr << "Eroare la configurare: " << e.what() << "\n";
    }

    sistemulMeu.afisareSistem();
    std::cout << "Performanta medie a sistemului: " << sistemulMeu.calculPerformantaMedie() << "\n";
    std::cout << "Numar procesoare detectate: " << sistemulMeu.numaraProcesoare() << "\n";
    std::cout << "\nTestare Deep Copy\n";
    SistemPC copieSistem = sistemulMeu; 
    std::cout << "Copia sistemului a fost creata cu succes folosind clone().\n";
    std::cout << "\nNumar total de piese hardware active in memorie: " 
              << Hardware::getNrTotalComponente() << "\n";

    return 0;
}