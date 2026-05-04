#ifndef SISTEMPC_H
#define SISTEMPC_H

#include "hardware.h"
#include <vector>
#include <memory>
#include <string>

class SistemPC
{
    std::string denumireSistem;
    std::vector<std::shared_ptr<Hardware>> piese;

public:
    //constructori
    SistemPC();
    SistemPC(std::string nume);
    SistemPC(const SistemPC& data); 
    SistemPC& operator=(SistemPC data); 
    ~SistemPC();

    //metode
    void adaugaPiesa(const std::shared_ptr<Hardware>& piesaNoua);
    void afisareSistem() const;
    double calculPerformantaMedie() const;
    int numaraProcesoare() const; 
    

   friend void swap(SistemPC& first, SistemPC& second) noexcept;
};

#endif